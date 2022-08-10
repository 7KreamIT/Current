#include "Header.h"	//подключение заголовка

#include "ExcelFormat.h"	 //для работы Экселя
#ifdef _WIN32				 //..
#define WIN32_LEAN_AND_MEAN	 //
#include <windows.h>		 //
#include <shellapi.h> 		 //
#include <crtdbg.h>			 //
#else // _WIN32				 //
#define	FW_NORMAL	400		 //
#define	FW_BOLD		700		 //
#endif // _WIN32			 //
using namespace ExcelFormat; // 

const int m = 30; //кол-во столбцов (j - переменная цикла)
const string fileName = "Test.csv"; //имя файла для ввода
const string fileNameOut = "TestOut.csv"; //имя файла для ввода

int main()
{
	#ifdef _MSC_VER												 //для работы Экселя
	// detect memory leaks										 //..
	//	_CrtSetDbgFlag(_CrtSetDbgFlag(0)|_CRTDBG_LEAK_CHECK_DF); //
	#endif														 //

	setlocale(LC_ALL, "Russian"); //поддержка Русского языка
	SetConsoleCP(1251);           //..
	SetConsoleOutputCP(1251);     //..
	system("mode con cols=60 lines=20"); //размер консоли
	int i, j; //переменные циклов	
	int aN = numberOfLines(fileName) - 1; //фактическое кол-во строк (i - переменная цикла)

	//чтение таблицы:
	ifstream fRead(fileName); //открытие файла для подсчёта строк
	string* gadgetString = new string[aN];
	for (i = 0; i < aN; i++) getline(fRead, gadgetString[i]); //читает всю строку
	fRead.close(); //закрытие файла

	//заполнение структуры:
	gadget* A = new gadget[aN];
	for (i = 0; i < aN; i++) //нулевая строка это заголовки
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
										   A[i].SHD		     += gadgetString[i][j++];	   //30 
	}
	delete[] gadgetString;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 1 блок
	
	//опрос Что? Где? Когда?: 
	int qWhere = 0;       //вопрос: Где?
	int qWhereFirst = 0;  //первое уточнение: Где?
	string aWhere;        //ответ:  Где?
	int qWhat = 0;        //вопрос: Что?
	string aWhat;         //ответ:  Что?
	int qWhen = 0;		  //вопрос: Когда?
	string aWhen;		  //ответ: Когда?
	int lastChosenGadget; //окончательный номер выбранного устройства
	int findMode = 1;	  //вариант работы функции findDialog
	findDialog(A, aN, qWhere, qWhereFirst, aWhere, qWhat, aWhat, qWhen, aWhen, lastChosenGadget, findMode);

	//проверки:
	cout << lastChosenGadget << " " << aWhat << " " << aWhere << endl;

	//вывод в файл:
	ofstream fWrite(fileNameOut); //объявим вывод в файл csv
	for (i = 0; i < aN; i++)
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

	delete[] A; //отчистить память
	exitProgram();
	return 1;
}

