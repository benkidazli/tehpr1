#include "Novelist.h"
Novelist::Novelist() : Publication() {
	biography = "";
	cout << "\t\t����� Novelist: ����������� ��� ����������" << endl;
}
Novelist::Novelist(string fio, int yearOfBird, int yearOfDeath, vector<string> works,
	string biography) :
	Publication(fio, yearOfBird, yearOfDeath, works) {
	setBiography(biography);
	cout << "\t\t����� Novelist: ����������� � �����������" << endl;
}
Novelist::Novelist(const Novelist& novelist) {
	setFio(novelist.fio);
	setYears(novelist.yearOfBird, novelist.yearOfDeath);
	setWorks(novelist.works);
	setBiography(novelist.biography);
	cout << "\t\t����� Novelist: ����������� �����������" << endl;
}
Novelist::~Novelist() {
	biography = "";
	cout << "\t\t����� Novelist: ����������" << endl;
}
void Novelist::setBiography(string biography) { this->biography = biography; }
string Novelist::getBiography() { return biography; }
string Novelist::out() {
	string buf;
	buf = "�������� - " + fio + " (" + getYears() + "); " + "\n\t���������: " +
		biography
		+
		"\n" + "\t�������� ������������: " + to_string(works.size()) + "\n";
	for (int i = 0; i < works.size(); i++)
		buf = buf + "\t\t" + to_string(i + 1) + ": " + "\"" + works[i] + "\"" +
		"\n";
	return buf;

}
void Novelist::change() {
	int choice;
	out();
	cout << "��������� ���������: " <<
		"\n\t1) ���" <<
		"\n\t2) ����" <<
		"\n\t3) ��������� ������" <<
		"\n\t4) ���������" << endl << "����� ��� ���������: ";
	cin >> choice;
	if (choice >= 1 && choice <= 3)
		changeBase(choice);
	else if (choice == 4)
	{
		string buf;
		cout << "������� ����� ���������: ";
		cin >> buf;
		setBiography(buf);
	}
	else
		throw exception("�������� ����� ��� ��������� ���������");
}
