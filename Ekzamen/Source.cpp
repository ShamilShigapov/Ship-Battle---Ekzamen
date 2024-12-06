#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include "Header.h"
using namespace std;

void fill_pc_hard_attack(vector<Point>& pc_hard_4deck_attack, vector<Point>& pc_hard_3_2deck_attack)
{
	pc_hard_4deck_attack = { {3,0}, {7,0}, {2,1}, {6,1}, {1,2}, {5,2},
							 {9,2}, {0,3}, {4,3}, {8,3}, {3,4}, {7,4},
							 {2,5}, {6,5}, {1,6}, {5,6}, {9,6}, {0,7},
							 {4,7}, {8,7}, {3,8}, {7,8}, {2,9}, {6,9} };

	pc_hard_3_2deck_attack = { {1,0}, {5,0}, {9,0}, {0,1}, {4,1}, {8,1},
						   {3,2}, {7,2}, {2,3}, {6,3}, {1,4}, {5,4},
						   {9,4}, {0,5}, {4,5}, {8,5}, {3,6}, {7,6},
						   {2,7}, {6,7}, {1,8}, {5,8}, {9,8}, {0,9}, {4,9}, {8,9} };
}

void pc_hard_random(vector<Point>& pc_hard_4deck_attack, vector<Point>& pc_hard_3_2deck_attack)
{
	int random = rand() % 4;
	if (random == 0)
		reverse(pc_hard_4deck_attack.begin(), pc_hard_4deck_attack.end());
	else if (random == 1)
		reverse(pc_hard_3_2deck_attack.begin(), pc_hard_3_2deck_attack.end());
	else if (random == 2)
	{
		for (int i = 0; i < pc_hard_4deck_attack.size(); i++)
		{
			int tmp = pc_hard_4deck_attack[i].Y;
			pc_hard_4deck_attack[i].Y = pc_hard_4deck_attack[i].X;
			pc_hard_4deck_attack[i].X = tmp;
		}
		for (int i = 0; i < pc_hard_3_2deck_attack.size(); i++)
		{
			int tmp = pc_hard_3_2deck_attack[i].Y;
			pc_hard_3_2deck_attack[i].Y = pc_hard_3_2deck_attack[i].X;
			pc_hard_3_2deck_attack[i].X = tmp;
		}
		reverse(pc_hard_4deck_attack.begin(), pc_hard_4deck_attack.end());
	}
	else if (random == 3)
	{
		for (int i = 0; i < pc_hard_4deck_attack.size(); i++)
		{
			int tmp = pc_hard_4deck_attack[i].Y;
			pc_hard_4deck_attack[i].Y = pc_hard_4deck_attack[i].X;
			pc_hard_4deck_attack[i].X = tmp;
		}
		for (int i = 0; i < pc_hard_3_2deck_attack.size(); i++)
		{
			int tmp = pc_hard_3_2deck_attack[i].Y;
			pc_hard_3_2deck_attack[i].Y = pc_hard_3_2deck_attack[i].X;
			pc_hard_3_2deck_attack[i].X = tmp;
		}
		reverse(pc_hard_3_2deck_attack.begin(), pc_hard_3_2deck_attack.end());
	}
}

bool is_end_game(char ships[][10])
{
	int count = sym_count(ships, Deck);
	if (count == 0)
		return true;
	return false;
}

void end_game(Player player1, Player player2, bool& game)
{
	if (is_end_game(player2.ships))
	{
		cls();
		cout << "\n\n\n\t     ����� ����!!!\n\n\n";
		cout << "\t������� " << player1.name << " !!!!!!!!!\n";
		game = false;
		system("pause");
	}
}

void cls()
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD point = { 0, 0 };
	std::cout.flush();

	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;

	FillConsoleOutputCharacter(hOut, TEXT(' '), length, point, &written);
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, point, &written);
	SetConsoleCursorPosition(hOut, point);
}

void cls(COORD coord)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD point;
	point.Y = coord.Y;
	point.X = coord.X;

	std::cout.flush();

	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;

	FillConsoleOutputCharacter(hOut, TEXT(' '), length, point, &written);
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, point, &written);
	SetConsoleCursorPosition(hOut, point);
}

COORD get_�oords()
{
	CONSOLE_SCREEN_BUFFER_INFO info_x;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_x);
	return info_x.dwCursorPosition;
}

char get_status_char(Status status)
{
	return (char)status;
}

int get_int_choice()
{
	bool flag = true;
	COORD coord = get_�oords();
	int y;
	string choice;
	/*
	while (flag)
	{
		if (choice == 0)
			choice = _getch();
		cls(coord);
		if (_kbhit())
			choice = _getch();
		switch (choice)
		{
		case '1':
			cout << "1\n";
			y = 0;
			flag = false;
			break;
		case '2':
			cout << "2\n";
			y = 1;
			flag = false;
			break;
		case '3':
			cout << "3\n";
			y = 2;
			flag = false;
			break;
		case '4':
			cout << "4\n";
			y = 3;
			flag = false;
			break;
		case '5':
			cout << "5\n";
			y = 4;
			flag = false;
			break;
		case '6':
			cout << "6\n";
			y = 5;
			flag = false;
			break;
		case '7':
			cout << "7\n";
			y = 6;
			flag = false;
			break;
		case '8':
			cout << "8\n";
			y = 7;
			flag = false;
			break;
		case '9':
			cout << "9\n";
			y = 8;
			flag = false;
			break;
		case '�':
			cout << "�\n";
			y = 9;
			flag = false;
			break;
		default:
			break;
		}
	}
	*/
	while (true)
	{
		cls(coord);
		bool flag = true;
		cin >> choice;
		for (char c : choice) // ��������� ���� �� ������� �������� �� ����
		{
			if (c < '0' || c > '9')
			{
				flag = false;
				break;
			}
		}

		if (!flag)
		{
			cls(coord);
			cout << "�������� ����. ���������� ��� ���.\n";
			Sleep(2000);
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}

		auto j = stoll(choice); // �� ������, ���� �������� ����� ������� �� �������� �������� ����
		if (j > INT_MAX or j < INT_MIN) // ��������� �� �������� �������� ����
			flag = false;

		if (!flag)
		{
			cls(coord);
			cout << "�������� ����. ���������� ��� ���.\n";
			Sleep(2000);
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}

		y = stoi(choice); // ����������� � ���
		cin.clear();
		while (cin.get() != '\n');
		break;
	}
	return y;
}

void set_color(ConsoleColor text, ConsoleColor background)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	/*
	�������� � ��������� �� 0 �� 15 �������� 4 ���� - 0000, ��������������,
	����� ��������� �������� ���� �������� ������ ������, ���������� �������� ������ �������� �� 4 ���� �����.
	�����������, ���:
	background = 0x9; // 9 (����-�����)
	foreground = 0xf; // 15 (����-�����)

	� �������� ������������� background = 1001, � foreground = 1111,
	��� ��� �������� �������� ���������� ������� �������� ����� - 0000 1111 (0x0f),
	���� ��������� ��������� ����� ����� ��� background, ��������� ���������:
	0000 1001 << 4 = 1001 0000.
	�����, ����������� ��������� ���������� � foreground:
	1001 0000 | 0000 1111 = 1001 1111.
	� �������, ����������� ��������� �������� ����� ���������� ����� c-style cast � ������������� ���� WORD.
	(WORD) 1001 1111 = 0000 0000 1001 1111 (� big-endian), 1001 1111 0000 0000 (� little-endian).
	*/
	SetConsoleTextAttribute(hOut, (WORD)((background << 4) | text));
}

void fill_players_fields(Player& player1, Player& player2)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			player1.ships[i][j] = get_status_char(Sea);
			player1.hits[i][j] = get_status_char(Sea);
			player2.ships[i][j] = get_status_char(Sea);
			player2.hits[i][j] = get_status_char(Sea);
		}
	}
	player1.name = "����� 1";
	player2.name = "����� 2";
}

void print_field(char ships[][10])
{
	cout << "\t   � � � � � � � � � �\n";
	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
			cout << "\t" << i + 1;
		else
			cout << "\t" << i + 1 << " ";
		for (int j = 0; j < 10; j++)
		{
			if (i % 2 == 0 and j % 2 == 0)
				set_color(Black, LightGray);
			else if(i % 2 != 0 and j % 2 != 0)
				set_color(Black, LightGray);
			else
				set_color(Black, White);
			cout << " ";
			cout << ships[i][j];
			set_color(White, Black);
		}
		cout << endl;
	}
	cout << "\n\n\n";
}

