#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// Базовый абстрактный класс
class Publication
{
public:
	// Конструктор без параметров
	Publication();
	// Конструктор с параметрами (ФИО, года рождения и смерти, некоротые работы)
	Publication(string fio, int yearOfBird, int yearOfDeath, vector<string> works);
	// Конструктор копирования
	Publication(const Publication& publication);
	// Деструктор
	virtual ~Publication();
	// Установление ФИО
	void setFio(string fio);
	// Извлечение ФИО
	string getFio();
	// Установление года рождения и года смерти
	void setYears(int yearOfBird, int yearOfDeath);
	// Извлечение года рождения и года смерти
	string getYears();
	// Установление основных работ
	void setWorks(vector<string> works);
	// Извлечение основных работ
	vector<string> getWorks();
	// Виртуальная функция для вывода объектов
	virtual string out() = 0;
	// Виртуальная функция для изменения объектов дочерних классов
	virtual void change() = 0;
	// Изменение элементов базового класса (1 - ФИО, 2 - года, 3 - основные произведения)
	void changeBase(int choice);
protected:
	string fio; // ФИО
	int yearOfBird; // Год рождения
	int yearOfDeath; // Год смерти
	vector<string> works; // Основные произведения
};