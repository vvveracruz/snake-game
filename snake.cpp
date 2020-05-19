/* Sources for this project:
  https://youtu.be/E_-lMZDi7Uw */
#include <iostream>
#include <ncurses.h> //for the inputs
#include <unistd.h>
using namespace std;

bool gameOver; //global variable that will be used throughout

const int width  = 40;
const int height = 20;
int headX, headY, fruitX, fruitY, score, nTail;
int tailX[100], tailY[100];

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup() {
  gameOver = false;
  dir = STOP;
  headX = width / 2;
  headY = height / 2;
  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
  nTail = 1;
}

void Draw() {
  system("clear"); //system('cls') on windows

  cout << "SCORE: " << score << endl;

  /*----- top wall ----*/
  for (int i = 0; i <= width; i++) {
    cout << "-";
  }
  cout << endl;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j <= width; j++){
      if (j == 0) {
        cout << "|";
      } else if ( j == width) {
        cout << "|";
      } else {
        if ( i == headY && j == headX) {          // snake head
          cout << "O";
        } else if ( i == fruitY && j == fruitX) { // fruit
          cout << "*";
        } else {
          bool tail = false;
          for (int k = 1; k < nTail; k++) {     // tail
            if (tailX[k] == j && tailY[k] ==  i) {
              cout << "o";
              tail = true;
            }
          }
          if (!tail) {
            cout << " ";
          }
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
        headX--;
        break;
      case 100: // d
        dir =  LEFT;
        headX++;
        break;
      case 115: // s
        dir = DOWN;
        headY++;
        break;
      case 119: // w
        dir = UP;
        headY--;
        break;
      case 120: // x
        gameOver = true;
        break;
    }
  } else {
    switch (dir) {
      case RIGHT: // a
        headX--;
        break;
      case LEFT: // d
        headX++;
        break;
      case DOWN: // s
        headY++;
        break;
      case UP: // w
        headY--;
        break;
      default:
        break;
    }
  }
}

void Logic() {
  if (headX >  width || headX < 0 || headY >  height || headY < 0) {
    gameOver = true;
  }

  tailX[0] = headX;
  tailY[0] = headY;
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;
  for (int i = 1; i < nTail; i++) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }

  if (headX == fruitX && headY == fruitY) {
    fruitX = rand() % width;
    fruitY = rand() % height;
    score += 10;
    nTail++;
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
