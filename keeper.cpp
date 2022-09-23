#include "Keeper.h"
#include <fstream>
#include <stdlib.h>
Keeper::Keeper() {
	size = 0;
	index = 0;
	conteiner = nullptr;
	cout << "\t\t����� Keeper: ����������� ��� ����������" << endl;
}
Keeper::Keeper(int size) {
	if (size <= 0)
		throw exception("���������� ��������� ���������� �� �����");
	this->size = size;
	conteiner = new Publication * [size];
	index = 0;
	cout << "\t\t����� Keeper: ����������� � �����������" << endl;
}
Keeper::Keeper(const Keeper& keeper) {
	size = keeper.size;
	for (int i = 0; i < keeper.index; i++)
		addObject(*keeper.conteiner[i]);
	cout << "\t\t����� Keeper: ����������� �����������" << endl;
}
Keeper::~Keeper() {
	int cnt = index;
	for (int i = 0; i < cnt; i++)
		removeObject();
	size = 0;
	index = 0;
	conteiner = nullptr;
	cout << "\t\t����� Keeper: ����������" << endl;
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
		throw exception("������ ��� ������ � ����");
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
			throw exception("������������ ���������� ��������� � ����������");
		}
		for (int i = 0; i < intBuf; i++)
		{
			fin >> strBuf;
			if (strBuf != "����" && strBuf != "��������" && strBuf != "�������")
				throw exception("������������ ������ � ����");
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
			if (strBuf == "����")
			{
				fin >> data >> nick;
			}
			else if (strBuf == "��������")
			{
				fin >> data >> bio;
			}
			else if (strBuf == "�������")
			{
				fin >> data >> data >> data >> data;
				if (data == "���")
					exs = false;
				else if (data == "��")
					exs = true;
				else
					throw exception("������������ ������ � ����");
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
			if (strBuf == "����")
			{
				pubBuf = new Poet(fio, stoi(date1), stoi(date2), vecBuf,
					nick);
			}
			else if (strBuf == "��������")
			{
				pubBuf = new Novelist(fio, stoi(date1), stoi(date2), vecBuf,
					bio);
			}
			else if (strBuf == "�������")
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
		throw exception("������������ ���������� �� �����");
	fin.close();
}
std::ostream& operator<< (std::ostream& out, const Keeper& keeper)
{
	if (keeper.index == 0)
		out << "��������� ����" << endl;
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
		throw exception("��������� ��������, ���������� ������� ����������");
	conteiner[index] = &publication;
	index++;
	cout << "������� �������� � ���������" << endl;
}
void Keeper::removeObject() {
	if (index == 0)
		throw exception("��������� ����, �������� ������� ����������");
	delete(conteiner[index - 1]);
	index--;
	cout << "������� ������ �� ����������" << endl;
}
void Keeper::change(int index) {
	if (index < 0 || index > this->index)
		throw exception("�������� ������ ��� ���������");
	conteiner[index]->change();
}