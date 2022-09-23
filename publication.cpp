#include "Publication.h"
Publication::Publication() {
	fio = "";
	yearOfBird = 0;
	yearOfDeath = 0;
	cout << "\t\t����� Publication: ����������� ��� ����������" << endl;
}
Publication::Publication(string fio, int yearOfBird, int yearOfDeath, vector<string>
	works)
{
	setFio(fio);
	setYears(yearOfBird, yearOfDeath);
	setWorks(works);
	cout << "\t\t����� Publication: ����������� � �����������" << endl;
}
Publication::Publication(const Publication& publication) {
	setFio(publication.fio);
	setYears(publication.yearOfBird, publication.yearOfDeath);
	setWorks(publication.works);
	cout << "\t\t����� Publication: ����������� �����������" << endl;
}
Publication::~Publication() {
	fio = "";
	yearOfBird = 0;
	yearOfDeath = 0;
	int cnt = works.size();
	for (int i = 0; i < cnt; i++)
		works.pop_back();
	cout << "\t\t����� Publication: ����������" << endl;
}
void Publication::setFio(string fio) {
	this->fio = fio;
}
string Publication::getFio() { return fio; }
void Publication::setYears(int yearOfBird, int yearOfDeath) {
	if (yearOfBird < 1000 || yearOfDeath < 1000 || yearOfBird > 2021 || yearOfDeath >
		2021 || yearOfBird >= yearOfDeath)
		throw exception("�������� ����");
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
		cout << "������� ����� ���: ";
		cin >> buf;
		setFio(buf);
	}
	else if (choice == 2) {
		int buf1, buf2;
		cout << "������� ��� ��������: ";
		cin >> buf1;
		cout << "������� ��� ������: ";
		cin >> buf2;
		setYears(buf1, buf2);
	}
	else if (choice == 3) {
		int cnt;
		string buf;
		cout << "������� ����� ������������ �� " << 1 << "�� " << works.size() <<
			":";
		cin >> cnt;
		cout << "������� ����� ������������: ";
		cin >> buf;
		works[cnt - 1] = buf;
	}
	else {
		throw exception("�������� �������� ��� ��������� �������� ������");
	}
}