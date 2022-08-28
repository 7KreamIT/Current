#include "Header.h" // ����������� ���������

#ifdef haveXlnt // ���� ���������� ������������

// ���������� ��������� ������� �� ����� xlsx:
gadget* getByXlsx(int& aN, string fileNameXlsx)
{
	// �������� ����� xlsx:
	xlnt::workbook wb;
	wb.load(fileNameXlsx);
	auto ws = wb.active_sheet();

	// ������� ���������� ��������:
	bool endRepeat = 0; // ����� �� �����?
	int tempABC = 0; // ����� ������� �����
	string tempCell; // �������� ������� ������
	int nCol = 0; // ���-�� ��������
	while (!endRepeat) // ���� ������ �� �������� ������
	{
		tempCell = englishABC[tempABC] + string("1");
		tempABC++;
		if (ws.cell(tempCell).value<string>() != "") nCol++; // ���� ������ �� ������
		else endRepeat = 1;
	}

	// ������� ���������� �����:
	endRepeat = 0; // ����� �� �����?
	int tempNumber = 1; // ����� ������� ����� (������ �� 0 ������, ��� ������ ����� � ������ ���������� � 1)
	tempCell = ""; // ������� �������� ������� ������
	while (!endRepeat) // ���� ������ �� �������� ������
	{
		tempCell = "A" + to_string(tempNumber);
		tempNumber++;
		if (ws.cell(tempCell).value<string>() != "") aN++;
		else endRepeat = 1;
	}

	// ���������� ���� ������� + ���������� ���������:
	tempABC = 0; // ����� ������� �����
	int i = 0; // ���������� �����
	gadget* A = new gadget[aN]; // ������� ������� - ��� �������� ��������
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
	cout << "��������� ������� ��������� ������� �� ����� " << fileNameXlsx << endl;
	return A;
}

// ����� � ���� Xlsx:
void setToXlsx(gadget*& A, int& aN, string fileNameOutXlsx)
{
	xlnt::workbook wb;
	xlnt::worksheet ws = wb.active_sheet();

	// ������������ ���-�� ��������:
	int nCol = 1; // �� ���� ��� ����� 1
	while (A[0].getValueByIndex(nCol) != "error") nCol++;

	// ���������� ������� ������� �� ���������:
	int tempABC = 0; // ����� ������� �����
	// int tempNumber = 1; // ����� ������� ����� (������ �� 0 ������, ��� ������ ����� � ������ ���������� � 1)
	int i = 0; // ���������� �����
	int currentNumCol; // ������� ����� �������
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

	// ws.merge_cells("C3:C4"); // ��� ��� ����� ���������� ������
	// ws.cell("C3").formula("=RAND()"); // ��� ��� �������� �������
	
	// �������������� �������:
	ws.freeze_panes("E2"); // ���������� ������

	wb.save(fileNameOutXlsx); // ��������� ����
}
#else
// ���������� ��������� ������� �� ����� csv:
gadget* getByCsv(int& aN, string fileNameCsv)
{
	int i, j; // ���������� ������
	aN = numberOfLines(fileNameCsv) - 1; // ������� ������������ ���-�� ����� � ����� (i - ���������� �����)
	// ������ �������:
	ifstream fileRead(fileNameCsv); // �������� �����
	string* gadgetString = new string[aN]; // ������ ����� �����
	for (i = 0; i < aN; i++) getline(fileRead, gadgetString[i]); // ������ ��� ������
	fileRead.close(); // �������� �����

	// ���������� ���������:
	gadget* A = new gadget[aN]; // �������� ������ ���������
	string tempWord;
	for (i = 0; i < aN; i++) // ������� ������ ��� ���������
	{
		j = 0;
		for (int currentNumCol = 1; currentNumCol < nCol - 1; currentNumCol++)
		{
			while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
			j++;
			A[i].setValueByIndex(tempWord, currentNumCol);
			tempWord = "";
		}
		// ��� ���������� ���� ������ ������� ��������� ���������� (�.�. ����� ���� � ����� csv �� ����� ";"
		while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
		A[i].setValueByIndex(tempWord, nCol);
	}
	delete[] gadgetString; // ��������� ������ �����
	cout << "��������� ������� ��������� ������� �� ����� " << fileNameCsv << endl;
	return A;
}

// ����� ������ � ���� csv:
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv)
{
	ofstream fileWrite(fileNameOutCsv); // ������� ����� � ���� csv

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
	fileWrite.close(); // �������� �����
}
#endif

// ������� ��� ����������� �� UTF-8 � OEM1251 � ������� WinApi:
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

// ������� ��� ����������� �� OEM1251 � UTF-8:
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

// ������� ���-�� ����� � ����� CSV � ����� � ������� int:
int numberOfLines(string fileName)
{
	char* str = new char[1024];
	int i = 0;
	ifstream file(fileName);
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		if (str[0] == ';') return i; // �� ������ ���� ����������� ���������
		else i++;
	}
	file.close();
	delete[] str;
	return i;
}

// ���������� ��� � ������ ������:
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

// ������� ��� ��������� ���������� ���������:
void exitProgram()
{
	char a;
	int b;
	cout << "��������� ��������� ��� ������!\n������� Enter ��� ������ �� ���������" << endl;
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
