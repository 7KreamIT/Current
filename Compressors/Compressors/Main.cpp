#include <iostream>    //для потока консоли
#include <fstream>     //для потока файла
#include <conio.h>     //для cout
#include <string>      //для работы со строками
#include <SDKDDKVer.h> //для чтения файла
#include <stdio.h>     //для чтения файла
#include <tchar.h>     //для чтения файла
#include <Windows.h>   //для Русского языка
#include "Header.h"	   //мой заголовок
using namespace std;
const int n = 87; //кол-во строк (i - переменная цикла)
const int m = 28; //кол-во столбцов (j - переменная цикла)
int main()
{
	setlocale(LC_ALL, "Russian"); //поддержка Русского языка
	SetConsoleCP(1251);           //поддержка Русского языка
	SetConsoleOutputCP(1251);     //поддержка Русского языка
	int i, j, k; //переменные циклов
	ifstream fin("FileSourse.csv"); //открытие файла
	string objectString[n]; //массив строчек каждого устройства
	int lengthString[n]{}; //массив с длинами строчек
	for (i = 0; i < n; i++)
	{
		getline(fin, objectString[i]); //читает строку
		lengthString[i] = objectString[i].length(); //вычисляет кол-во символов в строке
	}
	fin.close(); //закрытие файла
	cout << "Окей, летс го!" << endl;
	cout << "Проверка 1: " << endl << lengthString[5] << endl << "***" << endl;
	cout << "Проверка 2: " << endl << objectString[3] << endl << "***" << endl;
	
	//заполнение структуры
	object A[n];
	for (i = 1; i < n; i++)
	{
		j = 0;
		while (objectString[i][j] != ';') A[i].number		+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].model		+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].place		+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].oil			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].tools		+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].password		+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].qtAF		    += objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].qtOF		    += objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].qtOS         += objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].qtBelt		+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].info         += objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].lastDateTO   += objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].lastHoursTO  += objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].owner        += objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].serialNumber += objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].AF1			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].AF2			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].AF3			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].OF1			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].OF2			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].OF3			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].OS1			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].OS2			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].OS3			+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].Belt1		+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].Belt2		+= objectString[i][j++]; j++;
		while (objectString[i][j] != ';') A[i].Belt3		+= objectString[i][j++]; j++;
		A[i].SHD = objectString[i][j];
	}
	cout << "Проверка 3: " << endl << A[86].info << endl << "***" << endl;

	/*
	ofstream fWrite("Test1out.csv"); //объявим вывод в файл csv

	//cout << "*" << A[2].serialNumber << "*" << endl;

	cout << "Считанная матрица: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			fWrite << A[i].number;
			fWrite << A[i].model[30];
			fWrite << A[i].place[15];
			fWrite << A[i].oil[15];
			fWrite << A[i].tools[15];
			fWrite << A[i].password[15];
			fWrite << A[i].qtAF[4];
			fWrite << A[i].qtOF[4];
			fWrite << A[i].qtOS[4];
			fWrite << A[i].qtBelt[4];
			fWrite << A[i].info[300];
			fWrite << A[i].lastDateTO;
			fWrite << A[i].lastHoursTO;
			fWrite << A[i].owner[20];
			fWrite << A[i].serialNumber[20];
			fWrite << A[i].AF1[30];
			fWrite << A[i].AF2[30];
			fWrite << A[i].AF3[30];
			fWrite << A[i].OF1[30];
			fWrite << A[i].OF2[30];
			fWrite << A[i].OF3[30];
			fWrite << A[i].OS1[30];
			fWrite << A[i].OS2[30];
			fWrite << A[i].OS3[30];
			fWrite << A[i].Belt1[30];
			fWrite << A[i].Belt2[30];
			fWrite << A[i].Belt3[30];
			fWrite << A[i].SHD;
		}
		fWrite << endl;
	}
	fWrite << endl;
	*/

	// Опрос: (должен быть функцией)
	int qWhat = 17;       //вопрос: Что?
	string aWhat;         //ответ: Что?
	while (qWhat == 17)
	{
		cout << "Начало программы." << endl;
		cout << "Что за устройство?" << endl;
		cout << "0 - Назад" << endl;
		cout << "1 - Компрессор" << endl;
		cout << "2 - Воздуходувка" << endl;
		cout << "3 - Осушитель" << endl;
		cin >> qWhat;
		switch (qWhat)
		{
		case 0:
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
	cout << endl << "Проверка 1:" << aWhat << endl << "***" << endl;
	int qWhere = 17;       //вопрос: Где?
	string aWhere;         //ответ: Где?
	int qWhereFirst = 17;  //уточнение первого
	string aWhereFirst;    //уточнение первого
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
		cout << "9 - Другое" << endl; //доп ветка
		cin >> qWhere;
		switch (qWhere)
		{
		case 0:
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
			//!!!!!!!!!!!!!!!!!!!!!!!!КОНЕЦ!!!!!!!!!!!!!!!!!!!!
			break;
		case 3:
			break;
		default:
			qWhere = 17;
			break;
		}
	}
	cout << endl << "Проверка 2:" << aWhere << endl << "***" << endl;
	//system("cls"); //чистит экран вывода	
	int qWhen = 17;        //вопрос: Когда? 0;
	cout << "Когда сделано ТО?" << endl;
	cout << "1 - Сегодня" << endl;
	cout << "2 - Вчера" << endl;
	cout << "3 - Позавчера" << endl;
	cout << "4 - Ввести дату" << endl; //доп ветка
	cout << "0 - Назад" << endl;
	cin >> qWhen;

	return (0);
}