void print_fields(char ships[][10], char hits[][10])
{
	cout << "\t      ���� ������ 1\t\t      ���� ������ 2\n\n";
	cout << "\t   � � � � � � � � � �\t\t   � � � � � � � � � �\n";
	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
			cout << "\t" << i + 1;
		else
			cout << "\t" << i + 1 << " ";
		for (int j = 0; j < 10; j++)
		{
			if (i % 2 == 0 and j % 2 == 0)
			{
				if (ships[i][j] == get_status_char(Hit) or
					ships[i][j] == get_status_char(Kill))
					set_color(Red, LightGray);
				else
					set_color(Blue, LightGray);
			}
			else if (i % 2 != 0 and j % 2 != 0)
			{
				if (ships[i][j] == get_status_char(Hit) or
					ships[i][j] == get_status_char(Kill))
					set_color(Red, LightGray);
				else
					set_color(Blue, LightGray);
			}
			else
			{
				if (ships[i][j] == get_status_char(Hit) or
					ships[i][j] == get_status_char(Kill))
					set_color(Red, White);
				else
					set_color(Blue, White);
			}
			cout << " ";
			cout << ships[i][j];
			set_color(White, Black);
		}
		if (i == 9)
			cout << " \t\t" << i + 1;
		else
			cout << " \t\t" << i + 1 << " ";
		for (int j = 0; j < 10; j++)
		{
			if (i % 2 == 0 and j % 2 == 0)
			{
				if (hits[i][j] == get_status_char(Hit) or
					hits[i][j] == get_status_char(Kill))
					set_color(Red, LightGray);
				else
					set_color(Blue, LightGray);
			}
			else if (i % 2 != 0 and j % 2 != 0)
			{
				if (hits[i][j] == get_status_char(Hit) or
					hits[i][j] == get_status_char(Kill))
					set_color(Red, LightGray);
				else
					set_color(Blue, LightGray);
			}
			else
			{
				if (hits[i][j] == get_status_char(Hit) or
					hits[i][j] == get_status_char(Kill))
					set_color(Red, White);
				else
					set_color(Blue, White);
			}
			cout << " ";
			cout << hits[i][j];
			set_color(White, Black);
		}
		cout << endl;
	}
	cout << "\n\n\n";
	cout << "\t�����\t\t������ ��������\n";
}

