// rock_paper_scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "rock_paper_scissors.h"

using namespace std;

void Initialise()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
}

int GetBotChoice(int min, int max)
{
	srand(time(NULL));
	int num = min + rand() % (max - min + 1);
	return num;
}

void ToLowCase(string& data)
{
	transform(data.begin(), data.end(), data.begin(),
		[](unsigned char c) { return std::tolower(c); });
}

void InputYes(std::string& start)
{
	if (start == "")
	{
		cout << "Если вы хотите сыграть в камень-ножницы-бумага, введите: Да" << endl;
		cin >> start;
	}
	else if (start == "да")
	{
		cout << "Хотите сыграть ещё раз?" << endl;
		cin >> start;
	}
	ToLowCase(start);
}

void InputRPS(const int& len, int& bot_choice_num, std::string& start, std::string& player_choice)
{
	bot_choice_num = GetBotChoice(0, len-1);

	if (start == "да")
	{
		cout << "Камень||Ножницы||Бумага" << endl;
		cin >> player_choice;
	}

	ToLowCase(player_choice);
}

void Choice(std::string& player_choice)
{
	for (int i = 0; i == 0; i)
	{
		if (player_choice == "камень" || player_choice == "ножницы" || player_choice == "бумага")
		{
			break;
		}
		else
		{
			cout << "Неверный выбор. Попробуй ещё раз!" << endl;
			cin >> player_choice;
		}
	}
}

void SetMassiveNumers(const int& len, std::string  RPS_name[3], std::string& player_choice, int  RPS_power[3])
{
	for (int i = 0; i < len; i++)
	{
		if (RPS_name[i] == player_choice)
		{
			RPS_power[i] = 0;
		}
		else
		{
			continue;
		}
		if (i == len-1)
		{
			RPS_power[i - (len-1)] = -1;
		}
		else
		{
			RPS_power[i + 1] = -1;
		}
	}
}

void SetBotChioce(const int& len, int bot_choice_num, int& bot_power, int  RPS_power[3], std::string& bot_choice, std::string  RPS_name[3])
{
	for (int i = 0; i < len; i++)
	{
		if (bot_choice_num == i)
		{
			bot_power = RPS_power[i];
			bot_choice = RPS_name[i];
		}
	}
}

struct RPS
{
	int rock;
	int paper;
	int scissors;
};

void SetBotChoiceWithStruct(std::string& player_choice, std::string  RPS_name[3], RPS& bot_power2, int bot_choice_num, int& bot_power, std::string& bot_choice)
{
	if (player_choice == RPS_name[0])
	{
		bot_power2.rock = 0;
		bot_power2.scissors = -1;
		bot_power2.paper = 1;
	}
	else if (player_choice == RPS_name[1])
	{
		bot_power2.rock = 1;
		bot_power2.scissors = 0;
		bot_power2.paper = -1;
	}
	else if (player_choice == RPS_name[2])
	{
		bot_power2.rock = -1;
		bot_power2.scissors = 1;
		bot_power2.paper = 0;
	}


	if (bot_choice_num == 0)
	{
		bot_power = bot_power2.rock;
		bot_choice = RPS_name[0];
	}
	else if (bot_choice_num == 1)
	{
		bot_power = bot_power2.scissors;
		bot_choice = RPS_name[1];
	}
	else if (bot_choice_num == 2)
	{
		bot_power = bot_power2.paper;
		bot_choice = RPS_name[2];
	}
}

void Finish(std::string& player_choice, std::string& bot_choice, const int& player_power, int bot_power)
{
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
}

void General()
{
	Initialise();

	const int len = 3;
	string start;
	string player_choice;
	string bot_choice;
	int bot_choice_num;
	string RPS_name[len] = { "камень", "ножницы", "бумага" };
	const int player_power = 0;
	int bot_power;
	RPS bot_power2;

	while (true)
	{
		int RPS_power[len] = { 1, 1, 1 };

		InputYes(start);

		if (start != "да")
		{
			cout << "Досвидания" << endl;
			break;
		}

		InputRPS(len, bot_choice_num, start, player_choice);

		Choice(player_choice);

		//SetMassiveNumers(len, RPS_name, player_choice, RPS_power);

		//SetBotChioce(len, bot_choice_num, bot_power, RPS_power, bot_choice, RPS_name);

		SetBotChoiceWithStruct(player_choice, RPS_name, bot_power2, bot_choice_num, bot_power, bot_choice);

		Finish(player_choice, bot_choice, player_power, bot_power);

		bot_power = 0;
	}
}

int main()
{
	General();
}
