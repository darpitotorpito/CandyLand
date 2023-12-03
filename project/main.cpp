#include "Board.h"
#include "Game.h"
#include "Player.h"

int main()
{
    // Load the board
    Board board;
    board.displayBoard();

    // Load the game and information from text files
    Game game;
    game.loadCandies();
    game.loadCharacters();

    vector<Player> players = game.selectCharacters();

    for (int i = 0; i < players.size(); i++)
    {
        cout << "Player Name: " << players.at(i).getPlayerName() << endl;
        cout << "Player Number: " << players.at(i).getPlayerNumber() << endl;
        cout << "Player Character Name: " << players.at(i).getPlayerCharacterName() << endl;
        cout << "Player Stamina: " << players.at(i).getPlayerStamina() << endl;
        cout << "Player Gold: " << players.at(i).getPlayerGold() << endl;
        cout << "Player Effect: " << players.at(i).getPlayerEffect() << endl;
        cout << "Player Inventory: " << endl;
        players.at(i).printPlayerInventory();
        cout << "--------------------------------------------" << endl;
    }

}

void testLoadCandies()
{
    // vector<Candy> candies = game.getLoadedCandies();
    // for (int i = 0; i < candies.size(); i++)
    // {
    //     cout << candies[i].name << endl;
    // }
    // return 0;
}

void testLoadCharacters()
{
    // vector<Character> characters = game.getLoadedCharacters();
    // for (int i = 0; i < characters.size(); i++)
    // {
    //     cout << "Character Name: " << characters.at(i).name << " Character Stamina: " << characters.at(i).stamina << " Character Gold: " << characters.at(i).gold << endl;
    //     cout << characters.at(i).name << " Candies:" << endl;

    //     for (int j = 0; j < characters.at(i).character_candy.size(); j++)
    //     {
    //         cout << characters.at(i).character_candy.at(j).name << " " << characters.at(i).character_candy.at(j).price << endl;
    //     }
    // }
}