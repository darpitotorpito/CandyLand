#include "Board.h"
#include "Game.h"
#include "Player.h"

int main()
{

    // Load the game and information from text files
    srand(time(0));
    Game game;
    game.loadCandies();
    game.loadCharacters();
    game.loadRiddles();

    // Load the players
    game.setLoadedPlayers(game.selectCharacters());

    // Load the board
    Board board;
    board.setPlayerCount(game.getPlayerCount());
    board.resetBoard();
    board.displayBoard();

    //   for (int i = 0; i < game.getLoadedPlayers().size(); i++)
    // {
    //     cout << "Player Name: " << game.getLoadedPlayers().at(i).getPlayerName() << endl;
    //     cout << "Player Number: " << game.getLoadedPlayers().at(i).getPlayerNumber() << endl;
    //     cout << "Player Character Name: " << game.getLoadedPlayers().at(i).getPlayerCharacterName() << endl;
    //     cout << "Player Stamina: " << game.getLoadedPlayers().at(i).getPlayerStamina() << endl;
    //     cout << "Player Gold: " << game.getLoadedPlayers().at(i).getPlayerGold() << endl;
    //     cout << "Player Effect: " << game.getLoadedPlayers().at(i).getPlayerEffect() << endl;
    //     cout << "Player Inventory: " << endl;
    //     game.getLoadedPlayers().at(i).printPlayerInventory();
    //     cout << "--------------------------------------------" << endl;
    // }

    // vector<Player> players = game.getLoadedPlayers();
    // cout << "check 2" << endl;
    // game.nextTurn(game.getLoadedPlayers().at(0), board);

    bool winner = false;
    while (winner == false)
    {
        for (int i = 0; i < 3; i++)
        {
            game.nextTurn(game.getLoadedPlayers().at(i), board);
        }
    }

    // game.printCandyStore();

    // game.playRockPaperScissors();

    // vector<Player> loaded_players_temp = game.getLoadedPlayers();
    // loaded_players_temp.at(0).printPlayerStats();
    // game.calamity(loaded_players_temp.at(0));
    // game.calamity(loaded_players_temp.at(0));
    // game.calamity(loaded_players_temp.at(0));
    // game.calamity(loaded_players_temp.at(0));
    // loaded_players_temp.at(0).addPlayerSkippedTurn();
    // cout << loaded_players_temp.at(0).getPlayerSkipTurn().size() << endl;
    // loaded_players_temp.at(0).addPlayerSkippedTurn();
    // cout << loaded_players_temp.at(0).getPlayerSkipTurn().size() << endl;
    // loaded_players_temp.at(0).playerSkippedTurn();
    // cout << loaded_players_temp.at(0).getPlayerSkipTurn().size() << endl;
    // loaded_players_temp.at(0).playerSkippedTurn();
    // cout << loaded_players_temp.at(0).getPlayerSkipTurn().size() << endl;
    // cout << loaded_players_temp.at(0).playerSkippedTurn() << endl;

    // board.testHiddenTreasure();
    // board.setPlayerCount(game.getPlayerCount());


    // game.hiddenTreasure(game.getLoadedPlayers().at(0));
    // cout << game.getLoadedPlayers().at(0).getPlayerRobbersRepel() << endl;
    // srand(time(0));
    // for (int i = 0; i < 20; i++)
    // {
    // int riddle_index = rand() % game.getLoadedRiddles().size();
    // cout << riddle_index << endl;
    // }
    // for (int i = 0; i < game.getLoadedRiddles().size(); i++)
    // {
    //     cout << "Riddle " << i << endl;
    //     cout << game.getLoadedRiddles().at(i).riddle << endl;
    //     cout << "Solution" << endl;
    //     cout << game.getLoadedRiddles().at(i).solution << endl;
    // }

    // board.setPlayerPosition(10, game.getLoadedPlayers().at(0).getPlayerNumber());
    // board.setPlayerPosition(10, game.getLoadedPlayers().at(1).getPlayerNumber());
    // vector<Player> loaded_players_temp = game.getLoadedPlayers();
    // game.hiddenTreasure(loaded_players_temp.at(0));
    // cout << loaded_players_temp.at(0).getPlayerRobbersRepel() << endl;
    // loaded_players_temp.at(0).addCandy(game.getLoadedCandies().at(0));
    // loaded_players_temp.at(0).setPlayerGold(5);
    // loaded_players_temp.at(0).removeRandomGold(10, 5);
    // loaded_players_temp.at(0).setPlayerGold(90);
    // loaded_players_temp.at(0).addRandomGold(10, 20);
    // loaded_players_temp.at(0).addRandomStamina(100, 50);
    // game.setLoadedPlayers(loaded_players_temp);
    // game.getLoadedPlayers().at(0).printPlayerStats();

    // board.displayBoard();
    // game.sameTile(game.getLoadedPlayers().at(0), board);

    //       for (int i = 0; i < game.getLoadedPlayers().size(); i++)
    // {
    //     cout << "Player Name: " << game.getLoadedPlayers().at(i).getPlayerName() << endl;
    //     cout << "Player Number: " << game.getLoadedPlayers().at(i).getPlayerNumber() << endl;
    //     cout << "Player Character Name: " << game.getLoadedPlayers().at(i).getPlayerCharacterName() << endl;
    //     cout << "Player Stamina: " << game.getLoadedPlayers().at(i).getPlayerStamina() << endl;
    //     cout << "Player Gold: " << game.getLoadedPlayers().at(i).getPlayerGold() << endl;
    //     cout << "Player Effect: " << game.getLoadedPlayers().at(i).getPlayerEffect() << endl;
    //     cout << "Player Inventory: " << endl;
    //     game.getLoadedPlayers().at(i).printPlayerInventory();
    //     cout << "--------------------------------------------" << endl;
    // }

    // vector<Player> players = game.getLoadedPlayers();
    // players.at(1).addPlayerSkippedTurn();
    // players.at(1).addPlayerSkippedTurn();
    // cout << players.at(1).getPlayerSkipTurn().size() << endl;
    // game.setLoadedPlayers(players);

    // game.winner(game.getLoadedPlayers().at(0), board);

    //   for (int i = 0; i < game.getLoadedPlayers().size(); i++)
    // {
    //     cout << "Player Name: " << game.getLoadedPlayers().at(i).getPlayerName() << endl;
    //     cout << "Player Number: " << game.getLoadedPlayers().at(i).getPlayerNumber() << endl;
    //     cout << "Player Character Name: " << game.getLoadedPlayers().at(i).getPlayerCharacterName() << endl;
    //     cout << "Player Stamina: " << game.getLoadedPlayers().at(i).getPlayerStamina() << endl;
    //     cout << "Player Gold: " << game.getLoadedPlayers().at(i).getPlayerGold() << endl;
    //     cout << "Player Effect: " << game.getLoadedPlayers().at(i).getPlayerEffect() << endl;
    //     cout << "Player Inventory: " << endl;
    //     game.getLoadedPlayers().at(i).printPlayerInventory();
    //     cout << "--------------------------------------------" << endl;
    // }

    // vector<Player> players = game.getLoadedPlayers();
    // cout << "check 2" << endl;
    // game.nextTurn(game.getLoadedPlayers().at(0), board);

    // game.gummyCandy(game.getLoadedPlayers().at(0), board, 1);
    // game.gummyCandy(game.getLoadedPlayers().at(0), board, 2);
    // game.gummyCandy(game.getLoadedPlayers().at(0), board, 1);
    // game.gummyCandy(game.getLoadedPlayers().at(0), board, 2);
    // game.gummyCandy(game.getLoadedPlayers().at(0), board, 1);
    // game.gummyCandy(game.getLoadedPlayers().at(0), board, 2);

    // game.candyStore(game.getLoadedPlayers().at(0));

    // game.poisonCandy(game.getLoadedPlayers().at(0), board, 10);
    // game.poisonCandy(game.getLoadedPlayers().at(0), board, 15);
    // game.poisonCandy(game.getLoadedPlayers().at(0), board, 20);
    // game.poisonCandy(game.getLoadedPlayers().at(0), board, 20);

    //   for (int i = 0; i < game.getLoadedPlayers().size(); i++)
    //     {
    //         cout << "Player Name: " << game.getLoadedPlayers().at(i).getPlayerName() << endl;
    //         cout << "Player Number: " << game.getLoadedPlayers().at(i).getPlayerNumber() << endl;
    //         cout << "Player Character Name: " << game.getLoadedPlayers().at(i).getPlayerCharacterName() << endl;
    //         cout << "Player Stamina: " << game.getLoadedPlayers().at(i).getPlayerStamina() << endl;
    //         cout << "Player Gold: " << game.getLoadedPlayers().at(i).getPlayerGold() << endl;
    //         cout << "Player Effect: " << game.getLoadedPlayers().at(i).getPlayerEffect() << endl;
    //         cout << "Player Inventory: " << endl;
    //         game.getLoadedPlayers().at(i).printPlayerInventory();
    //         cout << "--------------------------------------------" << endl;
    //     }

    // bool winner = false;
    // while (winner == false)
    // {
    //     for (int i = 0; i < 3; i++)
    //     {
    //         game.nextTurn(game.getLoadedPlayers().at(i), board);
    //     }
    // }

    // game.printCandyStore();

    // game.playRockPaperScissors();

    // vector<Player> loaded_players_temp = game.getLoadedPlayers();
    // loaded_players_temp.at(0).printPlayerStats();
    // game.calamity(loaded_players_temp.at(0));
    // game.calamity(loaded_players_temp.at(0));
    // game.calamity(loaded_players_temp.at(0));
    // game.calamity(loaded_players_temp.at(0));
    // loaded_players_temp.at(0).addPlayerSkippedTurn();
    // cout << loaded_players_temp.at(0).getPlayerSkipTurn().size() << endl;
    // loaded_players_temp.at(0).addPlayerSkippedTurn();
    // cout << loaded_players_temp.at(0).getPlayerSkipTurn().size() << endl;
    // loaded_players_temp.at(0).playerSkippedTurn();
    // cout << loaded_players_temp.at(0).getPlayerSkipTurn().size() << endl;
    // loaded_players_temp.at(0).playerSkippedTurn();
    // cout << loaded_players_temp.at(0).getPlayerSkipTurn().size() << endl;
    // cout << loaded_players_temp.at(0).playerSkippedTurn() << endl;

    // board.testHiddenTreasure();
    // board.setPlayerCount(game.getPlayerCount());

    // game.hiddenTreasure(game.getLoadedPlayers().at(0));
    // cout << game.getLoadedPlayers().at(0).getPlayerRobbersRepel() << endl;
    // srand(time(0));
    // for (int i = 0; i < 20; i++)
    // {
    // int riddle_index = rand() % game.getLoadedRiddles().size();
    // cout << riddle_index << endl;
    // }
    // for (int i = 0; i < game.getLoadedRiddles().size(); i++)
    // {
    //     cout << "Riddle " << i << endl;
    //     cout << game.getLoadedRiddles().at(i).riddle << endl;
    //     cout << "Solution" << endl;
    //     cout << game.getLoadedRiddles().at(i).solution << endl;
    // }

    // board.setPlayerPosition(10, game.getLoadedPlayers().at(0).getPlayerNumber());
    // board.setPlayerPosition(10, game.getLoadedPlayers().at(1).getPlayerNumber());
    // vector<Player> loaded_players_temp = game.getLoadedPlayers();
    // game.hiddenTreasure(loaded_players_temp.at(0));
    // cout << loaded_players_temp.at(0).getPlayerRobbersRepel() << endl;
    // loaded_players_temp.at(0).addCandy(game.getLoadedCandies().at(0));
    // loaded_players_temp.at(0).setPlayerGold(5);
    // loaded_players_temp.at(0).removeRandomGold(10, 5);
    // loaded_players_temp.at(0).setPlayerGold(90);
    // loaded_players_temp.at(0).addRandomGold(10, 20);
    // loaded_players_temp.at(0).addRandomStamina(100, 50);
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
