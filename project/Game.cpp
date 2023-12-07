#include "Game.h"
#include "Player.h"

// ===== CONSTRUCTORS ===== //
Game::Game()
{
}

// ===== ACCESSOR FUNCTIONS ===== //
vector<Candy> Game::getLoadedCandies() // Returns the loaded candies in the Game class as a vector
{
    return _loaded_candies;
}

vector<Character> Game::getLoadedCharacters() // Returns the loaded characters in the Game class as a vector
{
    return _loaded_characters;
}

vector<Player> Game::getLoadedPlayers()
{
    return _loaded_players;
}

vector<Riddle> Game::getLoadedRiddles()
{
    return _loaded_riddles;
}

int Game::getPlayerCount()
{
    return _player_count;
}

// ===== MUTATOR FUNCTIONS ===== //
void Game::setPlayerCount(int player_count)
{
    _player_count = player_count;
}

void Game::setLoadedPlayers(vector<Player> loaded_players)
{
    _loaded_players = loaded_players;
}

// ===== MEMBER FUNCTIONS ====== //
bool Game::loadCandies() // Loads candies from .txt file into the Game class
{
    ifstream file("candies.txt");
    vector<Candy> loaded_candies;
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name;
            string description;
            string effect_type;
            string effect_value;
            string candy_type;
            string price;

            Candy leCandy;

            while (getline(ss, name, '|') && getline(ss, description, '|') && getline(ss, effect_type, '|') && getline(ss, effect_value, '|') && getline(ss, candy_type, '|') && getline(ss, price))
            {
                leCandy.name = name;
                leCandy.description = description;
                leCandy.effect_type = effect_type;
                leCandy.effect_value = stoi(effect_value);
                leCandy.candy_type = candy_type;
                leCandy.price = stod(price);
            }

            loaded_candies.push_back(leCandy);
        }
        _loaded_candies = loaded_candies;
        file.close();
        return true;
    }
    else
    {
        _loaded_candies = loaded_candies;
        cout << "Error: Failed to load candies." << endl;
        file.close();
        return false;
    }
}

bool Game::loadCharacters() // Loads characters from a .txt file into the Game class ** WARNING LOAD CANDIES FIRST USING loadCandies() **
{
    ifstream file("characters.txt");
    vector<Character> loaded_characters;
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name;          // Stores the name as a string
            string stamina;       // Stores the stamina as a string
            string gold;          // Stores the gold as a string
            string candy_inv_str; // Stores all the candies as an unparsed string
            vector<Candy> candy_inv;

            Character leCharacter;

            while (getline(ss, name, '|') && getline(ss, stamina, '|') && getline(ss, gold, '|') && getline(ss, candy_inv_str))
            {
                leCharacter.name = name;
                leCharacter.stamina = stoi(stamina);
                leCharacter.gold = stod(gold);

                stringstream ci(candy_inv_str);
                string candy_name;
                Candy leCandy;

                while (getline(ci, candy_name, ','))
                {
                    leCandy.name = candy_name;
                    candy_inv.push_back(leCandy);
                }
            }

            vector<Candy> loaded_candies = getLoadedCandies();

            for (int i = 0; i < candy_inv.size(); i++)
            {
                for (int j = 0; j < loaded_candies.size(); j++)
                {
                    if (candy_inv.at(i).name == loaded_candies.at(j).name)
                    {
                        candy_inv.at(i) = loaded_candies.at(j);
                    }
                }
            }

            leCharacter.character_candy = candy_inv;
            loaded_characters.push_back(leCharacter);
        }
        _loaded_characters = loaded_characters;
        file.close();
        return true;
    }
    else
    {
        _loaded_characters = loaded_characters;
        cout << "Error: Failed to load characters." << endl;
        file.close();
        return false;
    }
}

