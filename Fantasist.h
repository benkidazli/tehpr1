#pragma once
#include "Publication.h"
class Fantasist : public Publication
{
public:
	// Конструктор без параметров
	Fantasist();
	// Конструктор с параметрами (ФИО, года рождения и смерти, некоротые работы, сняты ли фильмы)
	Fantasist(string fio, int yearOfBird, int yearOfDeath, vector<string> works, bool
		filmExists);
	// Конструктор копирования
	Fantasist(const Fantasist& fantasist);
	// Деструктор
	~Fantasist();
	// Установление краткой биографии
	void setFilmExists(bool filmExists);
	// Извлечение краткой биографии
	bool getFilmExists();
	// Вывод в консоль
	string out();
	// Изменение объекта класса
	void change();
private:
	bool filmExists; // Сняты ли фильмы по книгам
};