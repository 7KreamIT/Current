/*
//������������ ������������� ������� � �������� ��������, ���������� ��������:
int* chosenGadget = new int[n] {0}; //������ ��������� ���������
int chosenGadgetN = 0; //���������� ��������
for (int i = 0; i < n; i++)
	if ((A[i].type == aWhat) && (A[i].place == aWhere))
	{
		chosenGadget[chosenGadgetN] = stoi(A[i].number);
		chosenGadgetN++;
	}
//������������� ����� �������������� �������:
//lastChosenGadget = winGadget(A, chosenGadget, chosenGadgetN);
//if (lastChosenGadget == 0) return 0;
delete[] chosenGadget;
*/

/*
//������� ���������� �������� �������� ����������.
int findDialog(gadget*& A, int& n, int& qWhat, int& qWhere, int& qWhereFirst, string& aWhat, string& aWhere, int& lastChosenGadget, int& findMode)
{
	//��� 1 - ������ ������ � ������������ ������� 4
	//��� 2 - ������ ��� �������� 4
	//��� 3 - ����� �� ��������� ������
	//������� ����������:
	//0 - ���� ����� �� �������
	//1 - ���� ������� ������� ���� ������
	qWhat = 17; //���������� �� �����
	while (qWhat == 17)
	{
		cout << "��� ���� �������?" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "1 - ����������" << endl;
		cout << "2 - ������������" << endl;
		cout << "3 - ���������" << endl;
		if (findMode == 1) cout << "4 - ������, � ��� �� ������� �������." << endl;
		cin >> qWhat;
		switch (qWhat)
		{
		case 0:
			exit(0); //����� �� ���������
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
		case 4:
			if (findMode == 1) return 4;
			else cout << "������� ����� �� 0 �� 3!" << endl;
			break;
		default:
			qWhat = 17;
			system("cls");
			cout << "������� ����� �� 0 �� 3!" << endl;
			break;
		}
		if ((qWhat > 0) && (qWhat <= 3)) //���������� � ������� �� ��������� ����
		{
			qWhere = 17;
			system("cls");
		}
		while (qWhere == 17)
		{
			cout << "�������:'" << aWhat << "' " << endl;
			cout << "��� ���������? (����� �����������)" << endl;
			cout << "0 - �����" << endl;
			cout << "1 - 1-�, 2-� ��� 3-� �������" << endl; //��� �����
			cout << "2 - ���" << endl;
			cout << "3 - �����" << endl;
			cout << "4 - ������� ���������" << endl; //��� �����
			cout << "5 - ����������" << endl;
			cout << "6 - ��������������" << endl;
			cout << "7 - ��������" << endl; //��� �����
			cout << "8 - ������� ������������" << endl;
			cout << "9 - ������" << endl;
			cin >> qWhere;
			switch (qWhere)
			{
			case 0:
				qWhat = 17;
				qWhere = 0;
				system("cls");
				break;
			case 1:
				qWhereFirst = 17;
				while (qWhereFirst == 17)
				{
					system("cls");
					cout << "�������:'" << aWhat << "' " << endl;
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
						qWhere = 0;
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
					cout << "�������:'" << aWhat << "' " << endl;
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
						qWhere = 0;
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
					cout << "�������:'" << aWhat << "' " << endl;
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
						qWhere = 0;
					}
				}
				break;
			case 8:
				aWhere = "����-��";
				break;
			case 9:
				aWhere = "��� �� ������ :�";
				break;
			default:
				system("cls");
				qWhere = 17;
				cout << "������� ����� �� 0 �� 9!" << endl;
				break;
			}
		}
	}
	//������������ ������������� ������� � �������� ��������, ���������� ��������:
	int* chosenGadget = new int[n] {0}; //������ ��������� ���������
	int chosenGadgetN = 0; //���������� ��������
	int i, j; //��������
	j = 0;
	for (i = 0; i < n; i++)
		if ((A[i].type == aWhat) && (A[i].place == aWhere))
		{
			chosenGadget[j] = stoi(A[i].number);
			j++;
			chosenGadgetN++;
		}
	//������������� ����� �������������� �������:
	lastChosenGadget = winGadget(A, chosenGadget, chosenGadgetN);
	if (lastChosenGadget == 0) return 0;
	delete[] chosenGadget;
	return 1;
}
*/