bool Game::loadRiddles()
{
    ifstream file("riddles.txt");
    vector<Riddle> loaded_riddles;
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string riddle;
            string solution;

            Riddle leRiddle;

            while (getline(ss, riddle, '|') && getline(ss, solution, '|'))
            {
                leRiddle.riddle = riddle;
                leRiddle.solution = solution;
            }

            loaded_riddles.push_back(leRiddle);
        }

        _loaded_riddles = loaded_riddles;
        file.close();
        return true;
    }
    else
    {
        _loaded_riddles = loaded_riddles;
        cout << "Error: Faield to load riddles." << endl;
        file.close();
        return false;
    }
}

vector<string> Game::printCandyStore()
{
    // srand(time(0));
    vector<int> used_index;
    vector<string> printed_candies;
    for (int i = 0; i < 3; i++)
    {
        bool new_index_generated = false;
        int candy_index = -1;
        while (!new_index_generated)
        {
            int candy_index_generated = rand() % _loaded_candies.size();
            bool is_index_used = false;

            for (int j = 0; j < used_index.size(); j++)
            {
                if (used_index.at(j) == candy_index_generated)
                {
                    is_index_used = true;
                    break;
                }
            }

            if (is_index_used == false)
            {
                candy_index = candy_index_generated;
                new_index_generated = true;
                used_index.push_back(candy_index);
            }
        }
        printed_candies.push_back(_loaded_candies.at(candy_index).name);
        cout << "-------------------------------" << endl;
        cout << "Name: " << _loaded_candies.at(candy_index).name << endl;
        cout << "Description: " << _loaded_candies.at(candy_index).description << endl;
        cout << "Effect: " << _loaded_candies.at(candy_index).effect_type << endl;
        cout << "Effect Value: " << _loaded_candies.at(candy_index).effect_value << endl;
        cout << "Candy Type: " << _loaded_candies.at(candy_index).candy_type << endl;
        cout << "Price: " << _loaded_candies.at(candy_index).price << endl;
    }
    cout << "-------------------------------" << endl;

    return printed_candies;
}

vector<Player> Game::selectCharacters() // Collects number of players, allows players to choose their characters, returns the players in the game as a vector of Player objects
{
    cout << "Welcome to the game of CandyLand. The maximum number of players is 4. Please enter the number of players:" << endl; // Ask user to input number of players
    string num_of_players_str;                                                                                                   // Create variable to store the number of players as a string
    getline(cin, num_of_players_str);                                                                                            // Collect user input for number of players
    int players_number = stoi(num_of_players_str);                                                                               // Convert number of players to integer
    setPlayerCount(players_number);

    vector<Player> players;

    for (int i = 0; i < players_number; i++)
    {
        // Set the players name
        cout << "Enter player name:" << endl;
        string name;
        getline(cin, name);
        Player lePlayer;
        lePlayer.setPlayerName(name);
        lePlayer.setPlayerNumber(i);

        // Ask the player to choose a character
        cout << "Awesome! Here is a list of characters to select from:" << endl;
        cout << "-------------------------------------------" << endl;
        printCharacterData();
        cout << "Which character would you like to select?" << endl;

        bool valid_selection = false;
        while (valid_selection == false)
        {
            string selected_character;
            getline(cin, selected_character);

            bool selection_found = false;
            for (int j = 0; j < _loaded_characters.size(); j++)
            {
                if (_loaded_characters.at(j).name == selected_character)
                {
                    valid_selection = true;
                    selection_found = true;
                    cout << "Your selected character is: " << selected_character << endl;

                    int selected_character_index = -1;
                    for (int k = 0; k < _loaded_characters.size(); k++)
                    {
                        if (_loaded_characters.at(k).name == selected_character)
                        {
                            selected_character_index = k;
                        }
                    }

                    lePlayer.setPlayerCharacterName(_loaded_characters.at(selected_character_index).name);
                    lePlayer.setPlayerStamina(_loaded_characters.at(selected_character_index).stamina);
                    lePlayer.setPlayerGold(_loaded_characters.at(selected_character_index).gold);
                    lePlayer.setPlayerInventory(_loaded_characters.at(selected_character_index).character_candy);
                    lePlayer.setPlayerCandyAmount(_loaded_characters.at(selected_character_index).character_candy.size()); // CHECK THIS

                    players.push_back(lePlayer);

                    vector<Character> new_character_list;
                    for (int l = 0; l < _loaded_characters.size(); l++)
                    {
                        if (l != selected_character_index)
                        {
                            new_character_list.push_back(_loaded_characters.at(l));
                        }
                    }
                    _loaded_characters = new_character_list;
                }
            }
            if (selection_found == false)
            {
                cout << "Invalid selection. Please enter a valid character." << endl;
            }
        }
    }
    return players;
}

