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
		cout << "\n\n\n\t     КОНЕЦ ИГРЫ!!!\n\n\n";
		cout << "\tВЫИГРАЛ " << player1.name << " !!!!!!!!!\n";
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

COORD get_сoords()
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
	COORD coord = get_сoords();
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
		case 'к':
			cout << "к\n";
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
		for (char c : choice) // проверяем есть ли символы отличные от цифр
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
			cout << "Неверный ввод. Попробуйте еще раз.\n";
			Sleep(2000);
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}

		auto j = stoll(choice); // на случай, если введённое число выходит за диапазон значений инта
		if (j > INT_MAX or j < INT_MIN) // проверяем на диапазон значений инта
			flag = false;

		if (!flag)
		{
			cls(coord);
			cout << "Неверный ввод. Попробуйте еще раз.\n";
			Sleep(2000);
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}

		y = stoi(choice); // преобразуем в инт
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
	Значение в диапазоне от 0 до 15 занимает 4 бита - 0000, соответственно,
	чтобы сохранить значения двух объектов внутри одного, необходимо значение одного сдвинуть на 4 бита влево.
	Предположим, что:
	background = 0x9; // 9 (ярко-синий)
	foreground = 0xf; // 15 (ярко-белый)

	В бинарном представлении background = 1001, а foreground = 1111,
	оба эти значения занимают одинаковую область младшего байта - 0000 1111 (0x0f),
	если применить побитовый сдвиг влево для background, получится следующее:
	0000 1001 << 4 = 1001 0000.
	Затем, применяется побитовая дизъюнкция с foreground:
	1001 0000 | 0000 1111 = 1001 1111.
	И наконец, завершающей операцией является явное приведение через c-style cast к двухбайтовому типу WORD.
	(WORD) 1001 1111 = 0000 0000 1001 1111 (в big-endian), 1001 1111 0000 0000 (в little-endian).
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
	player1.name = "Игрок 1";
	player2.name = "Игрок 2";
}

void print_field(char ships[][10])
{
	cout << "\t   А Б В Г Д Е Ж З И К\n";
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
	cout << "\t      Поле игрока 1\t\t      Поле игрока 2\n\n";
	cout << "\t   А Б В Г Д Е Ж З И К\t\t   А Б В Г Д Е Ж З И К\n";
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
	cout << "\tХодит\t\tСтатус выстрела\n";
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
	COORD coord = get_сoords();
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
	//	case 'А':
	//	case 'а':
	//		cout << "а\n";
	//		x = 0;
	//		flag = false;
	//		break;
	//	case 'Б':
	//	case 'б':
	//		cout << "б\n";
	//		x = 1;
	//		flag = false;
	//		break;
	//	case 'В':
	//	case 'в':
	//		cout << "в\n";
	//		x = 2;
	//		flag = false;
	//		break;
	//	case 'Г':
	//	case 'г':
	//		cout << "г\n";
	//		x = 3;
	//		flag = false;
	//		break;
	//	case 'Д':
	//	case 'д':
	//		cout << "д\n";
	//		x = 4;
	//		flag = false;
	//		break;
	//	case 'Е':
	//	case 'е':
	//		cout << "е\n";
	//		x = 5;
	//		flag = false;
	//		break;
	//	case 'Ж':
	//	case 'ж':
	//		cout << "ж\n";
	//		x = 6;
	//		flag = false;
	//		break;
	//	case 'З':
	//	case 'з':
	//		cout << "з\n";
	//		x = 7;
	//		flag = false;
	//		break;
	//	case 'И':
	//	case 'и':
	//		cout << "и\n";
	//		x = 8;
	//		flag = false;
	//		break;
	//	case 'К':
	//	case 'к':
	//		cout << "к\n";
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
		if (choice == "А" or choice == "а" or
			choice == "Б" or choice == "б" or
			choice == "В" or choice == "в" or
			choice == "Г" or choice == "г" or
			choice == "Д" or choice == "д" or
			choice == "Е" or choice == "е" or
			choice == "Ж" or choice == "ж" or
			choice == "З" or choice == "з" or
			choice == "И" or choice == "и" or
			choice == "К" or choice == "к")
		{
			char letter = choice[0];
			switch (letter)
			{
			case 'А':
			case 'а':
				x = 0;
				break;
			case 'Б':
			case 'б':
				x = 1;
				break;
			case 'В':
			case 'в':
				x = 2;
				break;
			case 'Г':
			case 'г':
				x = 3;
				break;
			case 'Д':
			case 'д':
				x = 4;
				break;
			case 'Е':
			case 'е':
				x = 5;
				break;
			case 'Ж':
			case 'ж':
				x = 6;
				break;
			case 'З':
			case 'з':
				x = 7;
				break;
			case 'И':
			case 'и':
				x = 8;
				break;
			case 'К':
			case 'к':
				x = 9;
				break;
			}
			flag = false;
		}
		else
		{
			cls(coord);
			cout << "Неверный ввод. Попробуйте еще раз.\n";
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
		sym = 'А';
		break;
	case 1:
		sym = 'Б';
		break;
	case 2:
		sym = 'В';
		break;
	case 3:
		sym = 'Г';
		break;
	case 4:
		sym = 'Д';
		break;
	case 5:
		sym = 'Е';
		break;
	case 6:
		sym = 'Ж';
		break;
	case 7:
		sym = 'З';
		break;
	case 8:
		sym = 'И';
		break;
	case 9:
		sym = 'К';
		break;
	}
	return sym;
}

