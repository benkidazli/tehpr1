#include "Fantasist.h"
Fantasist::Fantasist() : Publication() {
	filmExists = false;
	cout << "\t\t����� Fantasist: ����������� ��� ����������" << endl;
}
Fantasist::Fantasist(string fio, int yearOfBird, int yearOfDeath, vector<string> works,
	bool
	filmExists) : Publication(fio, yearOfBird, yearOfDeath, works) {
	setFilmExists(filmExists);
	cout << "\t\t����� Fantasist: ����������� � �����������" << endl;
}
Fantasist::Fantasist(const Fantasist& fantasist) {
	setFio(fantasist.fio);
	setYears(fantasist.yearOfBird, fantasist.yearOfDeath);
	setWorks(fantasist.works);
	setFilmExists(fantasist.filmExists);
	cout << "\t\t����� Fantasist: ����������� �����������" << endl;
}Fantasist::~Fantasist() {
	filmExists = false;
	cout << "\t\t����� Fantasist: ����������" << endl;
}
void Fantasist::setFilmExists(bool filmExists) { this->filmExists = filmExists; }
bool Fantasist::getFilmExists() { return filmExists; }
string Fantasist::out() {
	string buf;
	buf = "������� - " + fio + " (" + getYears() + "); " + "\n\t����� �� ������: " +
		((filmExists) ? "��" : "���") +
		"\n" + "\t�������� ������������: " + to_string(works.size()) + "\n";
	for (int i = 0; i < works.size(); i++)
		buf = buf + "\t\t" + to_string(i + 1) + ": " + "\"" + works[i] + "\"" +
		"\n";
	return buf;

}
void Fantasist::change() {
	int choice;
	out();
	cout << "��������� ��������: " <<
		"\n\t1) ���" <<
		"\n\t2) ����" <<
		"\n\t3) ��������� ������" <<
		"\n\t4) ����� �� ������" << endl << "����� ��� ���������: ";
	cin >> choice;
	if (choice >= 1 && choice <= 3)
		changeBase(choice);
	else if (choice == 4)
	{
		bool buf;
		cout << "������� ������� �� ������ �� ������: ";
		cin >> buf;
		setFilmExists(buf);
	}
	else
		throw exception("�������� ����� ��� ��������� ��������");
}