void Game::printCharacterData() // Prints the data of the character;
{
    for (int i = 0; i < _loaded_characters.size(); i++)
    {
        cout << "Name: " << _loaded_characters.at(i).name << endl;
        cout << "Stamina: " << _loaded_characters.at(i).stamina << endl;
        cout << "Gold: " << _loaded_characters.at(i).gold << endl;
        cout << "Candies:" << endl;

        string character_candies[9] = {};
        for (int j = 0; j < _loaded_characters.at(i).character_candy.size(); j++)
        {
            character_candies[j] = _loaded_characters.at(i).character_candy.at(j).name;
        }

        for (int k = 0; k < 9; k++)
        {
            if (character_candies[k] == "")
            {
                character_candies[k] = "Empty";
            }
        }

        cout << "|[" << character_candies[0] << "]|"
             << "[" << character_candies[1] << "]"
             << "|[" << character_candies[2] << "]|" << endl;

        cout << "|[" << character_candies[3] << "]|"
             << "[" << character_candies[4] << "]"
             << "|[" << character_candies[5] << "]|" << endl;

        cout << "|[" << character_candies[6] << "]|"
             << "[" << character_candies[7] << "]"
             << "|[" << character_candies[8] << "]|" << endl;

        cout << "-------------------------------------------" << endl;
    }
}

int Game::generateRandomCard()
{
    // srand(time(0));
    int card_number = 0;
    card_number = rand() % 6 + 1;
    return card_number;
}

bool Game::playRiddle()
{
    cout << "Read the following riddle and enter your answer. Be careful, you only get one try to get it right. Good luck!" << endl;

    // srand(time(0));
    int riddle_index = rand() % _loaded_riddles.size();

    cout << _loaded_riddles.at(riddle_index).riddle << endl;

    string answer;
    getline(cin, answer);

    if (answer == _loaded_riddles.at(riddle_index).solution)
    {
        cout << "Congratulations, you correctly answered the riddle!" << endl;
        return true;
    }
    else
    {
        cout << "Congratulations, you're fucking stupid!" << endl;
        return false;
    }
}

bool Game::playRockPaperScissors()
{
    cout << "Welcome to Rock Paper Scissors. You will be playing Rock Paper Scissors against the computer." << endl;

    bool tie = true;
    // srand(time(0));
    while (tie == true)
    {
        cout << "Enter R (Rock), P (Paper), or S (Scissors)" << endl;

        bool valid_input = false;
        string player_choice;
        while (valid_input == false)
        {
            string choice;
            getline(cin, choice);
            if (choice == "R" || choice == "P" || choice == "S" || choice == "r" || choice == "p" || choice == "s")
            {
                if (choice == "R" || choice == "r")
                {
                    cout << "You chose Rock." << endl;
                    player_choice = "Rock";
                }
                else if (choice == "S" || choice == "s")
                {
                    cout << "You chose Scissors." << endl;
                    player_choice = "Scissors";
                }
                else
                {
                    cout << "You chose paper." << endl;
                    player_choice = "Paper";
                }
                valid_input = true;
            }
            else
            {
                cout << "Invalid selection. Please enter a valid option." << endl;
                valid_input = false;
            }
        }

        int computer_choice_int = rand() % 3 + 1;
        string computer_choice;

        if (computer_choice_int == 1)
        {
            computer_choice = "Rock";
            cout << "The computer chose Rock." << endl;
        }
        else if (computer_choice_int == 2)
        {
            computer_choice = "Scissors";
            cout << "The computer chose Scissors." << endl;
        }
        else
        {
            computer_choice = "Paper";
            cout << "The computer chose Paper." << endl;
        }

        if (player_choice == computer_choice)
        {
            cout << "Tie! Play again" << endl;
            tie = true;
        }
        else if ((player_choice == "Rock" && computer_choice == "Scissors") || (player_choice == "Scissors" && computer_choice == "Paper") || (player_choice == "Paper" && computer_choice == "Scissors"))
        {
            cout << "You win!" << endl;
            tie = false;
            return true;
        }
        else
        {
            cout << "The computer has won. Better luck next time!" << endl;
            tie = false;
            return false;
        }
    }
    return false;
}

