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
	string location;     //локация устройства						//01
	string number;       //порядковый номер установки				//02
	string type;         //порядковый номер установки				//03
	string model;	     //название модели							//04
	string place;        //похожие									//05
	string oil;          //**										//06
	string tools;        //**										//07
	string password;     //**										//08
	string qtAF;	     //кол-во ВФ								//09
	string qtOF;	     //кол-во МФ								//10
	string qtOS;	     //кол-во масляных сепараторов				//11
	string qtBelt;	     //кол-во ремней;							//12
	string info;	     //дополнительная информация				//13
	string lastDateTO;   //дата последнего ТО						//14
	string lastHoursTO;  //часы наработки после последнего ТО		//15
	string owner;		 //чья установка							//16
	string serialNumber; //полный серийный номер					//17
	string AF1;			 //1 возможный вариант воздушного фильтра	//18
	string AF2;			 //2 возможный вариант воздушного фильтра	//19
	string AF3;			 //3 возможный вариант воздушного фильтра 	//20
	string OF1;			 //1 возможный вариант масляного фильтра	//21
	string OF2;			 //2 возможный вариант масляного фильтра	//22
	string OF3;			 //3 возможный вариант масляного фильтра	//23
	string OS1;			 //1 возможный вариант масляного сепаратора	//24
	string OS2;			 //2 возможный вариант масляного сепаратора	//25
	string OS3;			 //3 возможный вариант масляного сепаратора	//26
	string Belt1;		 //1 возможный вариант ремней				//27
	string Belt2;		 //2 возможный вариант ремней				//28
	string Belt3;		 //3 возможный вариант ремней				//29
	string SHD;			 // ШД - шаговая доступность 				//30
	//в будущем нужно будет рассчитывать наработки
};

//объявления функций vvv

int numberOfLines(string fileName);
int findDialog(gadget*& A, int& aN, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& qWhen, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
string dateToSixNumbers(int day, int month, int year);
bool exitProgram();