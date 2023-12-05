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

    for (int i = 0; i < _player_count; i++)
    {
        _player_positions.push_back(0);
    }

    for (int i = 0; i < _player_count; i++)
    {
        _player_positions_old.push_back(0);
    }

    generateHiddenTreasures();
}

void Board::displayTile(int position)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";
    char player_display[4] = {'_', '_', '_', '_'};

    for (int j = 0; j < _player_positions.size(); j++)
    {
        if (position == _player_positions.at(j))
        {
            player_display[j] = '1' + j;
        }
    }

    cout << player_display[0] << " " << player_display[1] << " " << player_display[2] << " " << player_display[3];
    cout << " " << RESET;
}

void Board::displayBoard()
{
    // First horizontal segment
    for (int i = 0; i <= 17; i++)
    {
        displayTile(i);
    }
    cout << endl;
    // First vertical segment
    for (int i = 18; i <= 32; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            cout << "   ";
        }
        displayTile(i);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 50; i > 32; i--)
    {
        displayTile(i);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 51; i <= 66; i++)
    {
        displayTile(i);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 67; i < _BOARD_SIZE; i++)
    {
        displayTile(i);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int new_position, int player_num)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_positions[player_num] = new_position;
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

int Board::getPlayerPosition(int player_num) const
{
    return _player_positions[player_num];
}

int Board::getPlayerCount() const
{
    return _player_count;
}

int Board::getPlayerPositionOld(int player_num) const
{
    return _player_positions_old[player_num];
}

void Board::setPlayerCount(int player_count)
{
    _player_count = player_count;
}

void Board::setPlayerPositionOld(int old_position, int player_num)
{
    _player_positions_old[player_num] = old_position;
}

void Board::generateHiddenTreasures()
{
    srand(time(0));

    for (int i = 0; i < _HIDDEN_TREASURE_AMOUNT; i++)
    {
        bool new_treasure_generated = false;
        while (!new_treasure_generated)
        {
            int hidden_treasure_pos = rand() % _BOARD_SIZE + 1;

            bool is_unique = true;
            for (int j = 0; j < i; j++)
            {
                if (_hidden_treasure_positions[j] == hidden_treasure_pos)
                {
                    is_unique = false;
                    break;
                }
            }

            if (is_unique)
            {
                _hidden_treasure_positions[i] = hidden_treasure_pos;
                new_treasure_generated = true;
            }
        }
    }
}

bool Board::isPositionHiddenTreasure(int position)
{
    for (int i = 0; i < _HIDDEN_TREASURE_AMOUNT; i++)
    {
        if (position == _hidden_treasure_positions[i])
        {
            return true;
        }
    }
    return false;
}

void Board::testHiddenTreasure()
{
    for (int i = 0; i < _HIDDEN_TREASURE_AMOUNT; i++)
    {
        cout << "The hidden treasure is located at: " << _hidden_treasure_positions[i] << endl;
    }
    
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        bool isHiddenTreasure = false;
        
        for (int j = 0; j < _HIDDEN_TREASURE_AMOUNT; j++)
        {
            if (i == _hidden_treasure_positions[j])
            {
                isHiddenTreasure = true;
                break;
            }
        }
        
        if (isHiddenTreasure)
        {
            cout << "Position " << i << ": TRUE" << endl;
        }
        else
        {
            cout << "Position " << i << ": FALSE" << endl;
        }
    }
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
        if (_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

bool Board::movePlayer(int tile_to_move_forward, int player_num)
{
    int new_player_position = tile_to_move_forward + _player_positions[player_num];
    if (new_player_position < 0 || new_player_position >= _BOARD_SIZE)
    {
        return false;
    }
    _player_positions[player_num] = new_player_position;
    return true;
}

int Board::findNextColorTile(int player_num, string color)
{
    int current_pos = getPlayerPosition(player_num) + 1;
    int new_pos = 0;
    bool new_pos_found = false;
    while (new_pos_found == false)
    {
        if (_tiles[current_pos].color == color)
        {
            new_pos = current_pos;
            new_pos_found = true;
        }
        else
        {
            new_pos_found = false;
            current_pos++;
        }
    }
    return new_pos;
}