void Game::drawCard(Player &current_player, Board &board)
{
    cout << "To draw a card press D. To return to turn menu press anything." << endl;
    string draw_card;
    getline(cin, draw_card);
    if (draw_card == "D" || draw_card == "d")
    {
        string color;
        int generated_card = generateRandomCard();
        if (generated_card == 1)
        {
            cout << "You drew a blue card!" << endl;
            color = BLUE;
            int new_pos = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos, current_player.getPlayerNumber());
        }
        else if (generated_card == 2)
        {
            cout << "You drew a green card!" << endl;
            color = GREEN;
            int new_pos = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos, current_player.getPlayerNumber());
        }
        else if (generated_card == 3)
        {
            cout << "You drew a pink card!" << endl;
            color = MAGENTA;
            int new_pos = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos, current_player.getPlayerNumber());
        }
        else if (generated_card == 4)
        {
            cout << "You drew a double blue card!" << endl;
            color = BLUE;
            int new_pos = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos, current_player.getPlayerNumber());
            int new_pos2 = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos2, current_player.getPlayerNumber());
        }
        else if (generated_card == 5)
        {
            cout << "You drew a double green card!" << endl;
            color = GREEN;
            int new_pos = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos, current_player.getPlayerNumber());
            new_pos = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos, current_player.getPlayerNumber());
        }
        else if (generated_card == 6)
        {
            cout << "You drew a double pink card!" << endl;
            color = MAGENTA;
            int new_pos = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos, current_player.getPlayerNumber());
            new_pos = board.findNextColorTile(current_player.getPlayerNumber(), color);
            board.setPlayerPosition(new_pos, current_player.getPlayerNumber());
        }
    }
}

void Game::useCandy(Player &current_player, Board &board)
{
    cout << "Here are your player stats." << endl;
    current_player.printPlayerStats();
    cout << "Here is a description of all the usable candies in your inventory." << endl;
    cout << "Note: Immunity candies may not be used. They only protect you against attacks from other players." << endl;
    current_player.printCandyStats();
    cout << "Which candy would you like to use? If you would like to exit type \"exit\"." << endl;

    bool valid_input = false;
    Candy candy_choice;
    while (valid_input == false)
    {
        string choice;
        getline (cin, choice);

        for (int i = 0; i < current_player.getPlayerInventory().size(); i++)
        {
            if (choice == current_player.getPlayerInventory().at(i).name)
            {
                candy_choice = current_player.getPlayerInventory().at(i);
                valid_input = true;
            }
            if (choice == "exit")
            {
                valid_input = true;
            }
        }

        if (valid_input == false)
        {
            cout << "Invalid selection. Please enter a valid option." << endl;
        }
    }

    if (candy_choice.candy_type == "magical") // MAGICAL CANDIES
    {
        if (candy_choice.name == "Frosty Fizz")
        {
            current_player.addRandomStamina(10, 10);
            current_player.removeCandy(candy_choice.name);
        }
        else if(candy_choice.name == "Crimson Crystal")
        {
            current_player.addRandomStamina(15, 15);
            current_player.removeCandy(candy_choice.name);
        }
        else if(candy_choice.name == "Mystic Marshmallow")
        {
            current_player.addRandomStamina(20, 20);
            current_player.removeCandy(candy_choice.name);
        }
    }
    if (candy_choice.candy_type == "poison")
    {
        if (candy_choice.name == "Lucky Licorice")
        {

        }
        else if (candy_choice.name == "Venomous Vortex")
        {

        }
        else if (candy_choice.name == "Toxic Taffy")
        {

        }
    }
    if (candy_choice.candy_type == "gummy")
    {
        if (candy_choice.name == "Ruby Rupture")
        {

        }
        else if (candy_choice.name == "Fearsome Fudge")
        {

        }
    }

}

