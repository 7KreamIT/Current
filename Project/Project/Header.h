#pragma once
#pragma warning(disable : 26495) // отключение предупреждения по библиотеке xlnt
#pragma warning(disable : 6387)  // отключение предупреждений по кодировке
#pragma warning(disable : 4267)  // ..
#include <iostream>      // для потока консоли
#include <fstream>       // для потока файла						для временного вывода в CSV
#include <conio.h>       // для cout
#include <string>        // для работы со строками
#include <ctime>		 // для вывода времени

// правила пользования таблицей:
// менять кол-во столбцов запрещено
// после последнего столбика необходимо оставлять пустой столбик
// после последнего обслуживаемого устройства необходимо оставлять пустую строчку
// нельзя оставлять пустые ячейчи в названиях столбцов и номерах строк
// программа не взаимодействует с выведенными из эксплотации устройствами
// не более 100 символов в клетке
// все ячейки должны быть в текстовом формате! (был зелёный треугольник в углу)
// 

// проверка на наличие библиотеки:
#ifdef __has_include
#	if __has_include(<xlnt/xlnt.hpp>)
#		define haveXlnt 1 // либа есть
#		include <xlnt/xlnt.hpp>
#		include <Windows.h>     // для Русского языка и std
		using namespace std;
#	else
#		define haveXlnt 0 // либы нет
#		include <Windows.h>     // для Русского языка и std
		using namespace std;
#	endif
#endif

const string fontName = "Times New Roman"; // название шрифта
const int fontHeight = 12; // высота шрифта
const string modelSymbol = "C"; // буква столбца с моделью

#ifdef haveXlnt // если либа подключилась
const string fileNameXlsx = "Test.xlsx"; // имя файла Xlsx для ввода
const string fileNameOutXlsx = "TestOut.xlsx"; // имя файла Xlsx для вывода
#else
const string fileNameCsv = "Test.csv"; // имя файла Csv для ввода
const string fileNameOutCsv = "TestOut.csv"; // имя файла Csv для вывода
#endif 

const int maxSymbol = 100; // максимальное кол-во символов в ячейке
const string englishABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int monthSize[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; // дни в месяцах

// структура с данными об устройстве:
class gadget
{
public:
	string number;       // порядковый номер установки		    // 01
	string type;         // тип установки					    // 02
	string model;	     // название модели					    // 03
	string place;        // место							    // 04
	string oil;          // масло							    // 05
	string tools;        // инструменты						    // 06
	string password;     // пароль							    // 07
	string qtAF;	     // кол-во ВФ						    // 08
	string qtOF;	     // кол-во МФ						    // 09
	string qtOS;	     // кол-во масляных сепараторов		    // 10
	string qtBelt;	     // кол-во ремней;					    // 11
	string info;	     // дополнительная информация		    // 12
	string lastDateTO;   // дата последнего ТО				    // 13
	string lastHoursTO;  // часы наработки после последнего ТО  // 14
	string owner;		 // чья установка					    // 15
	string serialNumber; // полный серийный номер			    // 16
	string AF;			 // вариант модели воздушного фильтра   // 17
	string OF;			 // вариант модели масляного фильтра	// 18
	string OS;			 // вариант модели масляного сепаратора // 19
	string Belt;		 // вариант модели ремня				// 20
	string SHD;			 // шаговая доступность (ШД)			// 21

	// метод, заполняющий поле по индексу:
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

	// метод, выдающий поле по индексу:
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

	~gadget() {};        // деструктор	
	// в будущем можно будет рассчитывать наработки ++				
};

// объявления считывающих функций:
#ifdef haveXlnt // если либа подключилась
gadget* getByXlsx(int& aN, string fileNameXlsx);
void setToXlsx(gadget*& A, int& aN, string fileNameOutXlsx);
#else
gadget* getByCsv(int& aN, string fileNameCsv);
void setToCsv(gadget*& A, int& aN, string fileNameOutCsv);
#endif 

// объявления функций:
string toOEM1251(string utf); //кодировка, использующаяся в IDE
string toUTF8(string oem); //кодировка, понимаемая программой
int numberOfLines(string fileName);
string dateToSixNumbers(int day, int month, int year);
void exitProgram();

// объявления диалогов:
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode);
int winGadget(gadget* A, int* x, int n);
int dateDialog(gadget*& A, int lastChosenGadget, string& aWhere, string& aWhat, string& aWhen);
int hoursDialog(gadget*& A, int& lastChosenGadget, string& aWhen);
