#include <iostream>
#include <vector>
using namespace std;
/*===================== FUNCTION DECLARATIONS =====================*/
std::vector<std::vector<char> > CreateBoard();

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int turn = 1;

void displayPlayerTurn(int turnCounter) {
    string currentPlayer = "Player 1";
    string turn = to_string(turnCounter);
    if ((turnCounter % 2) == 1) { // player 1's turn
        currentPlayer = " Player 1 (X)";
    } else {
        currentPlayer = " Player 2 (O)";
    }
    cout << " Turn " + turn << ": " << currentPlayer << endl;
    cout << "";
    cout << endl;
}

void replaceMatrixValues(int userInput, int turn) {
    char playerSign;
    if ((turn % 2) == 1) { // player 1's turn
        playerSign = 'X';
    } else {
        playerSign = 'O';
    }
    switch (userInput) {
        case 1:
            matrix[0][0] = playerSign;
            break;
        case 2:
            matrix[0][1] = playerSign;
            break;
        case 3:
            matrix[0][2] = playerSign;
            break;
        case 4:
            matrix[1][0] = playerSign;
            break;
        case 5:
            matrix[1][1] = playerSign;
            break;
        case 6:
            matrix[1][2] = playerSign;
            break;
        case 7:
            matrix[2][0] = playerSign;
            break;
        case 8:
            matrix[2][1] = playerSign;
            break;
        case 9:
            matrix[2][2] = playerSign;
            break;
        default:
            break;
    }
}

void GetPlayerInput() {
    int player1Input;
    int player2Input;
    displayPlayerTurn(turn);
    cout << " Pick a slot ";
    if ((turn % 2) == 1) { // player 1's turn
        cin >> player1Input;
        replaceMatrixValues(player1Input, turn);
    } else {
        cin >> player2Input;
        replaceMatrixValues(player2Input, turn);
    }
    turn ++;
}

void PlayerInput() {
    int turnCounter = 1;
    int player1Input;
    int player2Input;
    for (int turn = 1; turn < 10; turn++) {
        displayPlayerTurn(turnCounter);
        cout << " Pick a slot ";
        if ((turnCounter % 2) == 1) { // player 1's turn
            cin >> player1Input;
            replaceMatrixValues(player1Input, turnCounter);
        } else {
            cin >> player2Input;
            replaceMatrixValues(player2Input, turnCounter);
        }
        turnCounter ++;
    }
}

void DisplayBoard() {
    cout << " Tic Tac Toe " << endl;
    cout << "";
    cout << endl;
    
    for (int i = 0; i<=2; i++) {
        for (int j = 0; j<=2; j++) {
            //cout << " " << matrix[i][j] << " ";
            if (j == 1) {
                cout << "| " << matrix[i][j] << " |";
            } else {
                if (j != 2 ) {
                    cout << "  " << matrix[i][j] << " ";
                } else {
                    cout << " " << matrix[i][j] << " ";
                }
            }
        }
        cout << endl;
        if (i != 2) {
            cout << " --- --- --- ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
  std::vector<std::vector<char> > board = CreateBoard();
    
    DisplayBoard();
    while(1) {
        GetPlayerInput();
        DisplayBoard();
    }

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
