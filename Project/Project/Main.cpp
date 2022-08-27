#include "Header.h"	//подключение заголовка

int main()
{
	setlocale(LC_ALL, "Russian");		  //настройка консоли
	SetConsoleCP(1251);					  //..
	SetConsoleOutputCP(1251);			  //..
	system("mode con cols=100 lines=20"); //..

	int aN = 0;//кол-во строк
	gadget* A; //основной массив устройств

#ifdef haveXlnt // если либа подключилась
	A = getByXlsx(aN, fileNameXlsx); //считать структуру с файла Xlsx
#else
	A = getByCsv(aN, fileNameCsv); //считать структуру с файла Csv
#endif // если либа установлена
		
	//опрос Что? Где? Когда?: 
	string aWhere;        //ответ:  Где?
	string aWhat;         //ответ:  Что?
	string aWhen;		  //ответ: Когда?
	int lastChosenGadget; //окончательный номер выбранного устройства
	int findMode = 1;	  //вариант работы функции findDialog
	findDialog(A, aN, aWhere, aWhat, aWhen, lastChosenGadget, findMode);

	setToXlsx(A, lastChosenGadget, fileNameOutXlsx); //вывод в файл xlsx

	setToCsv(A, aN, fileNameOutCsv); //вывод в файл csv

	delete[] A; //отчистить память
	exitProgram();
	return 1;
}