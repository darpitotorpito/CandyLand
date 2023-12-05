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

int Game::getPlayerCount()
{
    return _player_count;
}

// ===== MUTATOR FUNCTIONS ===== //
void Game::setPlayerCount(int player_count)
{
    _player_count = player_count;
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
    srand(time(0));
    int card_number = 0;
    card_number = rand() % 6 + 1;
    return card_number;
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
            cout << new_pos2 << endl;
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

void Game::specialTile(Player &current_player, Board &board)
{
    srand(time(0));
    int special_tile_type = 0;
    special_tile_type = rand() % 4 + 1;

    if (special_tile_type == 1)
    {
        cout << "You have landed on a special tile! The tile is a Shortcut Tile" << endl;
        cout << "You are being moved forward 4 tiles!" << endl;

        if (board.getPlayerPosition(current_player.getPlayerNumber()) >= 79)
        {
            board.setPlayerPosition(board.getBoardSize(), current_player.getPlayerNumber());
            cout << "Your position is now " << board.getPlayerPosition(current_player.getPlayerNumber());
        }
        else
        {
            board.movePlayer(4, current_player.getPlayerNumber());
            cout << "Your position is now " << board.getPlayerPosition(current_player.getPlayerNumber());
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

        srand(time(0));
        int gold_lost = 0;
        gold_lost = rand() % 5 + 1;
        current_player.setPlayerGold(current_player.getPlayerGold() - gold_lost);
        cout << "You lost " << gold_lost << " gold. You now have " << current_player.getPlayerGold() << " gold.";

        if (board.getPlayerPosition(current_player.getPlayerNumber()) <= 4)
        {
            board.setPlayerPosition(0, current_player.getPlayerNumber());
            cout << "Your position is now " << board.getPlayerPosition(current_player.getPlayerNumber());
        }
        else
        {
            board.movePlayer(-4, current_player.getPlayerNumber());
            cout << "Your position is now " << board.getPlayerPosition(current_player.getPlayerNumber());
        }

    }
    else if (special_tile_type == 4)
    {
        cout << "You have landed on a special tile! The tile is a Gingerbread House Tile." << endl;
        cout << "You will lose one of your candies. You will be taken back to your previous position." << endl;

        board.setPlayerPosition(board.getPlayerPositionOld(current_player.getPlayerNumber()), current_player.getPlayerNumber());
        cout << "Your position is now " << board.getPlayerPosition(current_player.getPlayerNumber());

    }
}

void Game::nextTurn(Player &current_player, Board &board)
{
    if (current_player.getPlayerSkipTurn())
    {
        cout << current_player.getPlayerName() << "'s turn has been skipped. " << current_player.getPlayerName() << " will play on the next turn." << endl;
    }
    else
    {
        board.setPlayerPositionOld(board.getPlayerPosition(current_player.getPlayerNumber()), current_player.getPlayerNumber());
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

                srand(time(0));
                int special_tile_chance = 0;
                special_tile_chance = rand() % 10 + 1;

                if (special_tile_chance <= 3)
                {
                    specialTile(current_player, board);
                }
                else
                {
                    turn_completed = true;
                }
            }
            // else if (turn_choice == 2)
            // {

            // }
            else if (turn_choice == 3)
            {
                current_player.printPlayerStats();
                turn_completed = false;
            }
        }
    }
}

