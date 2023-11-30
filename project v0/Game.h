#include "Board.h"
#include "Player.h"

class Game
{
private:
    int _turn = 0;                // The current turn of the game
    bool _game_running = true;    // The status of the game
    int _players = 4;             // The number of players in the game
    vector<Character> characters; // All of the possible characters in the game
    vector<string> riddles;       // All of the riddles in the game
    vector<string> candies;       // All of the candies possible in the game

public:
    // ===== CONSTRUCTORS ===== //
    Game();                                         // Default constructor
    Game(int turn, bool game_running, int players); // Parameterized Constructor

    // ===== GETTER FUNCTIONS ===== //
    int getTurn();      // Returns the current turn of the game
    bool gameRunning(); // Returns whether the game is running
    int playerCount();  // Returns the number of players in the game

    // ===== SETTER FUNCTIONS ===== //
    void setTurn(int turn);                 // Sets the value of the current turn
    void setGameRunning(bool game_running); // Sets the game to running or not
    void setPlayerCount(int players);       // Sets the number of players in the game

    // ===== MEMBER FUNCTIONS ===== //
    //** ALL FUNCTIONS SET TO VOID CURRENTLY TO AVOID COMPILATION ERRORS **//
    void gameInitializationMenu(); // Displays the welcome message and asks for the number of players
    void loadGameData();           // Loads the game data for the characters and the candies
    void characterSelectionMenu(); // Displays the character selection menu at the beginning of the turn and assigns each player a character
    void displayMainMenu();        // Displays the main menu at the beginning of each turn
    void setHiddenTreasures();     // Sets hidden treasures on the map
    void drawCardAndMove();        // Allows the player to draw a card and move the according spaces forward
    void ShortcutTile();           // Lets player leap forward four tiles
    void IceCreamStopTile();       // Grants player an additional turn
    void GumdropForrestTile();     // Sends player back a random amount and takes away 5-10 coins
    void GingerbreadHouseTile();   // Transports player back to previous tile
    void SameTile();               // If two players are on the same tile, gives first player the opportunity to steal coins and moves them back one tile.
    void HiddenTreasure();         // Gives players their hidden treasure based on random chance
    void CandyStore();             // Allows player to make a purchase if they are on a candy store tile.
    void Calamity();               // 40% chance of Calamity ocurring after each turn. This function has a 40% chance of executing.
    void PlayRiddle();             // Allows player to play a riddle
    void PlayRockPaperScissors();  // Allows player to play rock paper scissors
};
