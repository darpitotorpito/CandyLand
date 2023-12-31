#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

struct Candy
{
    string name;
    string description;
    double price;
    string candy_type;
};

struct Tile
{
    string color;
    string tile_type;
};


class Board
{
private:
    const static int _BOARD_SIZE = 83;
    Tile _tiles[_BOARD_SIZE];
    const static int _MAX_CANDY_STORE = 3;
    int _candy_store_position[_MAX_CANDY_STORE];
    int _candy_store_count;
    int _player_position[4];

public:
    Board();

    void resetBoard();
    void displayTile(int, int player_number);
    void displayBoard();

    bool setPlayerPosition(int new_position, int player_number);

    int getBoardSize() const;
    int getCandyStoreCount() const;
    int getPlayerPosition(int player_number) const;

    bool addCandyStore(int);
    bool isPositionCandyStore(int); 

    void isPositionHiddenTreasure(int);

    bool movePlayer(int tile_to_move_forward, int player_number);
};

#endif