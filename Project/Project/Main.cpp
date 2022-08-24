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
	
	//A = getByXlsx(aN, fileNameXlsx); //���� ���������� ������������
	A = getByCsv(aN, fileNameCsv);	   //���� ���������� �� ������������
	
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