void enter_coord(int& x, int& y)
{
	string choice;
	bool flag = true;
	COORD coord = get_сoords();
	while (flag)
	{
		cls(coord);
		cout << "Введите букву: ";
		x = get_letter_int();
		cout << "Введите цифру: ";
		y = get_int_choice();
		if (y > 0 and y < 11)
			y = y - 1;
		else
		{
			cls(coord);
			cout << "Неверные координаты. Попробуйте еще раз.\n";
			Sleep(2000);
			continue;
		}
		flag = false;
	}

}

void negative_dir_massage(COORD coord)
{
	cls(coord);
	cout << "В этом направлении установить корабль нельзя. Попробуйте еще раз.\n";
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
		coord = get_сoords();
		if(ship_size == 1)
			cout << "Введите координаты корабля ( " << ship_size << "-палубный)\n\n";
		else
			cout << "Введите начальные координаты корабля ( " << ship_size << "-палубный)\n\n";
		enter_coord(deck_x, deck_y);
		if (check_up(deck_x, deck_y, ships, 1, Deck))
		{
			cls(coord);
			cout << "Размещать корабль рядом с другими запрещено. Попробуйте еще раз.\n";
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
				coord = get_сoords();
				bool is_ship = false;
				cout << "Укажите, в каком направлении будет располагаться хвостовая часть корабля.\n\n";
				cout << "1 - Вверх\n";
				cout << "2 - Вниз\n";
				cout << "3 - Вправо\n";
				cout << "4 - Влево\n";
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
					cout << "Неверный ввод. Попробуйте еще раз.\n";
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
	bool is_instal = true; // создаем флаг для проверки удачно ли разместился корабль
	int deck_y, deck_x;
	Direction dir;
	while (is_instal) // проверка удалось ли разместить корабль
	{
		dir = static_cast<Direction>(1 + rand() % 4); // выбираем направление хвостовой части корабля: 0 - горизонтально вправо, 1 - вертикально вниз
		deck_y = rand() % 10; // случайным образом определяются координаты
		deck_x = rand() % 10;
		bool is_ship = false; // создаем флаг для проверки смежных клеток на наличие кораблей или палуб корабля
		if (ship_size == 1) // установка однопалубынх
		{
			if (ships[deck_y][deck_x] == get_status_char(Sea))
			{
				is_ship = check_up(deck_x, deck_y, ships, ship_size, Deck); // проверка смежных клеток
				if (is_ship == 0)
				{
					ships[deck_y][deck_x] = get_status_char(Deck); // размещаем корабль в массиве ships
					/*Sleep(500);
					system("cls");
					print_field(ships);*/
					is_instal = 0;
				}
			}
		}
		else  // установка многопалубных
		{
			switch (dir)
			{
			case Right:
				if (ships[deck_y][deck_x + ship_size - 1] == get_status_char(Sea) and (deck_x + ship_size - 1) < 10) // проверяем можем ли установить корабль в эту сторону
				{
					is_ship = check_right(deck_x, deck_y, ships, ship_size, Deck); // проверка смежных клеток
					if (is_ship == 0)
					{
						for (int i = 0; i < ship_size; i++)
						{
							ships[deck_y][deck_x + i] = get_status_char(Deck); // размещаем корабль в массиве ships
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
	COORD coord = get_сoords();
	int x, y;
	while (game)
	{
		cls(coord);
		cout << "\nВведите координаты для выстрела\n\n";
		enter_coord(x, y);
		if (player2.ships[y][x] == get_status_char(Deck)) //если попал в палубу
		{
			// присваиваем клетке статус ранил
			player1.hits[y][x] = get_status_char(Hit);
			player2.ships[y][x] = get_status_char(Hit);
			bool is_deck = false;
			//узнаем остались ли ещё непрострелянные палубы у раненного корабля
			//(на случай, если непрострелянная палуба оказалась в противоположном конце от текущих координат многопалубного корабля)
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
			if (!check_up(x, y, player2.ships, 1, Deck) and !is_deck) //проверяем есть ли рядом клетки с палубами (для определения убил или ранил)
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
				cout << "\t" << player1.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Убил!\n";
				Sleep(2000);
				end_game(player1, player2, game);
				continue;
			}
			else
			{
				cls();
				print_fields(player1.ships, player1.hits);
				cout << "\t" << player1.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Ранил!\n";
				Sleep(2000);
				continue;
			}
		}
		else if (player2.ships[y][x] == get_status_char(Sea)) //если попал в пустоту (море)
		{
			player1.hits[y][x] = get_status_char(Miss);
			cls();
			print_fields(player1.ships, player1.hits);
			cout << "\t" << player1.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Мимо!\n";
			Sleep(2000);
			return;
		}
		else
		{
			cls();
			print_fields(player1.ships, player1.hits);
			cout << "\t" << player1.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Мимо!\n";
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
	else if (is_hit_after_miss) //если в прошлый ход подбил корабль, а затем промахнулся
	{
		is_hit_after_miss = false;
		int count = sym_count(player2.hits, Hit);
		if (count == 1) // имеется только 1 подбитая палуба
		{
			// присваиваем текущим координатам значения, которые запомнили после первого ранения
			// и выбираем направление стрельбы относительно них
			x = hit_x;
			y = hit_y;
			choice_dir(player2.hits, x, y);
		}
		else // более 1 палубы
		{
			// присваиваем значения текущим координатам
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (player2.hits[i][j] == get_status_char(Hit)) // если статус клетки ранен
						if (i == hit_y and j == hit_x) // и если координаты равны тем, которые запомнили при первом ранении
							continue; // пропускаем
						else // присваиваем
						{
							x = j;
							y = i;
						}
				}
			} // изменяем координаты
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
	else // если ранил
	{
		int count = sym_count(player2.hits, Hit);
		if (count == 1) // ранение первое
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
	COORD coord = get_сoords();
	Direction dir;
	int x, y;
	bool is_hit = false; //проверяем ранил или нет (для того, чтобы после того как ранил не подбирал рандомно координаты)
	while (game)
	{
		cls(coord);
		pc_easy_coord_choice(player1, player2, hit_x, hit_y, x, y, is_hit, is_hit_after_miss);
		if (player1.ships[y][x] == get_status_char(Deck)) //если попал в палубу
		{
			player2.hits[y][x] = get_status_char(Hit);
			player1.ships[y][x] = get_status_char(Hit);
			bool is_deck = false;
			//узнаем остались ли ещё непрострелянные палубы у раненного корабля
			//(на случай, если непрострелянная палуба оказалась в противоположном конце от текущих координат многопалубного корабля)
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
			//проверяем есть ли рядом клетки с палубами (для определения убил или ранил)
			if (!check_up(x, y, player1.ships, 1, Deck) and !is_deck) //если убил
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
				if (pc == 0) //проверяем с кем играет, если с человеком то 0
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					//kill_ship_fill_miss_char_around(x, y, player1.hits);----------------------------------------------------------------------------------------------------
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player1.ships, player1.hits);
				}
				else if(pc == 1) //1-й из 2-х компьютеров
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player1.hits, player2.hits);
				}
				else if(pc == 2) //2-й из 2-х компьютеров
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player2.hits, player1.hits);
				}
				is_hit_after_miss = false;
				is_hit = false;
				cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Убил!\n";
				Sleep(4000);
				end_game(player2, player1, game);
				continue;
			}
			else //если ранил
			{
				is_hit = true;
				cls();
				if (pc == 0)
					print_fields(player1.ships, player1.hits);
				else if (pc == 1)
					print_fields(player1.hits, player2.hits);
				else if (pc == 2)
					print_fields(player2.hits, player1.hits);
				cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Ранил!\n";
				Sleep(4000);
				continue;
			}
		}
		else if (player1.ships[y][x] == get_status_char(Sea)) //если попал в пустоту (море)
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
			cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Мимо!\n";
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
		else if (is_hit_after_miss) //если в прошлый ход подбил корабль, а затем промахнулся
		{
			is_hit_after_miss = false;
			int count = sym_count(player2.hits, Hit);
			if (count == 1) // имеется только 1 подбитая палуба
			{
				// присваиваем текущим координатам значения, которые запомнили после первого ранения
				// и выбираем направление стрельбы относительно них
				x = hit_x;
				y = hit_y;
				choice_dir(player2.hits, x, y);
			}
			else // более 1 палубы
			{
				// присваиваем значения текущим координатам
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (player2.hits[i][j] == get_status_char(Hit)) // если статус клетки ранен
							if (i == hit_y and j == hit_x) // и если координаты равны тем, которые запомнили при первом ранении
								continue; // пропускаем
							else // присваиваем
							{
								x = j;
								y = i;
							}
					}
				} // изменяем координаты
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
		else // если ранил
		{
			int count = sym_count(player2.hits, Hit);
			if (count == 1) // ранение первое
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
	cout << "\t" << "Компьютер (Сложный)" << "\t\n";
	COORD coord = get_сoords();
	Direction dir;
	int x, y;
	bool is_hit = false; //проверяем ранил или нет (для того, чтобы после того как ранил не подбирал рандомно координаты)
	while (game)
	{
		cls(coord);
		pc_hard_coord_choice(player1, player2, hit_x, hit_y, x, y, is_hit, is_hit_after_miss, i, pc_hard_4deck_attack, pc_hard_3_2deck_attack);
		if (player1.ships[y][x] == get_status_char(Deck)) //если попал в палубу
		{
			player2.hits[y][x] = get_status_char(Hit);
			player1.ships[y][x] = get_status_char(Hit);
			bool is_deck = false;
			//узнаем остались ли ещё непрострелянные палубы у раненного корабля
			//(на случай, если непрострелянная палуба оказалась в противоположном конце от текущих координат многопалубного корабля)
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
			//проверяем есть ли рядом клетки с палубами (для определения убил или ранил)
			if (!check_up(x, y, player1.ships, 1, Deck) and !is_deck) //если убил
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
				if (pc == 0) //проверяем с кем играет, если с человеком то 0
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player1.ships, player1.hits);
				}
				else if (pc == 1) //1-й из 2-х компьютеров
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player1.hits, player2.hits);
				}
				else if (pc == 2) //2-й из 2-х компьютеров
				{
					kill_ship_fill_miss_char_around(x, y, player2.hits);
					kill_ship_fill_miss_char_around(x, y, player1.ships);
					print_fields(player2.hits, player1.hits);
				}
				is_hit_after_miss = false;
				is_hit = false;
				cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Убил!\n";
				Sleep(4000);
				end_game(player2, player1, game);
				continue;
			}
			else //если ранил
			{
				is_hit = true;
				cls();
				if (pc == 0)
					print_fields(player1.ships, player1.hits);
				else if (pc == 1)
					print_fields(player1.hits, player2.hits);
				else if (pc == 2)
					print_fields(player2.hits, player1.hits);
				cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Ранил!\n";
				Sleep(4000);
				continue;
			}
		}
		else if (player1.ships[y][x] == get_status_char(Sea)) //если попал в пустоту (море)
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
			cout << "\t" << player2.name << "\t\t" << get_char_from_x(x) << (y + 1) << " - Мимо!\n";
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
	int hit_x; //переменная для сохранения координат после ранения и попадания в молоко
	int hit_y;
	int hit_x2;
	int hit_y2;
	int i_1 = 0; //переменная для счетчика при выборе координат атаки у ПК
	int i_2 = 0;
	COORD coord;
	bool is_game = true;
	bool is_hit_after_miss = false;  //проверяем есть ли раненные корабли, после прошлого хода у компьютера
	bool is_hit_after_miss2 = false;  //проверяем есть ли раненные корабли, после прошлого хода у компьютера 2
	while (is_game)
	{
		cls();
		if (pc == 0)
		{
			print_fields(player1.ships, player1.hits);
			coord = get_сoords();
			player_move(player1, player2, is_game);
			if (!is_game) continue;
			pc_hard_move(player1, player2, is_hit_after_miss, hit_x, hit_y, is_game, pc, i_1, pc_hard_4deck_attack, pc_hard_3_2deck_attack);
		}
		else if(pc == 1)
		{
			int pc1 = 1;
			int pc2 = 2;
			print_fields(player2.hits, player1.hits);
			coord = get_сoords();
			pc_hard_move(player2, player1, is_hit_after_miss, hit_x, hit_y, is_game, pc1, i_1, pc_hard_4deck_attack, pc_hard_3_2deck_attack);
			if (!is_game) continue;
			pc_hard_move(player1, player2, is_hit_after_miss2, hit_x2, hit_y2, is_game, pc2, i_2, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
		}
		else
		{
			int pc1 = 1;
			int pc2 = 2;
			print_fields(player2.hits, player1.hits);
			coord = get_сoords();
			pc_easy_move(player2, player1, is_hit_after_miss, hit_x, hit_y, is_game, pc1);
			if (!is_game) continue;
			pc_hard_move(player1, player2, is_hit_after_miss2, hit_x2, hit_y2, is_game, pc2, i_2, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
		}
	}
}

void game_easy(Player& player1, Player& player2, const int& pc)
{
	int hit_x; //переменная для сохранения координат после ранения и попадания в молоко
	int hit_y;
	int hit_x2;
	int hit_y2;
	COORD coord;
	bool is_game = true;
	bool is_hit_after_miss = false;  //проверяем есть ли раненные корабли, после прошлого хода у компьютера
	bool is_hit_after_miss2 = false;  //проверяем есть ли раненные корабли, после прошлого хода у компьютера 2
	while (is_game)
	{
		cls();
		if (pc == 0)
		{
			print_fields(player1.ships, player1.hits);
			coord = get_сoords();
			player_move(player1, player2, is_game);
			if (!is_game) continue;
			pc_easy_move(player1, player2, is_hit_after_miss, hit_x, hit_y, is_game, pc);
		}
		else
		{
			int pc1 = 1;
			int pc2 = 2;
			print_fields(player2.hits, player1.hits);
			coord = get_сoords();
			pc_easy_move(player2, player1, is_hit_after_miss, hit_x, hit_y, is_game, pc1);
			if (!is_game) continue;
			pc_easy_move(player1, player2, is_hit_after_miss2, hit_x2, hit_y2, is_game, pc2);
		}
	}
}

void game_manager()
{
	//стратегия атаки для хард ПК(поиск 4-х палубных кораблей) для первого хард ПК
	vector<Point> pc_hard_4deck_attack1;
	//стратегия атаки для хард ПК(поиск 3-х и 2-х палубных кораблей) для первого хард ПК
	vector<Point> pc_hard_3_2deck_attack1;
	fill_pc_hard_attack(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
	//стратегия атаки для хард ПК(поиск 4-х палубных кораблей) для второго хард ПК
	vector<Point> pc_hard_4deck_attack2;
	//стратегия атаки для хард ПК(поиск 3-х и 2-х палубных кораблей) для второго хард ПК
	vector<Point> pc_hard_3_2deck_attack2;
	fill_pc_hard_attack(pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);

	Player player1;
	Player player2;
	fill_players_fields(player1, player2);
	ships_auto_install(player2.ships);
	bool is_game = true; //триггер для выхода
	char code;
	COORD coord;

	while (is_game)
	{
		cls();
		code = 0;
		cout << "\tМОРСКОЙ БОЙ\n\n";
		cout << "\n1 - Играть\n";
		cout << "\n0 - Выход\n";
		if (code == 0) code = _getch();
		if (_kbhit()) code = _getch();
		switch (code)
		{
		case '1':
		{
			bool flag1 = true; // для выхода из этой страницы меню
			while (flag1)
			{
				cls();
				code = 0;
				cout << "\nВыберите режим игры:\n";
				cout << "\n1 - Игрок против компьютера\n";
				cout << "\n2 - Компьютер против компьютера\n";
				cout << "\n0 - Назад\n";
				if (code == 0) code = _getch();
				if (_kbhit()) code = _getch();
				switch (code)
				{
				case '1':
				{
					bool flag2 = true; // для выхода из этой страницы меню
					while(flag2)
					{
						cls();
						code = 0;
						cout << "\nИгрок против компьютера\n";
						cout << "\nВыберите сложность:\n";
						cout << "\n1 - Простая\n";
						cout << "\n2 - Сложная\n";
						cout << "\n0 - Назад\n";
						if (code == 0) code = _getch();
						if (_kbhit()) code = _getch();
						switch (code)
						{
						case '1': // простая
						{
							bool flag3 = true; // для выхода из этой страницы меню
							while(flag3)
							{
								cls();
								code = 0;
								cout << "\nИгрок против компьютера\n";
								cout << "\nКомпьютер - Простой\n";
								cout << "\nВыберите способ расстановки своих кораблей:\n";
								cout << "\n1 - Автоматически\n";
								cout << "\n2 - Вручную\n";
								cout << "\n0 - Назад\n";
								if (code == 0) code = _getch();
								if (_kbhit()) code = _getch();
								switch (code)
								{
								case '1':
									ships_auto_install(player1.ships);
									game_easy(player1, player2, 0); //цифра 0 означает, что режим игрок + ПК
									flag3 = false;
									flag2 = false;
									flag1 = false;
									break;
								case '2':
									ships_hand_install(player1.ships);
									game_easy(player1, player2, 0); //цифра 0 означает, что режим игрок + ПК
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
						case '2': // сложная
						{
							bool flag3 = true; // для выхода из этой страницы меню
							while(flag3)
							{
								cls();
								code = 0;
								cout << "\nИгрок против компьютера\n";
								cout << "\nКомпьютер - Сложный\n";
								cout << "\nВыберите способ расстановки своих кораблей:\n";
								cout << "\n1 - Автоматически\n";
								cout << "\n2 - Вручную\n";
								cout << "\n0 - Назад\n";
								if (code == 0) code = _getch();
								if (_kbhit()) code = _getch();
								switch (code)
								{
								case '1':
									ships_auto_install(player1.ships);
									pc_hard_random(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
									//цифра 0 означает, что режим игрок + ПК
									game_hard(player1, player2, 0, pc_hard_4deck_attack1, pc_hard_3_2deck_attack1, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
									break;
								case '2':
									ships_hand_install(player1.ships);
									pc_hard_random(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
									//цифра 0 означает, что режим игрок + ПК
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
					bool flag2 = true; // для выхода из этой страницы меню
					while (flag2)
					{
						cls();
						code = 0;
						cout << "\nВыберите режим игры:\n";
						cout << "\n1 - Компьютер(простой) против компьютера(простой)\n";
						cout << "\n2 - Компьютер(простой) против компьютера(сложный)\n";
						cout << "\n3 - Компьютер(сложный) против компьютера(сложный)\n";
						cout << "\n0 - Назад\n";
						if (code == 0) code = _getch();
						if (_kbhit()) code = _getch();
						switch (code)
						{
						case '1': // простой против простого
						{
							ships_auto_install(player1.ships);
							game_easy(player1, player2, 1); //цифра 1 означает, что режим ПК + ПК
							flag2 = false;
							flag1 = false;
						}
							break;
						case '2': // простой против сложного
						{
							ships_auto_install(player1.ships);
							pc_hard_random(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
							//цифра 2 означает, что режим легкий ПК + хард ПК
							game_hard(player1, player2, 2, pc_hard_4deck_attack1, pc_hard_3_2deck_attack1, pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
							break;
						}
							break;
						case '3': // сложный против сложного
						{
							ships_auto_install(player1.ships);
							pc_hard_random(pc_hard_4deck_attack1, pc_hard_3_2deck_attack1);
							pc_hard_random(pc_hard_4deck_attack2, pc_hard_3_2deck_attack2);
							//цифра 1 означает, что режим ПК + ПК
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
