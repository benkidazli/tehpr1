#include "Fantasist.h"
Fantasist::Fantasist() : Publication() {
	filmExists = false;
	cout << "\t\tКласс Fantasist: конструктор без параметров" << endl;
}
Fantasist::Fantasist(string fio, int yearOfBird, int yearOfDeath, vector<string> works,
	bool
	filmExists) : Publication(fio, yearOfBird, yearOfDeath, works) {
	setFilmExists(filmExists);
	cout << "\t\tКласс Fantasist: конструктор с параметрами" << endl;
}
Fantasist::Fantasist(const Fantasist& fantasist) {
	setFio(fantasist.fio);
	setYears(fantasist.yearOfBird, fantasist.yearOfDeath);
	setWorks(fantasist.works);
	setFilmExists(fantasist.filmExists);
	cout << "\t\tКласс Fantasist: конструктор копирования" << endl;
}Fantasist::~Fantasist() {
	filmExists = false;
	cout << "\t\tКласс Fantasist: деструктор" << endl;
}
void Fantasist::setFilmExists(bool filmExists) { this->filmExists = filmExists; }
bool Fantasist::getFilmExists() { return filmExists; }
string Fantasist::out() {
	string buf;
	buf = "Фантаст - " + fio + " (" + getYears() + "); " + "\n\tСняты ли фильмы: " +
		((filmExists) ? "Да" : "Нет") +
		"\n" + "\tОсновные произведения: " + to_string(works.size()) + "\n";
	for (int i = 0; i < works.size(); i++)
		buf = buf + "\t\t" + to_string(i + 1) + ": " + "\"" + works[i] + "\"" +
		"\n";
	return buf;

}
void Fantasist::change() {
	int choice;
	out();
	cout << "Изменение фантаста: " <<
		"\n\t1) ФИО" <<
		"\n\t2) Года" <<
		"\n\t3) Известные работы" <<
		"\n\t4) Сняты ли фильмы" << endl << "Пункт для изменение: ";
	cin >> choice;
	if (choice >= 1 && choice <= 3)
		changeBase(choice);
	else if (choice == 4)
	{
		bool buf;
		cout << "Введите снимали ли фильмы по книгам: ";
		cin >> buf;
		setFilmExists(buf);
	}
	else
		throw exception("Неверный пункт при изменении фантаста");
}