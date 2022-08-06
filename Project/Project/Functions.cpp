#include <iostream>      //��� ������ �������
#include <fstream>       //��� ������ �����
#include <conio.h>       //��� cout
#include <string>        //��� ������ �� ��������
#include <SDKDDKVer.h>   //��� ������ �����
#include <stdio.h>       //��� ������ �����
#include <tchar.h>       //��� ������ �����
#include <Windows.h>     //��� �������� �����
#include "Header.h"	     //��� ���������
#include <ctime>		 //��� ������ �������
using namespace std;

//���������� ��� � ������ ������:
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

//������� ������� ���� ���� ����� ����������, ������� ���������� ������:
int winGadget(gadget* A, int* x, int n) //x - ��� ������ � ����������� ��� �������� ������������, n - �� ���-��
{
	bool uncorrectAnswer = 0; //�������� �����
	int chosenGadget = 0; //�������� ����� ����������
	if (n > 1) //���� ����� ������ ��� 1
	{
		cout << "������ ���������� ��� �������� �����:" << endl;
		for (int i = 0; i < n; i++) cout << i + 1 << ":" << A[x[i]].model << endl;
		cout << "������� ����� ������ �� 1 �� " << n << ":" << endl;
		do
		{
			uncorrectAnswer = 0;
			cin >> chosenGadget;
			if ((chosenGadget > n) || (chosenGadget < 1))
			{
				uncorrectAnswer = 1;
				cout << "������� ���������� ����� �� 1 �� " << n << endl;
			}
		} while (uncorrectAnswer == 1);
		chosenGadget = stoi(A[x[chosenGadget - 1]].number); //������ ��� ���������� �������� ������� ��������� ������
	}
	else chosenGadget = stoi(A[x[0]].number);
	system("cls");
	cout << "�������:'" << A[chosenGadget].type
		<< "' �� '" << A[chosenGadget].place
		<< "' ������ '" << A[chosenGadget].model
		<< "'" << endl;
	return chosenGadget;
}