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
    int _gold;                                // The gold the player currently has
    string _effect;                           // The effect the player currently has
    Candy _inventory[_MAX_CANDY_AMOUNT] = {}; // The Candy inventory of the player
    int _candy_amount;                        // The amount of candy in the player inventory.
    bool _skip_turn = false;                  // If their next turn needs to be skipped
    bool _robbers_repel = false;              // If they have the robbers repel shield

public:
    // ===== CONSTRUCTORS ====== //
    Player();                                                                                                                       // Default constructor
    Player(int player_number, string player_name, string character_name, int stamina, int gold, string effect, Candy inventory[9]); // Parameterized Constructor

    // ====== ACCESSOR FUNCTIONS ====== //
    int getPlayerNumber();           // Returns the number of the player as an integer
    string getPlayerName();          // Returns the name of the player as a string
    string getPlayerCharacterName(); // Returns the name of the character the player has chosen as a string
    int getPlayerStamina();          // Returns the stamina of the player as an integer
    int getPlayerGold();             // Returns the gold the player currently has as a int
    string getPlayerEffect();        // Returns the effect the player currently has as a string
    bool getPlayerSkipTurn();
    bool getPlayerRobbersRepel(); 

    // ====== MUTATOR FUNCTIONS ===== //
    void setPlayerNumber(int player_number);            // Sets the number of the player to the provided integer argument
    void setPlayerName(string player_name);             // Sets the name of the player to the provided string argument
    void setPlayerCharacterName(string character_name); // Sets the name of the character of the player to the provided string argument
    void setPlayerStamina(int stamina);                 // Sets the stamina of the player to the provided integer argument
    void setPlayerGold(int gold);                       // Sets the gold of the player to the provided int argument
    void setPlayerEffect(string effect);                // Sets the effect of the player to the provided string argument
    void setPlayerInventory(vector<Candy> candy);       // Sets the inventory of the player to the provided vector of Candy argument
    void setPlayerCandyAmount(int _candy_amount);       // Sets the amount of candy in the players inventory to the provided integer argument
    void setPlayerSkipTurn(bool skip_turn);             // Sets skip turn if next player turn needs to be skipped.
    void setPlayerRobbersRepel(bool robbers_repel);

    // ====== MEMBER FUNCTIONS ====== //
    void printPlayerInventory();                                           // Prints the inventory of the player
    void printPlayerStats();                                               // Prints the player stats
    void removeCandy(string candy_name);                                   // Removes candy from the inventory of the player
    void removeRandomCandy();                                              // Removes RANDOM candy from the inventory of the player
    int removeRandomGold(int removal_amount_max, int removal_amount_min); // Removes RANDOM amount of gold from the inventory of the player
};

#endif