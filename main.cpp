#include "Keeper.h"
// ������� ��� ���������� ������� � ���������:
// �������� �����: number = 1
// �������� ���������: number = 2
// �������� ��������: number = 3
void add(Keeper& cont, int number);
int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0;
	cout << "�������� ����������. ";
	while (n <= 0)
	{
		cout << "������� ���������� ���������: ";
		cin >> n;
	}
	Keeper cont(n);
	char switch_on = '0';
	while (switch_on != '9')
	{
		system("pause");
		system("cls");
		cout << "����:\n\t1) ������� ��������� �� �����;" <<
			"\n\t2) �������� ��������� � ����;" <<
			"\n\t3) ������� ��������� � �������;" <<
			"\n\t4) �������� � ��������� �����;" <<
			"\n\t5) �������� � ��������� ���������;" <<
			"\n\t6) �������� � ��������� ��������;" <<
			"\n\t7) ������� ������� �� ����������;" <<
			"\n\t8) �������� ������� ����������;" <<
			"\n\t9) ����� �� ���������;" << endl << "��������� �����: ";
		cin >> switch_on;
		switch (switch_on)
		{
		case '1': // ���������� �� �����
			try
			{
				cont.extractFromFile();
			}
			catch (const exception exp) {
				cout << "����������: " << exp.what() <<
					endl;
			}
			break;
		case '2': // ������ � ����
			try
			{
				cont.saveToFile();
			}
			catch (const exception exp) {
				cout << "����������: " << exp.what() <<
					endl;
			}
			break;
		case '3': // ����� � �������
			cout << cont << endl;
			break;
		case '4': // �������� �����
			add(cont, 1);
			break;
		case '5': // �������� ���������
			add(cont, 2);
			break;
		case '6': // �������� ��������
			add(cont, 3);
			break;
		case '7': // ������� �������
			try
			{
				cont.removeObject();
			}
			catch (const exception exp) {
				cout << "����������: " << exp.what() <<
					endl;
			}
			break;
		case '8': // �������� �������
			try
			{
				int i;
				cout << "����� �������� ����������: ";
				cin >> i;
				cont.change(i - 1);
			}
			catch (const exception exp) {
				cout << "����������: " << exp.what() <<
					endl;
			}
			break;
		case '9':
			break;
		default:
			break;
		}
	}
	return 0;
}
void add(Keeper& cont, int number) {
	string name;
	if (number == 1)
		name = "�����";
	else if (number == 2)
		name = "���������";
	else if (number == 3)
		name = "��������";
	else
		cout << "������ ����������" << endl;
	try
	{
		string bufFio;
		int d1, d2, num;
		vector<string> bufVec;
		cout << "������� ��� " << name << ": ";
		cin >> bufFio;
		cout << "������� ��� �������� " << name << ": ";
		cin >> d1;
		cout << "������� ��� ������ " << name << ": ";
		cin >> d2;
		cout << "������� ���������� ��������� ������������ " << name << ": ";
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			string buf;
			cout << "������������ " << i + 1 << ": ";
			cin >> buf;
			bufVec.push_back(buf);
		}
		Publication* bufPub = nullptr;
		if (number == 1)
		{
			int bufPsevd;
			cout << "������� ���������� ����������� " << name << ": ";
			cin >> bufPsevd;
			bufPub = new Poet(bufFio, d1, d2, bufVec, bufPsevd);
		}
		else if (number == 2)
		{
			string bufBio;
			cout << "������� ��������� " << name << ": ";
			cin >> bufBio;
			bufPub = new Novelist(bufFio, d1, d2, bufVec, bufBio);
		}
		else if (number == 3)
		{
			bool bufEx;
			cout << "������� ����� �� ������ �� ������������� " << name << ": ";
			cin >> bufEx;
			bufPub = new Fantasist(bufFio, d1, d2, bufVec, bufEx);
		}
		cont.addObject(*bufPub);
	}
	catch (const exception exp) { cout << "����������: " << exp.what() << endl; }
}