#include "Header.h" // подключение заголовка

#ifdef haveXlnt // если библиотека подключилась

// заполнение структуры данными из файла xlsx:
gadget* getByXlsx(int& aN, string fileNameXlsx)
{
	// открытие файла xlsx:
	xlnt::workbook wb;
	wb.load(fileNameXlsx);
	auto ws = wb.active_sheet();

	// подсчёт количества столбцов:
	bool endRepeat = 0; // выйти из цикла?
	int tempABC = 0; // номер текущей буквы
	string tempCell; // название текущей ячейки
	int nCol = 0; // кол-во столбцов
	while (!endRepeat) // пока ячейка не окажется пустая
	{
		tempCell = englishABC[tempABC] + string("1");
		tempABC++;
		if (ws.cell(tempCell).value<string>() != "") nCol++; // если ячейка не пустая
		else endRepeat = 1;
	}

	// подсчёт количества строк:
	endRepeat = 0; // выйти из цикла?
	int tempNumber = 1; // номер текущей цифры (первая не 0 потому, что отсчёт строк в экселе начинается с 1)
	tempCell = ""; // очищаем название текущей ячейки
	while (!endRepeat) // пока ячейка не окажется пустая
	{
		tempCell = "A" + to_string(tempNumber);
		tempNumber++;
		if (ws.cell(tempCell).value<string>() != "") aN++;
		else endRepeat = 1;
	}

	// считывание всей таблицы + заполнение структуры:
	tempABC = 0; // номер текущей буквы
	int i = 0; // переменная цикла
	gadget* A = new gadget[aN]; // нулевой элемент - это название столбцов
	for (i = 0; i < aN; i++)
	{
		tempABC = 0;
		for (int currentNumCol = 1; currentNumCol < nCol + 1; currentNumCol++)
		{
			tempCell = englishABC[tempABC] + to_string(i + 1);
			tempABC++;
			A[i].setValueByIndex(toOEM1251(ws.cell(tempCell).value<string>()), currentNumCol);
		}			
	}
	cout << "Структура успешно заполнена данными из файла " << fileNameXlsx << endl;
	return A;
}

// вывод в файл Xlsx:
void setToXlsx(gadget*& A, int& aN, string fileNameOutXlsx)
{
	xlnt::workbook wb;
	xlnt::worksheet ws = wb.active_sheet();

	// подсчитываем кол-во столбцов:
	int nCol = 1; // не факт что равна 1
	while (A[0].getValueByIndex(nCol) != "error") nCol++;

	// заполнение таблицы данными из структуры:
	int tempABC = 0; // номер текущей буквы
	// int tempNumber = 1; // номер текущей цифры (первая не 0 потому, что отсчёт строк в экселе начинается с 1)
	int i = 0; // переменная цикла
	int currentNumCol; // текущий номер столбца
	string tempCell;
	for (i = 0; i < aN; i++)
	{
		tempABC = 0;
		for (currentNumCol = 1; currentNumCol < nCol; currentNumCol++)
		{
			tempCell = englishABC[tempABC] + to_string(i + 1);
			tempABC++;
			ws.cell(tempCell).value(toUTF8(A[i].getValueByIndex(currentNumCol)));
		}
	}

	// ws.merge_cells("C3:C4"); // вот так можно объединить ячейки
	// ws.cell("C3").formula("=RAND()"); // вот так вводится формула
	
	// форматирование таблицы:
	ws.freeze_panes("E2"); // закрепляем панели

	wb.save(fileNameOutXlsx); // сохраняем файл
}
#else
// заполнение структуры данными из файла csv:
gadget* getByCsv(int& aN, string fileNameCsv)
{
	int i, j; // переменные циклов
	aN = numberOfLines(fileNameCsv) - 1; // подсчёт фактического кол-ва строк в файле (i - переменная цикла)
	// чтение таблицы:
	ifstream fileRead(fileNameCsv); // открытие файла
	string* gadgetString = new string[aN]; // массив строк файла
	for (i = 0; i < aN; i++) getline(fileRead, gadgetString[i]); // читает всю строку
	fileRead.close(); // закрытие файла

	// заполнение структуры:
	gadget* A = new gadget[aN]; // основной массив устройств
	string tempWord;
	for (i = 0; i < aN; i++) // нулевая строка это заголовки
	{
		j = 0;
		for (int currentNumCol = 1; currentNumCol < nCol - 1; currentNumCol++)
		{
			while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
			j++;
			A[i].setValueByIndex(tempWord, currentNumCol);
			tempWord = "";
		}
		// для последнего поля класса проведём отдельное заполнение (т.к. после него в файле csv не стоит ";"
		while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
		A[i].setValueByIndex(tempWord, nCol);
	}
	delete[] gadgetString; // отчистить массив строк
	cout << "Структура успешно заполнена данными из файла " << fileNameCsv << endl;
	return A;
}

// вывод данных в файл csv:
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv)
{
	ofstream fileWrite(fileNameOutCsv); // объявим вывод в файл csv

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
	fileWrite.close(); // закрытие файла
}
#endif

// утилита для конвертации из UTF-8 в OEM1251 с помощью WinApi:
string toOEM1251(string utf)
{
	char oem1251Str[maxSymbol];
	int nLength = MultiByteToWideChar(CP_UTF8, 0, utf.c_str(), utf.length(), nullptr, 0);
	BSTR bstrWide = SysAllocStringLen(nullptr, nLength);
	MultiByteToWideChar(CP_UTF8, 0, utf.c_str(), utf.length(), bstrWide, nLength);
	nLength = WideCharToMultiByte(1251, 0, bstrWide, -1, nullptr, 0, nullptr, 0);
	WideCharToMultiByte(1251, 0, bstrWide, -1, oem1251Str, nLength, nullptr, nullptr);
	SysFreeString(bstrWide);
	string str = string(oem1251Str);
	return str;
}

// утилита для конвертации из OEM1251 в UTF-8:
string toUTF8(string oem)
{
	const char* str = oem.c_str();
	string res;
	int result_u, result_c;
	result_u = MultiByteToWideChar(1251, 0, str, -1, 0, 0);
	if (!result_u) { return 0; }
	wchar_t* ures = new wchar_t[result_u];
	if (!MultiByteToWideChar(1251, 0, str, -1, ures, result_u)) {
		delete[] ures;
		return 0;
	}
	result_c = WideCharToMultiByte(65001, 0, ures, -1, 0, 0, 0, 0);
	if (!result_c) {
		delete[] ures;
		return 0;
	}
	char* cres = new char[result_c];
	if (!WideCharToMultiByte(65001, 0, ures, -1, cres, result_c, 0, 0)) {
		delete[] cres;
		return 0;
	}
	delete[] ures;
	res.append(cres);
	delete[] cres;
	return res;
}

// подсчёт кол-ва строк в файле CSV и вывод в формате int:
int numberOfLines(string fileName)
{
	char* str = new char[1024];
	int i = 0;
	ifstream file(fileName);
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		if (str[0] == ';') return i; // на случай если закончились установки
		else i++;
	}
	file.close();
	delete[] str;
	return i;
}

// приведение дат в формат ДДММГГ:
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

// функция для красивого завершения программы:
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
