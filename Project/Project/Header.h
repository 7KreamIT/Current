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
	string number;       //���������� ����� ���������		  //01
	string type;         //���������� ����� ���������		  //02
	string model;	     //�������� ������					  //03
	string place;        //�������							  //04
	string oil;          //**								  //05
	string tools;        //**								  //06
	string password;     //**								  //07
	string qtAF;	     //���-�� ��						  //08
	string qtOF;	     //���-�� ��						  //09
	string qtOS;	     //���-�� �������� �����������		  //10
	string qtBelt;	     //���-�� ������;					  //11
	string info;	     //�������������� ����������		  //12
	string lastDateTO;   //���� ���������� ��				  //13
	string lastHoursTO;  //���� ��������� ����� ���������� �� //14
	string owner;		 //��� ���������					  //15
	string serialNumber; //������ �������� �����			  //16
	string AF;			 //������� ���������� �������		  //17
	string OF;			 //������� ��������� �������		  //18
	string OS;			 //������� ��������� ����������		  //19
	string Belt;		 //������� ������					  //20
	string SHD;			 // �� - ������� ����������� 		  //21
	//� ������� ����� ����� ������������ ���������
};

//���������� ������� vvv

int numberOfLines(string fileName);
int findDialog(gadget*& A, int& aN, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& qWhen, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
string dateToSixNumbers(int day, int month, int year);
bool exitProgram();