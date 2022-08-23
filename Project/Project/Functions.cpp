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
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].number  	 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //01
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].type  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //02
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].model  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //03
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].place  	     = toRus(ws.cell(tempCell).value<string>()); tempABC++; //04
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].oil  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //05
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].tools  	     = toRus(ws.cell(tempCell).value<string>()); tempABC++; //06
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].password  	 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //07
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].qtAF   		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //08
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].qtOF  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //09
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].qtOS  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //10
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].qtBelt  	 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //11
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].info  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //12
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].lastDateTO   = toRus(ws.cell(tempCell).value<string>()); tempABC++; //13
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].lastHoursTO  = toRus(ws.cell(tempCell).value<string>()); tempABC++; //14
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].owner  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //15
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].serialNumber = toRus(ws.cell(tempCell).value<string>()); tempABC++; //16
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].AF  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //17
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].OF  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //18
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].OS  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //19
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].Belt  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //20
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].SHD  		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //21
	}
	return A;
}

//���� ���������� �� ������������, �� ������������ �������� ���(������ �� ����� "�������.csv"):
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

//������� ������� ���� ���� ����� ����������, ������� ���������� ������:
int winGadget(gadget* A, int* x, int n) //x - ��� ������ � ����������� ��� �������� ������������, n - �� ���-��
{
	bool uncorrectAnswer = 0; //�������� �����
	int chosenGadget = 0; //�������� ����� ����������
	if (n > 1) //���� ����� ������ ��� 1
	{
		cout << "������ ���������� ��� �������� �����:" << endl;
		for (int i = 0; i < n; i++) cout << i + 1 << ":" << A[x[i]].model << endl;
		cout << "������� ����� ������ �� 1 �� " << n << ":" << endl;
		do
		{
			uncorrectAnswer = 0;
			cin >> chosenGadget;
			if ((chosenGadget > n) || (chosenGadget < 1))
			{
				uncorrectAnswer = 1;
				cout << "������� ���������� ����� �� 1 �� " << n << endl;
			}
		} while (uncorrectAnswer == 1);
		chosenGadget = stoi(A[x[chosenGadget - 1]].number); //������ ��� ���������� �������� ������� ��������� ������
	}
	else chosenGadget = stoi(A[x[0]].number);
	system("cls");
	cout << "�������:'" << A[chosenGadget].type
		<< "' �� '" << A[chosenGadget].place
		<< "' ������ '" << A[chosenGadget].model
		<< "'" << endl;
	return chosenGadget;
}

//������� ��� ��������� ���������� ���������:
bool exitProgram()
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
	return 0;
}

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