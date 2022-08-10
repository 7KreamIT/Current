#include "Header.h"	//����������� ���������

#include "ExcelFormat.h"	 //��� ������ ������
#ifdef _WIN32				 //..
#define WIN32_LEAN_AND_MEAN	 //
#include <windows.h>		 //
#include <shellapi.h> 		 //
#include <crtdbg.h>			 //
#else // _WIN32				 //
#define	FW_NORMAL	400		 //
#define	FW_BOLD		700		 //
#endif // _WIN32			 //
using namespace ExcelFormat; // 

const int m = 30; //���-�� �������� (j - ���������� �����)
const string fileName = "Test.csv"; //��� ����� ��� �����
const string fileNameOut = "TestOut.csv"; //��� ����� ��� �����

int main()
{
	#ifdef _MSC_VER												 //��� ������ ������
	// detect memory leaks										 //..
	//	_CrtSetDbgFlag(_CrtSetDbgFlag(0)|_CRTDBG_LEAK_CHECK_DF); //
	#endif														 //

	setlocale(LC_ALL, "Russian"); //��������� �������� �����
	SetConsoleCP(1251);           //..
	SetConsoleOutputCP(1251);     //..
	system("mode con cols=60 lines=20"); //������ �������
	int i, j; //���������� ������	
	int aN = numberOfLines(fileName) - 1; //����������� ���-�� ����� (i - ���������� �����)

	//������ �������:
	ifstream fRead(fileName); //�������� ����� ��� �������� �����
	string* gadgetString = new string[aN];
	for (i = 0; i < aN; i++) getline(fRead, gadgetString[i]); //������ ��� ������
	fRead.close(); //�������� �����

	//���������� ���������:
	gadget* A = new gadget[aN];
	for (i = 0; i < aN; i++) //������� ������ ��� ���������
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
										   A[i].SHD		     += gadgetString[i][j++];	   //30 
	}
	delete[] gadgetString;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 1 ����
	
	//����� ���? ���? �����?: 
	int qWhere = 0;       //������: ���?
	int qWhereFirst = 0;  //������ ���������: ���?
	string aWhere;        //�����:  ���?
	int qWhat = 0;        //������: ���?
	string aWhat;         //�����:  ���?
	int qWhen = 0;		  //������: �����?
	string aWhen;		  //�����: �����?
	int lastChosenGadget; //������������� ����� ���������� ����������
	int findMode = 1;	  //������� ������ ������� findDialog
	findDialog(A, aN, qWhere, qWhereFirst, aWhere, qWhat, aWhat, qWhen, aWhen, lastChosenGadget, findMode);

	//��������:
	cout << lastChosenGadget << " " << aWhat << " " << aWhere << endl;

	//����� � ����:
	ofstream fWrite(fileNameOut); //������� ����� � ���� csv
	for (i = 0; i < aN; i++)
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

	delete[] A; //��������� ������
	exitProgram();
	return 1;
}

