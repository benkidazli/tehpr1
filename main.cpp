#include "Keeper.h"
// Функция для добавления объекта в контейнер:
// Добавить поэта: number = 1
// Добавить романиста: number = 2
// Добавить фантаста: number = 3
void add(Keeper& cont, int number);
int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0;
	cout << "Создание контейнера. ";
	while (n <= 0)
	{
		cout << "Введите количество элементов: ";
		cin >> n;
	}
	Keeper cont(n);
	char switch_on = '0';
	while (switch_on != '9')
	{
		system("pause");
		system("cls");
		cout << "Меню:\n\t1) Считать контейнер из файла;" <<
			"\n\t2) Записать контейнер в файл;" <<
			"\n\t3) Вывести контейнер в консоль;" <<
			"\n\t4) Добавить в контейнер поэта;" <<
			"\n\t5) Добавить в контейнер романиста;" <<
			"\n\t6) Добавить в контейнер фантаста;" <<
			"\n\t7) Удалить элемент из контейнера;" <<
			"\n\t8) Изменить элемент контейнера;" <<
			"\n\t9) Выйти из программы;" << endl << "Выбранный пункт: ";
		cin >> switch_on;
		switch (switch_on)
		{
		case '1': // Считывание из файла
			try
			{
				cont.extractFromFile();
			}
			catch (const exception exp) {
				cout << "Исключение: " << exp.what() <<
					endl;
			}
			break;
		case '2': // Запись в файл
			try
			{
				cont.saveToFile();
			}
			catch (const exception exp) {
				cout << "Исключение: " << exp.what() <<
					endl;
			}
			break;
		case '3': // Вывод в консоль
			cout << cont << endl;
			break;
		case '4': // Добавить поэта
			add(cont, 1);
			break;
		case '5': // Добавить романиста
			add(cont, 2);
			break;
		case '6': // Добавить фантаста
			add(cont, 3);
			break;
		case '7': // Удалить элемент
			try
			{
				cont.removeObject();
			}
			catch (const exception exp) {
				cout << "Исключение: " << exp.what() <<
					endl;
			}
			break;
		case '8': // Изменить элемент
			try
			{
				int i;
				cout << "Номер элелента контейнера: ";
				cin >> i;
				cont.change(i - 1);
			}
			catch (const exception exp) {
				cout << "Исключение: " << exp.what() <<
					endl;
			}
			break;
		case '9':
			break;
		default:
			break;
		}
	}
	return 0;
}
void add(Keeper& cont, int number) {
	string name;
	if (number == 1)
		name = "поэта";
	else if (number == 2)
		name = "романиста";
	else if (number == 3)
		name = "фантаста";
	else
		cout << "Ошибка добавления" << endl;
	try
	{
		string bufFio;
		int d1, d2, num;
		vector<string> bufVec;
		cout << "Введите ФИО " << name << ": ";
		cin >> bufFio;
		cout << "Введите год рождения " << name << ": ";
		cin >> d1;
		cout << "Введите год смерти " << name << ": ";
		cin >> d2;
		cout << "Введите количество известных произведений " << name << ": ";
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			string buf;
			cout << "Произведение " << i + 1 << ": ";
			cin >> buf;
			bufVec.push_back(buf);
		}
		Publication* bufPub = nullptr;
		if (number == 1)
		{
			int bufPsevd;
			cout << "Введите количество псевдонимов " << name << ": ";
			cin >> bufPsevd;
			bufPub = new Poet(bufFio, d1, d2, bufVec, bufPsevd);
		}
		else if (number == 2)
		{
			string bufBio;
			cout << "Введите биографию " << name << ": ";
			cin >> bufBio;
			bufPub = new Novelist(bufFio, d1, d2, bufVec, bufBio);
		}
		else if (number == 3)
		{
			bool bufEx;
			cout << "Введите сняты ли фильмы по произведениям " << name << ": ";
			cin >> bufEx;
			bufPub = new Fantasist(bufFio, d1, d2, bufVec, bufEx);
		}
		cont.addObject(*bufPub);
	}
	catch (const exception exp) { cout << "Исключение: " << exp.what() << endl; }
}