bool check_right(const int& x, const int& y, char ships[][10], const int& ship_size, Status status)
{
	char sym = get_status_char(status);
	bool is_ship = 0;
	if (x == 0 and y == 0)
	{
		if (ships[y + 1][x + ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + 1][x + i] == sym or
				ships[y][x + i + 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 9 and y == 0)
	{
		if (ships[y + 1][x] == sym or
			ships[y][x - 1] == sym or
			ships[y + 1][x - 1] == sym)
			is_ship = 1;
	}
	//-------------------------------------------------------------------------------
	else if (x == 0 and y == 9)
	{
		if (ships[y - 1][x + ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x + i] == sym or
				ships[y][x + i + 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 9 and y == 9)
	{
		if (ships[y][x - 1] == sym or
			ships[y - 1][x] == sym or
			ships[y - 1][x - 1] == sym)
			is_ship = 1;
	}
	//-------------------------------------------------------------------------------
	else if (x == 0)
	{
		if (ships[y - 1][x + ship_size] == sym or
			ships[y + 1][x + ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x + i] == sym or
				ships[y + 1][x + i] == sym or
				ships[y][x + i + 1] == sym)
			{
				is_ship = 1;
			}
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 9)
	{
		if (ships[y - 1][x - ship_size] == sym or
			ships[y + 1][x - ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x + i] == sym or
				ships[y + 1][x + i] == sym or
				ships[y][x - i - 1] == sym)
			{
				is_ship = 1;
			}
		}
	}
	//-------------------------------------------------------------------------------
	else if (y == 0)
	{
		if (ships[y][x - 1] == sym or
			ships[y + 1][x - 1] == sym or
			ships[y + 1][x + ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + 1][x + i] == sym or
				ships[y][x + i + 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (y == 9)
	{
		if (ships[y][x - 1] == sym or
			ships[y - 1][x - 1] == sym or
			ships[y - 1][x + ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x + i] == sym or
				ships[y][x + i + 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else
	{
		if (ships[y][x - 1] == sym)
			is_ship = 1;
		if (ships[y - 1][x - 1] == sym)
			is_ship = 1;
		if (ships[y + 1][x - 1] == sym)
			is_ship = 1;
		if (ships[y - 1][x + ship_size] == sym)
			is_ship = 1;
		if (ships[y + 1][x + ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x + i] == sym or
				ships[y + 1][x + i] == sym or
				ships[y][x + i + 1] == sym)
			{
				is_ship = 1;
			}
		}
	}
	return is_ship;
}

bool check_left(const int& x, const int& y, char ships[][10], const int& ship_size, Status status)
{
	char sym = get_status_char(status);
	bool is_ship = 0;
	if (x == 0 and y == 0)
	{
		if (ships[y][x + 1] == sym or
			ships[y + 1][x] == sym or
			ships[y + 1][x + 1] == sym)
			is_ship = 1;
	}
	//-------------------------------------------------------------------------------
	else if (x == 9 and y == 0)
	{
		if (ships[y + 1][x - ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + 1][x - i] == sym or
				ships[y][x - i - 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 0 and y == 9)
	{
		if (ships[y - 1][x] == sym or
			ships[y][x + 1] == sym or
			ships[y - 1][x + 1] == sym)
			is_ship = 1;
	}
	//-------------------------------------------------------------------------------
	else if (x == 9 and y == 9)
	{
		if (ships[y - 1][x - ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x - i] == sym or
				ships[y][x - i - 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 0)
	{
		if (ships[y - 1][x + ship_size] == sym or
			ships[y + 1][x + ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x + i] == sym or
				ships[y + 1][x + i] == sym or
				ships[y][x + i + 1] == sym)
			{
				is_ship = 1;
			}
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 9)
	{
		if (ships[y + 1][x - ship_size] == sym or
			ships[y - 1][x - ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x + i] == sym or
				ships[y + 1][x + i] == sym or
				ships[y][x - i - 1] == sym)
			{
				is_ship = 1;
			}
		}
	}
	//-------------------------------------------------------------------------------
	else if (y == 0)
	{
		if (ships[y][x + 1] == sym or
			ships[y + 1][x + 1] == sym or
			ships[y + 1][x - ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + 1][x - i] == sym or
				ships[y][x - i - 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (y == 9)
	{
		if (ships[y][x + 1] == sym or
			ships[y - 1][x + 1] == sym or
			ships[y - 1][x - ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x - i] == sym or
				ships[y][x - i - 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else
	{
		if (ships[y][x + 1] == sym or
			ships[y - 1][x + 1] == sym or
			ships[y + 1][x + 1] == sym or
			ships[y - 1][x - ship_size] == sym or
			ships[y + 1][x - ship_size] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - 1][x - i] == sym or
				ships[y + 1][x - i] == sym or
				ships[y][x - i - 1] == sym)
			{
				is_ship = 1;
			}
		}
	}
	return is_ship;
}

bool check_down(const int& x, const int& y, char ships[][10], const int& ship_size, Status status)
{
	char sym = get_status_char(status);
	bool is_ship = 0;
	if (x == 0 and y == 0)
	{
		if (ships[y + ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + i][x + 1] == sym or
				ships[y + i + 1][x] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 9 and y == 0)
	{
		if (ships[y + ship_size][x - 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + i][x - 1] == sym or
				ships[y + i + 1][x] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 0 and y == 9)
	{
		if (ships[y - 1][x] == sym or
			ships[y - 1][x + 1] == sym or
			ships[y][x + 1] == sym)
			is_ship = 1;
	}
	//-------------------------------------------------------------------------------
	else if (x == 9 and y == 9)
	{
		if (ships[y - 1][x] == sym or
			ships[y - 1][x - 1] == sym or
			ships[y][x - 1] == sym)
			is_ship = 1;
	}
	//-------------------------------------------------------------------------------
	else if (x == 0)
	{
		if (ships[y - 1][x] == sym or
			ships[y - 1][x + 1] == sym or
			ships[y + ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + i][x + 1] == sym or
				ships[y + i + 1][x] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 9)
	{
		if (ships[y - 1][x] == sym or
			ships[y - 1][x - 1] == sym or
			ships[y + ship_size][x - 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + i][x - 1] == sym or
				ships[y + i + 1][x] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (y == 0)
	{
		if (ships[y + ship_size][x - 1] == sym or
			ships[y + ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + i][x - 1] == sym or
				ships[y + i][x + 1] == sym or
				ships[y + i + 1][x] == sym)
			{
				is_ship = 1;
			}
		}
	}
	//-------------------------------------------------------------------------------
	else if (y == 9)
	{
		if (ships[y - ship_size][x - 1] == sym)
			is_ship = 1;
		if (ships[y - ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - i][x - 1] == sym or
				ships[y - i][x + 1] == sym or
				ships[y - i - 1][x] == sym)
			{
				is_ship = 1;
			}
		}
	}
	//-------------------------------------------------------------------------------
	else
	{
		if (ships[y - 1][x] == sym)
			is_ship = 1;
		if (ships[y - 1][x - 1] == sym)
			is_ship = 1;
		if (ships[y - 1][x + 1] == sym)
			is_ship = 1;
		if (ships[y + ship_size][x - 1] == sym)
			is_ship = 1;
		if (ships[y + ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + i][x - 1] == sym or
				ships[y + i][x + 1] == sym or
				ships[y + i + 1][x] == sym)
			{
				is_ship = 1;
			}
		}
	}
	return is_ship;
}

bool check_up(const int& x, const int& y, char ships[][10], const int& ship_size, Status status)
{
	char sym = get_status_char(status);
	bool is_ship = 0;
	if (x == 0 and y == 0)
	{
		if (ships[y + 1][x] == sym or
			ships[y + 1][x + 1] == sym or
			ships[y][x + 1] == sym)
			is_ship = 1;
	}
	//-------------------------------------------------------------------------------
	else if (x == 9 and y == 0)
	{
		if (ships[y + 1][x] == sym or
			ships[y + 1][x - 1] == sym or
			ships[y][x - 1] == sym)
			is_ship = 1;
	}
	//-------------------------------------------------------------------------------
	else if (x == 0 and y == 9)
	{
		if (ships[y - ship_size][x] == sym or
			ships[y - ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - i][x + 1] == sym or
				ships[y - i - 1][x] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 9 and y == 9)
	{
		if (ships[y - ship_size][x] == sym or
			ships[y - ship_size][x - 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - i][x - 1] == sym or
				ships[y - i - 1][x] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 0)
	{
		if (ships[y - ship_size][x] == sym or
			ships[y - ship_size][x + 1] == sym or
			ships[y + 1][x] == sym or
			ships[y + 1][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - i][x + 1] == sym or
				ships[y - i - 1][x] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (x == 9)
	{
		if (ships[y - ship_size][x] == sym or
			ships[y - ship_size][x - 1] == sym or
			ships[y + 1][x] == sym or
			ships[y + 1][x - 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - i][x - 1] == sym or
				ships[y - i - 1][x] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (y == 0)
	{
		if (ships[y + ship_size][x] == sym or
			ships[y + ship_size][x - 1] == sym or
			ships[y + ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y + i][x - 1] == sym or
				ships[y + i][x + 1] == sym)
				is_ship = 1;
		}
	}
	//-------------------------------------------------------------------------------
	else if (y == 9)
	{
		if (ships[y - ship_size][x - 1] == sym or
			ships[y - ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - i][x - 1] == sym or
				ships[y - i - 1][x] == sym or
				ships[y - i][x + 1] == sym)
			{
				is_ship = 1;
			}
		}
	}
	//-------------------------------------------------------------------------------
	else
	{
		if (ships[y + 1][x] == sym)
			is_ship = 1;
		if (ships[y + 1][x - 1] == sym)
			is_ship = 1;
		if (ships[y + 1][x + 1] == sym)
			is_ship = 1;
		if (ships[y - ship_size][x - 1] == sym)
			is_ship = 1;
		if (ships[y - ship_size][x + 1] == sym)
			is_ship = 1;
		for (int i = 0; i < ship_size; i++)
		{
			if (ships[y - i][x - 1] == sym or
				ships[y - i][x + 1] == sym or
				ships[y - i - 1][x] == sym)
			{
				is_ship = 1;
			}
		}
	}
	return is_ship;
}

int get_letter_int()
{
	bool flag = true;
	COORD coord = get_�oords();
	string choice;
	int x;
	//while (flag)
	//{
	//	if (choice == 0)
	//		choice = _getch();
	//	cls(coord);
	//	if (_kbhit()) 
	//		choice = _getch();
	//	switch (choice)
	//	{
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 0;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 1;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 2;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 3;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 4;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 5;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 6;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 7;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 8;
	//		flag = false;
	//		break;
	//	case '�':
	//	case '�':
	//		cout << "�\n";
	//		x = 9;
	//		flag = false;
	//		break;
	//	default:
	//		break;
	//	}
	//}
	while (flag)
	{
		cls(coord);
		cin >> choice;
		if (choice == "�" or choice == "�" or
			choice == "�" or choice == "�" or
			choice == "�" or choice == "�" or
			choice == "�" or choice == "�" or
			choice == "�" or choice == "�" or
			choice == "�" or choice == "�" or
			choice == "�" or choice == "�" or
			choice == "�" or choice == "�" or
			choice == "�" or choice == "�" or
			choice == "�" or choice == "�")
		{
			char letter = choice[0];
			switch (letter)
			{
			case '�':
			case '�':
				x = 0;
				break;
			case '�':
			case '�':
				x = 1;
				break;
			case '�':
			case '�':
				x = 2;
				break;
			case '�':
			case '�':
				x = 3;
				break;
			case '�':
			case '�':
				x = 4;
				break;
			case '�':
			case '�':
				x = 5;
				break;
			case '�':
			case '�':
				x = 6;
				break;
			case '�':
			case '�':
				x = 7;
				break;
			case '�':
			case '�':
				x = 8;
				break;
			case '�':
			case '�':
				x = 9;
				break;
			}
			flag = false;
		}
		else
		{
			cls(coord);
			cout << "�������� ����. ���������� ��� ���.\n";
			Sleep(2000);
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}
		cin.clear();
		while (cin.get() != '\n');
	}
	return x;
}

char get_char_from_x(const int& x)
{
	char sym = '#';
	switch (x)
	{
	case 0:
		sym = '�';
		break;
	case 1:
		sym = '�';
		break;
	case 2:
		sym = '�';
		break;
	case 3:
		sym = '�';
		break;
	case 4:
		sym = '�';
		break;
	case 5:
		sym = '�';
		break;
	case 6:
		sym = '�';
		break;
	case 7:
		sym = '�';
		break;
	case 8:
		sym = '�';
		break;
	case 9:
		sym = '�';
		break;
	}
	return sym;
}

void enter_coord(int& x, int& y)
{
	string choice;
	bool flag = true;
	COORD coord = get_�oords();
	while (flag)
	{
		cls(coord);
		cout << "������� �����: ";
		x = get_letter_int();
		cout << "������� �����: ";
		y = get_int_choice();
		if (y > 0 and y < 11)
			y = y - 1;
		else
		{
			cls(coord);
			cout << "�������� ����������. ���������� ��� ���.\n";
			Sleep(2000);
			continue;
		}
		flag = false;
	}

}

void negative_dir_massage(COORD coord)
{
	cls(coord);
	cout << "� ���� ����������� ���������� ������� ������. ���������� ��� ���.\n";
	Sleep(2000);
}

void ship_hand_install(char ships[][10], const int& ship_size)
{
	bool is_instal = true;
	int deck_x;
	int deck_y;
	COORD coord;
	while (is_instal)
	{
		cls();
		print_field(ships);
		coord = get_�oords();
		if(ship_size == 1)
			cout << "������� ���������� ������� ( " << ship_size << "-��������)\n\n";
		else
			cout << "������� ��������� ���������� ������� ( " << ship_size << "-��������)\n\n";
		enter_coord(deck_x, deck_y);
		if (check_up(deck_x, deck_y, ships, 1, Deck))
		{
			cls(coord);
			cout << "��������� ������� ����� � ������� ���������. ���������� ��� ���.\n";
			Sleep(2000);
			continue;
		}
		ships[deck_y][deck_x] = get_status_char(Deck);

		if (ship_size == 1)
			return;
		else
		{
			int choice;
			bool is_dir = true;
			while (is_dir)
			{
				cls();
				print_field(ships);
				coord = get_�oords();
				bool is_ship = false;
				cout << "�������, � ����� ����������� ����� ������������� ��������� ����� �������.\n\n";
				cout << "1 - �����\n";
				cout << "2 - ����\n";
				cout << "3 - ������\n";
				cout << "4 - �����\n";
				choice = get_int_choice();
				Direction dir = static_cast<Direction>(choice);
				switch (dir)
				{
				case Up:
					if (ships[deck_y - ship_size + 1][deck_x] == get_status_char(Sea) and (deck_y - ship_size + 1) >= 0)
					{
						is_ship = check_up(deck_x, deck_y, ships, ship_size, Deck);
						if (is_ship == 0)
						{
							for (int i = 1; i < ship_size; i++)
							{
								ships[deck_y - i][deck_x] = get_status_char(Deck);
							}
							is_instal = 0;
							is_dir = 0;
						}
						else
							negative_dir_massage(coord);
					}
					else
						negative_dir_massage(coord);
					break;
				case Down:
					if (ships[deck_y + ship_size - 1][deck_x] == get_status_char(Sea) and (deck_y + ship_size - 1) < 10)
					{
						is_ship = check_down(deck_x, deck_y, ships, ship_size, Deck);
						if (is_ship == 0)
						{
							for (int i = 1; i < ship_size; i++)
							{
								ships[deck_y + i][deck_x] = get_status_char(Deck);
							}
							is_instal = 0;
							is_dir = 0;
						}
						else
							negative_dir_massage(coord);
					}
					else
						negative_dir_massage(coord);
					break;
				case Right:
					if (ships[deck_y][deck_x + ship_size - 1] == get_status_char(Sea) and (deck_x + ship_size - 1) < 10)
					{
						is_ship = check_right(deck_x, deck_y, ships, ship_size, Deck);
						if (is_ship == 0)
						{
							for (int i = 1; i < ship_size; i++)
							{
								ships[deck_y][deck_x + i] = get_status_char(Deck);
							}
							is_instal = 0;
							is_dir = 0;
						}
						else
							negative_dir_massage(coord);
					}
					else
						negative_dir_massage(coord);
					break;
				case Left:
					if (ships[deck_y][deck_x - ship_size + 1] == get_status_char(Sea) and (deck_x - ship_size + 1) >= 0)
					{
						is_ship = check_left(deck_x, deck_y, ships, ship_size, Deck);
						if (is_ship == 0)
						{
							for (int i = 1; i < ship_size; i++)
							{
								ships[deck_y][deck_x - i] = get_status_char(Deck);
							}
							is_instal = 0;
							is_dir = 0;
						}
						else
							negative_dir_massage(coord);
					}
					else
						negative_dir_massage(coord);
					break;
				default:
					cls(coord);
					cout << "�������� ����. ���������� ��� ���.\n";
					Sleep(1000);
					break;
				}
			}
		}
	}
}

void ships_hand_install(char ships[][10])
{
	ship_hand_install(ships, 4);
	ship_hand_install(ships, 3);
	ship_hand_install(ships, 3);
	ship_hand_install(ships, 2);
	ship_hand_install(ships, 2);
	ship_hand_install(ships, 2);
	ship_hand_install(ships, 1);
	ship_hand_install(ships, 1);
	ship_hand_install(ships, 1);
	ship_hand_install(ships, 1);
}

void ship_auto_install(char ships[][10], const int& ship_size)
{
	bool is_instal = true; // ������� ���� ��� �������� ������ �� ����������� �������
	int deck_y, deck_x;
	Direction dir;
	while (is_instal) // �������� ������� �� ���������� �������
	{
		dir = static_cast<Direction>(1 + rand() % 4); // �������� ����������� ��������� ����� �������: 0 - ������������� ������, 1 - ����������� ����
		deck_y = rand() % 10; // ��������� ������� ������������ ����������
		deck_x = rand() % 10;
		bool is_ship = false; // ������� ���� ��� �������� ������� ������ �� ������� �������� ��� ����� �������
		if (ship_size == 1) // ��������� ������������
		{
			if (ships[deck_y][deck_x] == get_status_char(Sea))
			{
				is_ship = check_up(deck_x, deck_y, ships, ship_size, Deck); // �������� ������� ������
				if (is_ship == 0)
				{
					ships[deck_y][deck_x] = get_status_char(Deck); // ��������� ������� � ������� ships
					/*Sleep(500);
					system("cls");
					print_field(ships);*/
					is_instal = 0;
				}
			}
		}
		else  // ��������� �������������
		{
			switch (dir)
			{
			case Right:
				if (ships[deck_y][deck_x + ship_size - 1] == get_status_char(Sea) and (deck_x + ship_size - 1) < 10) // ��������� ����� �� ���������� ������� � ��� �������
				{
					is_ship = check_right(deck_x, deck_y, ships, ship_size, Deck); // �������� ������� ������
					if (is_ship == 0)
					{
						for (int i = 0; i < ship_size; i++)
						{
							ships[deck_y][deck_x + i] = get_status_char(Deck); // ��������� ������� � ������� ships
							/*Sleep(500);
							system("cls");
							print_field(ships);*/
						}
						is_instal = 0;
					}
				}
				break;
			case Down:
				if (ships[deck_y + ship_size - 1][deck_x] == get_status_char(Sea) and (deck_y + ship_size - 1) < 10)
				{
					is_ship = check_down(deck_x, deck_y, ships, ship_size, Deck);
					if (is_ship == 0)
					{
						for (int i = 0; i < ship_size; i++)
						{
							ships[deck_y + i][deck_x] = get_status_char(Deck);
							/*Sleep(500);
							system("cls");
							print_field(ships);*/
						}
						is_instal = 0;
					}
				}
				break;
			case Up:
				if (ships[deck_y - ship_size + 1][deck_x] == get_status_char(Sea) and (deck_y - ship_size + 1) >= 0)
				{
					is_ship = check_up(deck_x, deck_y, ships, ship_size, Deck);
					if (is_ship == 0)
					{
						for (int i = 0; i < ship_size; i++)
						{
							ships[deck_y - i][deck_x] = get_status_char(Deck);
							/*Sleep(500);
							system("cls");
							print_field(ships);*/
						}
						is_instal = 0;
					}
				}
				break;
			case Left:
				if (ships[deck_y][deck_x - ship_size + 1] == get_status_char(Sea) and (deck_x - ship_size + 1) >= 0)
				{
					is_ship = check_left(deck_x, deck_y, ships, ship_size, Deck);
					if (is_ship == 0)
					{
						for (int i = 0; i < ship_size; i++)
						{
							ships[deck_y][deck_x - i] = get_status_char(Deck);
							/*Sleep(500);
							system("cls");
							print_field(ships);*/
						}
						is_instal = 0;
					}
				}
				break;
			}
		}
	}
}

void ships_auto_install(char ships[][10])
{
	ship_auto_install(ships, 4);
	ship_auto_install(ships, 3);
	ship_auto_install(ships, 3);
	ship_auto_install(ships, 2);
	ship_auto_install(ships, 2);
	ship_auto_install(ships, 2);
	ship_auto_install(ships, 1);
	ship_auto_install(ships, 1);
	ship_auto_install(ships, 1);
	ship_auto_install(ships, 1);
}

void kill_ship_fill_miss_char_around(const int& x, const int& y, char hits[][10])
{
	int i;
	if (x == 0 and y == 0)
	{
		if (hits[y][x + 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y + 1][x + i] = get_status_char(Miss);
			do
			{
				i++;
				hits[y + 1][x + i] = get_status_char(Miss);
			} while (hits[y][x + i] == get_status_char(Kill));
			hits[y][x + i] = get_status_char(Miss);
		}
		else if (hits[y + 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y + i][x + 1] = get_status_char(Miss);
			do
			{
				i++;
				hits[y + i][x + 1] = get_status_char(Miss);
			} while (hits[y + i][x] == get_status_char(Kill));
			hits[y + i][x] = get_status_char(Miss);
		}
		else
		{
			hits[y][x + 1] = get_status_char(Miss);
			hits[y + 1][x] = get_status_char(Miss);
			hits[y + 1][x + 1] = get_status_char(Miss);
		}
	}
	//---------------------------------------------------------------------------
	else if (x == 9 and y == 0)
	{
		if (hits[y][x - 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y + 1][x - i] = get_status_char(Miss);
			do
			{
				i++;
				hits[y + 1][x - i] = get_status_char(Miss);
			} while (hits[y][x - i] == get_status_char(Kill));
			hits[y][x + i] = get_status_char(Miss);
		}
		else if (hits[y + 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y + i][x - 1] = get_status_char(Miss);
			do
			{
				i++;
				hits[y + i][x - 1] = get_status_char(Miss);
			} while (hits[y + i][x] == get_status_char(Kill));
			hits[y + i][x] = get_status_char(Miss);
		}
		else
		{
			hits[y][x - 1] = get_status_char(Miss);
			hits[y + 1][x] = get_status_char(Miss);
			hits[y + 1][x - 1] = get_status_char(Miss);
		}
	}
	//---------------------------------------------------------------------------
	else if (x == 9 and y == 9)
	{
		if (hits[y][x - 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y - 1][x - i] = get_status_char(Miss);
			do
			{
				i++;
				hits[y - 1][x - i] = get_status_char(Miss);
			} while (hits[y][x - i] == get_status_char(Kill));
			hits[y][x - i] = get_status_char(Miss);
		}
		else if (hits[y - 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y - i][x - 1] = get_status_char(Miss);
			do
			{
				i++;
				hits[y - i][x - 1] = get_status_char(Miss);
			} while (hits[y - i][x] == get_status_char(Kill));
			hits[y - i][x] = get_status_char(Miss);
		}
		else
		{
			hits[y][x - 1] = get_status_char(Miss);
			hits[y - 1][x] = get_status_char(Miss);
			hits[y - 1][x - 1] = get_status_char(Miss);
		}
	}
	//---------------------------------------------------------------------------
	else if (x == 0 and y == 9)
	{
		if (hits[y][x + 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y - 1][x + i] = get_status_char(Miss);
			do
			{
				i++;
				hits[y - 1][x + i] = get_status_char(Miss);
			} while (hits[y][x + i] == get_status_char(Kill));
			hits[y][x + i] = get_status_char(Miss);
		}
		else if (hits[y - 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y - i][x + 1] = get_status_char(Miss);
			do
			{
				i++;
				hits[y - i][x + 1] = get_status_char(Miss);
			} while (hits[y - i][x] == get_status_char(Kill));
			hits[y - i][x] = get_status_char(Miss);
		}
		else
		{
			hits[y][x + 1] = get_status_char(Miss);
			hits[y - 1][x] = get_status_char(Miss);
			hits[y - 1][x + 1] = get_status_char(Miss);
		}
	}
	//---------------------------------------------------------------------------
	else if (x == 0)
	{
		if (hits[y][x + 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y - 1][x + i] = get_status_char(Miss);
			hits[y + 1][x + i] = get_status_char(Miss);
			do
			{
				i++;
				hits[y - 1][x + i] = get_status_char(Miss);
				hits[y + 1][x + i] = get_status_char(Miss);
			} while (hits[y][x + i] == get_status_char(Kill));
			hits[y][x + i] = get_status_char(Miss);
		}
		else if(hits[y - 1][x] == get_status_char(Kill) or
				hits[y + 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y - i][x + 1] = get_status_char(Miss);
			do
			{
				i++;
				if ((y - i) >= 0)
					hits[y - i][x + 1] = get_status_char(Miss);
			} while (hits[y - i][x] == get_status_char(Kill));
			if ((y - i) >= 0) hits[y - i][x] = get_status_char(Miss);

			i = 0;
			hits[y + i][x + 1] = get_status_char(Miss);
			do
			{
				i++;
				if ((y + i) <= 9)
					hits[y + i][x + 1] = get_status_char(Miss);
			} while (hits[y + i][x] == get_status_char(Kill));
			if ((y + i) <= 9) hits[y + i][x] = get_status_char(Miss);
		}
		else
		{
			hits[y][x + 1] = get_status_char(Miss);
			hits[y - 1][x] = get_status_char(Miss);
			hits[y + 1][x] = get_status_char(Miss);
			hits[y + 1][x + 1] = get_status_char(Miss);
			hits[y - 1][x + 1] = get_status_char(Miss);
		}
	}
	//---------------------------------------------------------------------------
	else if (x == 9)
	{
		if (hits[y][x - 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y - 1][x - i] = get_status_char(Miss);
			hits[y + 1][x - i] = get_status_char(Miss);
			do
			{
				i++;
				hits[y - 1][x - i] = get_status_char(Miss);
				hits[y + 1][x - i] = get_status_char(Miss);
			} while (hits[y][x - i] == get_status_char(Kill));
			hits[y][x - i] = get_status_char(Miss);
		}
		else if (hits[y - 1][x] == get_status_char(Kill) or
				hits[y + 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y - i][x - 1] = get_status_char(Miss);
			do
			{
				i++;
				if ((y - i) >= 0)
					hits[y - i][x - 1] = get_status_char(Miss);
			} while (hits[y - i][x] == get_status_char(Kill));
			if ((y - i) >= 0) hits[y - i][x] = get_status_char(Miss);

			i = 0;
			hits[y + i][x - 1] = get_status_char(Miss);
			do
			{
				i++;
				if ((y + i) <= 9)
					hits[y + i][x - 1] = get_status_char(Miss);
			} while (hits[y + i][x] == get_status_char(Kill));
			if ((y + i) <= 9) hits[y + i][x] = get_status_char(Miss);
		}
		else
		{
			hits[y][x - 1] = get_status_char(Miss);
			hits[y - 1][x] = get_status_char(Miss);
			hits[y + 1][x] = get_status_char(Miss);
			hits[y + 1][x - 1] = get_status_char(Miss);
			hits[y - 1][x - 1] = get_status_char(Miss);
		}
	}
	//---------------------------------------------------------------------------
	else if (y == 0)
	{
		if (hits[y + 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y + i][x + 1] = get_status_char(Miss);
			do
			{
				i++;
				hits[y + i][x + 1] = get_status_char(Miss);
			} while (hits[y + i][x] == get_status_char(Kill));
			hits[y + i][x] = get_status_char(Miss);
		}
		else if (hits[y][x - 1] == get_status_char(Kill) or
				hits[y][x + 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y + 1][x - i] = get_status_char(Miss);
			do
			{
				i++;
				if ((x - i) >= 0)
					hits[y + 1][x - i] = get_status_char(Miss);
			} while (hits[y][x - i] == get_status_char(Kill));
			if ((x - i) >= 0) hits[y][x - i] = get_status_char(Miss);

			i = 0;
			hits[y + 1][x + i] = get_status_char(Miss);
			do
			{
				i++;
				if ((x + i) <= 9)
					hits[y + 1][x + i] = get_status_char(Miss);
			} while (hits[y][x + i] == get_status_char(Kill));
			if ((x + i) <= 9) hits[y][x + i] = get_status_char(Miss);
		}
		else
		{
			hits[y][x - 1] = get_status_char(Miss);
			hits[y][x + 1] = get_status_char(Miss);
			hits[y + 1][x] = get_status_char(Miss);
			hits[y + 1][x - 1] = get_status_char(Miss);
			hits[y + 1][x + 1] = get_status_char(Miss);
		}
	}
	//---------------------------------------------------------------------------
	else if (y == 9)
	{
		if (hits[y - 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y - i][x + 1] = get_status_char(Miss);
			hits[y - i][x - 1] = get_status_char(Miss);
			do
			{
				i++;
				hits[y - i][x + 1] = get_status_char(Miss);
				hits[y - i][x - 1] = get_status_char(Miss);
			} while (hits[y - i][x] == get_status_char(Kill));
			hits[y - i][x] = get_status_char(Miss);
		}
		else if (hits[y][x - 1] == get_status_char(Kill) or
				hits[y][x + 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y - 1][x - i] = get_status_char(Miss);
			do
			{
				i++;
				if ((x - i) >= 0)
					hits[y - 1][x - i] = get_status_char(Miss);
			} while (hits[y][x - i] == get_status_char(Kill));
			if ((x - i) >= 0) hits[y][x - i] = get_status_char(Miss);

			i = 0;
			hits[y - 1][x + i] = get_status_char(Miss);
			do
			{
				i++;
				if ((x + i) <= 9)
					hits[y - 1][x + i] = get_status_char(Miss);
			} while (hits[y][x + i] == get_status_char(Kill));
			if ((x + i) <= 9) hits[y][x + i] = get_status_char(Miss);
		}
		else
		{
			hits[y][x - 1] = get_status_char(Miss);
			hits[y][x + 1] = get_status_char(Miss);
			hits[y - 1][x] = get_status_char(Miss);
			hits[y - 1][x - 1] = get_status_char(Miss);
			hits[y - 1][x + 1] = get_status_char(Miss);
		}
	}
	//---------------------------------------------------------------------------
	else
	{
		if (hits[y - 1][x] == get_status_char(Kill) or
			hits[y + 1][x] == get_status_char(Kill))
		{
			i = 0;
			hits[y - i][x + 1] = get_status_char(Miss);
			hits[y - i][x - 1] = get_status_char(Miss);
			do
			{
				i++;
				if ((y - i) >= 0)
				{
					hits[y - i][x + 1] = get_status_char(Miss);
					hits[y - i][x - 1] = get_status_char(Miss);
				}
			} while (hits[y - i][x] == get_status_char(Kill));
			if ((y - i) >= 0) hits[y - i][x] = get_status_char(Miss);

			i = 0;
			hits[y + i][x + 1] = get_status_char(Miss);
			hits[y + i][x - 1] = get_status_char(Miss);
			do
			{
				i++;
				if ((y + i) <= 9)
				{
					hits[y + i][x + 1] = get_status_char(Miss);
					hits[y + i][x - 1] = get_status_char(Miss);
				}
			} while (hits[y + i][x] == get_status_char(Kill));
			if ((y + i) <= 9) hits[y + i][x] = get_status_char(Miss);
		}
		else if (hits[y][x - 1] == get_status_char(Kill) or
				hits[y][x + 1] == get_status_char(Kill))
		{
			i = 0;
			hits[y - 1][x - i] = get_status_char(Miss);
			hits[y + 1][x - i] = get_status_char(Miss);
			do
			{
				i++;
				if ((x - i) >= 0)
				{
					hits[y - 1][x - i] = get_status_char(Miss);
					hits[y + 1][x - i] = get_status_char(Miss);
				}
			} while (hits[y][x - i] == get_status_char(Kill));
			if ((x - i) >= 0) hits[y][x - i] = get_status_char(Miss);

			i = 0;
			hits[y - 1][x + i] = get_status_char(Miss);
			hits[y + 1][x + i] = get_status_char(Miss);
			do
			{
				i++;
				if ((x + i) <= 9)
				{
					hits[y - 1][x + i] = get_status_char(Miss);
					hits[y + 1][x + i] = get_status_char(Miss);
				}
			} while (hits[y][x + i] == get_status_char(Kill));
			if ((x + i) <= 9) hits[y][x + i] = get_status_char(Miss);
		}
		else
		{
			hits[y][x - 1] = get_status_char(Miss);
			hits[y][x + 1] = get_status_char(Miss);
			hits[y - 1][x] = get_status_char(Miss);
			hits[y + 1][x] = get_status_char(Miss);
			hits[y - 1][x - 1] = get_status_char(Miss);
			hits[y - 1][x + 1] = get_status_char(Miss);
			hits[y + 1][x - 1] = get_status_char(Miss);
			hits[y + 1][x + 1] = get_status_char(Miss);
		}
	}
}

void choice_dir(char hits[][10], int& x, int& y)
{
	Direction dir;
	while (true)
	{
		dir = static_cast<Direction>(1 + rand() % 4);
		switch (dir)
		{
		case Up:
			if ((y - 1) < 0 or hits[y - 1][x] == get_status_char(Miss) or hits[y - 1][x] == get_status_char(Hit))
				continue;
			y = y - 1;
			break;
		case Down:
			if ((y + 1) > 9 or hits[y + 1][x] == get_status_char(Miss) or hits[y - 1][x] == get_status_char(Hit))
				continue;
			y = y + 1;
			break;
		case Right:
			if ((x + 1) > 9 or hits[y][x + 1] == get_status_char(Miss) or hits[y][x + 1] == get_status_char(Hit))
				continue;
			x = x + 1;
			break;
		case Left:
			if ((x - 1) < 0 or hits[y][x - 1] == get_status_char(Miss) or hits[y][x - 1] == get_status_char(Hit))
				continue;
			x = x - 1;
			break;
		}
		break;
	}
}

int sym_count(char hits[][10], Status status)
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (hits[i][j] == get_status_char(status))
				count++;
		}
	}
	return count;
}

void player_move(Player& player1, Player& player2, bool& game)
{
	cout << "\t" << player1.name << "\t\t\n";
	COORD coord = get_�oords();
	int x, y;
	while (game)
	{
		cls(coord);
		cout << "\n������� ���������� ��� ��������\n\n";
		enter_coord(x, y);
		if (player2.ships[y][x] == get_status_char(Deck)) //���� ����� � ������
		{
			// ����������� ������ ������ �����
			player1.hits[y][x] = get_status_char(Hit);
			player2.ships[y][x] = get_status_char(Hit);
			bool is_deck = false;
			//������ �������� �� ��� ��������������� ������ � ��������� �������
			//(�� ������, ���� ��������������� ������ ��������� � ��������������� ����� �� ������� ��������� �������������� �������)
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (player2.ships[i][j] == get_status_char(Hit))
					{
						if (check_up(j, i, player2.ships, 1, Deck))
							is_deck = true;
					}
				}
			}
			if (!check_up(x, y, player2.ships, 1, Deck) and !is_deck) //��������� ���� �� ����� ������ � �������� (��� ����������� ���� ��� �����)
			{
				player1.hits[y][x] = get_status_char(Hit);
				player2.ships[y][x] = get_status_char(Hit);
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (player1.hits[i][j] == get_status_char(Hit))
						{
							player1.hits[i][j] = get_status_char(Kill);
							player2.ships[i][j] = get_status_char(Kill);
						}
					}
				}
				kill_ship_fill_miss_char_around(x, y, player1.hits);
				cls();
				print_fields(player1.ships, player1.hits);
				cout << "\t" << player1.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - ����!\n";
				Sleep(2000);
				end_game(player1, player2, game);
				continue;
			}
			else
			{
				cls();
				print_fields(player1.ships, player1.hits);
				cout << "\t" << player1.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - �����!\n";
				Sleep(2000);
				continue;
			}
		}
		else if (player2.ships[y][x] == get_status_char(Sea)) //���� ����� � ������� (����)
		{
			player1.hits[y][x] = get_status_char(Miss);
			cls();
			print_fields(player1.ships, player1.hits);
			cout << "\t" << player1.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - ����!\n";
			Sleep(2000);
			return;
		}
		else
		{
			cls();
			print_fields(player1.ships, player1.hits);
			cout << "\t" << player1.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - ����!\n";
			Sleep(2000);
			return;
		}
	}
}

void pc_easy_coord_choice(Player& player1, Player& player2, int& hit_x, int& hit_y, int& x, int& y, bool& is_hit, bool& is_hit_after_miss)
{
	if (!is_hit and !is_hit_after_miss)
	{
		x = rand() % 10;
		y = rand() % 10;
	}
	else if (is_hit_after_miss) //���� � ������� ��� ������ �������, � ����� �����������
	{
		is_hit_after_miss = false;
		int count = sym_count(player2.hits, Hit);
		if (count == 1) // ������� ������ 1 �������� ������
		{
			// ����������� ������� ����������� ��������, ������� ��������� ����� ������� �������
			// � �������� ����������� �������� ������������ ���
			x = hit_x;
			y = hit_y;
			choice_dir(player2.hits, x, y);
		}
		else // ����� 1 ������
		{
			// ����������� �������� ������� �����������
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (player2.hits[i][j] == get_status_char(Hit)) // ���� ������ ������ �����
						if (i == hit_y and j == hit_x) // � ���� ���������� ����� ���, ������� ��������� ��� ������ �������
							continue; // ����������
						else // �����������
						{
							x = j;
							y = i;
						}
				}
			} // �������� ����������
			if ((x - hit_x) > 0)
				x = hit_x - 1;
			else if ((x - hit_x) < 0)
				x = hit_x + 1;
			else if ((y - hit_y) > 0)
				y = hit_y - 1;
			else if ((y - hit_y) < 0)
				y = hit_y + 1;
		}
	}
	else // ���� �����
	{
		int count = sym_count(player2.hits, Hit);
		if (count == 1) // ������� ������
		{
			hit_x = x;
			hit_y = y;
			choice_dir(player2.hits, x, y);
		}
		else
		{
			if ((x - hit_x) > 0)
			{
				if ((x + 1) <= 9 and player2.hits[x + 1][y] != get_status_char(Miss))
					x = x + 1;
				else
					x = hit_x - 1;
			}
			else if ((x - hit_x) < 0)
			{
				if ((x - 1) >= 0 and player2.hits[x - 1][y] != get_status_char(Miss))
					x = x - 1;
				else
					x = hit_x + 1;
			}
			else if ((y - hit_y) > 0)
			{
				if ((y + 1) <= 9 and player2.hits[x][y + 1] != get_status_char(Miss))
					y = y + 1;
				else
					y = hit_y - 1;
			}
			else if ((y - hit_y) < 0)
			{
				if ((y - 1) >= 0 and player2.hits[x][y - 1] != get_status_char(Miss))
					y = y - 1;
				else
					y = hit_y + 1;
			}
		}
	}
}

void pc_easy_move(Player& player1, Player& player2, bool& is_hit_after_miss, int& hit_x, int& hit_y, bool& game, const int& pc)
{
	cout << "\t" << player2.name << "\t\t\n";
	COORD coord = get_�oords();
	Direction dir;
	int x, y;
	bool is_hit = false; //��������� ����� ��� ��� (��� ����, ����� ����� ���� ��� ����� �� �������� �������� ����������)
	while (game)
	{
		cls(coord);
		pc_easy_coord_choice(player1, player2, hit_x, hit_y, x, y, is_hit, is_hit_after_miss);
		if (player1.ships[y][x] == get_status_char(Deck)) //���� ����� � ������
		{
			player2.hits[y][x] = get_status_char(Hit);
			player1.ships[y][x] = get_status_char(Hit);
			bool is_deck = false;
			//������ �������� �� ��� ��������������� ������ � ��������� �������
			//(�� ������, ���� ��������������� ������ ��������� � ��������������� ����� �� ������� ��������� �������������� �������)
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (player1.ships[i][j] == get_status_char(Hit))
					{
						if (check_up(j, i, player1.ships, 1, Deck))
							is_deck = true;
					}
				}
			}
			//��������� ���� �� ����� ������ � �������� (��� ����������� ���� ��� �����)
			if (!check_up(x, y, player1.ships, 1, Deck) and !is_deck) //���� ����
			{
				player2.hits[y][x] = get_status_char(Hit);
				player1.ships[y][x] = get_status_char(Hit);
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (player2.hits[i][j] == get_status_char(Hit))
						{
							player2.hits[i][j] = get_status_char(Kill);
							player1.ships[i][j] = get_status_char(Kill);
						}
					}
				}
				cls();
				if (pc == 0) //��������� � ��� ������, ���� � ��������� �� 0
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					//kill_ship_fill_miss_char_around(x, y, player1.hits);----------------------------------------------------------------------------------------------------
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player1.ships, player1.hits);
				}
				else if(pc == 1) //1-� �� 2-� �����������
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player1.hits, player2.hits);
				}
				else if(pc == 2) //2-� �� 2-� �����������
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player2.hits, player1.hits);
				}
				is_hit_after_miss = false;
				is_hit = false;
				cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - ����!\n";
				Sleep(4000);
				end_game(player2, player1, game);
				continue;
			}
			else //���� �����
			{
				is_hit = true;
				cls();
				if (pc == 0)
					print_fields(player1.ships, player1.hits);
				else if (pc == 1)
					print_fields(player1.hits, player2.hits);
				else if (pc == 2)
					print_fields(player2.hits, player1.hits);
				cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - �����!\n";
				Sleep(4000);
				continue;
			}
		}
		else if (player1.ships[y][x] == get_status_char(Sea)) //���� ����� � ������� (����)
		{
			player2.hits[y][x] = get_status_char(Miss);
			player1.ships[y][x] = get_status_char(Miss);
			cls();
			if (pc == 0)
				print_fields(player1.ships, player1.hits);
			else if (pc == 1)
				print_fields(player1.hits, player2.hits);
			else if (pc == 2)
				print_fields(player2.hits, player1.hits);
			int count = sym_count(player2.hits, Hit);
			if(count > 0)
				is_hit_after_miss = true;
			cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - ����!\n";
			Sleep(4000);
			return;
		}
		else
			continue;
	}
}

void pc_hard_coord_choice(Player& player1, Player& player2, int& hit_x, int& hit_y, int& x, int& y, bool& is_hit, bool& is_hit_after_miss, 
							int& i, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack)
{
		if (!is_hit and !is_hit_after_miss)
		{
			if (i <= pc_hard_4deck_attack.size())
			{
				x = pc_hard_4deck_attack[i].X;
				y = pc_hard_4deck_attack[i].Y;
				i++;
			}
			else if (i <= (pc_hard_3_2deck_attack.size() + pc_hard_4deck_attack.size()) and i > pc_hard_4deck_attack.size())
			{
				x = pc_hard_3_2deck_attack[i].X;
				y = pc_hard_3_2deck_attack[i].Y;
				i++;
			}
			else
			{
				x = rand() % 10;
				y = rand() % 10;
			}
		}
		else if (is_hit_after_miss) //���� � ������� ��� ������ �������, � ����� �����������
		{
			is_hit_after_miss = false;
			int count = sym_count(player2.hits, Hit);
			if (count == 1) // ������� ������ 1 �������� ������
			{
				// ����������� ������� ����������� ��������, ������� ��������� ����� ������� �������
				// � �������� ����������� �������� ������������ ���
				x = hit_x;
				y = hit_y;
				choice_dir(player2.hits, x, y);
			}
			else // ����� 1 ������
			{
				// ����������� �������� ������� �����������
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (player2.hits[i][j] == get_status_char(Hit)) // ���� ������ ������ �����
							if (i == hit_y and j == hit_x) // � ���� ���������� ����� ���, ������� ��������� ��� ������ �������
								continue; // ����������
							else // �����������
							{
								x = j;
								y = i;
							}
					}
				} // �������� ����������
				if ((x - hit_x) > 0)
					x = hit_x - 1;
				else if ((x - hit_x) < 0)
					x = hit_x + 1;
				else if ((y - hit_y) > 0)
					y = hit_y - 1;
				else if ((y - hit_y) < 0)
					y = hit_y + 1;
			}
		}
		else // ���� �����
		{
			int count = sym_count(player2.hits, Hit);
			if (count == 1) // ������� ������
			{
				hit_x = x;
				hit_y = y;
				choice_dir(player2.hits, x, y);
			}
			else
			{
				if ((x - hit_x) > 0)
				{
					if ((x + 1) <= 9 and player2.hits[x + 1][y] != get_status_char(Miss))
						x = x + 1;
					else
						x = hit_x - 1;
				}
				else if ((x - hit_x) < 0)
				{
					if ((x - 1) >= 0 and player2.hits[x - 1][y] != get_status_char(Miss))
						x = x - 1;
					else
						x = hit_x + 1;
				}
				else if ((y - hit_y) > 0)
				{
					if ((y + 1) <= 9 and player2.hits[x][y + 1] != get_status_char(Miss))
						y = y + 1;
					else
						y = hit_y - 1;
				}
				else if ((y - hit_y) < 0)
				{
					if ((y - 1) >= 0 and player2.hits[x][y - 1] != get_status_char(Miss))
						y = y - 1;
					else
						y = hit_y + 1;
				}
			}
		}
}

