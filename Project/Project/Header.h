#pragma once

#include <xlnt/xlnt.hpp> //подключение долгожданной библиотеки

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
	string number;       //порядковый номер установки		   //01
	string type;         //тип установки					   //02
	string model;	     //название модели					   //03
	string place;        //место							   //04
	string oil;          //масло							   //05
	string tools;        //инструменты						   //06
	string password;     //пароль							   //07
	string qtAF;	     //кол-во ВФ						   //08
	string qtOF;	     //кол-во МФ						   //09
	string qtOS;	     //кол-во масляных сепараторов		   //10
	string qtBelt;	     //кол-во ремней;					   //11
	string info;	     //дополнительная информация		   //12
	string lastDateTO;   //дата последнего ТО				   //13
	string lastHoursTO;  //часы наработки после последнего ТО  //14
	string owner;		 //чья установка					   //15
	string serialNumber; //полный серийный номер			   //16
	string AF;			 //вариант модели воздушного фильтра   //17
	string OF;			 //вариант модели масляного фильтра	   //18
	string OS;			 //вариант модели масляного сепаратора //19
	string Belt;		 //вариант модели ремня				   //20
	string SHD;			 //шаговая доступность (ШД)			   //21
	//в будущем нужно будет рассчитывать наработки
};

//объявления функций vvv
int numberOfLines(string fileName);
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
string dateToSixNumbers(int day, int month, int year);
bool exitProgram();