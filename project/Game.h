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

struct Riddle
{
    string riddle;   // The riddle
    string solution; // The solution
};

class Game
{
private:
    int _player_count;                    // Number of players playing
    vector<Candy> _loaded_candies;        // The candies loaded into the game
    vector<Character> _loaded_characters; // The characters loaded into the game
    vector<Riddle> _loaded_riddles;       // The riddles loaded into the game
    vector<Player> _loaded_players;       // The players loaded into the game
    int generateRandomCard();             // Generates a random card

public:
    // ===== CONSTRUCTORS ===== //
    Game(); // Default constructor

    // ===== ACCESSOR FUNCTIONS ===== //
    vector<Candy> getLoadedCandies();        // Returns the candies loaded into the game as a vector of Candy objects
    vector<Character> getLoadedCharacters(); // Returns the characters loaded into the game as a vector of Character objects
    vector<Riddle> getLoadedRiddles();       // Returns the riddles loaded into the game as a vector of Riddle objects
    vector<Player> getLoadedPlayers();       // Returns the players loaded into the game as a vector of Player objects
    int getPlayerCount();                    // Returns the number of players playing the game as an integer

    // ===== MUTATOR FUNCTIONS ===== //
    void setPlayerCount(int player_count);                // Sets the player count to the provided integer argument
    void setLoadedPlayers(vector<Player> loaded_players); // Sets the loaded characters to the vector of Players argument

    // ===== MEMBER FUNCTIONS ===== //
    bool loadCandies();                                     // Loads candies into the game from a .txt file
    bool loadCharacters();                                  // Loads characters into the game from a .txt file
    bool loadRiddles();                                     // Loads riddles into the game from a .txt file
    vector<string> printCandyStore();                       // Prints candies for the candy store
    vector<Player> selectCharacters();                      // Displays menu and allows players to select their characters
    void printCharacterData();                              // Prints the data of each of the characters
    void drawCard(Player &current_player, Board &board);    // Lets player draw a card
    void useCandy(Player &current_player, Board &board);    // Lets player use candy in their inventory.
    bool playRiddle();                                      // Lets player play the riddle
    bool playRockPaperScissors();                           // Lets player play rock paper scissors.
    void candyStore(Player &current_player);                // Lets player buy from candy store
    void specialTile(Player &current_player, Board &board); // If the player lands on a special tile
    void sameTile(Player &current_player, Board &board);    // If the player lands on the same tile as another player.
    void hiddenTreasure(Player &current_player);            // If the player lands on a hidden treasure.
    void calamity(Player &current_plyaer);    // If a calamity occurs
    void nextTurn(Player &current_player, Board &board);    // Used to complete each player turn
};

#endif
