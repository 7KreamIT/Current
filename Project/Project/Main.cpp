#include "Header.h"	//подключение заголовка

const string fileNameXlsx = "Test.xlsx"; //имя файла Xlsx для ввода
const string fileNameCsv = "Справка.csv"; //имя файла Csv для ввода
const string fileNameOutCsv = "Справка-Out.csv"; //имя файла Csv для вывода

int main()
{
	setlocale(LC_ALL, "Russian");		  //настройка консоли
	SetConsoleCP(1251);					  //..
	SetConsoleOutputCP(1251);			  //..
	system("mode con cols=100 lines=20"); //..

	int aN = 0;//кол-во строк
	gadget* A; //основной массив устройств

	A = getByXlsx(aN, fileNameXlsx); //если библиотека подключилась
	//A = getByCsv(aN, fileNameCsv); //если библиотека НЕ подключилась
	
	//опрос Что? Где? Когда?: 
	string aWhere;        //ответ:  Где?
	string aWhat;         //ответ:  Что?
	string aWhen;		  //ответ: Когда?
	int lastChosenGadget; //окончательный номер выбранного устройства
	int findMode = 1;	  //вариант работы функции findDialog
	findDialog(A, aN, aWhere, aWhat, aWhen, lastChosenGadget, findMode);

	setToCsv(A, aN, fileNameOutCsv); //вывод в файл csv

	delete[] A; //отчистить память
	exitProgram();
	return 1;
}

//функция ввода времени ТО:
int dateDialog(string& aWhere, string& aWhat, string& aWhen, string lastChosenGadgetModel)
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
					else tempDay = 28;
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
					cout << "Введите дату с левыми нулями, пожалуйста! \nНапример, так: 010407" << endl; //ошибка
				}
				else
				{
					int aWhenInt = stoi(aWhen);
					if (aWhenInt < 9999) //ошибка в вводе (день не может быть = 00)
					{
						cout << "День = 00!" << endl;
						i = 1;
					}
					else
					{
						if ((aWhenInt % 10000) < 99) //ошибка в вводе (месяц не может быть = 00)
						{
							cout << "Месяц = 00!" << endl;
							i = 1;
						}
						else
						{
							if ((aWhenInt % 10000 / 100) == 2) //если месяц вдруг - февраль, то..
							{
								int dayInFeb; //кол-во дней в феврале
								if ((aWhenInt % 100) % 4 == 0) dayInFeb = 29; //если год високосный, то..
								else dayInFeb = 28;
								if ((aWhenInt / 10000) > dayInFeb) i = 1;
								else i = 0; //данные введены корректно
							}
							else
							{
								int currentMonth; //какой месяц? (для массива дней)
								currentMonth = (aWhenInt % 10000 / 100) - 1;
								if (currentMonth > 11) i = 1; //ошибка если месяц оказался больше 12-го
								else
								{
									if ((aWhenInt / 10000) > monthSize[currentMonth]) i = 1;
									else i = 0; //данные введены корректно
								}
							}
							//aWhenInt = aWhenInt % 100; //достать год
							//aWhenInt = aWhenInt % 10000 /100; //достать месяц
							//aWhenInt = aWhenInt / 10000; //достать день
						}
					}
				}
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
	//мод 2 - ??
	//функция возвращает:
	//0 - если ??
	//1 - если ??
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
			}
			else
			{
				system("cls");
				qWhat = 17; //разрешение на опрос
				while (qWhat == 17)
				{
					string what[3]{ "КП","ВД","ОС" }; //массив со всеми типами
					cout << "Выбрано:'" << aWhere << "' " << endl;
					cout << "Что было сделано?" << endl;
					cout << "0 - Назад" << endl;

					bool flagKP = 0;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == what[0])	flagKP = 1;
					if (flagKP == 1) cout << "1 - Компрессор" << endl;

					bool flagVD = 0;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == what[1])	flagVD = 1;
					if (flagVD == 1) cout << "2 - Воздуходувка" << endl;

					bool flagOS = 0;
					for (int i = 0; i < arrWhereN; i++) if (A[arrWhere[i]].type == what[2])	flagOS = 1;
					if (flagOS == 1) cout << "3 - Осушитель" << endl;

					if ((flagKP + flagVD + flagOS) == 1) //если в списке только один из типов
					{
						if ((flagKP == 1) && (flagVD == 0) && (flagOS == 0))
						{
							aWhat = "КП";
							qWhat = 0; //конец опроса
						}
						if ((flagKP == 0) && (flagVD == 1) && (flagOS == 0))
						{
							aWhat = "ВД";
							qWhat = 0; //конец опроса
						}
							
						if ((flagKP == 0) && (flagVD == 0) && (flagOS == 1))
						{
							aWhat = "ОС";
							qWhat = 0; //конец опроса
						}
						int* arrWhat = new int[arrWhereN] {0}; //массив устр-в с подходящим местоположением
						int arrWhatN = 0; //их кол-во
						for (int i = 0; i < arrWhereN; i++)
							if (A[arrWhere[i]].type == aWhat)
								arrWhat[arrWhatN++] = stoi(A[arrWhere[i]].number);
						system("cls");
						cout << "Выбрано:'" << aWhat
							 << "' на '" << aWhere
							 << "'" << endl;
						lastChosenGadget = winGadget(A, arrWhat, arrWhatN);
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
						if (qWhat == 1)
						{
							aWhat = "КП";
						}
						if (qWhat == 2)
						{
							aWhat = "ВД";
						}
						if (qWhat == 3)
						{
							aWhat = "ОС";							
						}
						//обработка ошибочного ввода:
						if ((qWhat == 1) && (flagKP == 0) ||
							(qWhat == 2) && (flagVD == 0) ||
							(qWhat == 3) && (flagOS == 0) || 
							(qWhat < 0 ) || (qWhat > 3))
						{
							system("cls");
							cout << "Вы выбрали число, которого нет в списке!" << endl;
							qWhat = 17; //опрос заново
						}
						if ((qWhat == 1) && (flagKP == 1) ||
							(qWhat == 2) && (flagVD == 1) ||
							(qWhat == 3) && (flagOS == 1))
						{
							int* arrWhat = new int[arrWhereN] {0}; //массив устр-в с подходящим местоположением
							int arrWhatN = 0; //их кол-во
							for (int i = 0; i < arrWhereN; i++)
								if (A[arrWhere[i]].type == aWhat)
									arrWhat[arrWhatN++] = stoi(A[arrWhere[i]].number);
							system("cls");
							cout << "Выбрано:'" << aWhat
								 << "' на '" << aWhere
								 << "'" << endl;
							lastChosenGadget = winGadget(A, arrWhat, arrWhatN);
						}
					}
				}
			}
			if (qWhere != 17)
			{
				dateDialog(aWhere, aWhat, aWhen, A[lastChosenGadget].model);
				hoursDialog(A, lastChosenGadget, aWhen);
				return 1;
			}
		}
	}
}