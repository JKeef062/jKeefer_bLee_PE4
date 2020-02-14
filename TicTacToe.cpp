#include <iostream>
#include <algorithm>  // Provides transform
#include <vector>     // Provides vector usage

/*===================== FUNCTION DECLARATIONS =====================*/

// This funciton will create a 3x3 matrix of chars containing
// ' ' at all locations. This will be used as the initial
// game board.
std::vector<std::vector<char> > CreateBoard();


// This function will display the matrix 'board' to the user
void DisplayBoard(std::vector<std::vector<char> > board);


// This function prompt the user for which space they wish to
// place their marker. This choice is then returned as a string.
// The int parameter turn is used to determine which player's
// turn it is (Handled in the main program method).
  // NOTE: The options available/presented to the user are;
  //          - ul (Upper Left)
  //          - uc (Upper Center)
  //          - ur (Upper Right)
  //          - cl (Center Left)
  //          - c  (Center)
  //          - cr (Center Right)
  //          - ll (Lower Left)
  //          - lc (Lower Center)
  //          - lr (Lower Right)
        /* the user may input "help" as their space
           selection to view a detailed key of how
           the spaces and input string are mapped */
std::string GetPlayerChoice(int turn);


// This function is used to convert the user specified
// string representing the board location they wish to mark
// into the corresponding int value
int LocationFromString(std::string user_input);


// This function updates the game board with the specified
// player' marker at the location specified in user_input
void PlaceMarker(std::string user_input, int turn,
                 std::vector<std::vector<char> > &matrix);


// Checks the game condition. Returns true iff a player has
// successfully made a line of their specified marks or
// all spaces have been filled and no winner can be determined
bool GameOver(std::vector<std::vector<char> > board);



/*======================== MAIN METHOD =========================*/

int main(int argc, char **argv) {
  std::vector<std::vector<char> > board = CreateBoard();
  int turn = 1;
  std::string location_choice = " ";

  while(!GameOver(board)) {
    DisplayBoard(board);
    location_choice = GetPlayerChoice(turn);
    PlaceMarker(location_choice, turn, board);
    turn++;
  }
  DisplayBoard(board);
  std::cout << "========= GAME OVER =========\n\n";

  return 0;
}


/*=================== FUNCTION IMPLEMENATATIONS ==================*/

std::vector<std::vector<char> > CreateBoard() {
  return std::vector<std::vector<char> >(3, std::vector<char>(3, ' '));
}


void DisplayBoard(std::vector<std::vector<char> > board) {
  std::cout << '\n' << " Tic Tac Toe \n\n";
  for(int i = 0; i < board.size(); i++) {
    for(int j = 0; j < board.at(i).size(); j++) {
      if (j != board.at(i).size() - 1) {
        std::cout << ' ' << board.at(i).at(j) << " |";
      }
      else {
        std::cout << ' ' << board.at(i).at(j);
      }
    }
    if (i != board.size() - 1) {
      std::cout << "\n--- --- ---\n";
    }
    else {
      std::cout << "\n\n";
    }
  }
}


std::string GetPlayerChoice(int turn){
  std::string locations[9] = {"ul", "uc", "ur",
                              "cl", "c", "cr",
                              "ll", "lc", "lr"};
  std::string p_choice = " ";
  bool is_valid_selection = false;
  char player_sign = ' ';
  int player_num = 0;

  if ((turn % 2) == 1) { // player 1's turn
      player_sign = 'X';
      player_num = 1;
  } else {              // player 2's turn
      player_sign = 'O';
      player_num = 2;
  }

  // Prompt user decision
  while(!is_valid_selection) {
    std::cout << "Player " << player_num << "(" << player_sign
              << ")" << ": Please select the "
              << "space you wish to mark"
              << "or input \"help\" to show location key): ";
    std::getline(std::cin, p_choice);

    // Convert user input string to all lower case
    // for comparison against valid space locations
    std::transform(p_choice.begin(), p_choice.end(),
                   p_choice.begin(), ::tolower);

    if (p_choice == "help") {
      std::cout << "\n ul | uc | ur \n"
                << "---- ---- ----\n"
                << " cl |  c | cr \n"
                << "---- ---- ----\n"
                << " ll | lc | lr \n\n";
    }
    else if (p_choice[0] == 'u') {
      for(int i = 0; i < 3; i++) {
        if (p_choice == locations[i]) {
          is_valid_selection = true;
          break;
        }
      }
    }
    else if (p_choice[0] == 'c') {
      for(int i = 3; i < 6; i++) {
        if (p_choice == locations[i]) {
          is_valid_selection = true;
          break;
        }
      }
    }
    else if (p_choice[0] == 'l') {
      for(int i = 6; i < 9; i++) {
        if (p_choice == locations[i]) {
          is_valid_selection = true;
          break;
        }
      }
    }
    else {
      std::cout << "\nINVALID LOCATION!\n\n";
    }
  }

  return p_choice;
}


