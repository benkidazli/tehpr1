#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// ������� ����������� �����
class Publication
{
public:
	// ����������� ��� ����������
	Publication();
	// ����������� � ����������� (���, ���� �������� � ������, ��������� ������)
	Publication(string fio, int yearOfBird, int yearOfDeath, vector<string> works);
	// ����������� �����������
	Publication(const Publication& publication);
	// ����������
	virtual ~Publication();
	// ������������ ���
	void setFio(string fio);
	// ���������� ���
	string getFio();
	// ������������ ���� �������� � ���� ������
	void setYears(int yearOfBird, int yearOfDeath);
	// ���������� ���� �������� � ���� ������
	string getYears();
	// ������������ �������� �����
	void setWorks(vector<string> works);
	// ���������� �������� �����
	vector<string> getWorks();
	// ����������� ������� ��� ������ ��������
	virtual string out() = 0;
	// ����������� ������� ��� ��������� �������� �������� �������
	virtual void change() = 0;
	// ��������� ��������� �������� ������ (1 - ���, 2 - ����, 3 - �������� ������������)
	void changeBase(int choice);
protected:
	string fio; // ���
	int yearOfBird; // ��� ��������
	int yearOfDeath; // ��� ������
	vector<string> works; // �������� ������������
};