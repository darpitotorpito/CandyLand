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
#include <cstdlib>
#include <ctime>


#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;

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
    const static int _MAX_CANDY_STORE = 8;
    int _candy_store_positions[_MAX_CANDY_STORE];
    int _candy_store_count;
    int _player_count = 0;
    vector<int> _player_positions;
    vector<int> _player_positions_old;
    const static int _HIDDEN_TREASURE_AMOUNT = 3;
    int _hidden_treasure_positions[_HIDDEN_TREASURE_AMOUNT];

public:
    Board();

    void resetBoard();
    void displayTile(int);
    void displayBoard();

    bool setPlayerPosition(int new_position, int player_num);

    int getBoardSize() const;
    int getCandyStoreCount() const;
    int getPlayerPosition(int player_num) const;
    int getPlayerPositionOld(int player_num) const;
    int getPlayerCount() const;

    void setPlayerCount(int player_count);
    void setPlayerPositionOld(int old_position, int player_num);

    void generateHiddenTreasures();
    bool isPositionHiddenTreasure(int position);
    void testHiddenTreasure();

    void generateCandyStores();
    bool addCandyStore(int);
    bool isPositionCandyStore(int); 

    bool movePlayer(int tile_to_move_forward, int player_num);
    int findNextColorTile(int player_num, string color);
};

#endif