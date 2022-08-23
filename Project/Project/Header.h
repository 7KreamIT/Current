#pragma once
#pragma warning(disable : 26495) //отключение предупреждения по библиотеке xlnt
#pragma warning(disable : 6387)  //отключение предупреждений по кодировке
#pragma warning(disable : 4267)  //..
#include <xlnt/xlnt.hpp> //подключение долгожданной библиотеки
#include <iostream>      //для потока консоли
#include <fstream>       //для потока файла						для временного вывода в CSV
#include <conio.h>       //для cout
#include <string>        //для работы со строками
#include <Windows.h>     //для Русского языка
#include <ctime>		 //для вывода времени
using namespace std;

const int maxSymbol = 100; //максимальное кол-во символов в ячейке
const string englishABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int monthSize[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; //дни в месяцах

// правила пользования таблицей:
// менять кол-во столбцов запрещено
// после последнего столбика необходимо оставлять пустой столбик
// после последнего обслуживаемого устройства необходимо оставлять пустую строчку
// нельзя оставлять пустые ячейчи в названиях столбцов и номерах строк
// программа не взаимодействует с выведенными из эксплотации устройствами
// не более 100 символов в клетке
// для корректной работы программы с числами необходимо чтобы все ячейки были в текстовом формате! (у цифр был зелёный треугольник в углу)
// 

//структура с данными об устройстве:
class gadget
{
public:
	int aN; //кол-во элементов
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
	~gadget() {};        //деструктор	
	//написать массив для строк (это будет метод)  ++
	//в будущем нужно будет рассчитывать наработки ++				
};

//объявления функций vvv
gadget* getByXlsx(int& aN, string fileNameXlsx);
gadget* getByCsv(int& aN, string fileNameCsv);
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv);
int numberOfLines(string fileName);
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
string dateToSixNumbers(int day, int month, int year);
bool exitProgram();
string toRus(string utf);