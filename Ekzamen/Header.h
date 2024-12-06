#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//для отслеживания состояния клетки на поле
enum class Status: char
{
	Sea = ' ', //пустота или море
	Miss = '*', //промах или попадание в пустое место
	Kill = 'X', //убил
	Deck = 'O', //палуба корабля
	Hit = 'x' //ранил
};

//для определения направления установки корабля
enum class Direction
{
	Up = 1, //горизонтально вправо
	Down, //вертикально вниз
	Right, //вертикально вверх
	Left //горизонтально влево
};

//для определения цвета вывода на консоль
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
    string name; // имя плеера
	char hits[10][10]; // массив для отметки попаданий
	char ships[10][10]; // массив для размещения кораблей
};

// координаты клетки
struct Point
{
    int Y;
    int X;
};

// для заполнения вектора с координатами для стрельбы хард ПК
void fill_pc_hard_attack(vector<Point>& pc_hard_4deck_attack, vector<Point>& pc_hard_3_2deck_attack);

//переставляем элементы вектора задом на перед(для того, чтобы ПК хард не ходил единообразно)
void pc_hard_random(vector<Point>& pc_hard_4deck_attack, vector<Point>& pc_hard_3_2deck_attack);

//проверка на конец игры
bool is_end_game(char ships[][10]);

// функция для выхода из игры в случае уничтожения одним из противников всех кораблей
void end_game(Player player1, Player player2, bool& game);

//функция для обновления всего экрана (нашёл на просторах интернета, удобноее использовать вместо системной system("slc"))
void cls();

//функция для обновления только части экрана
void cls(COORD coord);

// получаем текущие координаты указателя консоли
COORD get_сoords();

//для преобразования enum в char
char get_status_char(Status status);

//для упрощения проверки ввода цифр пользователем при каком либо выборе в меню игры
//мне показалось, что проще записывать ввод в string и затем преобразовывать в int
int get_int_choice();

//интересная функция для изменения цвета текста и фона при консольном выводе
void set_color(ConsoleColor text, ConsoleColor background);

//заполняем массивы в Player значениями по умолчанию (" " - море)
void fill_players_fields(Player& player1, Player& player2);

//для отображения поля если игрок будет заполнять своё поле вручную
void print_field(char ships[][10]);

//для отображения полей игрока и компьютера (или компьютера и компьютера)
void print_fields(char ships[][10], char hits[][10]);

//для проверки смежных клеток при установке кораблей вправо
bool check_right(const int& x, const int& y, char ships[][10], const int& ship_size, Status status);

//для проверки смежных клеток при установке кораблей влево
bool check_left(const int& x, const int& y, char ships[][10], const int& ship_size, Status status);

//для проверки смежных клеток при установке кораблей вниз
bool check_down(const int& x, const int& y, char ships[][10], const int& ship_size, Status status);

//для проверки смежных клеток при установке кораблей вверх
bool check_up(const int& x, const int& y, char ships[][10], const int& ship_size, Status status);

//авто установка одного корабля
void ship_auto_install(char ships[][10], const int& ship_size);

//для авто установки кораблей
void ships_auto_install(char ships[][10]);

//для преобразования буквы в цифру
int get_letter_int();

//для преобразования цифры в букву
char get_char_from_x(const int& x);

//функция для ввода координат корабля
void enter_coord(int& x, int& y);

//функция для вывода сообщения о неверном направлении установки корабля
void negative_dir_massage(COORD coord);

//для установки одного корабля вручную
void ship_hand_install(char ships[][10], const int& ship_size);

//для установки кораблей вручную
void ships_hand_install(char ships[][10]);

// автозаполнение клеток символами '*' после убийства
void kill_ship_fill_miss_char_around(const int& x, const int& y, char hits[][10]);

//для выбора напраления атаки, если ПК ранил
void choice_dir(char hits[][10], int& x, int& y);

//для подсчета количества определённых символов в массиве
int sym_count(char hits[][10], Status status);

//логика игры во время хода игрока
void player_move(Player& player1, Player& player2, bool& game);

//логика выбора координат атаки лекого ПК
void pc_easy_coord_choice(Player& player1, Player& player2, int& hit_x, int& hit_y, int& x, int& y, bool& is_hit, bool& is_hit_after_miss);

//логика игры во время хода легкого ПК
void pc_easy_move(Player& player1, Player& player2, bool& is_hit_after_miss, int& hit_x, int& hit_y, bool& game, const int& pc);

//логика выбора координат атаки хард ПК
void pc_hard_coord_choice(Player& player1, Player& player2, int& hit_x, int& hit_y, int& x, int& y, bool& is_hit, bool& is_hit_after_miss,
                               int& i, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack);

//логика игры во время хода хард ПК
void pc_hard_move(Player& player1, Player& player2, bool& is_hit_after_miss, int& hit_x, int& hit_y, bool& game, const int& pc,
                        int& i, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack);

//логика игры при игре: игрока с хард ПК; хард ПК с хард ПК; легкий ПК с хард ПК 
void game_hard(Player& player1, Player& player2, const int& pc, const vector<Point>& pc_hard_4deck_attack, const vector<Point>& pc_hard_3_2deck_attack,
                                                                 const vector<Point>& pc_hard_4deck_attack2, const vector<Point>& pc_hard_3_2deck_attack2);

//логика игры при игре: игрока с легким ПК; легкий ПК с легким ПК
void game_easy(Player& player1, Player& player2, const int& pc);

//функция старт
void game_manager();
