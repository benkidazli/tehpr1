#include "Poet.h"
Poet::Poet() : Publication() {
	aliases = 0;
	cout << "\t\tКласс Poet: конструктор без параметров" << endl;
}
Poet::Poet(string fio, int yearOfBird, int yearOfDeath, vector<string> works, int
	aliases) :
	Publication(fio, yearOfBird, yearOfDeath, works) {
	setAliases(aliases);
	cout << "\t\tКласс Poet: конструктор с параметрами" << endl;
}
Poet::Poet(const Poet& poet) {
	setFio(poet.fio);
	setYears(poet.yearOfBird, poet.yearOfDeath);
	setWorks(poet.works);
	setAliases(poet.aliases);
	cout << "\t\tКласс Poet: конструктор копирования" << endl;
}
Poet::~Poet() {
	aliases = 0;
	cout << "\t\tКласс Poet: деструктор" << endl;
}
void Poet::setAliases(int aliases) {
	if (aliases < 0)
		throw exception("Неверное количество псевдонимов");
	this->aliases = aliases;
}
int Poet::getAliases() { return aliases; }
string Poet::out() {
	string buf;
	buf = "Поэт - " + fio + " (" + getYears() + "); " + "\n\tПсевдонимы: " +
		to_string(aliases) +
		"\n" + "\tОсновные произведения: " + to_string(works.size()) + "\n";
	for (int i = 0; i < works.size(); i++)
		buf = buf + "\t\t" + to_string(i + 1) + ": " + "\"" + works[i] + "\"" +
		"\n";
	return buf;
	/*cout << "Поэт - ";
	cout << fio << " (" << getYears() << "); " << "Псевдонимы: " << aliases << endl;
	cout << "\tОсновные произведения: " << endl;
	for (int i = 0; i < works.size(); i++)
	cout << "\t\t" << i + 1 << ": " << "\"" << works[i] << "\"" << endl;*/
}
void Poet::change() {
	int choice;
	out();
	cout << "Изменение поэта: " <<
		"\n\t1) ФИО" <<
		"\n\t2) Года" <<
		"\n\t3) Известные работы" <<
		"\n\t4) Количество псевдонимов" << endl << "Пункт для изменение: ";
	cin >> choice;
	if (choice >= 1 && choice <= 3)
		changeBase(choice);
	else if (choice == 4)
	{
		int buf;
		cout << "Введите новое количество псевдонимов: ";
		cin >> buf;
		setAliases(buf);
	}
	else
		throw exception("Неверный пункт при изменении поэта");
}