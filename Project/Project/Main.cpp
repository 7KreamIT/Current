#include <iostream>      //для потока консоли
#include <fstream>       //для потока файла
#include <conio.h>       //для cout
#include <string>        //для работы со строками
#include <SDKDDKVer.h>   //для чтения файла
#include <stdio.h>       //для чтения файла
#include <tchar.h>       //для чтения файла
#include <Windows.h>     //для Русского языка
#include "Header.h"	     //мой заголовок
#include <ctime>		 //для вывода времени
using namespace std;
const int nMax = 100; //максимальное кол-во строк (i - переменная цикла)
const int m = 30; //кол-во столбцов (j - переменная цикла)
const int monthSize[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; //дни в месяцах

int winGadget(gadget* A, int* x, int n);

string dateToSixNumbers(int day, int month, int year);

int findDialog(gadget*& A, int& n, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& lastChosenGadget, int& findMode);

int main()
{
	//вывод времени(может в int):
	SYSTEMTIME t;	  //для времени
	GetLocalTime(&t); //для времени
	setlocale(LC_ALL, "Russian"); //поддержка Русского языка
	SetConsoleCP(1251);           //..
	SetConsoleOutputCP(1251);     //..
	int i, j; //переменные циклов
	int n; //фактическое кол-во строк (i - переменная цикла)

	//чтение таблицы:
	ifstream fRead("Test.csv"); //открытие файла для подсчёта строк
	string gadgetString[nMax];
	i = 0;
	while (!fRead.eof()) getline(fRead, gadgetString[i++]); //читает всю строку				
	n = i - 2; //запомнили кол-во устройств
	fRead.close(); //закрытие файла

	//заполнение структуры:
	gadget* A = new gadget[n];
	for (i = 0; i < n; i++) //нулевая строка это заголовки
	{
		j = 0;
		while (gadgetString[i][j] != ';')  A[i].location	 += gadgetString[i][j++]; j++; //01
		while (gadgetString[i][j] != ';')  A[i].number		 += gadgetString[i][j++]; j++; //02
		while (gadgetString[i][j] != ';')  A[i].type		 += gadgetString[i][j++]; j++; //03
		while (gadgetString[i][j] != ';')  A[i].model		 += gadgetString[i][j++]; j++; //04
		while (gadgetString[i][j] != ';')  A[i].place		 += gadgetString[i][j++]; j++; //05
		while (gadgetString[i][j] != ';')  A[i].oil			 += gadgetString[i][j++]; j++; //06
		while (gadgetString[i][j] != ';')  A[i].tools		 += gadgetString[i][j++]; j++; //07
		while (gadgetString[i][j] != ';')  A[i].password	 += gadgetString[i][j++]; j++; //08
		while (gadgetString[i][j] != ';')  A[i].qtAF		 += gadgetString[i][j++]; j++; //09
		while (gadgetString[i][j] != ';')  A[i].qtOF		 += gadgetString[i][j++]; j++; //10
		while (gadgetString[i][j] != ';')  A[i].qtOS		 += gadgetString[i][j++]; j++; //11
		while (gadgetString[i][j] != ';')  A[i].qtBelt		 += gadgetString[i][j++]; j++; //12
		while (gadgetString[i][j] != ';')  A[i].info		 += gadgetString[i][j++]; j++; //13
		while (gadgetString[i][j] != ';')  A[i].lastDateTO	 += gadgetString[i][j++]; j++; //14
		while (gadgetString[i][j] != ';')  A[i].lastHoursTO	 += gadgetString[i][j++]; j++; //15
		while (gadgetString[i][j] != ';')  A[i].owner		 += gadgetString[i][j++]; j++; //16
		while (gadgetString[i][j] != ';')  A[i].serialNumber += gadgetString[i][j++]; j++; //17
		while (gadgetString[i][j] != ';')  A[i].AF1			 += gadgetString[i][j++]; j++; //18
		while (gadgetString[i][j] != ';')  A[i].AF2			 += gadgetString[i][j++]; j++; //19
		while (gadgetString[i][j] != ';')  A[i].AF3			 += gadgetString[i][j++]; j++; //20
		while (gadgetString[i][j] != ';')  A[i].OF1			 += gadgetString[i][j++]; j++; //21
		while (gadgetString[i][j] != ';')  A[i].OF2			 += gadgetString[i][j++]; j++; //22
		while (gadgetString[i][j] != ';')  A[i].OF3			 += gadgetString[i][j++]; j++; //23
		while (gadgetString[i][j] != ';')  A[i].OS1			 += gadgetString[i][j++]; j++; //24
		while (gadgetString[i][j] != ';')  A[i].OS2			 += gadgetString[i][j++]; j++; //25
		while (gadgetString[i][j] != ';')  A[i].OS3			 += gadgetString[i][j++]; j++; //26
		while (gadgetString[i][j] != ';')  A[i].Belt1		 += gadgetString[i][j++]; j++; //27
		while (gadgetString[i][j] != ';')  A[i].Belt2		 += gadgetString[i][j++]; j++; //28
		while (gadgetString[i][j] != ';')  A[i].Belt3		 += gadgetString[i][j++]; j++; //29
										   A[i].SHD		     += gadgetString[i][j++]; j++; //30 
	}
	//**************************************************************************************** 1 блок
	
	//опрос Что и Где: 
	int qWhere = 0;       //вопрос: Где?
	int qWhereFirst = 0;  //первое уточнение: Где?
	string aWhere;        //ответ:  Где?
	int qWhat = 0;        //вопрос: Что?
	string aWhat;         //ответ:  Что?
	int lastChosenGadget; //окончательный номер выбранного устройства
	int findMode = 1;	  //вариант работы функции findDialog
	cout << "Функция поиска: " << findDialog(A, n, qWhere, qWhereFirst, aWhere, qWhat, aWhat, lastChosenGadget, findMode) << endl;

	//проверки:
	//cout << lastChosenGadget;

	/*
	//опрос даты:
	int qWhen = 0; //вопрос: Когда?
	string aWhen;  //ответ: Когда?
	int tempDay;   //временная переменная дня
	if ((qWhere >= 1) && (qWhere <= 9)) //разрешение и переход на следующий цикл
	{
		qWhen = 17;
		system("cls");
	}
	while (qWhen == 17)
	{
		system("cls");
		cout << "Выбрано:'" << aWhat << "' на '" << aWhere << "'" << endl;
		cout << "Когда сделано ТО?" << endl;
		//cout << "0 - Назад" << endl;
		cout << "1 - Сегодня" << endl;
		cout << "2 - Вчера" << endl;
		cout << "3 - Ввести дату" << endl;
		//cout << "4 - Позавчера" << endl; //можно поделать если станет скучно
		cin >> qWhen;
		switch (qWhen)
		{
		case 0:
			qWhen = 17; //Временное
			break;
		case 1:
			//запоминаем дату в формате ДДММГГ:
			aWhen = dateToSixNumbers(t.wDay, t.wMonth, t.wYear);
			cout << aWhen << endl;
			break;
		case 2:
			if (t.wDay == 1)
			{
				if (t.wMonth == 1) aWhen = to_string(31) + to_string(12) + to_string(t.wYear - 2001);
				else
				{
					if ((monthSize[t.wMonth - 1] == 1) && ((t.wYear - 2000) % 4 == 0)) tempDay = 29; //если високосный
					else tempDay = monthSize[t.wMonth - 1];
					aWhen = dateToSixNumbers(tempDay, t.wMonth - 1, t.wYear);
				}
			}
			else aWhen = dateToSixNumbers(t.wDay - 1, t.wMonth, t.wYear);
			break;
		case 3:
			i = 1;
			system("cls");
			while (i == 1)
			{
				cout << "Дата Тех. обслуживания(ДДММГГ):" << endl;
				cin >> aWhen;
				if (aWhen.length() != 6)
				{
					system("cls");
					cout << "Введите дату с левыми нулями, пожалуйста! \nНапример, так: 010700" << endl; //ошибка
				}
				else i = 0;
			}
			break;
		default:
			qWhen = 17; //Временное
			break;
		}
	}
	*/

	/*
	//ввод ТО:
	unsigned long int aHowMuch;	//ответ: Какая наработка?
	cout << "Какая наработка после ТО?" << endl;
	cin >> aHowMuch;

	//первое заполнение ячейки наработки и времени:
	system("cls");
	cout << "Собранные данные:'" << A[lastChosenGadget].type
		 << "' на '" << A[lastChosenGadget].place
		 << "' модели '" << A[lastChosenGadget].model
		 << "'" << endl;
	//if (qWhen == 1) cout << "Сегодняшняя дата: " << aWhen;
	//if (qWhen == 2) cout << "Введена дата ТО:" << aWhen;
	cout << endl << "Введена наработка: " << aHowMuch;

	cout << endl << "Вы уверены что ходите внести изменения? (1-да, 0-нет)\n";
	int ready;
	cin >> ready;
	cout << endl;
	switch (ready)
	{
	case 0:
		exit(0); //обиделся
		break;
	case 1:
		//A[lastChosenGadget].lastDateTO = aWhen;
		A[lastChosenGadget].lastHoursTO = to_string(aHowMuch);
		cout << "Данные успешно внесены!" << endl;
		break;
	default:
		exit(0); //обиделся
		break;
	}

	//вывод в файл:
	ofstream fWrite("TestOut.csv"); //объявим вывод в файл csv
	for (i = 0; i < n; i++)
	{
		fWrite << A[i].location	    << ";";  //01
		fWrite << A[i].number		<< ";";  //02
		fWrite << A[i].type			<< ";";  //03
		fWrite << A[i].model		<< ";";  //04
		fWrite << A[i].place		<< ";";  //05
		fWrite << A[i].oil			<< ";";  //06
		fWrite << A[i].tools		<< ";";  //07
		fWrite << A[i].password		<< ";";  //08
		fWrite << A[i].qtAF			<< ";";  //09
		fWrite << A[i].qtOF			<< ";";  //10
		fWrite << A[i].qtOS			<< ";";  //11
		fWrite << A[i].qtBelt		<< ";";  //12
		fWrite << A[i].info			<< ";";  //13
		fWrite << A[i].lastDateTO	<< ";";  //14
		fWrite << A[i].lastHoursTO	<< ";";  //15
		fWrite << A[i].owner		<< ";";  //16
		fWrite << A[i].serialNumber << ";";  //17
		fWrite << A[i].AF1			<< ";";  //18
		fWrite << A[i].AF2			<< ";";  //19
		fWrite << A[i].AF3			<< ";";  //20
		fWrite << A[i].OF1			<< ";";  //21
		fWrite << A[i].OF2			<< ";";  //22
		fWrite << A[i].OF3			<< ";";  //23
		fWrite << A[i].OS1			<< ";";  //24
		fWrite << A[i].OS2			<< ";";  //25
		fWrite << A[i].OS3			<< ";";  //26
		fWrite << A[i].Belt1		<< ";";  //27
		fWrite << A[i].Belt2		<< ";";  //28
		fWrite << A[i].Belt3		<< ";";  //29
		fWrite << A[i].SHD			<< endl; //30
	}
	fWrite.close(); //закрытие файла
	*/

	delete[] A; //отчистить память
	return 0;
}

//функция определяет значения входящих переменных.
int findDialog(gadget*& A, int& n, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& lastChosenGadget, int& findMode)
{
	//мод 1 - Первый запуск с возможностью перехода к настройкам
	//мод 2 - Запуск без возврата 4
	//мод 3 - Поиск по серийному номеру
	//функция возвращает:
	//0 - если машин не нашлось (только если удалят единственную машину где-нибудь)
	//1 - если успешно найдена одна машина
	qWhere = 17; //разрешение на следующий раздел
	while (qWhere == 17)
	{
		cout << "Где находится? (Пешая доступность)" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "1 - 1-я, 2-я или 3-я очередь" << endl; //доп ветка
		cout << "2 - ДОФ" << endl;
		cout << "3 - Шихта" << endl;
		cout << "4 - Готовая продукция" << endl; //доп ветка
		cout << "5 - Перегрузка" << endl;
		cout << "6 - Пульпанасосная" << endl;
		cout << "7 - Сгущение" << endl; //доп ветка
		cout << "8 - Станция Комбинатская" << endl;
		cin >> qWhere;
		switch (qWhere)
		{
		case 0:
			exit(0); //выйти из программы
			break;
		case 1:
			qWhereFirst = 17;
			while (qWhereFirst == 17)
			{
				system("cls");
				cout << "Можно поконкретнее? Пожалуйста :)" << endl;
				cout << "0 - Назад" << endl;
				cout << "1 - Обжиг" << endl;
				cout << "2 - Вторая" << endl;
				cout << "3 - Третья" << endl;
				cout << "4 - Минус 3" << endl;
				cin >> qWhereFirst;
				switch (qWhereFirst)
				{
				case 0:
					qWhereFirst = 0;
					qWhere = 17;
					system("cls");
					break;
				case 1:
					aWhere = "Обжиг";
					break;
				case 2:
					aWhere = "2 очер.";
					break;
				case 3:
					aWhere = "3 очер.";
					break;
				case 4:
					aWhere = "-3 м";
					break;
				default:
					qWhereFirst = 17;
					system("cls");
					break;
				}
				if ((qWhereFirst >= 1) && (qWhereFirst <= 4)) //закрытие доп ветки всвязи с получением ответа
				{
					qWhereFirst = 0;
					qWhere = 1; //это просто номер кейса
				}
			}
			break;
		case 2:
			aWhere = "ДОФ";
			break;
		case 3:
			aWhere = "Шихта";
			break;
		case 4:
			qWhereFirst = 17;
			while (qWhereFirst == 17)
			{
				system("cls");
				cout << "Какой бункер из двух?" << endl;
				cout << "0 - Назад" << endl;
				cout << "1 - Первый (Ближе)" << endl;
				cout << "2 - Второй (Дальше)" << endl;
				cin >> qWhereFirst;
				switch (qWhereFirst)
				{
				case 0:
					qWhere = 17;
					qWhereFirst = 0;
					system("cls");
					break;
				case 1:
					aWhere = "ГП 1";
					break;
				case 2:
					aWhere = "ГП 2";
					break;
				default:
					qWhereFirst = 17;
					system("cls");
					break;
				}
				if ((qWhereFirst >= 1) && (qWhereFirst <= 2)) //закрытие доп ветки всвязи с получением ответа
				{
					qWhereFirst = 0;
					qWhere = 4; //это просто номер кейса
				}
			}
			break;
		case 5:
			aWhere = "Перегр.";
			break;
		case 6:
			aWhere = "Пульп.";
			break;
		case 7:
			qWhereFirst = 17;
			while (qWhereFirst == 17)
			{
				system("cls");
				cout << "Какое сгущение-то?" << endl;
				cout << "0 - Назад" << endl;
				cout << "1 - Ну то, что рядом с ДОФом" << endl;
				cout << "2 - Новое" << endl;
				cin >> qWhereFirst;
				switch (qWhereFirst)
				{
				case 0:
					qWhereFirst = 0;
					qWhere = 17;
					system("cls");
					break;
				case 1:
					aWhere = "Сгущ.";
					break;
				case 2:
					aWhere = "Нов.сгущ.";
					break;
				default:
					qWhereFirst = 17;
					system("cls");
					break;
				}
				if ((qWhereFirst >= 1) && (qWhereFirst <= 2)) //закрытие доп ветки всвязи с получением ответа
				{
					qWhereFirst = 0;
					qWhere = 7; //это просто номер кейса
				}
			}
			break;
		case 8:
			aWhere = "Комб-ая";
			break;
		default:
			system("cls");
			qWhere = 17;
			cout << "Введите число от 0 до 8!" << endl;
			break;
		}
		if ((qWhere >= 1) && (qWhere <= 8)) //переход на следующий раздел с созданием массива подходящих устр-в
		{
			qWhat = 17;
			int* ArrWhere = new int[n] {0}; //массив устр-в с подходящим местоположением
			int ArrWhereN = 0; //их кол-во
			for (int i = 0; i < n; i++)
				if (A[i].place == aWhere)
				{
					ArrWhere[ArrWhereN] = stoi(A[i].number);
					//cout << ArrWhere[ArrWhereN] << endl; //всё отлично работает
					ArrWhereN++;
				}
			if (ArrWhereN == 1) //если машина одна, то
			{
				aWhat = A[ArrWhere[0]].type; //найден ответ на вопрос "Что?"
				qWhat = 0; //дальнейший опрос не требуется
				lastChosenGadget = ArrWhere[0]; //номер устр-ва
				return 1;
			}
			while (qWhat == 17)
			{
				string What[3]{ "КП","ВД","ОС" }; //массив со всеми типами
				system("cls");
				cout << "Выбрано:'" << aWhere << "' " << endl;
				cout << "Что было сделано?" << endl;
				cout << "0 - Назад" << endl;
				int flagKP = 0;
				int flagVD = 0;
				int flagOS = 0;
				for (int i = 0; i < ArrWhereN; i++) if (A[ArrWhere[i]].type == What[0])	flagKP = 1;
				if (flagKP == 1) cout << "1 - Компрессор"   << endl;
				for (int i = 0; i < ArrWhereN; i++) if (A[ArrWhere[i]].type == What[1])	flagVD = 1;
				if (flagVD == 1) cout << "2 - Воздуходувка" << endl;
				for (int i = 0; i < ArrWhereN; i++) if (A[ArrWhere[i]].type == What[2])	flagOS = 1;
				if (flagOS == 1) cout << "3 - Осушитель"    << endl;
				if ((flagKP + flagVD + flagOS) == 1)
				{

				}
				else
				{
					cin >> qWhat;

					/* это уже не работает (нужно сделать через if):
					switch (qWhat)
					{
					case 0:
						qWhere = 17;
						qWhat = 0;
						system("cls");
						break;
					case 1:
						aWhat = "КП";
						break;
					case 2:
						aWhat = "ВД";
						break;
					case 3:
						aWhat = "ОС";
						break;
					default:
						qWhat = 17;
						system("cls");
						cout << "Введите число от 0 до 3!" << endl;
						break;
					}
					*/
				}				
			}
		}		
	}
	return 1;
}