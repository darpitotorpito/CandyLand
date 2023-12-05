#include "Board.h"
#include "Game.h"
#include "Player.h"

int main()
{

    // Load the game and information from text files
    Game game;
    game.loadCandies();
    game.loadCharacters();

    // Load the players
    // game.setLoadedPlayers(game.selectCharacters());

    // Load the board
    Board board;

    board.testHiddenTreasure();
    // board.setPlayerCount(game.getPlayerCount());
    // board.resetBoard();
    // board.displayBoard();
    // board.setPlayerPosition(10, game.getLoadedPlayers().at(0).getPlayerNumber());
    // board.setPlayerPosition(10, game.getLoadedPlayers().at(1).getPlayerNumber());
    // vector <Player> loaded_players_temp = game.getLoadedPlayers();
    // loaded_players_temp.at(0).setPlayerGold(5);
    // game.setLoadedPlayers(loaded_players_temp);
    // game.getLoadedPlayers().at(0).printPlayerStats();
    // board.displayBoard();
    // game.sameTile(game.getLoadedPlayers().at(0), board);
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
void testPlayerClass()
{
    //   for (int i = 0; i < players.size(); i++)
    // {
    //     cout << "Player Name: " << players.at(i).getPlayerName() << endl;
    //     cout << "Player Number: " << players.at(i).getPlayerNumber() << endl;
    //     cout << "Player Character Name: " << players.at(i).getPlayerCharacterName() << endl;
    //     cout << "Player Stamina: " << players.at(i).getPlayerStamina() << endl;
    //     cout << "Player Gold: " << players.at(i).getPlayerGold() << endl;
    //     cout << "Player Effect: " << players.at(i).getPlayerEffect() << endl;
    //     cout << "Player Inventory: " << endl;
    //     players.at(i).printPlayerInventory();
    //     cout << "--------------------------------------------" << endl;
    // }
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