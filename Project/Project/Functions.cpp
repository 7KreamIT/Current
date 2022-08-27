#include "Header.h" //����������� ���������

//���� ���������� ������������, �� ��������� ����������� ������� �� ����� Test.xlsx, ����� �� Test.csv:
#ifdef haveXlnt
gadget* getByXlsx(int& aN, string fileNameXlsx)
{
	//�������� ����� xlsx:
	xlnt::workbook wb;
	wb.load(fileNameXlsx);
	auto ws = wb.active_sheet();
	//������� ���������� ��������:
	bool endRepeat = 0; //����� �� �����?
	int tempABC = 0; //����� ������� �����
	string tempCell; //�������� ������� ������
	int nCol = 0; //���-�� ��������
	while (!endRepeat) //���� ������ �� �������� ������
	{
		tempCell = englishABC[tempABC] + string("1");
		tempABC++;
		if (ws.cell(tempCell).value<string>() != "") nCol++; // ���� ������ �� ������
		else endRepeat = 1;
	}
	//������� ���������� �����:
	endRepeat = 0; //����� �� �����?
	int tempNumber = 1; //����� ������� ����� (������ �� 0 ������, ��� ������ ����� � ������ ���������� � 1)
	tempCell = ""; //������� �������� ������� ������
	while (!endRepeat) //���� ������ �� �������� ������
	{
		tempCell = "A" + to_string(tempNumber);
		tempNumber++;
		if (ws.cell(tempCell).value<string>() != "") aN++;
		else endRepeat = 1;
	}
	//���������� ���� ������� + ���������� ���������:
	tempABC = 0; //����� ������� �����
	tempNumber = 1; //����� ������� ����� (������ �� 0 ������, ��� ������ ����� � ������ ���������� � 1)
	int i = 0; // ���������� �����
	//���������� ���������:
	gadget* A = new gadget[aN]; //������� ������� - ��� �������� ��������
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
	cout << "��������� ������� ��������� ������� �� ����� " << fileNameXlsx << endl;
	return A;
}
#else
gadget* getByCsv(int& aN, string fileNameCsv)
{
	int i, j; //���������� ������
	aN = numberOfLines(fileNameCsv) - 1; //������� ������������ ���-�� ����� � ����� (i - ���������� �����)
	//������ �������:
	ifstream fileRead(fileNameCsv); //�������� �����
	string* gadgetString = new string[aN]; //������ ����� �����
	for (i = 0; i < aN; i++) getline(fileRead, gadgetString[i]); //������ ��� ������
	fileRead.close(); //�������� �����

	//���������� ���������:
	gadget* A = new gadget[aN]; //�������� ������ ���������
	string tempWord;
	for (i = 0; i < aN; i++) //������� ������ ��� ���������
	{
		j = 0;
		for (int currentNumCol = 1; currentNumCol < nCol - 1; currentNumCol++)
		{
			while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
			j++;
			A[i].setValueByIndex(tempWord, currentNumCol);
			tempWord = "";
		}
		//��� ���������� ���� ������ ������� ��������� ���������� (�.�. ����� ���� � ����� csv �� ����� ";"
		while (gadgetString[i][j] != ';') tempWord += gadgetString[i][j++];
		A[i].setValueByIndex(tempWord, nCol);
	}
	delete[] gadgetString; //��������� ������ �����
	cout << "��������� ������� ��������� ������� �� ����� " << fileNameCsv << endl;
	return A;
}
#endif

//����������� UTF-8 � OEM1251 � ������� WinApi: (���������� ��������)
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

//������� ���-�� ����� � ����� CSV � ����� � ������� int:
int numberOfLines(string fileName)
{
	char* str = new char[1024];
	int i = 0;
	ifstream file(fileName);
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		if (str[0] == ';') return i; //�� ������ ���� ����������� ���������
		else i++;
	}
	file.close();
	delete[] str;
	return i;
}

//���������� ��� � ������ ������:
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

//����� � ���� Xlsx:
void setToXlsx(gadget*& A, int& lastChosenGadget, string fileNameOutXlsx)
{
	//�������� ����� xlsx:
	xlnt::workbook wb;
	wb.load(fileNameXlsx);
	auto ws = wb.active_sheet();

	string nameCellDate = "M" + to_string(lastChosenGadget - 1);
	ws.cell(nameCellDate).value(A[lastChosenGadget].lastDateTO);

	string nameCellHours = "N" + to_string(lastChosenGadget - 1);
	ws.cell(nameCellHours).value(A[lastChosenGadget].lastHoursTO);
	
	//wb.save(fileNameOutXlsx);
}

//����� � ���� Csv:
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv)
{
	ofstream fileWrite(fileNameOutCsv); //������� ����� � ���� csv

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
	fileWrite.close(); //�������� �����
}

//������� ��� ��������� ���������� ���������:
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
