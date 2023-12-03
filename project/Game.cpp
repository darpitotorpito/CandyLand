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

// ===== MUTATOR FUNCTIONS ===== //
void Game::setPlayers(int players)
{
    _players = players;
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

vector<Player> Game::selectCharacters()
{
    cout << "Welcome to the game of CandyLand. Please enter the number of players:" << endl; // Ask user to input number of players
    string num_of_players_str;                                                               // Create variable to store the number of players as a string
    getline(cin, num_of_players_str);                                                        // Collect user input for number of players
    int players_number = stoi(num_of_players_str);                                                      // Convert number of players to integer
    setPlayers(players_number);
    
    
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
                    for (int k = 0; k <  _loaded_characters.size(); k++)
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
                    lePlayer.setPlayerCandyAmount();

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
                cout << "Invalid selection. Please enter a valid cahracter." << endl;
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