#include "Board.h"
#include "Game.h"
#include "Player.h"

// ===== CONSTRUCTORS ===== //
Player::Player() // Default Constructor
{
    _player_number = 0;
    _player_name = "";
    _character_name = "";
    _stamina = 0;
    _gold = 0;
    _effect = "";
    // _inventory[_MAX_CANDY_AMOUNT] = {};
    _candy_amount = 0;
}
Player::Player(int player_number, string player_name, string character_name, int stamina, int gold, string effect, Candy inventory[_MAX_CANDY_AMOUNT])
{
    _player_number = player_number;
    _player_name = player_name;
    _character_name = character_name;
    _stamina = stamina;
    _gold = gold;
    _effect = effect;
}

// ===== ACCESSOR FUNCTIONS ===== //
int Player::getPlayerNumber() // Returns the player number as an integer
{
    return _player_number;
}

string Player::getPlayerName() // Returns the player name as a string
{
    return _player_name;
}

string Player::getPlayerCharacterName() // Returns the player character name as a string
{
    return _character_name;
}

int Player::getPlayerStamina() // Returns the player stamina as an integer
{
    return _stamina;
}

double Player::getPlayerGold() // Returns the player gold as a double
{
    return _gold;
}

string Player::getPlayerEffect() // Returns the player effect as a string
{
    return _effect;
}

// ====== MUTATOR FUNCTIONS ===== //
void Player::setPlayerNumber(int player_number) // Sets the player number to the provided integer argument
{
    _player_number = player_number;
}

void Player::setPlayerName(string player_name) // Sets the player name to the provided string argument
{
    _player_name = player_name;
}

void Player::setPlayerCharacterName(string character_name) // Sets the player character name to the provided string argument
{
    _character_name = character_name;
}

void Player::setPlayerStamina(int stamina) // Sets the player stamina to the provided integer argument
{
    _stamina = stamina;
}

void Player::setPlayerGold(double gold) // Sets the player gold to the provided double argument
{
    _gold = gold;
}

void Player::setPlayerEffect(string effect) // Sets player effect to the provided string argument
{
    _effect = effect;
}

void Player::setPlayerInventory(vector<Candy> candy)
{
    for (int i = 0; i < candy.size(); i++)
    {
        _inventory[i] = candy[i];
    }
}

void Player::setPlayerCandyAmount()
{
    _candy_amount = 0;
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        if (_inventory[i].name != "")
        {
            _candy_amount++;
        }
    }
}

// ====== MEMBER FUNCTIONS ====== //
void Player::printPlayerInventory()
{
    string print_inv[_MAX_CANDY_AMOUNT];

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        if (_inventory[i].name == "")
        {
            print_inv[i] = "Empty";
        }
        else
        {
            print_inv[i] = _inventory[i].name;
        }
    }

    cout << "|[" << print_inv[0] << "]|"
         << "[" << print_inv[1] << "]"
         << "|[" << print_inv[2] << "]|" << endl;

    cout << "|[" << print_inv[3] << "]|"
         << "[" << print_inv[4] << "]"
         << "|[" << print_inv[5] << "]|" << endl;

    cout << "|[" << print_inv[6] << "]|"
         << "[" << print_inv[7] << "]"
         << "|[" << print_inv[8] << "]|" << endl;
}