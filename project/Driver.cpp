#include "Board.h"
#include "Game.h"
#include "Player.h"


int main()
{
    // Test Board Class
    Board board;
    board.resetBoard();

    assert(board.getBoardSize() == 83); // Test if the board size is correct
    assert(board.setPlayerPosition(5, 1) == true); // Test setting a position successfully
    assert(board.setPlayerPosition(-1, 1) == false); // Test setting a position unsuccessfully
    assert(board.addCandyStore(15) == true); // Test adding a candy store
    assert(board.isPositionCandyStore(15) == true); // Test adding a candy store
    board.setPlayerPosition(0, 1); // Test setting player position
    assert(board.getPlayerPosition(1) == 5); // Test retrieving player position

    // Test Player Class
    Player regular_player;
    assert(regular_player.getStamina() == 0);
    assert(regular_player.getGold() == 0.0);
    assert(regular_player.getCandyAmount() == 0);
    assert(regular_player.getEffect() == "");

    regular_player.setStamina(5);
    assert(regular_player.getStamina() == 5);

    regular_player.setGold(45.5);
    assert(regular_player.getGold() == 45.5);

    regular_player.setEffect("Effect Lolz");
    assert(regular_player.getEffect() == "Effect Lolz");

    regular_player.setPlayerNumber(1);
    assert(regular_player.getPlayerNumber() == 1);

    Candy candyArray[] = {{"1"}, {"2"}, {"3"}};
    int candyArraySize = 3;
    Player custom_player(50, 50.0, "Effect Lol", candyArray, candyArraySize);
    assert(custom_player.getStamina() == 50);
    assert(custom_player.getGold() == 50.0);
    assert(custom_player.getEffect() == "Effect Lol");
    assert(custom_player.getCandyAmount() == candyArraySize);

    // Test Game Class
    Game custom_game(4, false, 4);
    assert(custom_game.getTurn() == 4);
    assert(custom_game.gameRunning() == false);
    assert(custom_game.playerCount() == 4);

    custom_game.setTurn(5);
    assert(custom_game.getTurn() == 5);

    custom_game.setGameRunning(false);
    assert(custom_game.gameRunning() == false);

    custom_game.setPlayerCount(4);
    assert(custom_game.playerCount() == 4);

}