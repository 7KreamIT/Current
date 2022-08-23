#include "Header.h"	//����������� ���������

const string fileNameXlsx = "Test.xlsx"; //��� ����� Xlsx ��� �����
const string fileNameCsv = "�������.csv"; //��� ����� Csv ��� �����
const string fileNameOutCsv = "�������-Out.csv"; //��� ����� Csv ��� ������

int main()
{
	setlocale(LC_ALL, "Russian");		  //��������� �������
	SetConsoleCP(1251);					  //..
	SetConsoleOutputCP(1251);			  //..
	system("mode con cols=100 lines=20"); //..

	int aN = 0;//���-�� �����
	gadget* A; //�������� ������ ���������

	A = getByXlsx(aN, fileNameXlsx); //���� ���������� ������������
	//A = getByCsv(aN, fileNameCsv); //���� ���������� �� ������������
	
	//����� ���? ���? �����?: 
	string aWhere;        //�����:  ���?
	string aWhat;         //�����:  ���?
	string aWhen;		  //�����: �����?
	int lastChosenGadget; //������������� ����� ���������� ����������
	int findMode = 1;	  //������� ������ ������� findDialog
	findDialog(A, aN, aWhere, aWhat, aWhen, lastChosenGadget, findMode);

	setToCsv(A, aN, fileNameOutCsv); //����� � ���� csv

	delete[] A; //��������� ������
	exitProgram();
	return 1;
}

