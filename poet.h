#pragma once
#include "Publication.h"
class Poet : public Publication
{
public:
	// ����������� ��� ����������
	Poet();
	// ����������� � ����������� (���, ���� �������� � ������, ��������� ������, ���������� �����������)
	Poet(string fio, int yearOfBird, int yearOfDeath, vector<string> works, int
		aliases);
	// ����������� �����������
	Poet(const Poet& poet);
	// ����������
	~Poet();
	// ������������ ���������� �����������
	void setAliases(int aliases);
	// ���������� ���������� �����������
	int getAliases();
	// ����� � �������
	string out();
	// ��������� ������� ������
	void change();
private:
	int aliases; // ���������� �����������
};
