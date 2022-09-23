#include "Publication.h"
Publication::Publication() {
	fio = "";
	yearOfBird = 0;
	yearOfDeath = 0;
	cout << "\t\tКласс Publication: конструктор без параметров" << endl;
}
Publication::Publication(string fio, int yearOfBird, int yearOfDeath, vector<string>
	works)
{
	setFio(fio);
	setYears(yearOfBird, yearOfDeath);
	setWorks(works);
	cout << "\t\tКласс Publication: конструктор с параметрами" << endl;
}
Publication::Publication(const Publication& publication) {
	setFio(publication.fio);
	setYears(publication.yearOfBird, publication.yearOfDeath);
	setWorks(publication.works);
	cout << "\t\tКласс Publication: конструктор копирования" << endl;
}
Publication::~Publication() {
	fio = "";
	yearOfBird = 0;
	yearOfDeath = 0;
	int cnt = works.size();
	for (int i = 0; i < cnt; i++)
		works.pop_back();
	cout << "\t\tКласс Publication: деструктор" << endl;
}
void Publication::setFio(string fio) {
	this->fio = fio;
}
string Publication::getFio() { return fio; }
void Publication::setYears(int yearOfBird, int yearOfDeath) {
	if (yearOfBird < 1000 || yearOfDeath < 1000 || yearOfBird > 2021 || yearOfDeath >
		2021 || yearOfBird >= yearOfDeath)
		throw exception("Неверные года");
	this->yearOfBird = yearOfBird;
	this->yearOfDeath = yearOfDeath;
}
string Publication::getYears() {
	return (to_string(yearOfBird) + "-" +
		to_string(yearOfDeath));
}
void Publication::setWorks(vector<string> works) { this->works = works; }
vector<string> Publication::getWorks() { return works; }
void Publication::changeBase(int choice) {
	if (choice == 1) {
		string buf;
		cout << "Введите новое ФИО: ";
		cin >> buf;
		setFio(buf);
	}
	else if (choice == 2) {
		int buf1, buf2;
		cout << "Введите год рождения: ";
		cin >> buf1;
		cout << "Введите год смерти: ";
		cin >> buf2;
		setYears(buf1, buf2);
	}
	else if (choice == 3) {
		int cnt;
		string buf;
		cout << "Введите номер произведения от " << 1 << "до " << works.size() <<
			":";
		cin >> cnt;
		cout << "Введите новое произведение: ";
		cin >> buf;
		works[cnt - 1] = buf;
	}
	else {
		throw exception("Неверный параметр для изменения базового класса");
	}
}