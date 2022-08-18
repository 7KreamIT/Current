#pragma once
#include <iostream>      //для потока консоли
#include <fstream>       //для потока файла
#include <conio.h>       //для cout
#include <string>        //для работы со строками
#include <SDKDDKVer.h>   //для чтения файла
#include <stdio.h>       //для чтения файла
#include <tchar.h>       //для чтения файла
#include <Windows.h>     //для Русского языка
#include <ctime>		 //для вывода времени
using namespace std;
const int monthSize[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; //дни в месяцах

//структура с данными об устройстве:
class gadget
{
public:
	~gadget() {};        //деструктор						
	string number;       //порядковый номер установки		  //01
	string type;         //порядковый номер установки		  //02
	string model;	     //название модели					  //03
	string place;        //похожие							  //04
	string oil;          //**								  //05
	string tools;        //**								  //06
	string password;     //**								  //07
	string qtAF;	     //кол-во ВФ						  //08
	string qtOF;	     //кол-во МФ						  //09
	string qtOS;	     //кол-во масляных сепараторов		  //10
	string qtBelt;	     //кол-во ремней;					  //11
	string info;	     //дополнительная информация		  //12
	string lastDateTO;   //дата последнего ТО				  //13
	string lastHoursTO;  //часы наработки после последнего ТО //14
	string owner;		 //чья установка					  //15
	string serialNumber; //полный серийный номер			  //16
	string AF;			 //вариант воздушного фильтра		  //17
	string OF;			 //вариант масляного фильтра		  //18
	string OS;			 //вариант масляного сепаратора		  //19
	string Belt;		 //вариант ремней					  //20
	string SHD;			 // ШД - шаговая доступность 		  //21
	//в будущем нужно будет рассчитывать наработки
};

//объявления функций vvv

int numberOfLines(string fileName);
int findDialog(gadget*& A, int& aN, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& qWhen, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
string dateToSixNumbers(int day, int month, int year);
bool exitProgram();