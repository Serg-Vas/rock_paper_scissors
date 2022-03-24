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
	string RPS_name[3] = { "Камень", "Ножницы", "Бумага" };
	const int player_power = 0;
	int bot_power;

	for (int i = 0; i == 0; i)
	{
		int RPS_power[3] = { 1, 1, 1 };
		if (start == "")
		{
			cout << "Если вы хотите сыграть в камень-ножницы-бумага, введите: Да" << endl;
			cin >> start;
		}
		else if (start == "Да" || start == "да")
		{
			cout << "Хотите сыграть ещё раз?" << endl;
			cin >> start;
		}

		if (start != "Да" && start != "да")
		{
			cout << "Досвидания" << endl;
			break;
		}

		bot_choice_num = GetBotChoice(0, 2);

		if (start == "Да" || start == "да")
		{
			cout << "Камень||Ножницы||Бумага" << endl;
			cin >> player_choice;
		}

		for (int i = 0; i == 0; i)
		{
			if (player_choice == "Камень" || player_choice == "Ножницы" || player_choice == "Бумага")
			{
				break;
			}
			else
			{
				cout << "Неверный выбор. Попробуй ещё раз!" << endl;
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
			cout << "Вы победили!" << endl;
		}
		else if (player_power == bot_power)
		{
			cout << "Ничья" << endl;
		}
		else
		{
			cout << "Вы проиграли(" << endl;
		}
		bot_power = 0;
	}
}