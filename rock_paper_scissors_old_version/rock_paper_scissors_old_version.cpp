#include <iostream>
#include<string>

using namespace std;

int GetBotChoice(int min, int max)
{
	srand(time(NULL));
	int num = min + rand() % (max - min + 1);
	return num;
}

int main()
{
	system("chcp 1251");
	//setlocale(LC_ALL, "Russian");
	string start;
	string player_choice;
	string bot_choice;
	int bot_choice_num;
	string RPS_name[3] = { "������", "�������", "������" };
	const int player_power = 0;
	int bot_power;

	for (int i = 0; i == 0; i)
	{
		int RPS_power[3] = { 1, 1, 1 };
		if (start == "")
		{
			cout << "���� �� ������ ������� � ������-�������-������, �������: ��" << endl;
			cin >> start;
		}
		else if (start == "��" || start == "��")
		{
			cout << "������ ������� ��� ���?" << endl;
			cin >> start;
		}

		if (start != "��" && start != "��")
		{
			cout << "����������" << endl;
			break;
		}

		bot_choice_num = GetBotChoice(0, 2);

		if (start == "��" || start == "��")
		{
			cout << "������||�������||������" << endl;
			cin >> player_choice;
		}

		for (int i = 0; i == 0; i)
		{
			if (player_choice == "������" || player_choice == "�������" || player_choice == "������")
			{
				break;
			}
			else
			{
				cout << "�������� �����. �������� ��� ���!" << endl;
				cin >> player_choice;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (RPS_name[i] == player_choice)
			{
				RPS_power[i] = 0;
			}
			else
			{
				continue;
			}
			if (i == 2)
			{
				RPS_power[i - 2] = -1;
			}
			else
			{
				RPS_power[i + 1] = -1;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (bot_choice_num == i)
			{
				bot_power = RPS_power[i];
				bot_choice = RPS_name[i];
			}
		}

		cout << player_choice << " || " << bot_choice << endl;
		if (player_power > bot_power)
		{
			cout << "�� ��������!" << endl;
		}
		else if (player_power == bot_power)
		{
			cout << "�����" << endl;
		}
		else
		{
			cout << "�� ���������(" << endl;
		}
		bot_power = 0;
	}
}