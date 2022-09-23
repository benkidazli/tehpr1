#include "Keeper.h"
#include <fstream>
#include <stdlib.h>
Keeper::Keeper() {
	size = 0;
	index = 0;
	conteiner = nullptr;
	cout << "\t\tКласс Keeper: конструктор без параметров" << endl;
}
Keeper::Keeper(int size) {
	if (size <= 0)
		throw exception("Количество элементов контейнера не верно");
	this->size = size;
	conteiner = new Publication * [size];
	index = 0;
	cout << "\t\tКласс Keeper: конструктор с параметрами" << endl;
}
Keeper::Keeper(const Keeper& keeper) {
	size = keeper.size;
	for (int i = 0; i < keeper.index; i++)
		addObject(*keeper.conteiner[i]);
	cout << "\t\tКласс Keeper: конструктор копирования" << endl;
}
Keeper::~Keeper() {
	int cnt = index;
	for (int i = 0; i < cnt; i++)
		removeObject();
	size = 0;
	index = 0;
	conteiner = nullptr;
	cout << "\t\tКласс Keeper: деструктор" << endl;
}
void Keeper::saveToFile() {
	ofstream fout;
	fout.open("file.txt");
	if (fout.is_open())
	{
		fout << index << "\n";
		for (int i = 0; i < index; i++)
			fout << conteiner[i]->out();
	}
	else
		throw exception("Ошибка при записи в файл");
	fout.close();
}
void Keeper::extractFromFile() {
	string strBuf;
	int intBuf;
	Publication* pubBuf = nullptr;
	ifstream fin;
	fin.open("file.txt");
	if (fin.is_open())
	{
		fin >> intBuf;
		if (intBuf > size - index)
		{
			fin.close();
			throw exception("Неподходящее количество элементов в контейнере");
		}
		for (int i = 0; i < intBuf; i++)
		{
			fin >> strBuf;
			if (strBuf != "Поэт" && strBuf != "Романист" && strBuf != "Фантаст")
				throw exception("Некорректная запись в файл");
			string fio;
			fin >> fio >> fio;
			string data;
			fin >> data;
			string date1, date2;
			for (int j = 1; j <= 4; j++)
				date1 += data[j];
			for (int j = 6; j <= 9; j++)
				date2 += data[j];
			int nick;
			string bio;
			bool exs;
			if (strBuf == "Поэт")
			{
				fin >> data >> nick;
			}
			else if (strBuf == "Романист")
			{
				fin >> data >> bio;
			}
			else if (strBuf == "Фантаст")
			{
				fin >> data >> data >> data >> data;
				if (data == "Нет")
					exs = false;
				else if (data == "Да")
					exs = true;
				else
					throw exception("Некорректная запись в файл");
			}
			vector<string> vecBuf;
			int s;
			fin >> data >> data >> s;
			for (int j = 0; j < s; j++)
			{
				fin >> data >> data;
				data.erase(0, 1);
				data.erase(data.size() - 1, 1);
				vecBuf.push_back(data);
			}
			if (strBuf == "Поэт")
			{
				pubBuf = new Poet(fio, stoi(date1), stoi(date2), vecBuf,
					nick);
			}
			else if (strBuf == "Романист")
			{
				pubBuf = new Novelist(fio, stoi(date1), stoi(date2), vecBuf,
					bio);
			}
			else if (strBuf == "Фантаст")
			{
				pubBuf = new Fantasist(fio, stoi(date1), stoi(date2), vecBuf,
					exs);
			}
			addObject(*pubBuf);
			date1 = "";
			date2 = "";
		}
	}
	else
		throw exception("Некорректное считывание из файла");
	fin.close();
}
std::ostream& operator<< (std::ostream& out, const Keeper& keeper)
{
	if (keeper.index == 0)
		out << "Контейнер пуст" << endl;
	else
		for (int i = 0; i < keeper.index; i++)
		{
			out << i + 1 << " ";
			cout << keeper.conteiner[i]->out();
		}
	return out;
}
void Keeper::addObject(Publication& publication) {
	if (index == size)
		throw exception("Контейнер заполнен, добавление объекта невозможно");
	conteiner[index] = &publication;
	index++;
	cout << "Элемент добавлен в контейнер" << endl;
}
void Keeper::removeObject() {
	if (index == 0)
		throw exception("Контейнер пуст, удаление объекта невозможно");
	delete(conteiner[index - 1]);
	index--;
	cout << "Элемент удален из контейнера" << endl;
}
void Keeper::change(int index) {
	if (index < 0 || index > this->index)
		throw exception("Неверный индекс при изменении");
	conteiner[index]->change();
}