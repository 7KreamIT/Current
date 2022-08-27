#include "Header.h" //����������� ���������

//���� ���������� ������������, �� ������������ �������� ���(������ �� ����� "Test.xlsx"):
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
	for (i = 0; i < aN; i++) //������� ������ ��� ���������
	{
		tempABC = 0;
		for (int currentNumCol = 1; currentNumCol < nCol; currentNumCol++)
		{
			tempCell = englishABC[tempABC] + to_string(i + 1);
			tempABC++;
			A[i].setName(currentNumCol, toRus(ws.cell(tempCell).value<string>()));
		}			
	}
	return A;
}

//���� ���������� �� ������������, �� ������������ �������� ���(������ �� ����� "�������.csv"):
/*
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
	for (i = 0; i < aN; i++) //������� ������ ��� ���������
	{
		j = 0;
		while (gadgetString[i][j] != ';') A[i].number  		+= gadgetString[i][j++]; j++; //01
		while (gadgetString[i][j] != ';') A[i].type  		+= gadgetString[i][j++]; j++; //02
		while (gadgetString[i][j] != ';') A[i].model  		+= gadgetString[i][j++]; j++; //03
		while (gadgetString[i][j] != ';') A[i].place  		+= gadgetString[i][j++]; j++; //04
		while (gadgetString[i][j] != ';') A[i].oil  		+= gadgetString[i][j++]; j++; //05
		while (gadgetString[i][j] != ';') A[i].tools  		+= gadgetString[i][j++]; j++; //06
		while (gadgetString[i][j] != ';') A[i].password  	+= gadgetString[i][j++]; j++; //07
		while (gadgetString[i][j] != ';') A[i].qtAF  		+= gadgetString[i][j++]; j++; //08
		while (gadgetString[i][j] != ';') A[i].qtOF  		+= gadgetString[i][j++]; j++; //09
		while (gadgetString[i][j] != ';') A[i].qtOS  		+= gadgetString[i][j++]; j++; //10
		while (gadgetString[i][j] != ';') A[i].qtBelt  		+= gadgetString[i][j++]; j++; //11
		while (gadgetString[i][j] != ';') A[i].info  		+= gadgetString[i][j++]; j++; //12
		while (gadgetString[i][j] != ';') A[i].lastDateTO   += gadgetString[i][j++]; j++; //13
		while (gadgetString[i][j] != ';') A[i].lastHoursTO  += gadgetString[i][j++]; j++; //14
		while (gadgetString[i][j] != ';') A[i].owner  		+= gadgetString[i][j++]; j++; //15
		while (gadgetString[i][j] != ';') A[i].serialNumber += gadgetString[i][j++]; j++; //16
		while (gadgetString[i][j] != ';') A[i].AF  			+= gadgetString[i][j++]; j++; //17
		while (gadgetString[i][j] != ';') A[i].OF  			+= gadgetString[i][j++]; j++; //18
		while (gadgetString[i][j] != ';') A[i].OS  			+= gadgetString[i][j++]; j++; //19
		while (gadgetString[i][j] != ';') A[i].Belt  		+= gadgetString[i][j++]; j++; //20
										  A[i].SHD 			+= gadgetString[i][j++]; j++; //21
	}
	delete[] gadgetString; //��������� ������ �����
	return A;
}
*/

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
		fileWrite << A[i].number << ";";  //01
		fileWrite << A[i].type << ";";  //02
		fileWrite << A[i].model << ";";  //03
		fileWrite << A[i].place << ";";  //04
		fileWrite << A[i].oil << ";";  //05
		fileWrite << A[i].tools << ";";  //06
		fileWrite << A[i].password << ";";  //07
		fileWrite << A[i].qtAF << ";";  //08
		fileWrite << A[i].qtOF << ";";  //09
		fileWrite << A[i].qtOS << ";";  //10
		fileWrite << A[i].qtBelt << ";";  //11
		fileWrite << A[i].info << ";";  //12
		fileWrite << A[i].lastDateTO << ";";  //13
		fileWrite << A[i].lastHoursTO << ";";  //14
		fileWrite << A[i].owner << ";";  //15
		fileWrite << A[i].serialNumber << ";";  //16
		fileWrite << A[i].AF << ";";  //17
		fileWrite << A[i].OF << ";";  //18
		fileWrite << A[i].OS << ";";  //19
		fileWrite << A[i].Belt << ";";  //20
		fileWrite << A[i].SHD << endl; //21
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