void pc_hard_move(Player& player1, Player& player2, bool& is_hit_after_miss, int& hit_x, int& hit_y, bool& game, const int& pc,
					int& i, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack)
{
	cout << "\t" << player2.name << "\t\t\n";
	cout << "\t" << "��������� (�������)" << "\t\n";
	COORD coord = get_�oords();
	Direction dir;
	int x, y;
	bool is_hit = false; //��������� ����� ��� ��� (��� ����, ����� ����� ���� ��� ����� �� �������� �������� ����������)
	while (game)
	{
		cls(coord);
		pc_hard_coord_choice(player1, player2, hit_x, hit_y, x, y, is_hit, is_hit_after_miss, i, pc_hard_4deck_attack, pc_hard_3_2deck_attack);
		if (player1.ships[y][x] == get_status_char(Deck)) //���� ����� � ������
		{
			player2.hits[y][x] = get_status_char(Hit);
			player1.ships[y][x] = get_status_char(Hit);
			bool is_deck = false;
			//������ �������� �� ��� ��������������� ������ � ��������� �������
			//(�� ������, ���� ��������������� ������ ��������� � ��������������� ����� �� ������� ��������� �������������� �������)
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (player1.ships[i][j] == get_status_char(Hit))
					{
						if (check_up(j, i, player1.ships, 1, Deck))
							is_deck = true;
					}
				}
			}
			//��������� ���� �� ����� ������ � �������� (��� ����������� ���� ��� �����)
			if (!check_up(x, y, player1.ships, 1, Deck) and !is_deck) //���� ����
			{
				player2.hits[y][x] = get_status_char(Hit);
				player1.ships[y][x] = get_status_char(Hit);
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (player2.hits[i][j] == get_status_char(Hit))
						{
							player2.hits[i][j] = get_status_char(Kill);
							player1.ships[i][j] = get_status_char(Kill);
						}
					}
				}
				cls();
				if (pc == 0) //��������� � ��� ������, ���� � ��������� �� 0
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player1.ships, player1.hits);
				}
				else if (pc == 1) //1-� �� 2-� �����������
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player1.hits, player2.hits);
				}
				else if (pc == 2) //2-� �� 2-� �����������
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player2.hits, player1.hits);
				}
				is_hit_after_miss = false;
				is_hit = false;
				cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - ����!\n";
				Sleep(4000);
				end_game(player2, player1, game);
				continue;
			}
			else //���� �����
			{
				is_hit = true;
				cls();
				if (pc == 0)
					print_fields(player1.ships, player1.hits);
				else if (pc == 1)
					print_fields(player1.hits, player2.hits);
				else if (pc == 2)
					print_fields(player2.hits, player1.hits);
				cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - �����!\n";
				Sleep(4000);
				continue;
			}
		}
		else if (player1.ships[y][x] == get_status_char(Sea)) //���� ����� � ������� (����)
		{
			player2.hits[y][x] = get_status_char(Miss);
			player1.ships[y][x] = get_status_char(Miss);
			cls();
			if (pc == 0)
				print_fields(player1.ships, player1.hits);
			else if (pc == 1)
				print_fields(player1.hits, player2.hits);
			else if (pc == 2)
				print_fields(player2.hits, player1.hits);
			int count = sym_count(player2.hits, Hit);
			if (count > 0)
				is_hit_after_miss = true;
			cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - ����!\n";
			Sleep(4000);
			return;
		}
		else
			continue;
	}
}