void Game::candyStore(Player &current_player)
{
    cout << "You landed on a tile which has a Candy Store, would you like to visit? Enter Y or N." << endl;

    bool valid_input = false;
    vector<string> candy_store_candies;
    while (valid_input == false)
    {
        string choice;
        getline(cin, choice);

        if (choice == "Y" || choice == "N" || choice == "y" || choice == "n")
        {
            valid_input = true;
            if (choice == "Y" || choice == "y")
            {
                cout << "Here is a list of candies in the Candy Store!" << endl;
                candy_store_candies = printCandyStore();
                cout << "Here is your current inventory." << endl;
                current_player.printPlayerStats();
                cout << "Enter the candy you would like to purchase." << endl;

                bool enough_gold = false;
                while (enough_gold == false)
                {

                    bool valid_input2 = false;
                    string chosen_candy_str;
                    while (valid_input2 == false)
                    {
                        string chosen_candy_temp;
                        getline(cin, chosen_candy_temp);

                        for (int i = 0; i < 3; i++)
                        {
                            if (chosen_candy_temp == candy_store_candies.at(i))
                            {
                                valid_input2 = true;
                                chosen_candy_str = chosen_candy_temp;
                            }
                        }

                        if (valid_input2 == false)
                        {
                            cout << "Invalid selection. Please enter a valid option." << endl;
                        }
                    }

                    Candy chosen_candy;
                    for (int i = 0; i < _loaded_candies.size(); i++)
                    {
                        if (chosen_candy_str == _loaded_candies.at(i).name)
                        {
                            chosen_candy = _loaded_candies.at(i);
                        }
                    }

                    if (chosen_candy.price > current_player.getPlayerGold())
                    {
                        cout << "You do not have enough gold for this candy. Please select another candy." << endl;
                    }
                    else
                    {
                        enough_gold = true;
                        bool candy_added = current_player.addCandy(chosen_candy);
                        if (candy_added)
                        {
                            current_player.setPlayerGold(current_player.getPlayerGold() - chosen_candy.price);
                            cout << chosen_candy.price << " gold was removed from your inventory." << endl;
                            current_player.printPlayerStats();
                        }
                    }
                }
            }
            else if (choice == "N" || choice == "n")
            {
            }
            else
            {
                cout << "Invalid selection. Please enter a valid option." << endl;
            }
        }
    }
}

void Game::specialTile(Player &current_player, Board &board)
{
    // srand(time(0));
    int special_tile_chance = -1;
    special_tile_chance = rand() % 10 + 1;

    if (special_tile_chance <= 3)
    {
        // srand(time(0));
        int special_tile_type = 0;
        special_tile_type = rand() % 4 + 1;

        if (special_tile_type == 1)
        {
            cout << "You have landed on a special tile! The tile is a Shortcut Tile" << endl;
            cout << "You are being moved forward 4 tiles!" << endl;

            if (board.getPlayerPosition(current_player.getPlayerNumber()) >= 79)
            {
                board.setPlayerPosition(board.getBoardSize(), current_player.getPlayerNumber());
                board.displayBoard();
            }
            else
            {
                board.movePlayer(4, current_player.getPlayerNumber());
                board.displayBoard();
            }
        }
        else if (special_tile_type == 2)
        {
            cout << "You have landed on a special tile! The tile is an Ice Cream Tile" << endl;
            cout << "You have been granted an additional turn!" << endl;
            nextTurn(current_player, board);
        }
        else if (special_tile_type == 3)
        {
            cout << "You have landed on a special tile! The tile is a Gumdrop Forrest Tile." << endl;
            cout << "You will lose between 5-10 gold coins. You will be taken 4 tiles backwards." << endl;

            current_player.removeRandomGold(10, 5);

            if (board.getPlayerPosition(current_player.getPlayerNumber()) <= 4)
            {
                board.setPlayerPosition(0, current_player.getPlayerNumber());
                board.displayBoard();
            }
            else
            {
                board.movePlayer(-4, current_player.getPlayerNumber());
                board.displayBoard();
            }
        }
        else if (special_tile_type == 4)
        {
            cout << "You have landed on a special tile! The tile is a Gingerbread House Tile." << endl;
            cout << "You will lose one of your candies. You will be taken back to your previous position." << endl;

            board.setPlayerPosition(board.getPlayerPositionOld(current_player.getPlayerNumber()), current_player.getPlayerNumber());
            board.displayBoard();

            current_player.removeRandomCandy();
        }
    }
}

