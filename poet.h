#pragma once
#include "Publication.h"
class Poet : public Publication
{
public:
	// Конструктор без параметров
	Poet();
	// Конструктор с параметрами (ФИО, года рождения и смерти, некоротые работы, количество псевдонимов)
	Poet(string fio, int yearOfBird, int yearOfDeath, vector<string> works, int
		aliases);
	// Конструктор копирования
	Poet(const Poet& poet);
	// Деструктор
	~Poet();
	// Установление количества псевдонимов
	void setAliases(int aliases);
	// Извлечение количества псевдонимов
	int getAliases();
	// Вывод в консоль
	string out();
	// Изменение объекта класса
	void change();
private:
	int aliases; // Количество псевдонимов
};
