#include "Header.h" // подключение заголовка

#if haveXlnt // если библиотека подключилась

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
	// объявление книги и страницы:
	xlnt::workbook wb;
	xlnt::worksheet ws = wb.active_sheet();

	// подсчитываем кол-во столбцов:
	int nCol = 1; // не факт что равна 1
	while (A[0].getValueByIndex(nCol) != "error") nCol++;

	// заполнение таблицы данными из структуры, попутно форматируя таблицу:
	int tempABC = 0; // номер текущей буквы
	int i = 0; // переменная цикла
	int currentNumCol; // текущий номер столбца
	string tempCell;
	xlnt::alignment alignment;								  // для выравнивания
	alignment.horizontal(xlnt::horizontal_alignment::center); // ..
	alignment.vertical(xlnt::vertical_alignment::center);	  // ..
	xlnt::border border;
	xlnt::border::border_property border_pro;			// для границ
	border_pro.style(xlnt::border_style::thin);			// ..
	border.side(xlnt::border_side::start, border_pro);	// ..
	border.side(xlnt::border_side::end, border_pro);	// ..
	border.side(xlnt::border_side::top, border_pro);	// ..
	border.side(xlnt::border_side::bottom, border_pro);	// ..
	for (i = 0; i < aN; i++)
	{
		tempABC = 0;
		for (currentNumCol = 1; currentNumCol < nCol; currentNumCol++)
		{
			tempCell = englishABC[tempABC] + to_string(i + 1);
			tempABC++;
			ws.cell(tempCell).value(toUTF8(A[i].getValueByIndex(currentNumCol)));
			ws.cell(tempCell).alignment(alignment);
			ws.cell(tempCell).border(border);
			ws.cell(tempCell).font(xlnt::font().name(fontName).size(fontHeight));
		}
	}

	// отдельно выравниваем столбик устройст по левому краю:
	alignment.horizontal(xlnt::horizontal_alignment::left);
	for (i = 0; i < aN; i++)
	{
		tempCell = modelSymbol + to_string(i + 1); 
		ws.cell(tempCell).alignment(alignment);
	}

	// оркашиваем весь первый столбик в оранжевый:
	for (i = 0; i < aN; i++)
	{
		tempCell = "A" + to_string(i + 1);
		ws.cell(tempCell).fill(xlnt::fill::solid(xlnt::rgb_color(237, 125, 49)));
	}

	// оркашиваем всю первую строчку в оранжевый:
	tempABC = 0;
	for (currentNumCol = 1; currentNumCol < nCol; currentNumCol++)
	{
		tempCell = englishABC[tempABC] + to_string(1);
		tempABC++;
		ws.cell(tempCell).fill(xlnt::fill::solid(xlnt::rgb_color(237, 125, 49)));
	}

	// автоширина столбцов:
	int maxLength = 0;
	for (currentNumCol = 1; currentNumCol < nCol; currentNumCol++)
	{
		for (i = 0; i < aN; i++)
		{
			if (A[i].getValueByIndex(currentNumCol).length() > maxLength)
				maxLength = A[i].getValueByIndex(currentNumCol).length();
		}
		ws.column_properties(currentNumCol).width = maxLength + 1; // добавляем единицу прозапас
		maxLength = 0;
	}
	
	// форматирование таблицы:
	ws.freeze_panes("E2"); // закрепляем панели
	setlocale(LC_ALL, "Russian"); // установка названия страницы
	ws.title(toUTF8("Справка"));  // ..
	setlocale(LC_ALL, "en-US");	  // ..

	wb.save(fileNameOutXlsx); // сохраняем файл
}

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

	// подчсёт кол-ва столбцов в А:
	int nCol = 0;
	string a = gadgetString[0];
	nCol = count(a.begin(), a.end(), ';') + 1; // ищет кол-во столбцов

	// заполнение структуры:
	gadget* A = new gadget[aN]; // основной массив устройств
	string tempWord;
	int gadgetStringLength; // длина строки
	for (i = 0; i < aN; i++) // нулевая строка это заголовки
	{
		gadgetStringLength = gadgetString[i].length();

		j = 0;
		for (int currentNumCol = 1; currentNumCol < nCol; currentNumCol++)
		{
			while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
			j++;
			A[i].setValueByIndex(tempWord, currentNumCol);
			tempWord = "";
		}
		// последнее поле класса заполним оставшимися символами:
		for (int k = j; k < gadgetStringLength; k++)
		{
			tempWord += gadgetString[i][j];
			j++;
		}
		A[i].setValueByIndex(tempWord, nCol);
		tempWord = "";
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
#endif

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