void Game::sameTile(Player &current_player, Board &board)
{
    for (int i = 0; i < _player_count; i++)
    {
        if (i != current_player.getPlayerNumber())
        {
            if (board.getPlayerPosition(i) == board.getPlayerPosition(current_player.getPlayerNumber()))
            {
                cout << current_player.getPlayerName() << " has ended their turn on the same tile as " << _loaded_players.at(i).getPlayerName() << endl;

                if (current_player.getPlayerRobbersRepel() == true)
                {
                    cout << current_player.getPlayerName() << " has a Robber's Repel shield. No gold can be stolen by " << _loaded_players.at(i).getPlayerName() << endl;
                    current_player.setPlayerRobbersRepel(false);
                    cout << current_player.getPlayerName() << "has now lost their Robber's Repel shield." << endl;
                }
                else
                {
                    cout << current_player.getPlayerName() << " has no shield. " << _loaded_players.at(i).getPlayerName() << " will steal 5 - 30 coins from " << current_player.getPlayerName() << "." << endl;
                    int gold_removed = current_player.removeRandomGold(30, 5);
                    _loaded_players.at(i).setPlayerGold(_loaded_players.at(i).getPlayerGold() + gold_removed);
                    cout << gold_removed << " gold has been added to " << _loaded_players.at(i).getPlayerName() << "'s inventory." << endl;
                    _loaded_players.at(i).printPlayerStats();
                }
            }
        }
    }
}

void Game::hiddenTreasure(Player &current_player)
{
    cout << "You have landed on a Hidden Treasure! To secure your treasure you must correctly answer a riddle." << endl;
    if (playRiddle() == true)
    {
        // srand(time(0));
        int treasure_type = 0;
        treasure_type = rand() % 100 + 1;
        if (treasure_type <= 30)
        {
            cout << "Your treasure is a Stamina Refill! You will receive between 10 - 30 additional stamina." << endl;
            current_player.addRandomStamina(30, 10);
        }
        if (treasure_type <= 40 && treasure_type > 30)
        {
            cout << "Your treasure is a Gold Windfall! You will receive between 20 - 40 additional gold." << endl;
            current_player.addRandomGold(40, 20);
        }
        if (treasure_type <= 70 && treasure_type > 40)
        {
            cout << "Your treasure is a Robber's Repel! You will be protected from getting your gold swiped the next time you land on the same tile as another player." << endl;
            current_player.setPlayerRobbersRepel(true);
        }
        if (treasure_type <= 100 && treasure_type > 70)
        {
            cout << "Your treasure is a candy aquisition. You have a 70% chance of receiving a Jellybean of Vigor, and a 30% chance of receiving a Treasure Hunter's Truffle." << endl;

            int candy_type = rand() % 10 + 1;
            if (candy_type <= 7)
            {
                Candy jeyllybean_of_vigor{"Jellybean of Vigor", "Restores 50 stamina", "stamina", 50, 0, "special"};
                cout << "You received a Jellybean of Vigor!" << endl;
                current_player.addCandy(jeyllybean_of_vigor);
            }
            else
            {
                Candy treasure_hunters_truffle{"Treasure Hunter's Truffle", "Solve a riddle and unlock another Hidden Treasure", "other", 0, 0, "special"};
                cout << "You received a Treasure Hunter's Truffle!" << endl;
                current_player.addCandy(treasure_hunters_truffle);
            }
        }
    }
    else
    {
        cout << "You answered the riddle incorrectly and could not get to the Hidden Treasure. Better luck next time!" << endl;
    }
}

