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
    _candy_amount = 0;
    _skip_turn = false;
}

Player::Player(int player_number, string player_name, string character_name, int stamina, int gold, string effect, Candy inventory[_MAX_CANDY_AMOUNT])
{
    _player_number = player_number;
    _player_name = player_name;
    _character_name = character_name;
    _stamina = stamina;
    _gold = gold;
    _effect = effect;
    _skip_turn = false;
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

int Player::getPlayerGold() // Returns the player gold as a int
{
    return _gold;
}

string Player::getPlayerEffect() // Returns the player effect as a string
{
    return _effect;
}

bool Player::getPlayerSkipTurn()
{
    return _skip_turn;
}

bool Player::getPlayerRobbersRepel()
{
    return _robbers_repel;
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

    if (_stamina > 100)
    {
        cout << "You have reached the maximum amount of stamina (100). Your stamina will be set to 100." << endl;
        _stamina = 100;
    }
}

void Player::setPlayerGold(int gold) // Sets the player gold to the provided int argument
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

void Player::setPlayerCandyAmount(int candy_amount) // CHECK THIS
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

void Player::setPlayerSkipTurn(bool skip_turn)
{
    _skip_turn = skip_turn;
}

void Player::setPlayerRobbersRepel(bool robbers_repel)
{
    _robbers_repel = robbers_repel;
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

void Player::printPlayerStats()
{
    cout << "--------------------------------------" << endl;
    cout << "Here are your stats: " << endl;
    cout << "Player Name: " << _player_name << endl;
    cout << "Player Number: " << _player_number << endl;
    cout << "Player Character Name: " << _character_name << endl;
    cout << "Player Stamina: " << _stamina << endl;
    cout << "Player Gold: " << _gold << endl;
    cout << "Player Effect: " << _effect << endl;
    cout << "Player Inventory: " << endl;
    printPlayerInventory();
    cout << "--------------------------------------" << endl;
}

void Player::removeCandy(string candy_name) // // Removes candy from the inventory of the player
{
    for (int i = 0; i < candy_name.size(); i++)
    {
        if (candy_name[i] <= 'Z' && candy_name[i] >= 'A')
        {
            candy_name[i] = candy_name[i] + 32;
        }
    }

    int removal_index = -1;
    for (int i = 0; i < _candy_amount; i++)
    {
        string inv_candy = _inventory[i].name;
        for (int j = 0; j < inv_candy.size(); j++)
        {
            if (inv_candy[j] <= 'Z' && inv_candy[j] >= 'A')
            {
                inv_candy[j] = inv_candy[j] + 32;
            }
        }
        if (inv_candy == candy_name)
        {
            removal_index = i;
            break;
        }
    }

    if (removal_index > -1)
    {
        Candy empty;
        for (int i = removal_index; i < _MAX_CANDY_AMOUNT - 1; i++)
        {
            _inventory[i] = _inventory[i + 1];
        }
        for (int i = _MAX_CANDY_AMOUNT - 1; i < _MAX_CANDY_AMOUNT; i++)
        {
            _inventory[i] = empty;
        }
        _candy_amount--;
    }
    printPlayerStats();
}

void Player::removeRandomCandy()
{
    srand(time(0));
    int yeet_index = 0;
    yeet_index = rand() % _candy_amount + 1;

    string candy_name = _inventory[yeet_index].name;
    string candy_name_unchanged = candy_name;

    for (int i = 0; i < candy_name.size(); i++)
    {
        if (candy_name[i] <= 'Z' && candy_name[i] >= 'A')
        {
            candy_name[i] = candy_name[i] + 32;
        }
    }

    int removal_index = -1;
    for (int i = 0; i < _candy_amount; i++)
    {
        string inv_candy = _inventory[i].name;
        for (int j = 0; j < inv_candy.size(); j++)
        {
            if (inv_candy[j] <= 'Z' && inv_candy[j] >= 'A')
            {
                inv_candy[j] = inv_candy[j] + 32;
            }
        }
        if (inv_candy == candy_name)
        {
            removal_index = i;
            break;
        }
    }

    if (removal_index > -1)
    {
        Candy empty;
        for (int i = removal_index; i < _MAX_CANDY_AMOUNT - 1; i++)
        {
            _inventory[i] = _inventory[i + 1];
        }
        for (int i = _MAX_CANDY_AMOUNT - 1; i < _MAX_CANDY_AMOUNT; i++)
        {
            _inventory[i] = empty;
        }
        _candy_amount--;
    }
    cout << candy_name_unchanged << " was removed from " << _player_name << "'s inventory." << endl;
    printPlayerStats();
}

int Player::removeRandomGold(int removal_amount_max, int removal_amount_min)
{
    srand(time(0));
    int yeet_amount = 0;
    int yeet_amount_removed = 0;
    yeet_amount = rand() % (removal_amount_max - removal_amount_min + 1) + removal_amount_min;

    if (getPlayerGold() < yeet_amount)
    {
        yeet_amount_removed = getPlayerGold();
        setPlayerGold(0);
        cout << getPlayerName() << " has less than " << yeet_amount << " gold. All gold will be removed from their inventory." << endl;
    }
    else
    {
        setPlayerGold(getPlayerGold() - yeet_amount);
    }

    cout << yeet_amount_removed << " gold was removed from " << _player_name << "'s inventory." << endl;
    printPlayerStats();
    return yeet_amount_removed;
}