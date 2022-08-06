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

//приведение дат в формат ДДММГГ:
string dateToSixNumbers(int day, int month, int year)
{
	string date;
	if (year > 2000)
	{
		if ((day < 10) && (month < 10)) date = '0' + to_string(day) + '0' + to_string(month) + to_string(year - 2000);
		if ((day < 10) && (month >= 10)) date = '0' + to_string(day) + to_string(month) + to_string(year - 2000);
		if ((day >= 10) && (month < 10)) date = to_string(day) + '0' + to_string(month) + to_string(year - 2000);
		if ((day >= 10) && (month >= 10)) date = to_string(day) + to_string(month) + to_string(year - 2000);
	}
	else
	{
		if ((day <  10) && (month <  10)) date = '0' + to_string(day) + '0' + to_string(month) + to_string(year);
		if ((day <  10) && (month >= 10)) date = '0' + to_string(day) + to_string(month) + to_string(year);
		if ((day >= 10) && (month <  10)) date = to_string(day) + '0' + to_string(month) + to_string(year);
		if ((day >= 10) && (month >= 10)) date = to_string(day) + to_string(month) + to_string(year);
	}
	return date;
}

//функция выводит лишь один номер устройства, которое собираемся менять:
int winGadget(gadget* A, int* x, int n) //x - это массив с подходящими под описание устройствами, n - их кол-во
{
	bool uncorrectAnswer = 0; //неверный ответ
	int chosenGadget = 0; //итоговый номер устройства
	if (n > 1) //если машин больше чем 1
	{
		cout << "Список подходящих под описание машин:" << endl;
		for (int i = 0; i < n; i++) cout << i + 1 << ":" << A[x[i]].model << endl;
		cout << "Введите номер машины от 1 до " << n << ":" << endl;
		do
		{
			uncorrectAnswer = 0;
			cin >> chosenGadget;
			if ((chosenGadget > n) || (chosenGadget < 1))
			{
				uncorrectAnswer = 1;
				cout << "Введите пожалуйста число от 1 до " << n << endl;
			}
		} while (uncorrectAnswer == 1);
		chosenGadget = stoi(A[x[chosenGadget - 1]].number); //отныне эта переменная является номером выбранной машины
	}
	else chosenGadget = stoi(A[x[0]].number);
	system("cls");
	cout << "Выбрано:'" << A[chosenGadget].type
		<< "' на '" << A[chosenGadget].place
		<< "' модели '" << A[chosenGadget].model
		<< "'" << endl;
	return chosenGadget;
}