#include <iostream>
#include <vector>

/*===================== FUNCTION DECLARATIONS =====================*/

// This funciton will create a 3x3 matrix of chars containing
// ' ' at all locations. This will be used as the initial
// game board.
std::vector<std::vector<char> > CreateBoard();


// This function will display the matrix 'board' to the user
void DisplayBoard(std::vector<std::vector<char> > board);


int main(int argc, char **argv) {
  std::vector<std::vector<char> > board = CreateBoard();

  // Testing Create Board
  for(int i = 0; i < board.size(); i++) {
    for(int j = 0; j < board.at(i).size(); j++) {
      std::cout << board.at(i).at(j) << " ";
    }
    std::cout << '\n';
  }

  return 0;
}


/*=================== FUNCTION IMPLEMENATATIONS ==================*/

std::vector<std::vector<char> > CreateBoard() {
  return std::vector<std::vector<char> >(3, std::vector<char>(3, ' '));
}


void DisplayBoard(std::vector<std::vector<char> > board) {
  std::cout << '\n';
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
      std::cout << "\n-----------\n";
    }
    else {
      std::cout << "\n\n";
    }
  }
}
