#include "Header.h"	//подключение заголовка

const string fileName = "Справка.csv"; //имя файла для ввода
const string fileNameOut = "Справка-Out.csv"; //имя файла для вывода

int main()
{
	setlocale(LC_ALL, "Russian"); //поддержка Русского языка
	SetConsoleCP(1251);           //..
	SetConsoleOutputCP(1251);     //..
	system("mode con cols=100 lines=20"); //размер консоли
	int i, j; //переменные циклов	
	int aN = numberOfLines(fileName) - 1; //подсчёт фактического кол-ва строк в файле (i - переменная цикла)

	//чтение таблицы:
	ifstream fileRead(fileName); //открытие файла 
	string* gadgetString = new string[aN]; //массив строк файла
	for (i = 0; i < aN; i++) getline(fileRead, gadgetString[i]); //читает всю строку
	fileRead.close(); //закрытие файла

	//заполнение структуры:
	gadget* A = new gadget[aN];
	for (i = 0; i < aN; i++) //нулевая строка это заголовки
	{
		j = 0;
		while (gadgetString[i][j] != ';')  A[i].number		 += gadgetString[i][j++]; j++; //01
		while (gadgetString[i][j] != ';')  A[i].type		 += gadgetString[i][j++]; j++; //02
		while (gadgetString[i][j] != ';')  A[i].model		 += gadgetString[i][j++]; j++; //03
		while (gadgetString[i][j] != ';')  A[i].place		 += gadgetString[i][j++]; j++; //04
		while (gadgetString[i][j] != ';')  A[i].oil			 += gadgetString[i][j++]; j++; //05
		while (gadgetString[i][j] != ';')  A[i].tools		 += gadgetString[i][j++]; j++; //06
		while (gadgetString[i][j] != ';')  A[i].password	 += gadgetString[i][j++]; j++; //07
		while (gadgetString[i][j] != ';')  A[i].qtAF		 += gadgetString[i][j++]; j++; //08
		while (gadgetString[i][j] != ';')  A[i].qtOF		 += gadgetString[i][j++]; j++; //09
		while (gadgetString[i][j] != ';')  A[i].qtOS		 += gadgetString[i][j++]; j++; //10
		while (gadgetString[i][j] != ';')  A[i].qtBelt		 += gadgetString[i][j++]; j++; //11
		while (gadgetString[i][j] != ';')  A[i].info		 += gadgetString[i][j++]; j++; //12
		while (gadgetString[i][j] != ';')  A[i].lastDateTO	 += gadgetString[i][j++]; j++; //13
		while (gadgetString[i][j] != ';')  A[i].lastHoursTO	 += gadgetString[i][j++]; j++; //14
		while (gadgetString[i][j] != ';')  A[i].owner		 += gadgetString[i][j++]; j++; //15
		while (gadgetString[i][j] != ';')  A[i].serialNumber += gadgetString[i][j++]; j++; //16
		while (gadgetString[i][j] != ';')  A[i].AF			 += gadgetString[i][j++]; j++; //17
		while (gadgetString[i][j] != ';')  A[i].OF			 += gadgetString[i][j++]; j++; //18
		while (gadgetString[i][j] != ';')  A[i].OS			 += gadgetString[i][j++]; j++; //19
		while (gadgetString[i][j] != ';')  A[i].Belt		 += gadgetString[i][j++]; j++; //20
										   A[i].SHD		     += gadgetString[i][j++];	   //21 
	}
	delete[] gadgetString; //отчистить массив строк
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 1 блок
	
	//опрос Что? Где? Когда?: 
	string aWhere;        //ответ:  Где?
	string aWhat;         //ответ:  Что?
	string aWhen;		  //ответ: Когда?
	int lastChosenGadget; //окончательный номер выбранного устройства
	int findMode = 1;	  //вариант работы функции findDialog
	findDialog(A, aN, aWhere, aWhat, aWhen, lastChosenGadget, findMode);

	//проверки:
	//cout << lastChosenGadget << " " << aWhat << " " << aWhere << endl;

	//вывод в файл:
	ofstream fileWrite(fileNameOut); //объявим вывод в файл csv
	for (i = 0; i < aN; i++)
	{
		fileWrite << A[i].number		<< ";";  //01
		fileWrite << A[i].type			<< ";";  //02
		fileWrite << A[i].model			<< ";";  //03
		fileWrite << A[i].place			<< ";";  //04
		fileWrite << A[i].oil			<< ";";  //05
		fileWrite << A[i].tools			<< ";";  //06
		fileWrite << A[i].password		<< ";";  //07
		fileWrite << A[i].qtAF			<< ";";  //08
		fileWrite << A[i].qtOF			<< ";";  //09
		fileWrite << A[i].qtOS			<< ";";  //10
		fileWrite << A[i].qtBelt		<< ";";  //11
		fileWrite << A[i].info			<< ";";  //12
		fileWrite << A[i].lastDateTO	<< ";";  //13
		fileWrite << A[i].lastHoursTO	<< ";";  //14
		fileWrite << A[i].owner			<< ";";  //15
		fileWrite << A[i].serialNumber  << ";";  //16
		fileWrite << A[i].AF			<< ";";  //17
		fileWrite << A[i].OF			<< ";";  //18
		fileWrite << A[i].OS			<< ";";  //19
		fileWrite << A[i].Belt			<< ";";  //20
		fileWrite << A[i].SHD			<< endl; //21
	}
	fileWrite.close(); //закрытие файла

	delete[] A; //отчистить память
	exitProgram();
	return 1;
}

