#pragma once
#include "Publication.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantasist.h"
class Keeper
{
public:
	// Конструктор без параметров
	Keeper();
	// Конструктор с параметрами (размер контейнера)
	Keeper(int size);
	// Конструктор копирования
	Keeper(const Keeper& keeper);
	// Деструктор
	~Keeper();
	// Сохранение контейнера в файл
	void saveToFile();
	// Извлечь контейнер из файла
	void extractFromFile();
	// Вывод контейнера на экран (перегрузка оператора вывода <<)
	friend std::ostream& operator<< (std::ostream& out, const Keeper& keeper);
	// Добавление элемента в конец контейнера
	void addObject(Publication& publication);
	// Удаление элемента с конца контейнера
	void removeObject();
	// Изменение элемента по индексу
	void change(int index);
private:
	int size; // Размер контейнера
	int index; // Количество элементов в контейнере
	Publication** conteiner; // Контейнер (массив указателей на базовый класс)
};
