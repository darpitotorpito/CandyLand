#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include "Board.h"

class Player
{
private:
    const static int _MAX_CANDY_AMOUNT = 9;   // The maximum number of candies a player can have in their inventory
    string _player_name;                      // The name of the player
    int _player_number;                       // The player number
    string _character_name;                   // The name of the character the player has chosen
    int _stamina;                             // The stamina the player currently has
    double _gold;                             // The gold the player currently has
    string _effect;                           // The effect the player currently has
    Candy _inventory[_MAX_CANDY_AMOUNT] = {}; // The Candy inventory of the player
    int _candy_amount;                        // The amount of candy in the player inventory.
    bool _skip_turn = false;

public:
    // ===== CONSTRUCTORS ====== //
    Player();                                                                                                                       // Default constructor
    Player(int player_number, string player_name, string character_name, int stamina, int gold, string effect, Candy inventory[9]); // Parameterized Constructor

    // ====== ACCESSOR FUNCTIONS ====== //
    int getPlayerNumber();           // Returns the number of the player as an integer
    string getPlayerName();          // Returns the name of the player as a string
    string getPlayerCharacterName(); // Returns the name of the character the player has chosen as a string
    int getPlayerStamina();          // Returns the stamina of the player as an integer
    double getPlayerGold();          // Returns the gold the player currently has as a double
    string getPlayerEffect();        // Returns the effect the player currently has as a string
    bool getPlayerSkipTurn();

    // ====== MUTATOR FUNCTIONS ===== //
    void setPlayerNumber(int player_number);            // Sets the number of the player to the provided integer argument
    void setPlayerName(string player_name);             // Sets the name of the player to the provided string argument
    void setPlayerCharacterName(string character_name); // Sets the name of the character of the player to the provided string argument
    void setPlayerStamina(int stamina);                 // Sets the stamina of the player to the provided integer argument
    void setPlayerGold(double gold);                    // Sets the gold of the player to the provided double argument
    void setPlayerEffect(string effect);                // Sets the effect of the player to the provided string argument
    void setPlayerInventory(vector<Candy> candy);       // Sets the inventory of the player to the provided vector of Candy argument
    void setPlayerCandyAmount(int _candy_amount);       // Sets the amount of candy in the players inventory to the provided integer argument
    void setPlayerSkipTurn(bool skip_turn);             // Sets skip turn if next player turn needs to be skipped.

    // ====== MEMBER FUNCTIONS ====== //
    void printPlayerInventory(); // Prints the inventory of the player
    void printPlayerStats(); // Prints the player stats
};

#endif