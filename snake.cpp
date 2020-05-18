/* Sources for this project:
  https://youtu.be/E_-lMZDi7Uw */
#include <iostream>
#include <ncurses> //for the inputs
using namespace std;

bool gameOver; //global variable that will be used throughout

/*--- Game dimensions ---*/
const int width  = 40;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup() {
  gameOver = false;
  dir = STOP;
  snakeX = width / 2;
  snakeY = height / 2;
  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
}

void Draw() {
  system("clear"); //system('cls') on windows

  /*----- top wall ----*/
  for (int i = 0; i <= width; i++) {
    cout << "#";
  }
  cout << endl;

  /*----- borders -----*/
  for (int i = 0; i < height; i++) {
    for (int j = 0; j <= width; j++){
      if (j == 0) {
        cout << "#";
      } else if ( j == width) {
        cout << "#";
      } else {
        if ( i == snakeY && j == snakeX) {
          cout << "O"; //this is the snake head
        } else if ( i == fruitY && j == fruitX) {
          cout << "F";
        } else {
          cout << " ";
        }
      }
    }
    cout << endl;
  }

  /*--- bottom wall ---*/
  for (int i = 0; i <= width; i++) {
    cout << "#";
  }
  cout << endl;


}

void Input() {
  cout << "Input running" << endl; //TODO: delete

  if (kbhit()) { // keyboard hit, returns positive no if keyboard is hit, zero otherwise
    switch (getch()) { // return ascii value of keyboard hit
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = DOWN;
        break;
      case 's':
        dir = RIGHT;
        break;
      case 'w':
        dir = UP;
        break;
      case 'x':
        gameOver = true;
        break;
    }
  }

}

void Logic() {
  cout << "Logic running" << endl; //TODO: delete

}

int main() {
  cout << "Main running" << endl; //TODO: delete

  Setup();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
    // need to change the value of gameOver here otherwise it will keep going forever!
    // can add a sleep function here to make it go slower
    // sleep(10) - 10 milliseconds
    gameOver = true;
  }

  cout << "End of main" << endl; //TODO: delete

  return 0;
}