//функция ввода времени ТО:
int dateDialog(int& qWhere, string& aWhere, int& qWhat, string& aWhat, int& qWhen, string& aWhen)
{
	int tempDay; //временная переменная дня
	SYSTEMTIME t;	  //для вывода времени(может в int):
	GetLocalTime(&t); //..
	if ((qWhere >= 1) && (qWhere <= 9)) //разрешение и переход на следующий цикл
	{
		qWhen = 17;
		system("cls");
	}
	while (qWhen == 17)
	{
		system("cls");
		int i;
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
			break;
		case 2:
			if (t.wDay == 1)
			{
				if (t.wMonth == 1) 
					aWhen = to_string(31) + to_string(12) + to_string(t.wYear - 2001);
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
	return 1;
}

//функция ввода ТО:
int hoursDialog(gadget*& A, int& lastChosenGadget, string& aWhen)
{
	unsigned long int aHowMuch;	//ответ: Какая наработка?
	cout << "Какая наработка после ТО?" << endl;
	cin >> aHowMuch;

	//первое заполнение ячейки наработки и времени:
	system("cls");
	cout << "Собранные данные:'" << A[lastChosenGadget].type
		<< "' на '" << A[lastChosenGadget].place
		<< "' модели '" << A[lastChosenGadget].model
		<< "'" << endl;
	cout << "Введена наработка: " << aHowMuch << endl;
	cout << "Введена дата: " << aWhen << endl;
	cout << "Вы уверены что ходите внести изменения? (1-да, 0-нет)" << endl;
	int ready;
	cin >> ready;
	switch (ready)
	{
	case 0:
		exit(0); //обиделся
		break;
	case 1:
		A[lastChosenGadget].lastDateTO = aWhen;
		A[lastChosenGadget].lastHoursTO = to_string(aHowMuch);
		cout << "Данные успешно внесены!" << endl;
		break;
	default:
		exit(0); //обиделся
		break;
	}
	return 1;
}

//функция основного диалога, которая изменяет все переменные:
int findDialog(gadget*& A, int& aN, int& qWhere, int& qWhereFirst, string& aWhere, int& qWhat, string& aWhat, int& qWhen, string& aWhen, int& lastChosenGadget, int& findMode)
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
			exitProgram(); //красиво выйти из программы
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
			int* arrWhere = new int[aN] {0}; //массив устр-в с подходящим местоположением
			int arrWhereN = 0; //их кол-во
			for (int i = 0; i < aN; i++)
				if (A[i].place == aWhere)
				{
					arrWhere[arrWhereN] = stoi(A[i].number);
					//cout << ArrWhere[ArrWhereN] << endl; //всё отлично работает
					arrWhereN++;
				}
			if (arrWhereN == 1) //если машина одна, то
			{
				aWhat = A[arrWhere[0]].type; //найден ответ на вопрос "Что?"
				qWhat = 0; //дальнейший опрос не требуется
				lastChosenGadget = arrWhere[0]; //номер устр-ва
				dateDialog(qWhere, aWhere, qWhat, aWhat, qWhen, aWhen);
				hoursDialog(A, lastChosenGadget, aWhen);
				return 1;
			}
			else
			{
				while (qWhat == 17)
				{
					string What[3]{ "КП","ВД","ОС" }; //массив со всеми типами
					system("cls");
					cout << "Выбрано:'" << aWhere << "' " << endl;
					cout << "Что было сделано?" << endl;
					cout << "0 - Назад" << endl;
					bool flagKP = 0;
					bool flagVD = 0;
					bool flagOS = 0;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == What[0])	flagKP = 1;
					if (flagKP == 1) cout << "1 - Компрессор" << endl;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == What[1])	flagVD = 1;
					if (flagVD == 1) cout << "2 - Воздуходувка" << endl;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == What[2])	flagOS = 1;
					if (flagOS == 1) cout << "3 - Осушитель" << endl;
					if ((flagKP + flagVD + flagOS) == 1) //если в списке только один из типов
					{
						if ((flagKP == 1) && (flagVD == 0) && (flagOS == 0)) aWhat = "КП";
						if ((flagKP == 0) && (flagVD == 1) && (flagOS == 0)) aWhat = "ВД";
						if ((flagKP == 0) && (flagVD == 0) && (flagOS == 1)) aWhat = "ОС";
					}
					else
					{
						cin >> qWhat;
						if (qWhat == 0) //назад
						{
							qWhat = 0;
							qWhere = 17;
							system("cls");
						}
						if (qWhat == 1) aWhat = "КП";
						if (qWhat == 2) aWhat = "ВД";
						if (qWhat == 3) aWhat = "ОС";
					}
					int* arrWhat = new int[arrWhereN] {0}; //массив устр-в с подходящим местоположением
					int arrWhatN = 0; //их кол-во
					for (int i = 0; i < arrWhereN; i++)
						if (A[arrWhere[i]].type == aWhat)
						{
							arrWhat[arrWhatN] = stoi(A[arrWhere[i]].number);
							//cout << ArrWhat[ArrWhatN] << endl; //всё отлично работает
							arrWhatN++;
						}
					lastChosenGadget = winGadget(A, arrWhat, arrWhatN);
					dateDialog(qWhere, aWhere, qWhat, aWhat, qWhen, aWhen);
					hoursDialog(A, lastChosenGadget, aWhen);
					return 1;
				}
			}
		}
	}
	return 1;
}
