#pragma once
#include <iostream>      //��� ������ �������
#include <fstream>       //��� ������ �����
#include <conio.h>       //��� cout
#include <string>        //��� ������ �� ��������
#include <SDKDDKVer.h>   //��� ������ �����
#include <stdio.h>       //��� ������ �����
#include <tchar.h>       //��� ������ �����
#include <Windows.h>     //��� �������� �����
#include <ctime>		 //��� ������ �������
using namespace std;
const int monthSize[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; //��� � �������

//��������� � ������� �� ����������:
class gadget
{
public:
	~gadget() {};        //����������
	string location;     //������� ����������						//01
	string number;       //���������� ����� ���������				//02
	string type;         //���������� ����� ���������				//03
	string model;	     //�������� ������							//04
	string place;        //�������									//05
	string oil;          //**										//06
	string tools;        //**										//07
	string password;     //**										//08
	string qtAF;	     //���-�� ��								//09
	string qtOF;	     //���-�� ��								//10
	string qtOS;	     //���-�� �������� �����������				//11
	string qtBelt;	     //���-�� ������;							//12
	string info;	     //�������������� ����������				//13
	string lastDateTO;   //���� ���������� ��						//14
	string lastHoursTO;  //���� ��������� ����� ���������� ��		//15
	string owner;		 //��� ���������							//16
	string serialNumber; //������ �������� �����					//17
	string AF1;			 //1 ��������� ������� ���������� �������	//18
	string AF2;			 //2 ��������� ������� ���������� �������	//19
	string AF3;			 //3 ��������� ������� ���������� ������� 	//20
	string OF1;			 //1 ��������� ������� ��������� �������	//21
	string OF2;			 //2 ��������� ������� ��������� �������	//22
	string OF3;			 //3 ��������� ������� ��������� �������	//23
	string OS1;			 //1 ��������� ������� ��������� ����������	//24
	string OS2;			 //2 ��������� ������� ��������� ����������	//25
	string OS3;			 //3 ��������� ������� ��������� ����������	//26
	string Belt1;		 //1 ��������� ������� ������				//27
	string Belt2;		 //2 ��������� ������� ������				//28
	string Belt3;		 //3 ��������� ������� ������				//29
	string SHD;			 // �� - ������� ����������� 				//30
	//� ������� ����� ����� ������������ ���������
};

//���������� ������� vvv

int numberOfLines(string fileName);
int findDialog(gadget*& A, int& aN, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& qWhen, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
string dateToSixNumbers(int day, int month, int year);
bool exitProgram();