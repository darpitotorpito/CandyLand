#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

#include <iostream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Character
{
    string character_name; // The name of the character
    int stamina;           // The stamina of the character
    double gold;              // The gold of the character
    Candy candies[9] = {};      // The candies of the character
};

class Player
{
private:
    const static int _MAX_CANDY_AMOUNT = 9;   // The maximum number of candies the player can have in their inventory.
    int _stamina;                             // Current Energy
    double _gold;                             // Value of the player's current money
    string _effect;                           // Name of current effect
    Candy _inventory[_MAX_CANDY_AMOUNT] = {}; // Array to store the player's candy
    int _candy_amount;                        // Amount of initialized candy structs in the inventory array
public:
    // Constructors
    Player();                                                                                       // Default constructor
    Player(int stamina, double gold, string effect, Candy candy_array[], const int CANDY_ARR_SIZE); // Parameterized constructor

    // Getter Functions
    int getCandyAmount(); // Returns the amount of candy the player has in their inventory.
    int getStamina();     // Returns the current value of stamina as an integer.
    double getGold();     // Returns the current value of gold as a double.
    string getEffect();   // Returns the current value of effect as a string.

    // Setter Functions
    void setStamina(int stamina);  // Takes an integer as input, and sets stamina to the input value.
    void setGold(double gold);     // Takes a double as input, and sets gold to the input value.
    void setEffect(string effect); // Takes a string as input, and sets effect to the input value.

    // Member Functions
    void printInventory();              // Prints out the player's current inventory.
    Candy findCandy(string candy_name); // Searches for a Candy in the Player's inventory
    bool addCandy(Candy candy);         // Adds a Candy to the Player's inventory
    bool removeCandy(string candy_name);      // Removes a Candy from the Player's inventory
}