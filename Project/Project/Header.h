#pragma once
#pragma warning(disable : 26495) //���������� �������������� �� ���������� xlnt
#pragma warning(disable : 6387)  //���������� �������������� �� ���������
#pragma warning(disable : 4267)  //..
#include <xlnt/xlnt.hpp>
#include <iostream>      //��� ������ �������
#include <fstream>       //��� ������ �����						��� ���������� ������ � CSV
#include <conio.h>       //��� cout
#include <string>        //��� ������ �� ��������
#include <Windows.h>     //��� �������� �����
#include <ctime>		 //��� ������ �������

using namespace std;

const string fileNameXlsx = "Test.xlsx"; //��� ����� Xlsx ��� �����
const string fileNameOutXlsx = "TestOut.xlsx"; //��� ����� Xlsx ��� ������
const string fileNameCsv = "Test.csv"; //��� ����� Csv ��� �����
const string fileNameOutCsv = "TestOut.csv"; //��� ����� Csv ��� ������

const int maxSymbol = 100; //������������ ���-�� �������� � ������
const string englishABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int monthSize[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; //��� � �������

// ������� ����������� ��������:
// ������ ���-�� �������� ���������
// ����� ���������� �������� ���������� ��������� ������ �������
// ����� ���������� �������������� ���������� ���������� ��������� ������ �������
// ������ ��������� ������ ������ � ��������� �������� � ������� �����
// ��������� �� ��������������� � ����������� �� ����������� ������������
// �� ����� 100 �������� � ������
// ��� ���������� ������ ��������� � ������� ���������� ����� ��� ������ ���� � ��������� �������! (� ���� ��� ������ ����������� � ����)
// 

//��������� � ������� �� ����������:
class gadget
{
public:
	string number;       //���������� ����� ���������		   //01
	string type;         //��� ���������					   //02
	string model;	     //�������� ������					   //03
	string place;        //�����							   //04
	string oil;          //�����							   //05
	string tools;        //�����������						   //06
	string password;     //������							   //07
	string qtAF;	     //���-�� ��						   //08
	string qtOF;	     //���-�� ��						   //09
	string qtOS;	     //���-�� �������� �����������		   //10
	string qtBelt;	     //���-�� ������;					   //11
	string info;	     //�������������� ����������		   //12
	string lastDateTO;   //���� ���������� ��				   //13
	string lastHoursTO;  //���� ��������� ����� ���������� ��  //14
	string owner;		 //��� ���������					   //15
	string serialNumber; //������ �������� �����			   //16
	string AF;			 //������� ������ ���������� �������   //17
	string OF;			 //������� ������ ��������� �������	   //18
	string OS;			 //������� ������ ��������� ���������� //19
	string Belt;		 //������� ������ �����				   //20
	string SHD;			 //������� ����������� (��)			   //21

	//�����, ������������ ����������:
	string name(int i)
	{
		if (i == 1)  return number;
		if (i == 2)  return type;
		if (i == 3)  return model;
		if (i == 4)  return place;
		if (i == 5)  return oil;
		if (i == 6)  return tools;
		if (i == 7)  return password;
		if (i == 8)  return qtAF;
		if (i == 9)  return qtOF;
		if (i == 10) return qtOS;
		if (i == 11) return qtBelt;
		if (i == 12) return info;
		if (i == 13) return lastDateTO;
		if (i == 14) return lastHoursTO;
		if (i == 15) return owner;
		if (i == 16) return serialNumber;
		if (i == 17) return AF;
		if (i == 18) return OF;
		if (i == 19) return OS;
		if (i == 20) return Belt;
		if (i == 21) return SHD;
	}

	~gadget() {};        //����������	
	//� ������� ����� ����� ������������ ��������� ++				
};

//���������� �������:
gadget* getByXlsx(int& aN, string fileNameXlsx);	//���� ���������� ������������
//gadget* getByCsv(int& aN, string fileNameCsv);		//���� ���������� �� ������������
string toRus(string utf);
int numberOfLines(string fileName);
string dateToSixNumbers(int day, int month, int year);
void setToXlsx(gadget*& A, int& lastChosenGadget, string fileNameOutXlsx);
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv);
void exitProgram();

//���������� ��������:
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
int dateDialog(gadget*& A, int lastChosenGadget, string& aWhere, string& aWhat, string& aWhen);
int hoursDialog(gadget*& A, int& lastChosenGadget, string& aWhen);