//������� ����� ������� ��:
int dateDialog(int& qWhere, string& aWhere, int& qWhat, string& aWhat, int& qWhen, string& aWhen)
{
	int tempDay; //��������� ���������� ���
	SYSTEMTIME t;	  //��� ������ �������(����� � int):
	GetLocalTime(&t); //..
	if ((qWhere >= 1) && (qWhere <= 9)) //���������� � ������� �� ��������� ����
	{
		qWhen = 17;
		system("cls");
	}
	while (qWhen == 17)
	{
		system("cls");
		int i;
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
			break;
		case 2:
			if (t.wDay == 1)
			{
				if (t.wMonth == 1) 
					aWhen = to_string(31) + to_string(12) + to_string(t.wYear - 2001);
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
	return 1;
}

//������� ����� ��:
int hoursDialog(gadget*& A, int& lastChosenGadget, string& aWhen)
{
	unsigned long int aHowMuch;	//�����: ����� ���������?
	cout << "����� ��������� ����� ��?" << endl;
	cin >> aHowMuch;

	//������ ���������� ������ ��������� � �������:
	system("cls");
	cout << "��������� ������:'" << A[lastChosenGadget].type
		<< "' �� '" << A[lastChosenGadget].place
		<< "' ������ '" << A[lastChosenGadget].model
		<< "'" << endl;
	cout << "������� ���������: " << aHowMuch << endl;
	cout << "������� ����: " << aWhen << endl;
	cout << "�� ������� ��� ������ ������ ���������? (1-��, 0-���)" << endl;
	int ready;
	cin >> ready;
	switch (ready)
	{
	case 0:
		exit(0); //��������
		break;
	case 1:
		A[lastChosenGadget].lastDateTO = aWhen;
		A[lastChosenGadget].lastHoursTO = to_string(aHowMuch);
		cout << "������ ������� �������!" << endl;
		break;
	default:
		exit(0); //��������
		break;
	}
	return 1;
}

//������� ��������� �������, ������� �������� ��� ����������:
int findDialog(gadget*& A, int& aN, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& qWhen, string& aWhen, int& lastChosenGadget, int& findMode)
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
			exitProgram(); //������� ����� �� ���������
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
			int* arrWhere = new int[aN] {0}; //������ ����-� � ���������� ���������������
			int arrWhereN = 0; //�� ���-��
			for (int i = 0; i < aN; i++)
				if (A[i].place == aWhere)
				{
					arrWhere[arrWhereN] = stoi(A[i].number);
					//cout << ArrWhere[ArrWhereN] << endl; //�� ������� ��������
					arrWhereN++;
				}
			if (arrWhereN == 1) //���� ������ ����, ��
			{
				aWhat = A[arrWhere[0]].type; //������ ����� �� ������ "���?"
				qWhat = 0; //���������� ����� �� ���������
				lastChosenGadget = arrWhere[0]; //����� ����-��
				dateDialog(qWhere, aWhere, qWhat, aWhat, qWhen, aWhen);
				hoursDialog(A, lastChosenGadget, aWhen);
				return 1;
			}
			else
			{
				while (qWhat == 17)
				{
					string What[3]{ "��","��","��" }; //������ �� ����� ������
					system("cls");
					cout << "�������:'" << aWhere << "' " << endl;
					cout << "��� ���� �������?" << endl;
					cout << "0 - �����" << endl;
					bool flagKP = 0;
					bool flagVD = 0;
					bool flagOS = 0;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == What[0])	flagKP = 1;
					if (flagKP == 1) cout << "1 - ����������" << endl;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == What[1])	flagVD = 1;
					if (flagVD == 1) cout << "2 - ������������" << endl;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == What[2])	flagOS = 1;
					if (flagOS == 1) cout << "3 - ���������" << endl;
					if ((flagKP + flagVD + flagOS) == 1) //���� � ������ ������ ���� �� �����
					{
						if ((flagKP == 1) && (flagVD == 0) && (flagOS == 0)) aWhat = "��";
						if ((flagKP == 0) && (flagVD == 1) && (flagOS == 0)) aWhat = "��";
						if ((flagKP == 0) && (flagVD == 0) && (flagOS == 1)) aWhat = "��";
					}
					else
					{
						cin >> qWhat;
						if (qWhat == 0) //�����
						{
							qWhat = 0;
							qWhere = 17;
							system("cls");
						}
						if (qWhat == 1) aWhat = "��";
						if (qWhat == 2) aWhat = "��";
						if (qWhat == 3) aWhat = "��";
					}
					int* arrWhat = new int[arrWhereN] {0}; //������ ����-� � ���������� ���������������
					int arrWhatN = 0; //�� ���-��
					for (int i = 0; i < arrWhereN; i++)
						if (A[arrWhere[i]].type == aWhat)
						{
							arrWhat[arrWhatN] = stoi(A[arrWhere[i]].number);
							//cout << ArrWhat[ArrWhatN] << endl; //�� ������� ��������
							arrWhatN++;
						}
					lastChosenGadget = winGadget(A, arrWhat, arrWhatN);
					dateDialog(qWhere, aWhere, qWhat, aWhat, qWhen, aWhen);
					hoursDialog(A, lastChosenGadget, aWhen);
					return 1;
				}
			}
		}
	}
	return 1;
}
