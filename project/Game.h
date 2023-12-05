#ifndef GAME_H
#define GAME_H

#include "Board.h"
class Player;

using namespace std;

struct Candy
{
    string name;        // Name of the Candy
    string description; // Description of the candy
    string effect_type; // The effect the candy provides
    int effect_value;   // The value of the effect
    double price;       // The price of the candy
    string candy_type;  // The type of candy
};

struct Character
{
    string name;                   // Name of the character
    int stamina;                   // Character starting stamina
    double gold;                   // Character starting gold
    vector<Candy> character_candy; // Character starting inventory
};

class Game
{
private:
    int _player_count;                    // Number of players playing
    vector<Candy> _loaded_candies;        // The candies loaded into the game
    vector<Character> _loaded_characters; // The characters loaded into the game
    int generateRandomCard();             // Generates a random card

public:
    // ===== CONSTRUCTORS ===== //
    Game(); // Default constructor

    // ===== ACCESSOR FUNCTIONS ===== //
    vector<Candy> getLoadedCandies();        // Returns the candies loaded into the game as a vector of Candy objects
    vector<Character> getLoadedCharacters(); // Returns the characters loaded into the game as a vector of Character objects
    int getPlayerCount();                    // Returns the number of players playing the game as an integer

    // ===== MUTATOR FUNCTIONS ===== //
    void setPlayerCount(int player_count); // Sets the player count to the provided integer argument

    // ===== MEMBER FUNCTIONS ===== //
    bool loadCandies();                                     // Loads candies into the game from a .txt file
    bool loadCharacters();                                  // Loads characters into the game from a .txt file
    vector<Player> selectCharacters();                      // Displays menu and allows players to select their characters
    void printCharacterData();                              // Prints the data of each of the characters
    void drawCard(Player &current_player, Board &board);    // Lets player draw a card
    void specialTile(Player &current_player, Board &board); // If the player lands on a special tile
    void nextTurn(Player &current_player, Board &board);    // Used to complete each player turn
};

#endif
