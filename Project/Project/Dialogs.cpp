#include "Header.h"	// ����������� ���������

// ������� ��������� �������, ������� �������� ��� ����������:
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode)
{
	// ��� 1 - ������ ������ � ������������ �������� � ����������
	// ��� 2 - ??
	// ������� ����������:
	// 0 - ���� ??
	// 1 - ���� ??
	int qWhere = 17; // ���������� �������� ������� "���?" � ���������� �� ��������� ������
	int qWhereFirst = 0; // ���������� �������� ��� ������������ ������� "���?"
	int qWhat = 0; // ���������� �������� ������� "���?"
	while (qWhere == 17)
	{
		cout << "��� ���������? (����� �����������)" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "1 - �������: 1-��(�����), 2-�� ��� 3-�" << endl; // ��� �����
		cout << "2 - ���" << endl;
		cout << "3 - �����" << endl;
		cout << "4 - ������� ���������" << endl; // ��� �����
		cout << "5 - ����������" << endl;
		cout << "6 - ��������������" << endl;
		cout << "7 - ��������" << endl; // ��� �����
		cout << "8 - ����" << endl;
		cout << "9 - ������� ������������" << endl; // � ������� ����� "�������" � ��� ������
		cin >> qWhere;
		switch (qWhere)
		{
		case 0:
			exitProgram(); // ������� ����� �� ���������
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
				if ((qWhereFirst >= 1) && (qWhereFirst <= 3)) // �������� ��� ����� ������ � ���������� ������
				{
					qWhereFirst = 0;
					qWhere = 1; // ��� ������ ����� �����
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
				if ((qWhereFirst >= 1) && (qWhereFirst <= 2)) // �������� ��� ����� ������ � ���������� ������
				{
					qWhereFirst = 0;
					qWhere = 4; // ��� ������ ����� �����
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
				if ((qWhereFirst >= 1) && (qWhereFirst <= 2)) // �������� ��� ����� ������ � ���������� ������
				{
					qWhereFirst = 0;
					qWhere = 7; // ��� ������ ����� �����
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
		if ((qWhere >= 1) && (qWhere <= 9)) // ������� �� ��������� ������ � ��������� ������� ���������� ����-�
		{
			int* arrWhere = new int[aN] {0}; // ������ ����-� � ���������� ���������������
			int arrWhereN = 0; // �� ���-��
			for (int i = 0; i < aN; i++)
				if (A[i].place == aWhere)
				{
					arrWhere[arrWhereN] = stoi(A[i].number);
					arrWhereN++;
				}
			if (arrWhereN == 1) // ���� ������ ����, ��
			{
				aWhat = A[arrWhere[0]].type; // ������ ����� �� ������ "���?"
				qWhat = 0; // ���������� ����� �� ���������
				lastChosenGadget = arrWhere[0]; // ����� ����-��
			}
			else
			{
				system("cls");
				qWhat = 17; // ���������� �� �����
				while (qWhat == 17)
				{
					string what[3]{ "��","��","��" }; // ������ �� ����� ������
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

					if ((flagKP + flagVD + flagOS) == 1) // ���� � ������ ������ ���� �� �����
					{
						if ((flagKP == 1) && (flagVD == 0) && (flagOS == 0))
						{
							aWhat = "��";
							qWhat = 0; // ����� ������
						}
						if ((flagKP == 0) && (flagVD == 1) && (flagOS == 0))
						{
							aWhat = "��";
							qWhat = 0; // ����� ������
						}

						if ((flagKP == 0) && (flagVD == 0) && (flagOS == 1))
						{
							aWhat = "��";
							qWhat = 0; // ����� ������
						}
						int* arrWhat = new int[arrWhereN] {0}; // ������ ����-� � ���������� ���������������
						int arrWhatN = 0; // �� ���-��
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
						if (qWhat == 0) // �����
						{
							qWhat = 0;
							qWhere = 17;
							system("cls");
						}
						// ��������� ���������� �����:
						if ((qWhat == 1) && (flagKP == 0) ||
							(qWhat == 2) && (flagVD == 0) ||
							(qWhat == 3) && (flagOS == 0) ||
							(qWhat <  0) || (qWhat  >  3))
						{
							system("cls");
							cout << "�� ������� �����, �������� ��� � ������!" << endl;
							qWhat = 17; // ����� ������
						}
						if ((qWhat == 1) && (flagKP == 1) ||
							(qWhat == 2) && (flagVD == 1) ||
							(qWhat == 3) && (flagOS == 1))
						{
							if (qWhat == 1) aWhat = "��";
							if (qWhat == 2) aWhat = "��";
							if (qWhat == 3) aWhat = "��";
							int* arrWhat = new int[arrWhereN]; // ������ ����-� � ���������� ���������������
							int arrWhatN = 0; // �� ���-��
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
				dateDialog(A, lastChosenGadget, aWhere, aWhat, aWhen);
				hoursDialog(A, lastChosenGadget, aWhen);
				return 1;
			}
		}
	}
}

// ������� ������� ���� ���� ����� ����������, ������� ���������� ������:
int winGadget(gadget* A, int* x, int n) // x - ��� ������ � ����������� ��� �������� ������������, n - �� ���-��
{
	bool uncorrectAnswer = 0; // �������� �����
	int chosenGadget = 0; // �������� ����� ����������
	if (n > 1) // ���� ����� ������ ��� 1
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
		chosenGadget = stoi(A[x[chosenGadget - 1]].number); // ������ ��� ���������� �������� ������� ��������� ������
	}
	else chosenGadget = stoi(A[x[0]].number);
	system("cls");
	cout << "�������:'" << A[chosenGadget].type
		<< "' �� '" << A[chosenGadget].place
		<< "' ������ '" << A[chosenGadget].model
		<< "'" << endl;
	return chosenGadget;
}

// ������� ����� ������� ��:
int dateDialog(gadget*& A, int lastChosenGadget, string& aWhere, string& aWhat, string& aWhen)
{
	int tempDay; // ��������� ���������� ���
	int qWhen; // �������� ��� ������ ������� 
	SYSTEMTIME t;	  // ��� ������ �������(����� � int):
	GetLocalTime(&t); // ..
	qWhen = 17; // ���������� ����� ������������� ��� ������ �������
	while (qWhen == 17)
	{
		system("cls");
		bool repeatWhile; // ���������� ��� �����
		cout << "�������:'" << A[lastChosenGadget].type
			<< "' �� '" << A[lastChosenGadget].place
			<< "' ������ '" << A[lastChosenGadget].model
			<< "' � �������� ������� '" << A[lastChosenGadget].serialNumber
			<< "'" << endl;
		cout << "����� ������� ��?" << endl;
		// cout << "0 - �����" << endl;
		cout << "1 - �������" << endl;
		cout << "2 - �����" << endl;
		cout << "3 - ������ ����" << endl;
		// cout << "4 - ���������" << endl; // ����� �������� ���� ������ ������
		cin >> qWhen;
		switch (qWhen)
		{
		case 0:
			qWhen = 17; // ���������
			break;
		case 1:
			// ���������� ���� � ������� ������:
			aWhen = dateToSixNumbers(t.wDay, t.wMonth, t.wYear);
			break;
		case 2:
			if (t.wDay == 1)
			{
				if (t.wMonth == 1)
					aWhen = to_string(31) + to_string(12) + to_string(t.wYear - 2001);
				else
				{
					if ((monthSize[t.wMonth - 1] == 1) && ((t.wYear - 2000) % 4 == 0)) tempDay = 29; // ���� ����������
					else tempDay = 28;
					aWhen = dateToSixNumbers(tempDay, t.wMonth - 1, t.wYear);
				}
			}
			else aWhen = dateToSixNumbers(t.wDay - 1, t.wMonth, t.wYear);
			break;
		case 3:
			system("cls");
			repeatWhile = 1;
			while (repeatWhile == 1)
			{
				cout << "�������:'" << A[lastChosenGadget].type
					 << "' �� '" << A[lastChosenGadget].place
					 << "' ������ '" << A[lastChosenGadget].model
					 << "' � �������� ������� '" << A[lastChosenGadget].serialNumber
					 << "'" << endl;
				cout << "���� ���. ������������(������):" << endl;
				cin >> aWhen;
				if (aWhen.length() != 6)
				{
					system("cls");
					cout << "����������, ������� ���� � ������ ������! (��������, ���: 010407)" << endl; // ������
				}
				else
				{
					int aWhenInt = stoi(aWhen);
					if (aWhenInt < 9999) // ������ � ����� (���� �� ����� ���� = 00)
					{
						system("cls");
						cout << "���� = 00!" << endl;
					}
					else
					{
						if ((aWhenInt % 10000) < 99) // ������ � ����� (����� �� ����� ���� = 00)
						{
							system("cls");
							cout << "����� = 00!" << endl;
						}
						else
						{
							if ((aWhenInt % 10000 / 100) == 2) // ���� ����� ����� - �������, ��..
							{
								int dayInFeb; // ���-�� ���� � �������
								if ((aWhenInt % 100) % 4 == 0) dayInFeb = 29; // ���� ��� ����������, ��..
								else dayInFeb = 28;
								if ((aWhenInt / 10000) > dayInFeb)
								{
									system("cls");
									cout << "� ���� ������� ����� " << dayInFeb << " ����!";
								}
								else repeatWhile = 0; // ������ ������� ���������
							}
							else
							{
								int currentMonth; // ����� �����? (��� ������� ����)
								currentMonth = (aWhenInt % 10000 / 100);
								if (currentMonth > 12)
								{
									system("cls");
									cout << "� ���� ����� 12 �������." << endl;
									repeatWhile = 1; // ������ ���� ����� �������� ������ 12-��
								}
								else
								{
									if ((aWhenInt / 10000) > monthSize[currentMonth - 1])
									{
										system("cls");
										string currentMonthName;
										switch (currentMonth)
										{
										case  1: currentMonthName = "������";   break;
										case  2: currentMonthName = "�������";  break;
										case  3: currentMonthName = "����";     break;
										case  4: currentMonthName = "������";   break;
										case  5: currentMonthName = "���";      break;
										case  6: currentMonthName = "����";     break;
										case  7: currentMonthName = "����";     break;
										case  8: currentMonthName = "������";   break;
										case  9: currentMonthName = "��������"; break;
										case 10: currentMonthName = "�������";  break;
										case 11: currentMonthName = "������";   break;
										case 12: currentMonthName = "�������";  break;
										default:							    break;	
										}
										//��������� �������� ��� ��������� ������ :)
										string niceName = monthSize[currentMonth - 1] == 31 ? " ����" : " ����";
										cout << "� " << currentMonth
											 << "-� ������ (" << currentMonthName
											 << ") ����� " << monthSize[currentMonth - 1]
											 << niceName
											 << endl;
										repeatWhile = 1; // ������ ���� ���� ��������� ������
									}
									else repeatWhile = 0; // ������ ������� ���������
								}
							}
							// aWhenInt = aWhenInt % 100; // ������� ���
							// aWhenInt = aWhenInt % 10000 /100; // ������� �����
							// aWhenInt = aWhenInt / 10000; // ������� ����
						}
					}
				}
			}
			break;
		default:
			qWhen = 17; // ���������
			break;
		}
	}
	return 1;
}

// ������� ����� ��:
int hoursDialog(gadget*& A, int& lastChosenGadget, string& aWhen)
{
	unsigned long int aHowMuch;	// �����: ����� ���������?
	cout << "����� ��������� ����� ��?" << endl;
	cin >> aHowMuch;

	// ������ ���������� ������ ��������� � �������:
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
		exit(0); // ��������
		break;
	case 1:
		A[lastChosenGadget].lastDateTO = aWhen;
		A[lastChosenGadget].lastHoursTO = to_string(aHowMuch);
		cout << "������ ������� �������!" << endl;
		break;
	default:
		exit(0); // ��������
		break;
	}
	return 1;
}
