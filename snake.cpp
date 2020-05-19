/* Sources for this project:
  https://youtu.be/E_-lMZDi7Uw */
#include <iostream>
#include <ncurses.h> //for the inputs
#include <unistd.h>
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
    cout << "-";
  }
  cout << endl;

  /*----- borders -----*/
  for (int i = 0; i < height; i++) {
    for (int j = 0; j <= width; j++){
      if (j == 0) {
        cout << "|";
      } else if ( j == width) {
        cout << "|";
      } else {
        if ( i == snakeY && j == snakeX) {
          cout << "O"; //this is the snake head
        } else if ( i == fruitY && j == fruitX) {
          cout << "*";
        } else {
          cout << " ";
        }
      }
    }
    cout << endl;
  }

  /*--- bottom wall ---*/
  for (int i = 0; i <= width; i++) {
    cout << "-";
  }
  cout << endl;


}

int kbhit() {
  int ch = getch();

   if (ch != ERR) {
       ungetch(ch);
       return 1;
   } else {
       return 0;
   }
}

void Input() {
  clear();
  Draw();
  usleep(200000);
  nodelay(stdscr, TRUE);
  if (kbhit()) {
    switch (getch()) { // return ascii value of keyboard hit
      case 97: // a
        dir = RIGHT;
        snakeX--;
        break;
      case 100: // d
        dir =  LEFT;
        snakeX++;
        break;
      case 115: // s
        dir = DOWN;
        snakeY++;
        break;
      case 119: // w
        dir = UP;
        snakeY--;
        break;
      case 120: // x
        gameOver = true;
        break;
    }
  } else {
    switch (dir) {
      case RIGHT: // a
        snakeX--;
        break;
      case LEFT: // d
        snakeX++;
        break;
      case DOWN: // s
        snakeY++;
        break;
      case UP: // w
        snakeY--;
        break;
      default:
        break;
    }
  }
}

void Logic() {
  if (snakeX >  width || snakeX < 0 || snakeY >  height || snakeY < 0) {
    gameOver = true;
  }

  if (snakeX == fruitX && snakeY == fruitY) {
    // add tail to snake
    // change the position fo the fruit
    fruitX = rand() % width;
    fruitY = rand() % height;
  }
}

void Play() {
  cout << "Input running" << endl; //TODO: delete

  initscr();
  noecho();
  curs_set(FALSE);

  while(!gameOver){
    Input();
    Logic();
    refresh();
    endwin();
  }
}


int main() {

  Setup();
  Play();

  return 0;
}
