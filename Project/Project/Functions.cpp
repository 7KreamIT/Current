#include "Header.h" //����������� ���������

//������� ���-�� ����� � ����� � ����� � ������� int:
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
		if ((day < 10) && (month < 10)) date = '0' + to_string(day) + '0' + to_string(month) + to_string(year - 2000);
		if ((day < 10) && (month >= 10)) date = '0' + to_string(day) + to_string(month) + to_string(year - 2000);
		if ((day >= 10) && (month < 10)) date = to_string(day) + '0' + to_string(month) + to_string(year - 2000);
		if ((day >= 10) && (month >= 10)) date = to_string(day) + to_string(month) + to_string(year - 2000);
	}
	else
	{
		if ((day <  10) && (month <  10)) date = '0' + to_string(day) + '0' + to_string(month) + to_string(year);
		if ((day <  10) && (month >= 10)) date = '0' + to_string(day) + to_string(month) + to_string(year);
		if ((day >= 10) && (month <  10)) date = to_string(day) + '0' + to_string(month) + to_string(year);
		if ((day >= 10) && (month >= 10)) date = to_string(day) + to_string(month) + to_string(year);
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
	//if (str.size() == 0) str = utf;
	return str;
}