void Game::calamity(Player &current_player)
{
    // srand(time(0));
    int calamity_chance = -1;
    calamity_chance = rand() % 10 + 1;

    if (calamity_chance <= 4)
    {
        int calamity_type = -1;
        calamity_type = rand() % 100;

        if (calamity_type < 30)
        {
            cout << "Oh No! A calamity has ocurred! Candy Bandits have swiped your gold coins." << endl;
            current_player.removeRandomGold(10, 1);
        }
        else if (calamity_type >= 30 && calamity_type < 65)
        {
            cout << "Oh Dear! A calamity has ocurred! You got lost in the lollipop labyrinth! You will lose your next turn. To save your turn, you can play rock, paper, scissors." << endl;

            bool valid_input = false;
            while (valid_input == false)
            {
                string choice;
                cout << "Would you like to play rock paper scissors? Enter Y or N" << endl;
                getline(cin, choice);
                if (choice == "Y" || choice == "N" || choice == "y" || choice == "n")
                {
                    valid_input = true;
                    if (choice == "Y" || choice == "y")
                    {
                        bool win = playRockPaperScissors();

                        if (win == true)
                        {
                            cout << "Good Job! You will no longer lose your next turn." << endl;
                        }
                        else
                        {
                            cout << "You will lose your next turn." << endl;
                            current_player.addPlayerSkippedTurn();
                        }
                    }
                    else
                    {
                        cout << "You will lose your next turn." << endl;
                        current_player.addPlayerSkippedTurn();
                    }
                }
            }
        }
        else if (calamity_type >= 65 && calamity_type < 80)
        {
            cout << "Watch Out! A calamity has ocurred! A candy avalanche has struck! You will lose 5 - 10 stamina. To save your stamina, you can play rock, paper, scissors." << endl;

            bool valid_input = false;
            while (valid_input == false)
            {
                string choice;
                cout << "Would you like to play rock paper scissors? Enter Y or N" << endl;
                getline(cin, choice);
                if (choice == "Y" || choice == "N" || choice == "y" || choice == "n")
                {
                    valid_input = true;
                    if (choice == "Y" || choice == "y")
                    {
                        bool win = playRockPaperScissors();

                        if (win == true)
                        {
                            cout << "Good Job! You will no longer lose stamina!" << endl;
                        }
                        else
                        {
                            cout << "You will lose 5 - 10 stamina." << endl;
                            current_player.removeRandomStamina(10, 5);
                        }
                    }
                }
                else
                {
                    cout << "You will lose 5 - 10 stamina." << endl;
                    current_player.removeRandomStamina(10, 5);
                }
            }
        }
        else
        {
            cout << "Oops! A calamity has ocurred! You are stuck in a sticky taffy trap. You will lose your next turn unless you have a magical candy in your inventory." << endl;

            vector<Candy> magic;
            for (int i = 0; i < current_player.getPlayerInventory().size(); i++)
            {
                if (current_player.getPlayerInventory().at(i).candy_type == "magical")
                {
                    magic.push_back(current_player.getPlayerInventory().at(i));
                }
            }

            if (magic.size() > 0)
            {
                cout << "You have a magical candy in your inventory. Would you like to use it to regain your lost turn? Enter Y or N." << endl;
                bool valid_input = false;
                while (valid_input == false)
                {
                    string choice;
                    getline(cin, choice);

                    if (choice == "Y" || choice == "y")
                    {
                        valid_input = true;
                        cout << "Choose the magical candy you would like to use." << endl;
                        cout << "-----------------------------------------------" << endl;

                        for (int i = 0; i < magic.size(); i++)
                        {
                            cout << "Name: " << magic.at(i).name << endl;
                            cout << "Description: " << magic.at(i).description << endl;
                            cout << "Effect: " << magic.at(i).effect_type << endl;
                            cout << "Effect Value: " << magic.at(i).effect_value << endl;
                            cout << "Candy Type: " << magic.at(i).candy_type << endl;
                            cout << "Price: " << magic.at(i).price << endl;
                            cout << "-----------------------------------------------" << endl;
                        }

                        bool valid_input2 = false;
                        while (valid_input2 == false)
                        {
                            string candy_choice;
                            getline(cin, candy_choice);
                            for (int i = 0; i < magic.size(); i++)
                            {
                                if (candy_choice == magic.at(i).name)
                                {
                                    current_player.removeCandy(magic.at(i).name);
                                    cout << "You have used a " << candy_choice << " to escape the sticky taffy trap." << endl;
                                    valid_input2 = true;
                                    break;
                                }
                            }

                            if (valid_input2 == false)
                            {
                                cout << "Invalid selection. Please enter a valid option." << endl;
                            }
                        }
                    }
                    else if (choice == "N" || choice == "n")
                    {
                        valid_input = true;
                        current_player.addPlayerSkippedTurn();
                        cout << "You have lost a turn." << endl;
                    }
                    else
                    {
                        cout << "Invalid selection. Please enter a valid option." << endl;
                    }
                }
            }
            else
            {
                cout << "You have no magical candies in your inventory. You have lost a turn" << endl;
                current_player.addPlayerSkippedTurn();
            }
        }
    }
}