int LocationFromString(std::string user_input) {
  int location = 0;
  if(user_input == "ul") {
    location = 1;
  }
  else if(user_input == "uc") {
    location = 2;
  }
  else if(user_input == "ur") {
    location = 3;
  }
  else if(user_input == "cl") {
    location = 4;
  }
  else if(user_input == "c") {
    location = 5;
  }
  else if(user_input == "cr") {
    location = 6;
  }
  else if(user_input == "ll") {
    location = 7;
  }
  else if(user_input == "lc") {
    location = 8;
  }
  else {
    location = 9;
  }

  return location;
}


void PlaceMarker(std::string user_input, int turn,
                 std::vector<std::vector<char> > &matrix) {
  int location = LocationFromString(user_input);
  char playerSign;
  if ((turn % 2) == 1) { // player 1's turn
      playerSign = 'X';
  } else {              // player 2's turn
      playerSign = 'O';
  }


  switch (location) {
    case 1:
      matrix.at(0).at(0) = playerSign;
      break;
    case 2:
      matrix.at(0).at(1) = playerSign;
      break;
    case 3:
      matrix.at(0).at(2) = playerSign;
      break;
    case 4:
      matrix.at(1).at(0) = playerSign;
      break;
    case 5:
      matrix.at(1).at(1) = playerSign;
      break;
    case 6:
      matrix.at(1).at(2) = playerSign;
      break;
    case 7:
      matrix.at(2).at(0) = playerSign;
      break;
    case 8:
      matrix.at(2).at(1) = playerSign;
      break;
    case 9:
      matrix.at(2).at(2) = playerSign;
      break;
    default:
      std::cout << "ERROR: location parameter " << location
                << " does not match a valid board location\n"
                << "Terminating...\n\n";
      break;
  }
}


bool GameOver(std::vector<std::vector<char> > board) {
  int unmarked = 0; // Holds the number of unmarked spaces
  char start_char = ' ';

  // Check if board is full
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if (board.at(i).at(j) == ' ') {
        unmarked++;
      }
    }
  }
  if (unmarked == 0) {
    return true;
  }

  // Row-wise check for player win
  for(int i = 0; i < 3; i++) {
    if (board.at(i).at(0) == ' ') {
      continue;
    }
    else if ( (board.at(i).at(0) == board.at(i).at(1)) &&
         (board.at(i).at(1) == board.at(i).at(2)) ) {
      return true;
    }
  }

  // Column-wise check for player win
  for(int i = 0; i < 3; i++) {
    if (board.at(0).at(i) == ' ') {
      continue;
    }
    else if ( (board.at(0).at(i) == board.at(1).at(i)) &&
         (board.at(1).at(i) == board.at(2).at(i)) ) {
      return true;
    }
  }

  // Diagonal check for player win
  if ( (board.at(2).at(0) != ' ') &&
       (board.at(0).at(0) == board.at(1).at(1)) &&
       (board.at(1).at(1) == board.at(2).at(2)) ) {
    return true;
  }

  // Anti-diagonal check for player win
  if ( (board.at(2).at(0) != ' ') &&
       (board.at(2).at(0) == board.at(1).at(1)) &&
       (board.at(1).at(1) == board.at(0).at(2)) ) {
    return true;
  }

  return false;
}
