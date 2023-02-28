#include <iostream>
#include <random>
#include <chrono>
#include <thread>
using namespace std;

// Constants
const int WINDOW_SIZE = 800;
const int CELL_SIZE = 5;
const int DELAY_MS = 100;
const int SIZE = 20;


// Function prototypes
// Function prototypes
void initialize_board(bool board[][SIZE]);
/*
  Initializes the given 2D boolean array to a random initial state.
  Parameters:
    board: A 2D boolean array representing the game board.
*/

void update_board(bool board[][SIZE]);
/*
  Updates the given 2D boolean array to the next state of the game board based on the Game of Life rules.
  Parameters:
    board: A 2D boolean array representing the game board.
*/

void visualize_board(bool board[][SIZE]);
/*
  Prints the given 2D boolean array to the console to visualize the current state of the game board.
  Parameters:
    board: A 2D boolean array representing the game board.
*/

int main() {
  bool board[SIZE][SIZE];
  
  initialize_board(board);
  
  for (int i = 0; i < 10; i++) {
    update_board(board);
    visualize_board(board);
  }
  
  return 0;
}

void initialize_board(bool board[][SIZE]) {
  srand(time(NULL));
  
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = rand() % 2;
    }
  }
}

void update_board(bool board[][SIZE]) {
  bool new_board[SIZE][SIZE];
  
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      int count = 0;
      
      for (int k = i - 1; k <= i + 1; k++) {
        for (int l = j - 1; l <= j + 1; l++) {
          if (k >= 0 && k < SIZE && l >= 0 && l < SIZE && !(k == i && l == j)) {
            count += board[k][l];
          }
        }
      }
      
      if (board[i][j]) {
        if (count < 2 || count > 3) {
          new_board[i][j] = false;
        } else {
          new_board[i][j] = true;
        }
      } else {
        if (count == 3) {
          new_board[i][j] = true;
        } else {
          new_board[i][j] = false;
        }
      }
    }
  }
  
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = new_board[i][j];
    }
  }
}


void visualize_board(bool board[][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j]) {
        cout << "X ";
      } else {
        cout << ". ";
      }
    }
    
    cout << endl;
  }
  
  cout << endl;
}