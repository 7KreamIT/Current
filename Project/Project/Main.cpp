#include <iostream>      //��� ������ �������
#include <fstream>       //��� ������ �����
#include <conio.h>       //��� cout
#include <string>        //��� ������ �� ��������
#include <SDKDDKVer.h>   //��� ������ �����
#include <stdio.h>       //��� ������ �����
#include <tchar.h>       //��� ������ �����
#include <Windows.h>     //��� �������� �����
#include "Header.h"	     //��� ���������
#include <ctime>		 //��� ������ �������
using namespace std;
const int nMax = 100; //������������ ���-�� ����� (i - ���������� �����)
const int m = 30; //���-�� �������� (j - ���������� �����)
const int monthSize[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; //��� � �������

int winGadget(gadget* A, int* x, int n);

string dateToSixNumbers(int day, int month, int year);

int findDialog(gadget*& A, int& n, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& lastChosenGadget, int& findMode);

int main()
{
	//����� �������(����� � int):
	SYSTEMTIME t;	  //��� �������
	GetLocalTime(&t); //��� �������
	setlocale(LC_ALL, "Russian"); //��������� �������� �����
	SetConsoleCP(1251);           //..
	SetConsoleOutputCP(1251);     //..
	int i, j; //���������� ������
	int n; //����������� ���-�� ����� (i - ���������� �����)

	//������ �������:
	ifstream fRead("Test.csv"); //�������� ����� ��� �������� �����
	string gadgetString[nMax];
	i = 0;
	while (!fRead.eof()) getline(fRead, gadgetString[i++]); //������ ��� ������				
	n = i - 2; //��������� ���-�� ���������
	fRead.close(); //�������� �����

	//���������� ���������:
	gadget* A = new gadget[n];
	for (i = 0; i < n; i++) //������� ������ ��� ���������
	{
		j = 0;
		while (gadgetString[i][j] != ';')  A[i].location	 += gadgetString[i][j++]; j++; //01
		while (gadgetString[i][j] != ';')  A[i].number		 += gadgetString[i][j++]; j++; //02
		while (gadgetString[i][j] != ';')  A[i].type		 += gadgetString[i][j++]; j++; //03
		while (gadgetString[i][j] != ';')  A[i].model		 += gadgetString[i][j++]; j++; //04
		while (gadgetString[i][j] != ';')  A[i].place		 += gadgetString[i][j++]; j++; //05
		while (gadgetString[i][j] != ';')  A[i].oil			 += gadgetString[i][j++]; j++; //06
		while (gadgetString[i][j] != ';')  A[i].tools		 += gadgetString[i][j++]; j++; //07
		while (gadgetString[i][j] != ';')  A[i].password	 += gadgetString[i][j++]; j++; //08
		while (gadgetString[i][j] != ';')  A[i].qtAF		 += gadgetString[i][j++]; j++; //09
		while (gadgetString[i][j] != ';')  A[i].qtOF		 += gadgetString[i][j++]; j++; //10
		while (gadgetString[i][j] != ';')  A[i].qtOS		 += gadgetString[i][j++]; j++; //11
		while (gadgetString[i][j] != ';')  A[i].qtBelt		 += gadgetString[i][j++]; j++; //12
		while (gadgetString[i][j] != ';')  A[i].info		 += gadgetString[i][j++]; j++; //13
		while (gadgetString[i][j] != ';')  A[i].lastDateTO	 += gadgetString[i][j++]; j++; //14
		while (gadgetString[i][j] != ';')  A[i].lastHoursTO	 += gadgetString[i][j++]; j++; //15
		while (gadgetString[i][j] != ';')  A[i].owner		 += gadgetString[i][j++]; j++; //16
		while (gadgetString[i][j] != ';')  A[i].serialNumber += gadgetString[i][j++]; j++; //17
		while (gadgetString[i][j] != ';')  A[i].AF1			 += gadgetString[i][j++]; j++; //18
		while (gadgetString[i][j] != ';')  A[i].AF2			 += gadgetString[i][j++]; j++; //19
		while (gadgetString[i][j] != ';')  A[i].AF3			 += gadgetString[i][j++]; j++; //20
		while (gadgetString[i][j] != ';')  A[i].OF1			 += gadgetString[i][j++]; j++; //21
		while (gadgetString[i][j] != ';')  A[i].OF2			 += gadgetString[i][j++]; j++; //22
		while (gadgetString[i][j] != ';')  A[i].OF3			 += gadgetString[i][j++]; j++; //23
		while (gadgetString[i][j] != ';')  A[i].OS1			 += gadgetString[i][j++]; j++; //24
		while (gadgetString[i][j] != ';')  A[i].OS2			 += gadgetString[i][j++]; j++; //25
		while (gadgetString[i][j] != ';')  A[i].OS3			 += gadgetString[i][j++]; j++; //26
		while (gadgetString[i][j] != ';')  A[i].Belt1		 += gadgetString[i][j++]; j++; //27
		while (gadgetString[i][j] != ';')  A[i].Belt2		 += gadgetString[i][j++]; j++; //28
		while (gadgetString[i][j] != ';')  A[i].Belt3		 += gadgetString[i][j++]; j++; //29
										   A[i].SHD		     += gadgetString[i][j++]; j++; //30 
	}
	//**************************************************************************************** 1 ����
	
	//����� ��� � ���: 
	int qWhere = 0;       //������: ���?
	int qWhereFirst = 0;  //������ ���������: ���?
	string aWhere;        //�����:  ���?
	int qWhat = 0;        //������: ���?
	string aWhat;         //�����:  ���?
	int lastChosenGadget; //������������� ����� ���������� ����������
	int findMode = 1;	  //������� ������ ������� findDialog
	cout << "������� ������: " << findDialog(A, n, qWhere, qWhereFirst, aWhere, qWhat, aWhat, lastChosenGadget, findMode) << endl;

	//��������:
	//cout << lastChosenGadget;

	/*
	//����� ����:
	int qWhen = 0; //������: �����?
	string aWhen;  //�����: �����?
	int tempDay;   //��������� ���������� ���
	if ((qWhere >= 1) && (qWhere <= 9)) //���������� � ������� �� ��������� ����
	{
		qWhen = 17;
		system("cls");
	}
	while (qWhen == 17)
	{
		system("cls");
		cout << "�������:'" << aWhat << "' �� '" << aWhere << "'" << endl;
		cout << "����� ������� ��?" << endl;
		//cout << "0 - �����" << endl;
		cout << "1 - �������" << endl;
		cout << "2 - �����" << endl;
		cout << "3 - ������ ����" << endl;
		//cout << "4 - ���������" << endl; //����� �������� ���� ������ ������
		cin >> qWhen;
		switch (qWhen)
		{
		case 0:
			qWhen = 17; //���������
			break;
		case 1:
			//���������� ���� � ������� ������:
			aWhen = dateToSixNumbers(t.wDay, t.wMonth, t.wYear);
			cout << aWhen << endl;
			break;
		case 2:
			if (t.wDay == 1)
			{
				if (t.wMonth == 1) aWhen = to_string(31) + to_string(12) + to_string(t.wYear - 2001);
				else
				{
					if ((monthSize[t.wMonth - 1] == 1) && ((t.wYear - 2000) % 4 == 0)) tempDay = 29; //���� ����������
					else tempDay = monthSize[t.wMonth - 1];
					aWhen = dateToSixNumbers(tempDay, t.wMonth - 1, t.wYear);
				}
			}
			else aWhen = dateToSixNumbers(t.wDay - 1, t.wMonth, t.wYear);
			break;
		case 3:
			i = 1;
			system("cls");
			while (i == 1)
			{
				cout << "���� ���. ������������(������):" << endl;
				cin >> aWhen;
				if (aWhen.length() != 6)
				{
					system("cls");
					cout << "������� ���� � ������ ������, ����������! \n��������, ���: 010700" << endl; //������
				}
				else i = 0;
			}
			break;
		default:
			qWhen = 17; //���������
			break;
		}
	}
	*/

	/*
	//���� ��:
	unsigned long int aHowMuch;	//�����: ����� ���������?
	cout << "����� ��������� ����� ��?" << endl;
	cin >> aHowMuch;

	//������ ���������� ������ ��������� � �������:
	system("cls");
	cout << "��������� ������:'" << A[lastChosenGadget].type
		 << "' �� '" << A[lastChosenGadget].place
		 << "' ������ '" << A[lastChosenGadget].model
		 << "'" << endl;
	//if (qWhen == 1) cout << "����������� ����: " << aWhen;
	//if (qWhen == 2) cout << "������� ���� ��:" << aWhen;
	cout << endl << "������� ���������: " << aHowMuch;

	cout << endl << "�� ������� ��� ������ ������ ���������? (1-��, 0-���)\n";
	int ready;
	cin >> ready;
	cout << endl;
	switch (ready)
	{
	case 0:
		exit(0); //��������
		break;
	case 1:
		//A[lastChosenGadget].lastDateTO = aWhen;
		A[lastChosenGadget].lastHoursTO = to_string(aHowMuch);
		cout << "������ ������� �������!" << endl;
		break;
	default:
		exit(0); //��������
		break;
	}

	//����� � ����:
	ofstream fWrite("TestOut.csv"); //������� ����� � ���� csv
	for (i = 0; i < n; i++)
	{
		fWrite << A[i].location	    << ";";  //01
		fWrite << A[i].number		<< ";";  //02
		fWrite << A[i].type			<< ";";  //03
		fWrite << A[i].model		<< ";";  //04
		fWrite << A[i].place		<< ";";  //05
		fWrite << A[i].oil			<< ";";  //06
		fWrite << A[i].tools		<< ";";  //07
		fWrite << A[i].password		<< ";";  //08
		fWrite << A[i].qtAF			<< ";";  //09
		fWrite << A[i].qtOF			<< ";";  //10
		fWrite << A[i].qtOS			<< ";";  //11
		fWrite << A[i].qtBelt		<< ";";  //12
		fWrite << A[i].info			<< ";";  //13
		fWrite << A[i].lastDateTO	<< ";";  //14
		fWrite << A[i].lastHoursTO	<< ";";  //15
		fWrite << A[i].owner		<< ";";  //16
		fWrite << A[i].serialNumber << ";";  //17
		fWrite << A[i].AF1			<< ";";  //18
		fWrite << A[i].AF2			<< ";";  //19
		fWrite << A[i].AF3			<< ";";  //20
		fWrite << A[i].OF1			<< ";";  //21
		fWrite << A[i].OF2			<< ";";  //22
		fWrite << A[i].OF3			<< ";";  //23
		fWrite << A[i].OS1			<< ";";  //24
		fWrite << A[i].OS2			<< ";";  //25
		fWrite << A[i].OS3			<< ";";  //26
		fWrite << A[i].Belt1		<< ";";  //27
		fWrite << A[i].Belt2		<< ";";  //28
		fWrite << A[i].Belt3		<< ";";  //29
		fWrite << A[i].SHD			<< endl; //30
	}
	fWrite.close(); //�������� �����
	*/

	delete[] A; //��������� ������
	return 0;
}

//������� ���������� �������� �������� ����������.
int findDialog(gadget*& A, int& n, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& lastChosenGadget, int& findMode)
{
	//��� 1 - ������ ������ � ������������ �������� � ����������
	//��� 2 - ������ ��� �������� 4
	//��� 3 - ����� �� ��������� ������
	//������� ����������:
	//0 - ���� ����� �� ������� (������ ���� ������ ������������ ������ ���-������)
	//1 - ���� ������� ������� ���� ������
	qWhere = 17; //���������� �� ��������� ������
	while (qWhere == 17)
	{
		cout << "��� ���������? (����� �����������)" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "1 - 1-�, 2-� ��� 3-� �������" << endl; //��� �����
		cout << "2 - ���" << endl;
		cout << "3 - �����" << endl;
		cout << "4 - ������� ���������" << endl; //��� �����
		cout << "5 - ����������" << endl;
		cout << "6 - ��������������" << endl;
		cout << "7 - ��������" << endl; //��� �����
		cout << "8 - ������� ������������" << endl;
		cin >> qWhere;
		switch (qWhere)
		{
		case 0:
			exit(0); //����� �� ���������
			break;
		case 1:
			qWhereFirst = 17;
			while (qWhereFirst == 17)
			{
				system("cls");
				cout << "����� ������������? ���������� :)" << endl;
				cout << "0 - �����" << endl;
				cout << "1 - �����" << endl;
				cout << "2 - ������" << endl;
				cout << "3 - ������" << endl;
				cout << "4 - ����� 3" << endl;
				cin >> qWhereFirst;
				switch (qWhereFirst)
				{
				case 0:
					qWhereFirst = 0;
					qWhere = 17;
					system("cls");
					break;
				case 1:
					aWhere = "�����";
					break;
				case 2:
					aWhere = "2 ����.";
					break;
				case 3:
					aWhere = "3 ����.";
					break;
				case 4:
					aWhere = "-3 �";
					break;
				default:
					qWhereFirst = 17;
					system("cls");
					break;
				}
				if ((qWhereFirst >= 1) && (qWhereFirst <= 4)) //�������� ��� ����� ������ � ���������� ������
				{
					qWhereFirst = 0;
					qWhere = 1; //��� ������ ����� �����
				}
			}
			break;
		case 2:
			aWhere = "���";
			break;
		case 3:
			aWhere = "�����";
			break;
		case 4:
			qWhereFirst = 17;
			while (qWhereFirst == 17)
			{
				system("cls");
				cout << "����� ������ �� ����?" << endl;
				cout << "0 - �����" << endl;
				cout << "1 - ������ (�����)" << endl;
				cout << "2 - ������ (������)" << endl;
				cin >> qWhereFirst;
				switch (qWhereFirst)
				{
				case 0:
					qWhere = 17;
					qWhereFirst = 0;
					system("cls");
					break;
				case 1:
					aWhere = "�� 1";
					break;
				case 2:
					aWhere = "�� 2";
					break;
				default:
					qWhereFirst = 17;
					system("cls");
					break;
				}
				if ((qWhereFirst >= 1) && (qWhereFirst <= 2)) //�������� ��� ����� ������ � ���������� ������
				{
					qWhereFirst = 0;
					qWhere = 4; //��� ������ ����� �����
				}
			}
			break;
		case 5:
			aWhere = "������.";
			break;
		case 6:
			aWhere = "�����.";
			break;
		case 7:
			qWhereFirst = 17;
			while (qWhereFirst == 17)
			{
				system("cls");
				cout << "����� ��������-��?" << endl;
				cout << "0 - �����" << endl;
				cout << "1 - �� ��, ��� ����� � �����" << endl;
				cout << "2 - �����" << endl;
				cin >> qWhereFirst;
				switch (qWhereFirst)
				{
				case 0:
					qWhereFirst = 0;
					qWhere = 17;
					system("cls");
					break;
				case 1:
					aWhere = "����.";
					break;
				case 2:
					aWhere = "���.����.";
					break;
				default:
					qWhereFirst = 17;
					system("cls");
					break;
				}
				if ((qWhereFirst >= 1) && (qWhereFirst <= 2)) //�������� ��� ����� ������ � ���������� ������
				{
					qWhereFirst = 0;
					qWhere = 7; //��� ������ ����� �����
				}
			}
			break;
		case 8:
			aWhere = "����-��";
			break;
		default:
			system("cls");
			qWhere = 17;
			cout << "������� ����� �� 0 �� 8!" << endl;
			break;
		}
		if ((qWhere >= 1) && (qWhere <= 8)) //������� �� ��������� ������ � ��������� ������� ���������� ����-�
		{
			qWhat = 17;
			int* ArrWhere = new int[n] {0}; //������ ����-� � ���������� ���������������
			int ArrWhereN = 0; //�� ���-��
			for (int i = 0; i < n; i++)
				if (A[i].place == aWhere)
				{
					ArrWhere[ArrWhereN] = stoi(A[i].number);
					//cout << ArrWhere[ArrWhereN] << endl; //�� ������� ��������
					ArrWhereN++;
				}
			if (ArrWhereN == 1) //���� ������ ����, ��
			{
				aWhat = A[ArrWhere[0]].type; //������ ����� �� ������ "���?"
				qWhat = 0; //���������� ����� �� ���������
				lastChosenGadget = ArrWhere[0]; //����� ����-��
				return 1;
			}
			while (qWhat == 17)
			{
				string What[3]{ "��","��","��" }; //������ �� ����� ������
				system("cls");
				cout << "�������:'" << aWhere << "' " << endl;
				cout << "��� ���� �������?" << endl;
				cout << "0 - �����" << endl;
				int flagKP = 0;
				int flagVD = 0;
				int flagOS = 0;
				for (int i = 0; i < ArrWhereN; i++) if (A[ArrWhere[i]].type == What[0])	flagKP = 1;
				if (flagKP == 1) cout << "1 - ����������"   << endl;
				for (int i = 0; i < ArrWhereN; i++) if (A[ArrWhere[i]].type == What[1])	flagVD = 1;
				if (flagVD == 1) cout << "2 - ������������" << endl;
				for (int i = 0; i < ArrWhereN; i++) if (A[ArrWhere[i]].type == What[2])	flagOS = 1;
				if (flagOS == 1) cout << "3 - ���������"    << endl;
				if ((flagKP + flagVD + flagOS) == 1)
				{

				}
				else
				{
					cin >> qWhat;

					/* ��� ��� �� �������� (����� ������� ����� if):
					switch (qWhat)
					{
					case 0:
						qWhere = 17;
						qWhat = 0;
						system("cls");
						break;
					case 1:
						aWhat = "��";
						break;
					case 2:
						aWhat = "��";
						break;
					case 3:
						aWhat = "��";
						break;
					default:
						qWhat = 17;
						system("cls");
						cout << "������� ����� �� 0 �� 3!" << endl;
						break;
					}
					*/
				}				
			}
		}		
	}
	return 1;
}