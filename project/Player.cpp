#include "Board.h"
#include "Player.h"

// ===== CONSTRUCTORS ===== //
Player::Player() // Default Constructor
{
    _stamina = 0;
    _gold = 0;
    _candy_amount = 0;
    _effect = "";
}
Player::Player(int stamina, double gold, string effect, Candy candy_array[], const int CANDY_ARR_SIZE) // Parameterized Constructor
{
    _stamina = stamina; // Set Stamina
    _gold = gold;       // Set Gold
    _effect = effect;   // Set effect
    _candy_amount = 0;  // Set temporary value for candy amount
    int current_candy = 0;
    for (int i = 0; i < CANDY_ARR_SIZE; i++) // Set inventory
    {
        if (_candy_amount >= _MAX_CANDY_AMOUNT) // Check if inventory is full
        {
            break;
        }

        if (candy_array[i].name != "") // Check if candy is not empty
        {
            _inventory[current_candy] = candy_array[i];
            current_candy++; // Increment the current candy counter
            _candy_amount++; // Increment the count of candies in inventory
        }
    }
}

// ===== GETTER FUNCTIONS ===== //
int Player::getCandyAmount() // Returns the amount of candy the player has in their inventory.
{
    return _candy_amount;
}
int Player::getStamina() // Returns the current value of stamina as an integer.
{
    return _stamina;
}
double Player::getGold() // Returns the current value of gold as a double.
{
    return _gold;
}
string Player::getEffect() // Returns the current value of effect as a string.
{
    return _effect;
}
int Player::getPlayerNumber() // Returns the numeric value assigned to the player
{
    return _player_number;
}

// ===== SETTER FUNCTIONS ===== //
void Player::setStamina(int stamina) // Takes an integer as input, and sets stamina to the input value.
{
    _stamina = stamina;
}
void Player::setGold(double gold) // Takes a double as input, and sets gold to the input value.
{
    _gold = gold;
}
void Player::setEffect(string effect) // Takes a string as input, and sets effect to the input value.
{
    _effect = effect;
}
void Player::setPlayerNumber(int player_number) // Takes an integer as an input, and sets player number to the input value.
{
    _player_number = player_number;
}

// ===== MEMBER FUNCTIONS ===== //
void Player::setPlayerCharacter(Character selected_character) // Sets the values of the character to the player.
{
    _stamina = selected_character.stamina;               // Set stamina to stamina of character
    _gold = selected_character.gold;                     // Set gold to gold of character
    _character_name = selected_character.character_name; // Set name to name of character

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++) // Gives the player the candy inventory of the character they selected
    {
        _inventory[i] = selected_character.candies[i];
        _candy_amount++;
    }
}
void Player::printInventory() // Prints out the player's current inventory.
{
    string inv[_MAX_CANDY_AMOUNT];
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        if (_inventory[i].name != "")
        {
            inv[i] = _inventory[i].name;
        }
        else
        {
            inv[i] = "Empty";
        }
    }
    cout << "|[" << inv[0] << "]|"
         << "[" << inv[1] << "]"
         << "|[" << inv[2] << "]|" << endl;

    cout << "|[" << inv[3] << "]|"
         << "[" << inv[4] << "]"
         << "|[" << inv[5] << "]|" << endl;

    cout << "|[" << inv[6] << "]|"
         << "[" << inv[7] << "]"
         << "|[" << inv[8] << "]|" << endl;
}
Candy Player::findCandy(string candy_name)                    // Searches for a Candy in the Player's inventory
{
    Candy not_found;
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        string candy_fucker;
        candy_fucker = _inventory[i].name;
        for (int i = 0; i < candy_fucker.size(); i++)
        {
            candy_fucker[i] = tolower(candy_fucker[i]);
        }
        if (candy_name == candy_fucker)
        {
            return _inventory[i];
        }
    }
    return not_found;
}
bool Player::addCandy(Candy candy)                            // Adds a Candy to the Player's inventory
{
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        if (_inventory[i].name == "")
        {
            _inventory[i] = candy;
            _candy_amount++;
            return true;
        }
    }
    return false;
}
bool Player::removeCandy(string candy_name)                   // Removes a Candy from the Player's inventory
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
        return true;
    }
    return false;
}