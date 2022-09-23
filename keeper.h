#pragma once
#include "Publication.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantasist.h"
class Keeper
{
public:
	// ����������� ��� ����������
	Keeper();
	// ����������� � ����������� (������ ����������)
	Keeper(int size);
	// ����������� �����������
	Keeper(const Keeper& keeper);
	// ����������
	~Keeper();
	// ���������� ���������� � ����
	void saveToFile();
	// ������� ��������� �� �����
	void extractFromFile();
	// ����� ���������� �� ����� (���������� ��������� ������ <<)
	friend std::ostream& operator<< (std::ostream& out, const Keeper& keeper);
	// ���������� �������� � ����� ����������
	void addObject(Publication& publication);
	// �������� �������� � ����� ����������
	void removeObject();
	// ��������� �������� �� �������
	void change(int index);
private:
	int size; // ������ ����������
	int index; // ���������� ��������� � ����������
	Publication** conteiner; // ��������� (������ ���������� �� ������� �����)
};