void Game::nextTurn(Player &current_player, Board &board)
{
    if (current_player.playerSkippedTurn())
    {
        cout << current_player.getPlayerName() << "'s turn has been skipped. " << current_player.getPlayerName() << " will play on the next turn." << endl;
    }
    else
    {
        board.setPlayerPositionOld(board.getPlayerPosition(current_player.getPlayerNumber()), current_player.getPlayerNumber()); // Sets the old position of the player to the current position.
        bool turn_completed = false;
        while (turn_completed == false)
        {
            // Ask the user who's turn it is what they would like to do
            cout << "It is " << current_player.getPlayerName() << "'s turn." << endl;
            cout << "What would you like to do?" << endl;
            cout << "1. Draw a card" << endl;
            cout << "2. Use candy" << endl;
            cout << "3. Show player stats" << endl;

            // Collect user input
            bool valid_selection = false;
            int turn_choice = -1;
            while (valid_selection == false)
            {
                string turn_choice_str;
                getline(cin, turn_choice_str);
                int turn_choice_temp = stoi(turn_choice_str);

                if (turn_choice_temp == 1 || turn_choice_temp == 2 || turn_choice_temp == 3)
                {
                    turn_choice = turn_choice_temp;
                    valid_selection = true;
                }
                else
                {
                    cout << "Invalid selection. Please enter a valid option." << endl;
                    valid_selection = false;
                }
            }

            // Execute selected choice
            if (turn_choice == 1)
            {
                drawCard(current_player, board);
                current_player.setPlayerStamina(current_player.getPlayerStamina() - 1);
                cout << "You lost 1 stamina for your turn." << endl;
                board.displayBoard();
                if (board.isPositionCandyStore(board.getPlayerPosition(current_player.getPlayerNumber())))
                {
                }
                specialTile(current_player, board);
                sameTile(current_player, board);
                if (board.isPositionHiddenTreasure(board.getPlayerPosition(current_player.getPlayerNumber())))
                {
                    hiddenTreasure(current_player);
                }
                calamity(current_player);

                turn_completed = true;
            }
            // else if (turn_choice == 2)
            // {
            //     useCandy(current_player, board);
            // }
            else if (turn_choice == 3)
            {
                current_player.printPlayerStats();
                turn_completed = false;
            }
        }
    }
}
