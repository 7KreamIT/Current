#pragma once
#pragma warning(disable : 26495) //���������� �������������� �� ���������� xlnt
#pragma warning(disable : 6387)  //���������� �������������� �� ���������
#pragma warning(disable : 4267)  //..
#include <iostream>      //��� ������ �������
#include <fstream>       //��� ������ �����						��� ���������� ������ � CSV
#include <conio.h>       //��� cout
#include <string>        //��� ������ �� ��������
#include <Windows.h>     //��� �������� �����
#include <ctime>		 //��� ������ �������

//�������� �� ������� ����������:
#ifdef __has_include
#  if __has_include(<xlnt/xlnt.hpp>)
#    include <xlnt/xlnt.hpp>
#    define haveXlnt 1 //���� ����
#  else
#    define haveXlnt 0 //���� ���
#endif
#endif
//(�������� � ������� ����� ������ ���������� ����� ������)

using namespace std;

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
	int aN; //���-�� ���������
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
	~gadget() {};        //����������	
	//�������� ������ ��� ����� (��� ����� �����)  ++
	//� ������� ����� ����� ������������ ��������� ++				
};

//���������� �������:
//gadget* getByXlsx(int& aN, string fileNameXlsx);	//���� ���������� ������������
gadget* getByCsv(int& aN, string fileNameCsv);		//���� ���������� �� ������������
string toRus(string utf);
int numberOfLines(string fileName);
string dateToSixNumbers(int day, int month, int year);
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv);
void exitProgram();

//���������� ��������:
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
int dateDialog(gadget*& A, int lastChosenGadget, string& aWhere, string& aWhat, string& aWhen);
int hoursDialog(gadget*& A, int& lastChosenGadget, string& aWhen);