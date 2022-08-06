/*
//формирование динамического массива с номерами гаджетов, подходящих описанию:
int* chosenGadget = new int[n] {0}; //массив выбранных устройств
int chosenGadgetN = 0; //количество выбраных
for (int i = 0; i < n; i++)
	if ((A[i].type == aWhat) && (A[i].place == aWhere))
	{
		chosenGadget[chosenGadgetN] = stoi(A[i].number);
		chosenGadgetN++;
	}
//окончательный выбор редактируемого гаджета:
//lastChosenGadget = winGadget(A, chosenGadget, chosenGadgetN);
//if (lastChosenGadget == 0) return 0;
delete[] chosenGadget;
*/

/*
//функция определяет значения входящих переменных.
int findDialog(gadget*& A, int& n, int& qWhat, int& qWhere, int& qWhereFirst, string& aWhat, string& aWhere, int& lastChosenGadget, int& findMode)
{
	//мод 1 - Первый запуск с возможностью вернуть 4
	//мод 2 - Запуск без возврата 4
	//мод 3 - Поиск по серийному номеру
	//функция возвращает:
	//0 - если машин не нашлось
	//1 - если успешно найдена одна машина
	qWhat = 17; //разрешение на опрос
	while (qWhat == 17)
	{
		cout << "Что было сделано?" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "1 - Компрессор" << endl;
		cout << "2 - Воздуходувка" << endl;
		cout << "3 - Осушитель" << endl;
		if (findMode == 1) cout << "4 - Ничего, я тут по другому вопросу." << endl;
		cin >> qWhat;
		switch (qWhat)
		{
		case 0:
			exit(0); //выйти из программы
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
		case 4:
			if (findMode == 1) return 4;
			else cout << "Введите число от 0 до 3!" << endl;
			break;
		default:
			qWhat = 17;
			system("cls");
			cout << "Введите число от 0 до 3!" << endl;
			break;
		}
		if ((qWhat > 0) && (qWhat <= 3)) //разрешение и переход на следующий цикл
		{
			qWhere = 17;
			system("cls");
		}
		while (qWhere == 17)
		{
			cout << "Выбрано:'" << aWhat << "' " << endl;
			cout << "Где находится? (Пешая доступность)" << endl;
			cout << "0 - Назад" << endl;
			cout << "1 - 1-я, 2-я или 3-я очередь" << endl; //доп ветка
			cout << "2 - ДОФ" << endl;
			cout << "3 - Шихта" << endl;
			cout << "4 - Готовая продукция" << endl; //доп ветка
			cout << "5 - Перегрузка" << endl;
			cout << "6 - Пульпанасосная" << endl;
			cout << "7 - Сгущение" << endl; //доп ветка
			cout << "8 - Станция Комбинатская" << endl;
			cout << "9 - Другое" << endl;
			cin >> qWhere;
			switch (qWhere)
			{
			case 0:
				qWhat = 17;
				qWhere = 0;
				system("cls");
				break;
			case 1:
				qWhereFirst = 17;
				while (qWhereFirst == 17)
				{
					system("cls");
					cout << "Выбрано:'" << aWhat << "' " << endl;
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
						qWhere = 0;
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
					cout << "Выбрано:'" << aWhat << "' " << endl;
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
						qWhere = 0;
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
					cout << "Выбрано:'" << aWhat << "' " << endl;
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
						qWhere = 0;
					}
				}
				break;
			case 8:
				aWhere = "Комб-ая";
				break;
			case 9:
				aWhere = "Ещё не готово :с";
				break;
			default:
				system("cls");
				qWhere = 17;
				cout << "Введите число от 0 до 9!" << endl;
				break;
			}
		}
	}
	//формирование динамического массива с номерами гаджетов, подходящих описанию:
	int* chosenGadget = new int[n] {0}; //массив выбранных устройств
	int chosenGadgetN = 0; //количество выбраных
	int i, j; //счётчики
	j = 0;
	for (i = 0; i < n; i++)
		if ((A[i].type == aWhat) && (A[i].place == aWhere))
		{
			chosenGadget[j] = stoi(A[i].number);
			j++;
			chosenGadgetN++;
		}
	//окончательный выбор редактируемого гаджета:
	lastChosenGadget = winGadget(A, chosenGadget, chosenGadgetN);
	if (lastChosenGadget == 0) return 0;
	delete[] chosenGadget;
	return 1;
}
*/
