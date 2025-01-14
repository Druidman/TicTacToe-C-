#include <iostream>
using namespace std;

void printBoard(char board[3][3]);
void placeMove(char board[3][3], char currPlayer);
bool checkBoardState(char board[3][3], char currPlayer);
bool checkValidMove(char board[3][3],int row, int column);


int main(){
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char currPlayer = 'X';
    cout << "Zaczyna: " << currPlayer;
    while (true){
        printBoard(board);
        placeMove(board,currPlayer);
        if (checkBoardState(board,currPlayer)){
            cout << "\nWygrał gracz " << currPlayer << "!\n"; 
            break;
        }
        switch (currPlayer)
        {
            case 'X':
                currPlayer = 'O';
                break;
            case 'O':
                currPlayer = 'X';
                break;
        }
    }
    
    return 0;
}

void printBoard(char board[3][3]){
    cout << "\n";
    for (int i=0; i<3; i++){
        cout << "| ";
        for (int j=0; j<3; j++){
            cout << board[i][j] << " | ";
        }   
        cout << "\n|___________|\n";
    }
}

bool checkBoardState(char board[3][3],char currPlayer){
    //rows
    for (int i=0; i<3; i++){
        bool full = true;
        for (int j=0; j<3; j++){
            if (board[i][j] != currPlayer){
                full = false;
                break;
            }
        }
        if (full){
            return true ; 
        }
        
    }

    //columns
    for (int j=0; j<3; j++){
        bool full = true;
        for (int i=0; i<3; i++){
            if (board[i][j] != currPlayer){
                full = false;
                break;
            }
        }
        if (full){
            return true ; 
        }
        
    }

    //diagonals
    if (
        board[0][2] == board[1][1] == board[2][0] == currPlayer 
        ||
        board[0][0] == board[1][1] == board[2][2] == currPlayer
    ) { 
     
        return true; 
    }
    return false;
}

void placeMove(char board[3][3], char currPlayer){
    cout << "Ruch gracza: " << currPlayer;
    int row;
    int column;
    cout << "\nWiersz: ";
    cin >> row;
    cout << "\nKolumna: ";
    cin >> column;
    if (!checkValidMove(board,row,column)){
        cout << "\nZły ruch jeszcze raz!\n";
        placeMove(board,currPlayer);
        return ; 
    }
    board[row-1][column-1] = currPlayer;
}

bool checkValidMove(char board[3][3],int row, int column){
    if (row <= 0 || column <= 0){
        return false;
    }
    if (row > 3 || column > 3){
        return false;
    }
    if (board[row-1][column-1] != ' '){
        return false;
    }
    return true;


}



