#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//��� ������������ ��������� ������ �� ����
enum class Status: char
{
	Sea = ' ', //������� ��� ����
	Miss = '*', //������ ��� ��������� � ������ �����
	Kill = 'X', //����
	Deck = 'O', //������ �������
	Hit = 'x' //�����
};

//��� ����������� ����������� ��������� �������
enum class Direction
{
	Up = 1, //������������� ������
	Down, //����������� ����
	Right, //����������� �����
	Left //������������� �����
};

//��� ����������� ����� ������ �� �������
enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

using enum Status;
using enum Direction;

struct Player
{
    string name; // ��� ������
	char hits[10][10]; // ������ ��� ������� ���������
	char ships[10][10]; // ������ ��� ���������� ��������
};

// ���������� ������
struct Point
{
    int Y;
    int X;
};

// ��� ���������� ������� � ������������ ��� �������� ���� ��
void fill_pc_hard_attack(vector<Point>& pc_hard_4deck_attack, vector<Point>& pc_hard_3_2deck_attack);

//������������ �������� ������� ����� �� �����(��� ����, ����� �� ���� �� ����� ������������)
void pc_hard_random(vector<Point>& pc_hard_4deck_attack, vector<Point>& pc_hard_3_2deck_attack);

//�������� �� ����� ����
bool is_end_game(char ships[][10]);

// ������� ��� ������ �� ���� � ������ ����������� ����� �� ����������� ���� ��������
void end_game(Player player1, Player player2, bool& game);

//������� ��� ���������� ����� ������ (����� �� ��������� ���������, �������� ������������ ������ ��������� system("slc"))
void cls();

//������� ��� ���������� ������ ����� ������
void cls(COORD coord);

// �������� ������� ���������� ��������� �������
COORD get_�oords();

//��� �������������� enum � char
char get_status_char(Status status);

//��� ��������� �������� ����� ���� ������������� ��� ����� ���� ������ � ���� ����
//��� ����������, ��� ����� ���������� ���� � string � ����� ��������������� � int
int get_int_choice();

//���������� ������� ��� ��������� ����� ������ � ���� ��� ���������� ������
void set_color(ConsoleColor text, ConsoleColor background);

//��������� ������� � Player ���������� �� ��������� (" " - ����)
void fill_players_fields(Player& player1, Player& player2);

//��� ����������� ���� ���� ����� ����� ��������� ��� ���� �������
void print_field(char ships[][10]);

//��� ����������� ����� ������ � ���������� (��� ���������� � ����������)
void print_fields(char ships[][10], char hits[][10]);

//��� �������� ������� ������ ��� ��������� �������� ������
bool check_right(const int& x, const int& y, char ships[][10], const int& ship_size, Status status);

//��� �������� ������� ������ ��� ��������� �������� �����
bool check_left(const int& x, const int& y, char ships[][10], const int& ship_size, Status status);

//��� �������� ������� ������ ��� ��������� �������� ����
bool check_down(const int& x, const int& y, char ships[][10], const int& ship_size, Status status);

//��� �������� ������� ������ ��� ��������� �������� �����
bool check_up(const int& x, const int& y, char ships[][10], const int& ship_size, Status status);

//���� ��������� ������ �������
void ship_auto_install(char ships[][10], const int& ship_size);

//��� ���� ��������� ��������
void ships_auto_install(char ships[][10]);

//��� �������������� ����� � �����
int get_letter_int();

//��� �������������� ����� � �����
char get_char_from_x(const int& x);

//������� ��� ����� ��������� �������
void enter_coord(int& x, int& y);

//������� ��� ������ ��������� � �������� ����������� ��������� �������
void negative_dir_massage(COORD coord);

//��� ��������� ������ ������� �������
void ship_hand_install(char ships[][10], const int& ship_size);

//��� ��������� �������� �������
void ships_hand_install(char ships[][10]);

// �������������� ������ ��������� '*' ����� ��������
void kill_ship_fill_miss_char_around(const int& x, const int& y, char hits[][10]);

//��� ������ ���������� �����, ���� �� �����
void choice_dir(char hits[][10], int& x, int& y);

//��� �������� ���������� ����������� �������� � �������
int sym_count(char hits[][10], Status status);

//������ ���� �� ����� ���� ������
void player_move(Player& player1, Player& player2, bool& game);

//������ ������ ��������� ����� ������ ��
void pc_easy_coord_choice(Player& player1, Player& player2, int& hit_x, int& hit_y, int& x, int& y, bool& is_hit, bool& is_hit_after_miss);

//������ ���� �� ����� ���� ������� ��
void pc_easy_move(Player& player1, Player& player2, bool& is_hit_after_miss, int& hit_x, int& hit_y, bool& game, const int& pc);

//������ ������ ��������� ����� ���� ��
void pc_hard_coord_choice(Player& player1, Player& player2, int& hit_x, int& hit_y, int& x, int& y, bool& is_hit, bool& is_hit_after_miss,
                               int& i, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack);

//������ ���� �� ����� ���� ���� ��
void pc_hard_move(Player& player1, Player& player2, bool& is_hit_after_miss, int& hit_x, int& hit_y, bool& game, const int& pc,
                        int& i, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack);

//������ ���� ��� ����: ������ � ���� ��; ���� �� � ���� ��; ������ �� � ���� �� 
void game_hard(Player& player1, Player& player2, const int& pc, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack,
                                                                 const vector<Point>& pc_hard_4deck_attack2, const vector<Point>& pc_hard_3_2deck_attack2);

//������ ���� ��� ����: ������ � ������ ��; ������ �� � ������ ��
void game_easy(Player& player1, Player& player2, const int& pc);

//������� �����
void game_manager();