//������� ����� ������� ��:
int dateDialog(string& aWhere, string& aWhat, string& aWhen, string lastChosenGadgetModel)
{
	int tempDay; //��������� ���������� ���
	int qWhen; //�������� ��� ������ ������� 
	SYSTEMTIME t;	  //��� ������ �������(����� � int):
	GetLocalTime(&t); //..
	qWhen = 17; //���������� ����� ������������� ��� ������ �������
	while (qWhen == 17)
	{
		system("cls");
		int i;
		cout << "�������:'" << aWhat 
			 << "' �� '" << aWhere
			 << "' ������ '" << lastChosenGadgetModel
			 << "'" << endl;
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
					else tempDay = 28;
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
					cout << "������� ���� � ������ ������, ����������! \n��������, ���: 010407" << endl; //������
				}
				else
				{
					int aWhenInt = stoi(aWhen);
					if (aWhenInt < 9999) //������ � ����� (���� �� ����� ���� = 00)
					{
						cout << "���� = 00!" << endl;
						i = 1;
					}
					else
					{
						if ((aWhenInt % 10000) < 99) //������ � ����� (����� �� ����� ���� = 00)
						{
							cout << "����� = 00!" << endl;
							i = 1;
						}
						else
						{
							if ((aWhenInt % 10000 / 100) == 2) //���� ����� ����� - �������, ��..
							{
								int dayInFeb; //���-�� ���� � �������
								if ((aWhenInt % 100) % 4 == 0) dayInFeb = 29; //���� ��� ����������, ��..
								else dayInFeb = 28;
								if ((aWhenInt / 10000) > dayInFeb) i = 1;
								else i = 0; //������ ������� ���������
							}
							else
							{
								int currentMonth; //����� �����? (��� ������� ����)
								currentMonth = (aWhenInt % 10000 / 100) - 1;
								if (currentMonth > 11) i = 1; //������ ���� ����� �������� ������ 12-��
								else
								{
									if ((aWhenInt / 10000) > monthSize[currentMonth]) i = 1;
									else i = 0; //������ ������� ���������
								}
							}
							//aWhenInt = aWhenInt % 100; //������� ���
							//aWhenInt = aWhenInt % 10000 /100; //������� �����
							//aWhenInt = aWhenInt / 10000; //������� ����
						}
					}
				}
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
	cout << "�������:'" << A[lastChosenGadget].type
		 << "' �� '" << A[lastChosenGadget].place
		 << "' ������ '" << A[lastChosenGadget].model
		 << "'" << endl
		 << "������� ���������: " << aHowMuch << endl
		 << "������� ����: " << aWhen << endl
		 << "�� ������� ��� ������ ������ ���������? (1-��, 0-���)" << endl;
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
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode)
{
	//��� 1 - ������ ������ � ������������ �������� � ����������
	//��� 2 - ??
	//������� ����������:
	//0 - ���� ??
	//1 - ���� ??
	int qWhere = 17; //���������� �������� ������� "���?" � ���������� �� ��������� ������
	int qWhereFirst = 0; //���������� �������� ��� ������������ ������� "���?"
	int qWhat = 0; //���������� �������� ������� "���?"
	while (qWhere == 17)
	{
		cout << "��� ���������? (����� �����������)" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "1 - �������: 1-��(�����), 2-�� ��� 3-�" << endl; //��� �����
		cout << "2 - ���" << endl;
		cout << "3 - �����" << endl;
		cout << "4 - ������� ���������" << endl; //��� �����
		cout << "5 - ����������" << endl;
		cout << "6 - ��������������" << endl;
		cout << "7 - ��������" << endl; //��� �����
		cout << "8 - ����" << endl;
		cout << "9 - ������� ������������" << endl; //� ������� ����� "�������" � ��� ������
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
					aWhere = "2 �������";
					break;
				case 3:
					aWhere = "3 �������";
					break;
				default:
					qWhereFirst = 17;
					system("cls");
					break;
				}
				if ((qWhereFirst >= 1) && (qWhereFirst <= 3)) //�������� ��� ����� ������ � ���������� ������
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
			aWhere = "����������";
			break;
		case 6:
			aWhere = "������-���";
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
					aWhere = "��������";
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
			aWhere = "����";
			break;
		case 9:
			aWhere = "������-�";
			break;
		default:
			system("cls");
			qWhere = 17;
			cout << "������� ����� �� 0 �� 9!" << endl;
			break;
		}
		if ((qWhere >= 1) && (qWhere <= 9)) //������� �� ��������� ������ � ��������� ������� ���������� ����-�
		{
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
			}
			else
			{
				system("cls");
				qWhat = 17; //���������� �� �����
				while (qWhat == 17)
				{
					string what[3]{ "��","��","��" }; //������ �� ����� ������
					cout << "�������:'" << aWhere << "' " << endl;
					cout << "��� ���� �������?" << endl;
					cout << "0 - �����" << endl;

					bool flagKP = 0;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == what[0])	flagKP = 1;
					if (flagKP == 1) cout << "1 - ����������" << endl;

					bool flagVD = 0;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == what[1])	flagVD = 1;
					if (flagVD == 1) cout << "2 - ������������" << endl;

					bool flagOS = 0;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == what[2])	flagOS = 1;
					if (flagOS == 1) cout << "3 - ���������" << endl;

					if ((flagKP + flagVD + flagOS) == 1) //���� � ������ ������ ���� �� �����
					{
						if ((flagKP == 1) && (flagVD == 0) && (flagOS == 0))
						{
							aWhat = "��";
							qWhat = 0; //����� ������
						}
						if ((flagKP == 0) && (flagVD == 1) && (flagOS == 0))
						{
							aWhat = "��";
							qWhat = 0; //����� ������
						}
							
						if ((flagKP == 0) && (flagVD == 0) && (flagOS == 1))
						{
							aWhat = "��";
							qWhat = 0; //����� ������
						}
						int* arrWhat = new int[arrWhereN] {0}; //������ ����-� � ���������� ���������������
						int arrWhatN = 0; //�� ���-��
						for (int i = 0; i < arrWhereN; i++)
							if (A[arrWhere[i]].type == aWhat)
								arrWhat[arrWhatN++] = stoi(A[arrWhere[i]].number);
						system("cls");
						cout << "�������:'" << aWhat
							 << "' �� '" << aWhere
							 << "'" << endl;
						lastChosenGadget = winGadget(A, arrWhat, arrWhatN);
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
						if (qWhat == 1)
						{
							aWhat = "��";
						}
						if (qWhat == 2)
						{
							aWhat = "��";
						}
						if (qWhat == 3)
						{
							aWhat = "��";							
						}
						//��������� ���������� �����:
						if ((qWhat == 1) && (flagKP == 0) ||
							(qWhat == 2) && (flagVD == 0) ||
							(qWhat == 3) && (flagOS == 0) || 
							(qWhat < 0 ) || (qWhat > 3))
						{
							system("cls");
							cout << "�� ������� �����, �������� ��� � ������!" << endl;
							qWhat = 17; //����� ������
						}
						if ((qWhat == 1) && (flagKP == 1) ||
							(qWhat == 2) && (flagVD == 1) ||
							(qWhat == 3) && (flagOS == 1))
						{
							int* arrWhat = new int[arrWhereN] {0}; //������ ����-� � ���������� ���������������
							int arrWhatN = 0; //�� ���-��
							for (int i = 0; i < arrWhereN; i++)
								if (A[arrWhere[i]].type == aWhat)
									arrWhat[arrWhatN++] = stoi(A[arrWhere[i]].number);
							system("cls");
							cout << "�������:'" << aWhat
								 << "' �� '" << aWhere
								 << "'" << endl;
							lastChosenGadget = winGadget(A, arrWhat, arrWhatN);
						}
					}
				}
			}
			if (qWhere != 17)
			{
				dateDialog(aWhere, aWhat, aWhen, A[lastChosenGadget].model);
				hoursDialog(A, lastChosenGadget, aWhen);
				return 1;
			}
		}
	}
}