#include "Header.h"	// ����������� ���������

int main()
{
	setlocale(LC_ALL, "Russian");		  // ��������� �������
	SetConsoleCP(1251);					  // ..
	SetConsoleOutputCP(1251);			  // ..
	system("mode con cols=100 lines=20"); // ..

	int aN = 0;// ���-�� �����
	gadget* A; // �������� ������ ���������

#ifdef haveXlnt // ���� ���� ������������
	A = getByXlsx(aN, fileNameXlsx); // ������� ��������� � ����� Xlsx
#else
	A = getByCsv(aN, fileNameCsv); // ������� ��������� � ����� Csv
#endif // ���� ���� �����������
		
	// ����� ���? ���? �����?: 
	string aWhere;        // �����:  ���?
	string aWhat;         // �����:  ���?
	string aWhen;		  // �����: �����?
	int lastChosenGadget; // ������������� ����� ���������� ����������
	int findMode = 1;	  // ������� ������ ������� findDialog
	findDialog(A, aN, aWhere, aWhat, aWhen, lastChosenGadget, findMode);

#ifdef haveXlnt // ���� ���� ������������
	// ��� ���������� ������ ������ ����� ������� ������ �� ����������:
	setlocale(LC_ALL, "en-US");
	setToXlsx(A, aN, fileNameOutXlsx); // ����� � ���� xlsx
	setlocale(LC_ALL, "Russian"); // � �������
#else
	setToCsv(A, aN, fileNameOutCsv); // ����� � ���� csv
#endif // ���� ���� �����������

	delete[] A; // ��������� ������
	exitProgram(); // �������� ����� � �����
	return 1;
}