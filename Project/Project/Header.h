#pragma once
using namespace std;

//структура с данными об устройстве:
class gadget
{
public:
	~gadget() {};        //деструктор
	string location;     //локаци€ устройства						//01
	string number;       //пор€дковый номер установки				//02
	string type;         //пор€дковый номер установки				//03
	string model;	     //название модели							//04
	string place;        //похожие									//05
	string oil;          //**										//06
	string tools;        //**										//07
	string password;     //**										//08
	string qtAF;	     //кол-во ¬‘								//09
	string qtOF;	     //кол-во ћ‘								//10
	string qtOS;	     //кол-во масл€ных сепараторов				//11
	string qtBelt;	     //кол-во ремней;							//12
	string info;	     //дополнительна€ информаци€				//13
	string lastDateTO;   //дата последнего “ќ						//14
	string lastHoursTO;  //часы наработки после последнего “ќ		//15
	string owner;		 //чь€ установка							//16
	string serialNumber; //полный серийный номер					//17
	string AF1;			 //1 возможный вариант воздушного фильтра	//18
	string AF2;			 //2 возможный вариант воздушного фильтра	//19
	string AF3;			 //3 возможный вариант воздушного фильтра 	//20
	string OF1;			 //1 возможный вариант масл€ного фильтра	//21
	string OF2;			 //2 возможный вариант масл€ного фильтра	//22
	string OF3;			 //3 возможный вариант масл€ного фильтра	//23
	string OS1;			 //1 возможный вариант масл€ного сепаратора	//24
	string OS2;			 //2 возможный вариант масл€ного сепаратора	//25
	string OS3;			 //3 возможный вариант масл€ного сепаратора	//26
	string Belt1;		 //1 возможный вариант ремней				//27
	string Belt2;		 //2 возможный вариант ремней				//28
	string Belt3;		 //3 возможный вариант ремней				//29
	string SHD;			 // Ўƒ - шагова€ доступность 				//30
	//в будущем нужно будет рассчитывать наработки
};

string dateToSixNumbers(int day, int month, int year);

int winGadget(gadget* A, int* x, int n);