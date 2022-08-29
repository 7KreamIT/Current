#pragma once
#pragma warning(disable : 26495) // ���������� �������������� �� ���������� xlnt
#pragma warning(disable : 6387)  // ���������� �������������� �� ���������
#pragma warning(disable : 4267)  // ..
#include <iostream>      // ��� ������ �������
#include <fstream>       // ��� ������ �����						��� ���������� ������ � CSV
#include <conio.h>       // ��� cout
#include <string>        // ��� ������ �� ��������
#include <ctime>		 // ��� ������ �������

// ������� ����������� ��������:
// ������ ���-�� �������� ���������
// ����� ���������� �������� ���������� ��������� ������ �������
// ����� ���������� �������������� ���������� ���������� ��������� ������ �������
// ������ ��������� ������ ������ � ��������� �������� � ������� �����
// ��������� �� ��������������� � ����������� �� ����������� ������������
// �� ����� 100 �������� � ������
// ��� ������ ������ ���� � ��������� �������! (��� ������ ����������� � ����)
// 

// �������� �� ������� ����������:
#ifdef __has_include
#	if __has_include(<xlnt/xlnt.hpp>)
#		define haveXlnt 1 // ���� ����
#		include <xlnt/xlnt.hpp>
#		include <Windows.h>     // ��� �������� ����� � std
		using namespace std;
#	else
#		define haveXlnt 0 // ���� ���
#		include <Windows.h>     // ��� �������� ����� � std
		using namespace std;
#	endif
#endif

const string fontName = "Times New Roman"; // �������� ������
const int fontHeight = 12; // ������ ������
const string modelSymbol = "C"; // ����� ������� � �������

#ifdef haveXlnt // ���� ���� ������������
const string fileNameXlsx = "Test.xlsx"; // ��� ����� Xlsx ��� �����
const string fileNameOutXlsx = "TestOut.xlsx"; // ��� ����� Xlsx ��� ������
#else
const string fileNameCsv = "Test.csv"; // ��� ����� Csv ��� �����
const string fileNameOutCsv = "TestOut.csv"; // ��� ����� Csv ��� ������
#endif 

const int maxSymbol = 100; // ������������ ���-�� �������� � ������
const string englishABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int monthSize[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; // ��� � �������

// ��������� � ������� �� ����������:
class gadget
{
public:
	string number;       // ���������� ����� ���������		    // 01
	string type;         // ��� ���������					    // 02
	string model;	     // �������� ������					    // 03
	string place;        // �����							    // 04
	string oil;          // �����							    // 05
	string tools;        // �����������						    // 06
	string password;     // ������							    // 07
	string qtAF;	     // ���-�� ��						    // 08
	string qtOF;	     // ���-�� ��						    // 09
	string qtOS;	     // ���-�� �������� �����������		    // 10
	string qtBelt;	     // ���-�� ������;					    // 11
	string info;	     // �������������� ����������		    // 12
	string lastDateTO;   // ���� ���������� ��				    // 13
	string lastHoursTO;  // ���� ��������� ����� ���������� ��  // 14
	string owner;		 // ��� ���������					    // 15
	string serialNumber; // ������ �������� �����			    // 16
	string AF;			 // ������� ������ ���������� �������   // 17
	string OF;			 // ������� ������ ��������� �������	// 18
	string OS;			 // ������� ������ ��������� ���������� // 19
	string Belt;		 // ������� ������ �����				// 20
	string SHD;			 // ������� ����������� (��)			// 21

	// �����, ����������� ���� �� �������:
	int setValueByIndex(string text, int i)
	{
		switch (i)
		{
		case 1:	 number		  = text; return 1;	break;
		case 2:	 type		  = text; return 1;	break;
		case 3:	 model		  = text; return 1;	break;
		case 4:	 place		  = text; return 1;	break;
		case 5:	 oil		  = text; return 1;	break;
		case 6:	 tools		  = text; return 1;	break;
		case 7:	 password	  = text; return 1;	break;
		case 8:	 qtAF		  = text; return 1;	break;
		case 9:	 qtOF		  = text; return 1;	break;
		case 10: qtOS		  = text; return 1;	break;
		case 11: qtBelt		  = text; return 1;	break;
		case 12: info		  = text; return 1;	break;
		case 13: lastDateTO	  = text; return 1;	break;
		case 14: lastHoursTO  = text; return 1;	break;
		case 15: owner		  = text; return 1;	break;
		case 16: serialNumber = text; return 1;	break;
		case 17: AF			  = text; return 1;	break;
		case 18: OF			  = text; return 1;	break;
		case 19: OS			  = text; return 1;	break;
		case 20: Belt		  = text; return 1;	break;
		case 21: SHD		  = text; return 1;	break;
		default:					  return 0;	break;
		}
	}

	// �����, �������� ���� �� �������:
	string getValueByIndex(int i)
	{
		switch (i)
		{			
		case 1:	 return number		 ; break;
		case 2:	 return type		 ; break;
		case 3:	 return model		 ; break;
		case 4:	 return place		 ; break;
		case 5:	 return oil			 ; break;
		case 6:	 return tools		 ; break;
		case 7:	 return password	 ; break;
		case 8:	 return qtAF		 ; break;
		case 9:	 return qtOF		 ; break;
		case 10: return qtOS		 ; break;
		case 11: return qtBelt		 ; break;
		case 12: return info		 ; break;
		case 13: return lastDateTO	 ; break;
		case 14: return lastHoursTO  ; break;
		case 15: return owner		 ; break;
		case 16: return serialNumber ; break;
		case 17: return AF			 ; break;
		case 18: return OF			 ; break;
		case 19: return OS			 ; break;
		case 20: return Belt		 ; break;
		case 21: return SHD			 ; break;
		default: return "error"		 ; break;
		}
	}

	~gadget() {};        // ����������	
	// � ������� ����� ����� ������������ ��������� ++				
};

// ���������� ����������� �������:
#ifdef haveXlnt // ���� ���� ������������
gadget* getByXlsx(int& aN, string fileNameXlsx);
void setToXlsx(gadget*& A, int& aN, string fileNameOutXlsx);
#else
gadget* getByCsv(int& aN, string fileNameCsv);
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv);
#endif 

// ���������� �������:
string toOEM1251(string utf); //���������, �������������� � IDE
string toUTF8(string oem); //���������, ���������� ����������
int numberOfLines(string fileName);
string dateToSixNumbers(int day, int month, int year);
void exitProgram();

// ���������� ��������:
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
int dateDialog(gadget*& A, int lastChosenGadget, string& aWhere, string& aWhat, string& aWhen);
int hoursDialog(gadget*& A, int& lastChosenGadget, string& aWhen);
