#include "Header.h"	// подключение заголовка

int main()
{
	setlocale(LC_ALL, "Russian");		  // настройка консоли
	SetConsoleCP(1251);					  // ..
	SetConsoleOutputCP(1251);			  // ..
	system("mode con cols=100 lines=20"); // ..

	int aN = 0;// кол-во строк
	gadget* A; // основной массив устройств

#ifdef haveXlnt // если либа подключилась
	A = getByXlsx(aN, fileNameXlsx); // считать структуру с файла Xlsx
#else
	A = getByCsv(aN, fileNameCsv); // считать структуру с файла Csv
#endif // если либа установлена
		
	// опрос Что? Где? Когда?: 
	string aWhere;        // ответ:  Где?
	string aWhat;         // ответ:  Что?
	string aWhen;		  // ответ: Когда?
	int lastChosenGadget; // окончательный номер выбранного устройства
	int findMode = 1;	  // вариант работы функции findDialog
	findDialog(A, aN, aWhere, aWhat, aWhen, lastChosenGadget, findMode);

#ifdef haveXlnt // если либа подключилась
	// для корректной работы вывода нужно сменить локаль на английскую:
	setlocale(LC_ALL, "en-US");
	setToXlsx(A, aN, fileNameOutXlsx); // вывод в файл xlsx
	setlocale(LC_ALL, "Russian"); // и обратно
#else
	setToCsv(A, aN, fileNameOutCsv); // вывод в файл csv
#endif // если либа установлена

	delete[] A; // отчистить память
	exitProgram(); // красывый выход с проги
	return 1;
}