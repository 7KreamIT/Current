/*
	int i, j; //���������� ������
	int aN = numberOfLines(fileName) - 1; //������� ������������ ���-�� ����� � ����� (i - ���������� �����)

	//������ �������:
	ifstream fileRead(fileName); //�������� �����
	string* gadgetString = new string[aN]; //������ ����� �����
	for (i = 0; i < aN; i++) getline(fileRead, gadgetString[i]); //������ ��� ������
	fileRead.close(); //�������� �����

	//���������� ���������:
	gadget* A = new gadget[aN];
	for (i = 0; i < aN; i++) //������� ������ ��� ���������
	{
		j = 0;
		while (gadgetString[i][j] != ';')  A[i].number		 += gadgetString[i][j++]; j++; //01
		while (gadgetString[i][j] != ';')  A[i].type		 += gadgetString[i][j++]; j++; //02
		while (gadgetString[i][j] != ';')  A[i].model		 += gadgetString[i][j++]; j++; //03
		while (gadgetString[i][j] != ';')  A[i].place		 += gadgetString[i][j++]; j++; //04
		while (gadgetString[i][j] != ';')  A[i].oil			 += gadgetString[i][j++]; j++; //05
		while (gadgetString[i][j] != ';')  A[i].tools		 += gadgetString[i][j++]; j++; //06
		while (gadgetString[i][j] != ';')  A[i].password	 += gadgetString[i][j++]; j++; //07
		while (gadgetString[i][j] != ';')  A[i].qtAF		 += gadgetString[i][j++]; j++; //08
		while (gadgetString[i][j] != ';')  A[i].qtOF		 += gadgetString[i][j++]; j++; //09
		while (gadgetString[i][j] != ';')  A[i].qtOS		 += gadgetString[i][j++]; j++; //10
		while (gadgetString[i][j] != ';')  A[i].qtBelt		 += gadgetString[i][j++]; j++; //11
		while (gadgetString[i][j] != ';')  A[i].info		 += gadgetString[i][j++]; j++; //12
		while (gadgetString[i][j] != ';')  A[i].lastDateTO	 += gadgetString[i][j++]; j++; //13
		while (gadgetString[i][j] != ';')  A[i].lastHoursTO	 += gadgetString[i][j++]; j++; //14
		while (gadgetString[i][j] != ';')  A[i].owner		 += gadgetString[i][j++]; j++; //15
		while (gadgetString[i][j] != ';')  A[i].serialNumber += gadgetString[i][j++]; j++; //16
		while (gadgetString[i][j] != ';')  A[i].AF			 += gadgetString[i][j++]; j++; //17
		while (gadgetString[i][j] != ';')  A[i].OF			 += gadgetString[i][j++]; j++; //18
		while (gadgetString[i][j] != ';')  A[i].OS			 += gadgetString[i][j++]; j++; //19
		while (gadgetString[i][j] != ';')  A[i].Belt		 += gadgetString[i][j++]; j++; //20
										   A[i].SHD		     += gadgetString[i][j++];	   //21
	}
	delete[] gadgetString; //��������� ������ �����
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 1 ����
*/



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
