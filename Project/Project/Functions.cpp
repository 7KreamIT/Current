#include "Header.h" //подключение заголовка

//если библиотека подключилась, то структура заполняется данными из файла Test.xlsx, иначе из Test.csv:
#ifdef haveXlnt
gadget* getByXlsx(int& aN, string fileNameXlsx)
{
	//открытие файла xlsx:
	xlnt::workbook wb;
	wb.load(fileNameXlsx);
	auto ws = wb.active_sheet();
	//подсчёт количества столбцов:
	bool endRepeat = 0; //выйти из цикла?
	int tempABC = 0; //номер текущей буквы
	string tempCell; //название текущей ячейки
	int nCol = 0; //кол-во столбцов
	while (!endRepeat) //пока ячейка не окажется пустая
	{
		tempCell = englishABC[tempABC] + string("1");
		tempABC++;
		if (ws.cell(tempCell).value<string>() != "") nCol++; // если ячейка не пустая
		else endRepeat = 1;
	}
	//подсчёт количества строк:
	endRepeat = 0; //выйти из цикла?
	int tempNumber = 1; //номер текущей цифры (первая не 0 потому, что отсчёт строк в экселе начинается с 1)
	tempCell = ""; //очищаем название текущей ячейки
	while (!endRepeat) //пока ячейка не окажется пустая
	{
		tempCell = "A" + to_string(tempNumber);
		tempNumber++;
		if (ws.cell(tempCell).value<string>() != "") aN++;
		else endRepeat = 1;
	}
	//считывание всей таблицы + заполнение структуры:
	tempABC = 0; //номер текущей буквы
	tempNumber = 1; //номер текущей цифры (первая не 0 потому, что отсчёт строк в экселе начинается с 1)
	int i = 0; // переменная цикла
	//заполнение структуры:
	gadget* A = new gadget[aN]; //нулевой элемент - это название столбцов
	for (i = 0; i < aN; i++)
	{
		tempABC = 0;
		for (int currentNumCol = 1; currentNumCol < nCol + 1; currentNumCol++)
		{
			tempCell = englishABC[tempABC] + to_string(i + 1);
			tempABC++;
			A[i].setValueByIndex(toRus(ws.cell(tempCell).value<string>()), currentNumCol);
		}			
	}
	cout << "Структура успешно заполнена данными из файла " << fileNameXlsx << endl;
	return A;
}
#else
gadget* getByCsv(int& aN, string fileNameCsv)
{
	int i, j; //переменные циклов
	aN = numberOfLines(fileNameCsv) - 1; //подсчёт фактического кол-ва строк в файле (i - переменная цикла)
	//чтение таблицы:
	ifstream fileRead(fileNameCsv); //открытие файла
	string* gadgetString = new string[aN]; //массив строк файла
	for (i = 0; i < aN; i++) getline(fileRead, gadgetString[i]); //читает всю строку
	fileRead.close(); //закрытие файла

	//заполнение структуры:
	gadget* A = new gadget[aN]; //основной массив устройств
	string tempWord;
	for (i = 0; i < aN; i++) //нулевая строка это заголовки
	{
		j = 0;
		for (int currentNumCol = 1; currentNumCol < nCol - 1; currentNumCol++)
		{
			while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
			j++;
			A[i].setValueByIndex(tempWord, currentNumCol);
			tempWord = "";
		}
		//для последнего поля класса проведём отдельное заполнение (т.к. после него в файле csv не стоит ";"
		while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
		A[i].setValueByIndex(tempWord, nCol);
	}
	delete[] gadgetString; //отчистить массив строк
	cout << "Структура успешно заполнена данными из файла " << fileNameCsv << endl;
	return A;
}
#endif

//конвертация UTF-8 в OEM1251 с помощью WinApi: (называется утилитой)
string toRus(string utf)
{
	char oem1251Str[maxSymbol];
	int nLength = MultiByteToWideChar(CP_UTF8, 0, utf.c_str(), utf.length(), nullptr, 0);
	BSTR bstrWide = SysAllocStringLen(nullptr, nLength);
	MultiByteToWideChar(CP_UTF8, 0, utf.c_str(), utf.length(), bstrWide, nLength);
	nLength = WideCharToMultiByte(866, 0, bstrWide, -1, nullptr, 0, nullptr, 0);
	WideCharToMultiByte(1251, 0, bstrWide, -1, oem1251Str, nLength, nullptr, nullptr);
	SysFreeString(bstrWide);
	string str = string(oem1251Str);
	return str;
}

//подсчёт кол-ва строк в файле CSV и вывод в формате int:
int numberOfLines(string fileName)
{
	char* str = new char[1024];
	int i = 0;
	ifstream file(fileName);
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		if (str[0] == ';') return i; //на случай если закончились установки
		else i++;
	}
	file.close();
	delete[] str;
	return i;
}

//приведение дат в формат ДДММГГ:
string dateToSixNumbers(int day, int month, int year)
{
	string date;
	if (year > 2000)
	{
		if ((day <  10) && (month <  10)) date = '0' + to_string(day) + '0' + to_string(month) + to_string(year - 2000);
		if ((day <  10) && (month >= 10)) date = '0' + to_string(day) +		  to_string(month) + to_string(year - 2000);
		if ((day >= 10) && (month <  10)) date =	   to_string(day) + '0' + to_string(month) + to_string(year - 2000);
		if ((day >= 10) && (month >= 10)) date =	   to_string(day) +		  to_string(month) + to_string(year - 2000);
	}
	else
	{
		if ((day <  10) && (month <  10)) date = '0' + to_string(day) + '0' + to_string(month) + to_string(year);
		if ((day <  10) && (month >= 10)) date = '0' + to_string(day) +		  to_string(month) + to_string(year);
		if ((day >= 10) && (month <  10)) date =	   to_string(day) + '0' + to_string(month) + to_string(year);
		if ((day >= 10) && (month >= 10)) date =	   to_string(day) +		  to_string(month) + to_string(year);
	}
	return date;
}

//вывод в файл Xlsx:
void setToXlsx(gadget*& A, int& lastChosenGadget, string fileNameOutXlsx)
{
	//открытие файла xlsx:
	xlnt::workbook wb;
	wb.load(fileNameXlsx);
	auto ws = wb.active_sheet();

	string nameCellDate = "M" + to_string(lastChosenGadget - 1);
	ws.cell(nameCellDate).value(A[lastChosenGadget].lastDateTO);

	string nameCellHours = "N" + to_string(lastChosenGadget - 1);
	ws.cell(nameCellHours).value(A[lastChosenGadget].lastHoursTO);
	
	//wb.save(fileNameOutXlsx);
}

//вывод в файл Csv:
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv)
{
	ofstream fileWrite(fileNameOutCsv); //объявим вывод в файл csv

	for (int i = 0; i < aN; i++)
	{
		int currentNumCol = 1;
		while (A[i].getValueByIndex(currentNumCol) != "error")
		{
			fileWrite << A[i].getValueByIndex(currentNumCol) << ";";
			currentNumCol++;
		}
		fileWrite << endl;
	}
	fileWrite.close(); //закрытие файла
}

//функция для красивого завершения программы:
void exitProgram()
{
	char a;
	int b;
	cout << "Программа завершена без ошибок!\nНажмите Enter для выхода из программы" << endl;
	while (1)
	{
		a = _getch();
		b = static_cast <int> (a);
		if (b == 13)
		{
			exit(0);
			break;
		}
		else continue;
	}
}
