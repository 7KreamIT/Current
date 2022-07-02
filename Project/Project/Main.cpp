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
const int n = 87; //кол-во строк (i - переменная цикла)
const int m = 28; //кол-во столбцов (j - переменная цикла)

int main()
{
	//вывод времени(может в int):
	SYSTEMTIME t;	  //для времени
	GetLocalTime(&t); //для времени
	setlocale(LC_ALL, "Russian"); //поддержка Русского языка
	SetConsoleCP(1251);           //поддержка Русского языка
	SetConsoleOutputCP(1251);     //поддержка Русского языка
	int i, j; //переменные циклов
	ifstream fin("FileSourse.csv"); //открытие файла
	string objectString[n]; //массив строчек каждого устройства
	int lengthString[n]{}; //массив с длинами строчек
	for (i = 0; i < n; i++)
	{
		getline(fin, objectString[i]); //читает строку
		//lengthString[i] = objectString[i].length(); //вычисляет кол-во символов в строке
	}
	fin.close(); //закрытие файла

	//cout << "Проверка 1: " << lengthString[5] << " ***" << endl;
	//cout << "Проверка 2: " << objectString[3] << " ***" << endl;

	//заполнение структуры:	
	object A[n];
	for (i = 0; i < n; i++) //нулевая строка это заголовки
	{
		j = 0;
		while (objectString[i][j] != ';')  A[i].number		 += objectString[i][j++]; j++; //01
		while (objectString[i][j] != ';')  A[i].model		 += objectString[i][j++]; j++; //02
		while (objectString[i][j] != ';')  A[i].place		 += objectString[i][j++]; j++; //03
		while (objectString[i][j] != ';')  A[i].oil			 += objectString[i][j++]; j++; //04
		while (objectString[i][j] != ';')  A[i].tools		 += objectString[i][j++]; j++; //05
		while (objectString[i][j] != ';')  A[i].password	 += objectString[i][j++]; j++; //06
		while (objectString[i][j] != ';')  A[i].qtAF		 += objectString[i][j++]; j++; //07
		while (objectString[i][j] != ';')  A[i].qtOF		 += objectString[i][j++]; j++; //08
		while (objectString[i][j] != ';')  A[i].qtOS		 += objectString[i][j++]; j++; //09
		while (objectString[i][j] != ';')  A[i].qtBelt		 += objectString[i][j++]; j++; //10
		while (objectString[i][j] != ';')  A[i].info		 += objectString[i][j++]; j++; //11
		while (objectString[i][j] != ';')  A[i].lastDateTO	 += objectString[i][j++]; j++; //12
		while (objectString[i][j] != ';')  A[i].lastHoursTO	 += objectString[i][j++]; j++; //13
		while (objectString[i][j] != ';')  A[i].owner		 += objectString[i][j++]; j++; //14
		while (objectString[i][j] != ';')  A[i].serialNumber += objectString[i][j++]; j++; //15
		while (objectString[i][j] != ';')  A[i].AF1			 += objectString[i][j++]; j++; //16
		while (objectString[i][j] != ';')  A[i].AF2			 += objectString[i][j++]; j++; //17
		while (objectString[i][j] != ';')  A[i].AF3			 += objectString[i][j++]; j++; //18
		while (objectString[i][j] != ';')  A[i].OF1			 += objectString[i][j++]; j++; //19
		while (objectString[i][j] != ';')  A[i].OF2			 += objectString[i][j++]; j++; //20
		while (objectString[i][j] != ';')  A[i].OF3			 += objectString[i][j++]; j++; //21
		while (objectString[i][j] != ';')  A[i].OS1			 += objectString[i][j++]; j++; //22
		while (objectString[i][j] != ';')  A[i].OS2			 += objectString[i][j++]; j++; //23
		while (objectString[i][j] != ';')  A[i].OS3			 += objectString[i][j++]; j++; //24
		while (objectString[i][j] != ';')  A[i].Belt1		 += objectString[i][j++]; j++; //25
		while (objectString[i][j] != ';')  A[i].Belt2		 += objectString[i][j++]; j++; //26
		while (objectString[i][j] != ';')  A[i].Belt3		 += objectString[i][j++]; j++; //27
										   A[i].SHD		     += objectString[i][j];        //28
	}

	//cout << "Проверка 3: " << A[3].SHD  << " ***" << endl;

	/*
	// Опрос: 
	int qWhat = 17;       //вопрос: Что?
	string aWhat;         //ответ: Что?
	while (qWhat == 17)
	{
		cout << "Окей, летс го!" << endl;
		cout << "Что за устройство?" << endl;
		cout << "0 - Назад (Назад дороги нет)" << endl;
		cout << "1 - Компрессор" << endl;
		cout << "2 - Воздуходувка" << endl;
		cout << "3 - Осушитель" << endl;
		cin >> qWhat;
		switch (qWhat)
		{
		case 0:
			qWhat = 17;
			//придумать алгоритм возврата к предыдущему разделу
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
			break;
		}
	}

	system("cls");
	cout << aWhat << " " << endl;

	int qWhere = 17;       //вопрос: Где?
	string aWhere;         //ответ: Где?
	int qWhereFirst  = 17; //уточнение первого
	int qWhereSecond = 17; //уточнение второго
	int qWhereThird  = 17; //уточнение третьего
	while (qWhere == 17)
	{
		cout << "Где находится? (Пешая доступность)" << endl;
		cout << "0 - Назад" << endl;
		cout << "1 - 1-я, 2-я или 3-я очередь" << endl; //доп ветка
		cout << "2 - ДОФ" << endl;
		cout << "3 - Шихта" << endl;
		cout << "4 - Готовая продукция" << endl;
		cout << "5 - Перегрузка" << endl;
		cout << "6 - Пульпанасосная" << endl;
		cout << "7 - Сгущение" << endl;
		cout << "8 - Станция Комбинатская" << endl;
		cout << "9 - Перегрузка" << endl; //доп ветка
		cin >> qWhere;
		switch (qWhere)
		{
		case 0:
			qWhere = 17; //костыль
			//придумать алгоритм возврата к предыдущему разделу
			break;
		case 1:
			while (qWhereFirst == 17)
			{
				cout << "Можно поконкретнее? Пожалуйста)))" << endl;
				cout << "0 - Назад" << endl; //Придумать алгоритм возврата
				cout << "1 - Обжиг" << endl;
				cout << "2 - Вторая" << endl;
				cout << "3 - Третья" << endl;
				cout << "4 - Минус 3" << endl;
				cin >> qWhereFirst;
				switch (qWhereFirst)
				{
				case 0:
					qWhere = 17; //костыль
					//придумать алгоритм возврата к предыдущему разделу
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
					qWhere = 17;
					break;
				}
			}
		case 2:
			aWhere = "ДОФ";
			break;
		case 3:
			aWhere = "Шихта";
			break;
		case 4:
			cout << "Какой бункер из двух?" << endl;
			cout << "0 - Назад" << endl; //Придумать алгоритм возврата
			cout << "1 - Первый (Ближе)" << endl;
			cout << "2 - Второй (Дальше)" << endl;
			cin >> qWhereSecond;
			switch (qWhereSecond)
			{
			case 0:
				qWhere = 17; //костыль
				//придумать алгоритм возврата к предыдущему разделу
				break;
			case 1:
				aWhere = "ГП 1";
				break;
			case 2:
				aWhere = "ГП 2";
				break;
			default:
				qWhere = 17;
				break;
			}
			break;
		case 5:
			aWhere = "Перегр.";
			break;
		case 6:
			aWhere = "Пульп.";
			break;
		case 7:
			cout << "Какое сгущение-то?" << endl;
			cout << "0 - Назад" << endl; //Придумать алгоритм возврата
			cout << "1 - Ну то, что рядом с ДОФом" << endl;
			cout << "2 - Новое" << endl;
			cin >> qWhereThird;
			switch (qWhereThird)
			{
			case 0:
				qWhere = 17; //костыль
				//придумать алгоритм возврата к предыдущему разделу
				break;
			case 1:
				aWhere = "Сгущ.";
				break;
			case 2:
				aWhere = "Нов.сгущ.";
				break;
			default:
				qWhere = 17;
				break;
			}
			break;
		case 8:
			aWhere = "Комб-ая";
			break;
		case 9:
			aWhere = "Перегр.";
			break;
		default:
			qWhere = 17;
			break;
		}
	}
	
	system("cls");
	cout << aWhat << " на " << aWhere << " " << endl;
	*/

	int qWhen = 17; //вопрос: Когда?
	int aWhen = 0; //вопрос: Когда?
	while (qWhen == 17)
	{
		cout << "Когда сделано ТО?" << endl;
		cout << "0 - Назад" << endl;
		cout << "1 - Сегодня" << endl;
		cout << "2 - Вчера" << endl;
		cout << "3 - Позавчера" << endl;
		cout << "4 - Ввести дату" << endl; //доп ветка
		cin >> qWhen;
		switch (qWhen)
		{
		case 0:
			qWhen = 17; //костыль
			//придумать алгоритм возврата к предыдущему разделу
			break;
		case 1:
			cout << t.wDay << endl;
			cout << t.wMonth << endl;
			cout << t.wYear << endl;
			//cout << t.wHour << endl;   //а ещё можно часы
			//cout << t.wMinute << endl; //а ещё можно минуты
			//cout << t.wSecond << endl; //а ещё можно секунды
			************************************КОНЕЦ********************************
			break;
		case 2:
			aWhen;
			break;
		case 3:
			aWhen;
			break;
		case 4:
			aWhen;
			break;
		default:
			qWhen = 17;
			break;
		}
	}

	//вывод в файл:
	ofstream fWrite("FileOut.csv"); //объявим вывод в файл csv
	for (i = 0; i < n; i++)
	{
		fWrite << A[i].number		<< ";"; //01
		fWrite << A[i].model		<< ";"; //02
		fWrite << A[i].place		<< ";"; //03
		fWrite << A[i].oil			<< ";"; //04
		fWrite << A[i].tools		<< ";"; //05
		fWrite << A[i].password		<< ";"; //06
		fWrite << A[i].qtAF			<< ";"; //07
		fWrite << A[i].qtOF			<< ";"; //08
		fWrite << A[i].qtOS			<< ";"; //09
		fWrite << A[i].qtBelt		<< ";"; //10
		fWrite << A[i].info			<< ";"; //11
		fWrite << A[i].lastDateTO	<< ";"; //12
		fWrite << A[i].lastHoursTO	<< ";"; //13
		fWrite << A[i].owner		<< ";"; //14
		fWrite << A[i].serialNumber << ";"; //15
		fWrite << A[i].AF1			<< ";"; //16
		fWrite << A[i].AF2			<< ";"; //17
		fWrite << A[i].AF3			<< ";"; //18
		fWrite << A[i].OF1			<< ";"; //19
		fWrite << A[i].OF2			<< ";"; //20
		fWrite << A[i].OF3			<< ";"; //21
		fWrite << A[i].OS1			<< ";"; //22
		fWrite << A[i].OS2			<< ";"; //23
		fWrite << A[i].OS3			<< ";"; //24
		fWrite << A[i].Belt1		<< ";"; //25
		fWrite << A[i].Belt2		<< ";"; //26
		fWrite << A[i].Belt3		<< ";"; //27
		fWrite << A[i].SHD			<< ";"; //28
		fWrite << endl;
	}

	delete A; //деструктор
	//system("cls"); //чистит экран вывода	
	return (0);
}