void game_hard(Player& player1, Player& player2, const int& pc, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack, 
																const vector<Point>& pc_hard_4deck_attack2, const vector<Point>& pc_hard_3_2deck_attack2)
{
	int hit_x; //���������� ��� ���������� ��������� ����� ������� � ��������� � ������
	int hit_y;
	int hit_x2;
	int hit_y2;
	int i_1 = 0; //���������� ��� �������� ��� ������ ��������� ����� � ��
	int i_2 = 0;
	COORD coord;
	bool is_game = true;
	bool is_hit_after_miss = false;  //��������� ���� �� �������� �������, ����� �������� ���� � ����������
	bool is_hit_after_miss2 = false;  //��������� ���� �� �������� �������, ����� �������� ���� � ���������� 2
	while (is_game)
	{
		cls();
		if (pc == 0)
		{
			print_fields(player1.ships, player1.hits);
			coord = get_�oords();
			player_move(player1, player2, is_game);
			if (!is_game) continue;
			pc_hard_move(player1, player2, is_hit_after_miss, hit_x, hit_y, is_game, pc, i_1, pc_hard_4deck_attack, pc_hard_3_2deck_attack);
		}
		else if(pc == 1)
		{
			int pc1 = 1;
			int pc2 = 2;
			print_fields(player2.hits, player1.hits);
			coord = get_�oords();
			pc_hard_move(player2, player1, is_hit_after_miss, hit_x, hit_y, is_game, pc1, i_1, pc_hard_4deck_attack, pc_hard_3_2deck_attack);
			if (!is_game) continue;
			pc_hard_move(player1, player2, is_hit_after_miss2, hit_x2, hit_y2, is_game, pc2, i_2, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
		}
		else
		{
			int pc1 = 1;
			int pc2 = 2;
			print_fields(player2.hits, player1.hits);
			coord = get_�oords();
			pc_easy_move(player2, player1, is_hit_after_miss, hit_x, hit_y, is_game, pc1);
			if (!is_game) continue;
			pc_hard_move(player1, player2, is_hit_after_miss2, hit_x2, hit_y2, is_game, pc2, i_2, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
		}
	}
}

void game_easy(Player& player1, Player& player2, const int& pc)
{
	int hit_x; //���������� ��� ���������� ��������� ����� ������� � ��������� � ������
	int hit_y;
	int hit_x2;
	int hit_y2;
	COORD coord;
	bool is_game = true;
	bool is_hit_after_miss = false;  //��������� ���� �� �������� �������, ����� �������� ���� � ����������
	bool is_hit_after_miss2 = false;  //��������� ���� �� �������� �������, ����� �������� ���� � ���������� 2
	while (is_game)
	{
		cls();
		if (pc == 0)
		{
			print_fields(player1.ships, player1.hits);
			coord = get_�oords();
			player_move(player1, player2, is_game);
			if (!is_game) continue;
			pc_easy_move(player1, player2, is_hit_after_miss, hit_x, hit_y, is_game, pc);
		}
		else
		{
			int pc1 = 1;
			int pc2 = 2;
			print_fields(player2.hits, player1.hits);
			coord = get_�oords();
			pc_easy_move(player2, player1, is_hit_after_miss, hit_x, hit_y, is_game, pc1);
			if (!is_game) continue;
			pc_easy_move(player1, player2, is_hit_after_miss2, hit_x2, hit_y2, is_game, pc2);
		}
	}
}

void game_manager()
{
	//��������� ����� ��� ���� ��(����� 4-� �������� ��������) ��� ������� ���� ��
	vector<Point> pc_hard_4deck_attack1;
	//��������� ����� ��� ���� ��(����� 3-� � 2-� �������� ��������) ��� ������� ���� ��
	vector<Point> pc_hard_3_2deck_attack1;
	fill_pc_hard_attack(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
	//��������� ����� ��� ���� ��(����� 4-� �������� ��������) ��� ������� ���� ��
	vector<Point> pc_hard_4deck_attack2;
	//��������� ����� ��� ���� ��(����� 3-� � 2-� �������� ��������) ��� ������� ���� ��
	vector<Point> pc_hard_3_2deck_attack2;
	fill_pc_hard_attack(pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);

	Player player1;
	Player player2;
	fill_players_fields(player1, player2);
	ships_auto_install(player2.ships);
	bool is_game = true; //������� ��� ������
	char code;
	COORD coord;

	while (is_game)
	{
		cls();
		code = 0;
		cout << "\t������� ���\n\n";
		cout << "\n1 - ������\n";
		cout << "\n0 - �����\n";
		if (code == 0) code = _getch();
		if (_kbhit()) code = _getch();
		switch (code)
		{
		case '1':
		{
			bool flag1 = true; // ��� ������ �� ���� �������� ����
			while (flag1)
			{
				cls();
				code = 0;
				cout << "\n�������� ����� ����:\n";
				cout << "\n1 - ����� ������ ����������\n";
				cout << "\n2 - ��������� ������ ����������\n";
				cout << "\n0 - �����\n";
				if (code == 0) code = _getch();
				if (_kbhit()) code = _getch();
				switch (code)
				{
				case '1':
				{
					bool flag2 = true; // ��� ������ �� ���� �������� ����
					while(flag2)
					{
						cls();
						code = 0;
						cout << "\n����� ������ ����������\n";
						cout << "\n�������� ���������:\n";
						cout << "\n1 - �������\n";
						cout << "\n2 - �������\n";
						cout << "\n0 - �����\n";
						if (code == 0) code = _getch();
						if (_kbhit()) code = _getch();
						switch (code)
						{
						case '1': // �������
						{
							bool flag3 = true; // ��� ������ �� ���� �������� ����
							while(flag3)
							{
								cls();
								code = 0;
								cout << "\n����� ������ ����������\n";
								cout << "\n��������� - �������\n";
								cout << "\n�������� ������ ����������� ����� ��������:\n";
								cout << "\n1 - �������������\n";
								cout << "\n2 - �������\n";
								cout << "\n0 - �����\n";
								if (code == 0) code = _getch();
								if (_kbhit()) code = _getch();
								switch (code)
								{
								case '1':
									ships_auto_install(player1.ships);
									game_easy(player1, player2, 0); //����� 0 ��������, ��� ����� ����� + ��
									flag3 = false;
									flag2 = false;
									flag1 = false;
									break;
								case '2':
									ships_hand_install(player1.ships);
									game_easy(player1, player2, 0); //����� 0 ��������, ��� ����� ����� + ��
									flag3 = false;
									flag2 = false;
									flag1 = false;
									break;
								case '0':
									flag3 = false;
									break;
								default:
									break;
								}
								cls();
							}
						}
							break;
						case '2': // �������
						{
							bool flag3 = true; // ��� ������ �� ���� �������� ����
							while(flag3)
							{
								cls();
								code = 0;
								cout << "\n����� ������ ����������\n";
								cout << "\n��������� - �������\n";
								cout << "\n�������� ������ ����������� ����� ��������:\n";
								cout << "\n1 - �������������\n";
								cout << "\n2 - �������\n";
								cout << "\n0 - �����\n";
								if (code == 0) code = _getch();
								if (_kbhit()) code = _getch();
								switch (code)
								{
								case '1':
									ships_auto_install(player1.ships);
									pc_hard_random(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
									//����� 0 ��������, ��� ����� ����� + ��
									game_hard(player1, player2, 0, pc_hard_4deck_attack1, pc_hard_3_2deck_attack1, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
									break;
								case '2':
									ships_hand_install(player1.ships);
									pc_hard_random(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
									//����� 0 ��������, ��� ����� ����� + ��
									game_hard(player1, player2, 0, pc_hard_4deck_attack1, pc_hard_3_2deck_attack1, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
									break;
								case '0':
									flag3 = false;
									break;
								default:
									break;
								}
							}
						}
							break;
						case '0':
							flag2 = false;
							break;
						default:
							break;
						}
					}
				}
					break;
				case '2':
				{
					bool flag2 = true; // ��� ������ �� ���� �������� ����
					while (flag2)
					{
						cls();
						code = 0;
						cout << "\n�������� ����� ����:\n";
						cout << "\n1 - ���������(�������) ������ ����������(�������)\n";
						cout << "\n2 - ���������(�������) ������ ����������(�������)\n";
						cout << "\n3 - ���������(�������) ������ ����������(�������)\n";
						cout << "\n0 - �����\n";
						if (code == 0) code = _getch();
						if (_kbhit()) code = _getch();
						switch (code)
						{
						case '1': // ������� ������ ��������
						{
							ships_auto_install(player1.ships);
							game_easy(player1, player2, 1); //����� 1 ��������, ��� ����� �� + ��
							flag2 = false;
							flag1 = false;
						}
							break;
						case '2': // ������� ������ ��������
						{
							ships_auto_install(player1.ships);
							pc_hard_random(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
							//����� 2 ��������, ��� ����� ������ �� + ���� ��
							game_hard(player1, player2, 2, pc_hard_4deck_attack1, pc_hard_3_2deck_attack1, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
							break;
						}
							break;
						case '3': // ������� ������ ��������
						{
							ships_auto_install(player1.ships);
							pc_hard_random(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
							pc_hard_random(pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
							//����� 1 ��������, ��� ����� �� + ��
							game_hard(player1, player2, 1, pc_hard_4deck_attack1, pc_hard_3_2deck_attack1, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
							break;
						}
							break;
						case '0':
							flag2 = false;
							break;
						default:
							break;
						}
					}
				}
					break;
				case '0':
					flag1 = false;
					break;
				default:
					break;
				}
			}
		}
			break;
		case '0':
			is_game = 0;
			break;
		default:
			break;
		}
	}
}
