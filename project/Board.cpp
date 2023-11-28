#include "Board.h"

Board::Board()
{
    resetBoard();
}

void Board::resetBoard()
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    Tile new_tile;
    string current_color;
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        new_tile = {current_color, "regular tile"};
        _tiles[i] = new_tile;
    }
    new_tile = {ORANGE, "regular tile"};
    _tiles[_BOARD_SIZE - 1] = new_tile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    _player_position[0] = 0;
    _player_position[1] = 0;
    _player_position[2] = 0;
    _player_position[3] = 0;
}

void Board::displayTile(int position, int player_number)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";
    if (position == _player_position[player_number])
    {
        cout << "X";
    }
    else
    {
        cout << " ";
    }
    cout << " " << RESET;
}

void Board::displayBoard()
{
    int x = 0;
    // First horizontal segment
    for (int i = 0; i <= 23; i++)
    {
        displayTile(i , x);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i, x);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i, x);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i, x);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i, x);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int new_position, int player_number)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_position[player_number] = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

int Board::getPlayerPosition(int player_number) const
{
    return _player_position[player_number];
}

bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}

bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if(_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

void Board::isPositionHiddenTreasure(int)
{
    // Check the hidden treasure position array to see weather the integer value passed into the function matches one of the positions of the hidden treasures
    // If the position passed matches a position in the array return true to indicate a hidden treasure
    // Otherwise return false to indicate no hidden treasure
}

bool Board::movePlayer(int tile_to_move_forward, int player_number)
{
    int new_player_position = tile_to_move_forward + _player_position[player_number];
    if(new_player_position < 0 || new_player_position >= _BOARD_SIZE)
    {
        return false;
    }
    _player_position[player_number] = new_player_position;
    return true;
}