//функция ввода времени ТО:
int dateDialog(string& aWhere, string& aWhat, string& aWhen, string& lastChosenGadgetModel)
{
	int tempDay; //временная переменная дня
	int qWhen; //флажочек для циклов времени 
	SYSTEMTIME t;	  //для вывода времени(может в int):
	GetLocalTime(&t); //..
	qWhen = 17; //разрешение даётся автоматически при вызове функции
	while (qWhen == 17)
	{
		system("cls");
		int i;
		cout << "Выбрано:'" << aWhat 
			 << "' на '" << aWhere
			 << "' модели '" << lastChosenGadgetModel
			 << "'" << endl;
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
					cout << "Введите дату с левыми нулями, пожалуйста! \nНапример, так: 010207" << endl; //ошибка
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
	cout << "Выбрано:'" << A[lastChosenGadget].type
		 << "' на '" << A[lastChosenGadget].place
		 << "' модели '" << A[lastChosenGadget].model
		 << "'" << endl
		 << "Введена наработка: " << aHowMuch << endl
		 << "Введена дата: " << aWhen << endl
		 << "Вы уверены что ходите внести изменения? (1-да, 0-нет)" << endl;
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
int findDialog(gadget*& A, int& aN, string& aWhere, string& aWhat, string& aWhen, int& lastChosenGadget, int& findMode)
{
	//мод 1 - Первый запуск с возможностью перехода к настройкам
	//мод 2 - Запуск без возврата 4
	//мод 3 - Поиск по серийному номеру
	//функция возвращает:
	//0 - если возникла какая-нибудь ошибка
	//1 - если успешно найдена одна машина
	int qWhere = 17; //объявление флажочка вопроса "Где?" и разрешение на следующий раздел
	int qWhereFirst = 0; //объявления флажочка для углубленного вопроса "Где?"
	int qWhat = 0; //объявление флажочка вопроса "Что?"
	while (qWhere == 17)
	{
		cout << "Где находится? (Пешая доступность)" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "1 - Очереди: 1-ая(обжиг), 2-ая или 3-я" << endl; //доп ветка
		cout << "2 - ДОФ" << endl;
		cout << "3 - Шихта" << endl;
		cout << "4 - Готовая продукция" << endl; //доп ветка
		cout << "5 - Перегрузка" << endl;
		cout << "6 - Пульпанасосная" << endl;
		cout << "7 - Сгущение" << endl; //доп ветка
		cout << "8 - КСМД" << endl;
		cout << "9 - Станция Комбинатская" << endl; //в будущем будет "Станции" с доп веткой
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
					aWhere = "2 очередь";
					break;
				case 3:
					aWhere = "3 очередь";
					break;
				default:
					qWhereFirst = 17;
					system("cls");
					break;
				}
				if ((qWhereFirst >= 1) && (qWhereFirst <= 3)) //закрытие доп ветки всвязи с получением ответа
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
			aWhere = "Перегрузка";
			break;
		case 6:
			aWhere = "Пульпа-ная";
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
					aWhere = "Сгущение";
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
			aWhere = "КСМД";
			break;
		case 9:
			aWhere = "Комбин-я";
			break;
		default:
			system("cls");
			qWhere = 17;
			cout << "Введите число от 0 до 9!" << endl;
			break;
		}
		if ((qWhere >= 1) && (qWhere <= 9)) //переход на следующий раздел с созданием массива подходящих устр-в
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
				string lastChosenGadgetModel = A[lastChosenGadget].model;
				dateDialog(aWhere, aWhat, aWhen, lastChosenGadgetModel);
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
					string lastChosenGadgetModel = A[lastChosenGadget].model;
					dateDialog(aWhere, aWhat, aWhen, lastChosenGadgetModel);
					hoursDialog(A, lastChosenGadget, aWhen);
					return 1;
				}
			}
		}
	}
	return 1;
}
