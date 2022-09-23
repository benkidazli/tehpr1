#pragma once
#include "Publication.h"
class Novelist : public Publication
{
public:
	// ����������� ��� ����������
	Novelist();
	// ����������� � ����������� (���, ���� �������� � ������, ��������� ������, ������� ���������)
	Novelist(string fio, int yearOfBird, int yearOfDeath, vector<string> works, string
		biography);
	// ����������� �����������
	Novelist(const Novelist& novelist);
	// ����������
	~Novelist();
	// ������������ ������� ���������
	void setBiography(string biography);
	// ���������� ������� ���������
	string getBiography();
	// ����� � �������
	string out();
	// ��������� ������� ������
	void change();
private:
	string biography; // ������� ���������
};
