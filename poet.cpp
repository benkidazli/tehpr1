#include "Poet.h"
Poet::Poet() : Publication() {
	aliases = 0;
	cout << "\t\t����� Poet: ����������� ��� ����������" << endl;
}
Poet::Poet(string fio, int yearOfBird, int yearOfDeath, vector<string> works, int
	aliases) :
	Publication(fio, yearOfBird, yearOfDeath, works) {
	setAliases(aliases);
	cout << "\t\t����� Poet: ����������� � �����������" << endl;
}
Poet::Poet(const Poet& poet) {
	setFio(poet.fio);
	setYears(poet.yearOfBird, poet.yearOfDeath);
	setWorks(poet.works);
	setAliases(poet.aliases);
	cout << "\t\t����� Poet: ����������� �����������" << endl;
}
Poet::~Poet() {
	aliases = 0;
	cout << "\t\t����� Poet: ����������" << endl;
}
void Poet::setAliases(int aliases) {
	if (aliases < 0)
		throw exception("�������� ���������� �����������");
	this->aliases = aliases;
}
int Poet::getAliases() { return aliases; }
string Poet::out() {
	string buf;
	buf = "���� - " + fio + " (" + getYears() + "); " + "\n\t����������: " +
		to_string(aliases) +
		"\n" + "\t�������� ������������: " + to_string(works.size()) + "\n";
	for (int i = 0; i < works.size(); i++)
		buf = buf + "\t\t" + to_string(i + 1) + ": " + "\"" + works[i] + "\"" +
		"\n";
	return buf;
	/*cout << "���� - ";
	cout << fio << " (" << getYears() << "); " << "����������: " << aliases << endl;
	cout << "\t�������� ������������: " << endl;
	for (int i = 0; i < works.size(); i++)
	cout << "\t\t" << i + 1 << ": " << "\"" << works[i] << "\"" << endl;*/
}
void Poet::change() {
	int choice;
	out();
	cout << "��������� �����: " <<
		"\n\t1) ���" <<
		"\n\t2) ����" <<
		"\n\t3) ��������� ������" <<
		"\n\t4) ���������� �����������" << endl << "����� ��� ���������: ";
	cin >> choice;
	if (choice >= 1 && choice <= 3)
		changeBase(choice);
	else if (choice == 4)
	{
		int buf;
		cout << "������� ����� ���������� �����������: ";
		cin >> buf;
		setAliases(buf);
	}
	else
		throw exception("�������� ����� ��� ��������� �����");
}