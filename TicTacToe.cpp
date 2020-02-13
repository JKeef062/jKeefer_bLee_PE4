#include <iostream>
#include <vector>

/*===================== FUNCTION DECLARATIONS =====================*/
std::vector<std::vector<char> > CreateBoard();


int main(int argc, char **argv) {
  std::vector<std::vector<char> > board = CreateBoard();

  /* Testing Create Board
  for(int i = 0; i < board.size(); i++) {
    for(int j = 0; j < board[i].size(); j++) {
      std::cout << board[i][j] << " ";
    }
    std::cout << '\n';
  }*/

  return 0;
}


/*=================== FUNCTION IMPLEMENATATIONS ==================*/
std::vector<std::vector<char> > CreateBoard() {
  return std::vector<std::vector<char> >(3, std::vector<char>(3, ' '));
}
