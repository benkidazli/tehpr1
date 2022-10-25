#include "Novelist.h"
Novelist::Novelist() : Publication() {
	biography = "";
	cout << "\t\tКласс Novelist: конструктор без параметров" << endl;
}
Novelist::Novelist(string fio, int yearOfBird, int yearOfDeath, vector<string> works,
	string biography) :
	Publication(fio, yearOfBird, yearOfDeath, works) {
	setBiography(biography);
	cout << "\t\tКласс Novelist: конструктор с параметрами" << endl;
}
Novelist::Novelist(const Novelist& novelist) {
	setFio(novelist.fio);
	setYears(novelist.yearOfBird, novelist.yearOfDeath);
	setWorks(novelist.works);
	setBiography(novelist.biography);
	cout << "\t\tКласс Novelist: конструктор копирования" << endl;
}
Novelist::~Novelist() {
	biography = "";
	cout << "\t\tКласс Novelist: деструктор" << endl;
}
void Novelist::setBiography(string biography) { this->biography = biography; }
string Novelist::getBiography() { return biography; }
string Novelist::out() {
	string buf;
	buf = "Романист - " + fio + " (" + getYears() + "); " + "\n\tБиография: " +
		biography
		+
		"\n" + "\tОсновные произведения: " + to_string(works.size()) + "\n";
	for (int i = 0; i < works.size(); i++)
		buf = buf + "\t\t" + to_string(i + 1) + ": " + "\"" + works[i] + "\"" +
		"\n";
	return buf;

}
void Novelist::change() {
	int choice;
	out();
	cout << "Изменение романиста: " <<
		"\n\t1) ФИО" <<
		"\n\t2) Года" <<
		"\n\t3) Известные работы" <<
		"\n\t4) Биография" << endl << "Пункт для изменение: ";
	cin >> choice;
	if (choice >= 1 && choice <= 3)
		changeBase(choice);
	else if (choice == 4)
	{
		string buf;
		cout << "Введите новую биографию: ";
		cin >> buf;
		setBiography(buf);
	}
	else
		throw exception("Неверный пункт при изменении романиста");
}
