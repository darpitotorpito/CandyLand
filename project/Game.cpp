#include "Board.h"
#include "Player.h"
#include "Game.h"

Game::Game(int turn, bool game_running, int players) // Parameterized constructor
{
    _turn = turn;
    _game_running = game_running;
    _players = players;
}
int Game::getTurn() // Returns the current turn of the game
{
    return _turn;
}
bool Game::gameRunning() // Returns whether the game is running
{
    return _game_running;
}
int Game::playerCount() // Returns the number of players in the game
{
    return _players;
}
void Game::setTurn(int turn) // Sets the value of the current turn
{
    _turn = turn;
}
void Game::setGameRunning(bool game_running) // Sets the game to running or not
{
    _game_running = game_running;
}
void Game::setPlayerCount(int players) // Sets the number of players in the game
{
    _players = players;
}
void Game::gameInitializationMenu() // Displays the welcome message and asks for the number of players
{
    /*
    - Displays welcome message to users
    - Asks for number of players that will be participating in the game
    - Sets _players equal to the amount of players playing
    */
}
void Game::loadGameData() // Loads the game data for the characters, riddles, and the candies
{
    /*
    - Opens text files for characters, riddles, and candies
    - Using stringstreams to load the data from the text files into the game
    - Saves all the possible characters in an vector of the Characters struct
    - Saves all the riddles in a vector of strings
    - Saves all the possible candies in a vector of candies
    */
}
void Game::characterSelectionMenu() // Displays the character selection menu at the beginning of the turn and assigns each player a character
{
    /*
    - Displays a menu of characters possible to select
    - Allows user to input which character they would like to select
    - Runs once for each player
    - Calls the Player::setPlayerCharacter() function to set the values of the player to that of the character they chose
    - Function ends once all players have chosen a character
    */
}
void Game::displayMainMenu() // Displays the main menu at the beginning of each turn
{
    /*
    - Displays a menu and the board at the beginning of each players turn
    - Allows player to choose what they would like to do during the turn
    - Depending on the player choice, other functions will be called to execute the player choice
    - Updates player data at the end of the turn and stores it in the instance of their class
    */
}
void Game::setHiddenTreasures() // Sets hidden treasures on the map
{
    /*
    - Generates random numbers depending on the board size to set the hidden treasures to
    - Stores the positions in the array in the Board Class
    */
}
void Game::drawCardAndMove() // Allows the player to draw a card and move the according spaces forward
{
    /*
    - Draws a randomly generated card for the player
    - Moves the player according to the card generated using functions from the Board class
    - Updates the values for the player
    */
}
void Game::ShortcutTile() // Lets player leap forward four tiles
{
    /*
    - If a shortcut tile is found, lets the player move the number of spaces according to the shortcut tile
    - Updates the player position using functions from the Board class
    */
}
void Game::IceCreamStopTile() // Grants player an additional turn
{
    /*
    - If Ice Cream Stop Tile is found, it grants the player an additional turn
    - All player values updated accordingly at the end of their additional turn.
    */
}
void Game::GumdropForrestTile() // Sends player back a random amount and takes away 5-10 coins
{
    /*
    - If Gumdrop Forrest Tile is found
    - sends the player backwards the according amount
    - Takes a random number between 5-10 gold from the player
    - Player stats get updated accordingly at the end
    */
}
void Game::GingerbreadHouseTile() // Transports player back to previous tile
{
    /*
    - If gingerbread house tile is found
    - Transports the player back to the position/tile they were at previously
    - Player stats updated accordingly.
    */
}
void Game::SameTile() // If two players are on the same tile, gives first player the opportunity to steal coins and moves them back one tile.
{
    /*
    - If two players are at the same tile
    - The player who was on the tile first gets the opportunity to steal coins from the second player
    - The player who was on the tile first steals the coins and gets moved backwards by one tile
    - All player stats get updated accordingly
    */
}
void Game::HiddenTreasure() // Gives players their hidden treasure based on random chance
{
    /*
    - If a hidden treasure is found
    - Random number is used to determine which hidden treasure they receive
    - 30% chance of stamina refill
    - 10% chance of receiveing between 20 to 40 gold
    - 30% chance of receiving an anti-robbery shield
    - 30% chance of receiving one of two candies
        - 70% chance of receiving Jellybean of Vigor
        - 30% chance of receiving Hunter's truffle
    */
}
void Game::CandyStore() // Allows player to make a purchase if they are on a candy store tile.
{
    /*
    - If the player lands on a Candy Store and would like to buy a candy
    - Display the candies available in the candy store
    - Allow the player to make a selection if their inventory is not full
    - Add the selected candy to their inventory and subtract the corresponding amount of gold from their inventory
    - Repeat until they are done purchasing candy
    */
}
void Game::Calamity() // 40% chance of Calamity ocurring after each turn. This function has a 40% chance of executing.
{
    /*
    - If the 40% chance of a calamity ocurring is successful
    - One of the following will occur based on random numbers
        - 30% chance of losing a random number of 1-10 gold coins
        - 35% chance of losing a turn but can win it back by playing rock paper scissors
        - 15% chance of losing 5-10 stamina and next turn but can play rock paper scissors to recover
        - 20% chance of losing next turn
    */
}
void Game::PlayRiddle() // Allows player to play a riddle
{
    /*
    - If the player chooses to play a riddle
    - A riddle is randomly selected from the riddle vector
    - The riddle is presented to the player and they either get it right or wrong
    - True returned if riddle answered correctly
    - False returned if riddle answered incorrectly
    */
}
void Game::PlayRockPaperScissors() // Allows player to play rock paper scissors
{
    /*
    - If the player chooses to play rock paper scissors
    - The player chooses r, p, or s
    - The computer randomly generates r, p, or s
    - The user input and the computer generated answer are compared
    - If the user wins return true
    - If the computer wins return false
    */
}