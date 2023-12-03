#ifndef GAME_H
#define GAME_H

#include "Board.h"
class Player;

using namespace std;

struct Candy
{
    string name;
    string description;
    string effect_type;
    int effect_value;
    double price;
    string candy_type;
};

struct Character
{
    string name;
    int stamina;
    double gold;
    vector<Candy> character_candy;
};

class Game
{
private:
    int _player_count;                          // Number of players playing
    vector<Candy> _loaded_candies;        // The candies loaded into the game
    vector<Character> _loaded_characters; // The characters loaded into the game

public:
    // ===== CONSTRUCTORS ===== //
    Game();

    // ===== ACCESSOR FUNCTIONS ===== //
    vector<Candy> getLoadedCandies();
    vector<Character> getLoadedCharacters();
    int getPlayerCount();

    // ===== MUTATOR FUNCTIONS ===== //
    void setPlayerCount(int player_count);

    // ===== MEMBER FUNCTIONS ===== //
    bool loadCandies();
    bool loadCharacters();
    vector<Player> selectCharacters();
    void printCharacterData();
};

#endif
