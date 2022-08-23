#include "Header.h"	//����������� ���������

const string fileName = "�������.csv"; //��� ����� ��� �����			//��������
const string fileNameOut = "�������-Out.csv"; //��� ����� ��� ������	//�������� �� ������� � �������

int main()
{
	setlocale(LC_ALL, "Russian"); //��������� �������� �����
	SetConsoleCP(1251);           //..
	SetConsoleOutputCP(1251);     //..
	system("mode con cols=100 lines=20"); //������ �������

	//���� ���������� �� ������������, �� ������������ �������� ���(������ ���������� �� ����� "�������.csv"):
	//.......................................................................................................................
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
		while (gadgetString[i][j] != ';')  A[i].number   	 += gadgetString[i][j++]; j++; //01
		while (gadgetString[i][j] != ';')  A[i].type   		 += gadgetString[i][j++]; j++; //02
		while (gadgetString[i][j] != ';')  A[i].model   	 += gadgetString[i][j++]; j++; //03
		while (gadgetString[i][j] != ';')  A[i].place   	 += gadgetString[i][j++]; j++; //04
		while (gadgetString[i][j] != ';')  A[i].oil   		 += gadgetString[i][j++]; j++; //05
		while (gadgetString[i][j] != ';')  A[i].tools   	 += gadgetString[i][j++]; j++; //06
		while (gadgetString[i][j] != ';')  A[i].password   	 += gadgetString[i][j++]; j++; //07
		while (gadgetString[i][j] != ';')  A[i].qtAF   		 += gadgetString[i][j++]; j++; //08
		while (gadgetString[i][j] != ';')  A[i].qtOF   		 += gadgetString[i][j++]; j++; //09
		while (gadgetString[i][j] != ';')  A[i].qtOS   		 += gadgetString[i][j++]; j++; //10
		while (gadgetString[i][j] != ';')  A[i].qtBelt   	 += gadgetString[i][j++]; j++; //11
		while (gadgetString[i][j] != ';')  A[i].info   		 += gadgetString[i][j++]; j++; //12
		while (gadgetString[i][j] != ';')  A[i].lastDateTO   += gadgetString[i][j++]; j++; //13
		while (gadgetString[i][j] != ';')  A[i].lastHoursTO  += gadgetString[i][j++]; j++; //14
		while (gadgetString[i][j] != ';')  A[i].owner   	 += gadgetString[i][j++]; j++; //15
		while (gadgetString[i][j] != ';')  A[i].serialNumber += gadgetString[i][j++]; j++; //16
		while (gadgetString[i][j] != ';')  A[i].AF   		 += gadgetString[i][j++]; j++; //17
		while (gadgetString[i][j] != ';')  A[i].OF   		 += gadgetString[i][j++]; j++; //18
		while (gadgetString[i][j] != ';')  A[i].OS   		 += gadgetString[i][j++]; j++; //19
		while (gadgetString[i][j] != ';')  A[i].Belt   		 += gadgetString[i][j++]; j++; //20
										   A[i].SHD			 += gadgetString[i][j++];	   //21
	}
	delete[] gadgetString; //��������� ������ �����
	//.......................................................................................................................

	//���� ���������� ������������, �� ������������ �������� ���(������ ���������� �� ����� "Test.xlsx"):
	/*
	//.......................................................................................................................
	//�������� ����� xlsx:
	xlnt::workbook wb;
	wb.load("Test.xlsx");
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
	int aN = 0; //���-�� �����
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
	gadget* A = new gadget[aN]; //������� ������� - ��� �������� ��������
	for (i = 0; i < aN; i++) //������� ������ ��� ���������
	{
		tempABC = 0;
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].number 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//01
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].type 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//02
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].model 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//03
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].place 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//04
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].oil 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//05
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].tools 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//06
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].password 	 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//07
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].qtAF		 = toRus(ws.cell(tempCell).value<string>()); tempABC++; //08
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].qtOF 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//09
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].qtOS 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//10
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].qtBelt 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//11
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].info 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//12
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].lastDateTO 	 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//13
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].lastHoursTO  = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//14
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].owner 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//15
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].serialNumber = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//16
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].AF 			 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//17
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].OF 			 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//18
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].OS 			 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//19
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].Belt 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//20
		tempCell = englishABC[tempABC] + to_string(i + 1); A[i].SHD 		 = toRus(ws.cell(tempCell).value<string>()); tempABC++;	//21
	}
	//.......................................................................................................................
	*/
	
	//����� ���? ���? �����?: 
	string aWhere;        //�����:  ���?
	string aWhat;         //�����:  ���?
	string aWhen;		  //�����: �����?
	int lastChosenGadget; //������������� ����� ���������� ����������
	int findMode = 1;	  //������� ������ ������� findDialog
	findDialog(A, aN, aWhere, aWhat, aWhen, lastChosenGadget, findMode);

	//����� � ����:
	ofstream fileWrite(fileNameOut); //������� ����� � ���� csv
	for (i = 0; i < aN; i++)
	{
		fileWrite << A[i].number		<< ";";  //01
		fileWrite << A[i].type			<< ";";  //02
		fileWrite << A[i].model			<< ";";  //03
		fileWrite << A[i].place			<< ";";  //04
		fileWrite << A[i].oil			<< ";";  //05
		fileWrite << A[i].tools			<< ";";  //06
		fileWrite << A[i].password		<< ";";  //07
		fileWrite << A[i].qtAF			<< ";";  //08
		fileWrite << A[i].qtOF			<< ";";  //09
		fileWrite << A[i].qtOS			<< ";";  //10
		fileWrite << A[i].qtBelt		<< ";";  //11
		fileWrite << A[i].info			<< ";";  //12
		fileWrite << A[i].lastDateTO	<< ";";  //13
		fileWrite << A[i].lastHoursTO	<< ";";  //14
		fileWrite << A[i].owner			<< ";";  //15
		fileWrite << A[i].serialNumber  << ";";  //16
		fileWrite << A[i].AF			<< ";";  //17
		fileWrite << A[i].OF			<< ";";  //18
		fileWrite << A[i].OS			<< ";";  //19
		fileWrite << A[i].Belt			<< ";";  //20
		fileWrite << A[i].SHD			<< endl; //21
	}
	fileWrite.close(); //�������� �����

	delete[] A; //��������� ������
	exitProgram();
	return 1;
}

//������� ����� ������� ��:
int dateDialog(string& aWhere, string& aWhat, string& aWhen, string& lastChosenGadgetModel)
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
	//��� 2 - ������ ��� �������� 4
	//��� 3 - ����� �� ��������� ������
	//������� ����������:
	//0 - ���� �������� �����-������ ������
	//1 - ���� ������� ������� ���� ������
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
				string lastChosenGadgetModel = A[lastChosenGadget].model;
				dateDialog(aWhere, aWhat, aWhen, lastChosenGadgetModel);
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
					system("cls");
					cout << "�������:'" << aWhat
						 << "' �� '" << aWhere
						 << "'" << endl;
					lastChosenGadget = winGadget(A, arrWhat, arrWhatN);
					string lastChosenGadgetModel = A[lastChosenGadget].model;
					dateDialog(aWhere, aWhat, aWhen, lastChosenGadgetModel);
					hoursDialog(A, lastChosenGadget, aWhen);
					return 1;
				}
			}
		}
	}
	return 1;
}
