#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include "Board.h"


class Player
{
private:
    const static int _MAX_CANDY_AMOUNT = 9;
    string _player_name;
    int _player_number;
    string _character_name;
    int _stamina;
    double _gold;
    string _effect;

    Candy _inventory[_MAX_CANDY_AMOUNT] = {};
    int _candy_amount;

public:
    // ===== CONSTRUCTORS ====== //
    Player();
    Player(int player_number, string player_name, string character_name, int stamina, int gold, string effect, Candy inventory[9]);

    // ====== ACCESSOR FUNCTIONS ====== //
    int getPlayerNumber();
    string getPlayerName();
    string getPlayerCharacterName();
    int getPlayerStamina();
    double getPlayerGold();
    string getPlayerEffect();

    // ====== MUTATOR FUNCTIONS ===== //
    void setPlayerNumber(int player_number);
    void setPlayerName(string player_name);
    void setPlayerCharacterName(string character_name);
    void setPlayerStamina(int stamina);
    void setPlayerGold(double gold);
    void setPlayerEffect(string effect);
    void setPlayerInventory(vector<Candy> candy);
    void setPlayerCandyAmount();

    // ====== MEMBER FUNCTIONS ====== //
    void printPlayerInventory();


};

#endif