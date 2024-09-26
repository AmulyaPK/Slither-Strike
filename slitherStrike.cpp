#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;

const int height = 30;
const int width = 60;

enum eDirection {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class fruit {
public:
    int x, y;

    fruit() {
        respawn();
    }

    void respawn() {
        x = rand() % width;
        y = rand() % height;
    }
};

class snake {
public:
    int x, y;
    int tailX[100], tailY[100];
    int nTail;
    eDirection dir;

    snake() {
        x = width / 2;
        y = height / 2;
        nTail = 0;
        dir = STOP;
    }

    void move() {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1 ; i < nTail ; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch(dir) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            default:
                break;
        }

        if (x < 1) x += width;
        if (x >= width) x -= width;
        if (y <= 1) y += height;
        if (y >= height + 1) y -= height;
    }

    bool checkCollision() {
        for (int i = 0 ; i < nTail ; i++) {
            if (tailX[i] == x && tailY[i] == y)
                return true;
        }
        return false;
    }

    void grow() {
        nTail++;
    }

    void changeDirection(eDirection newDir) {
        dir = newDir;
    }
};

class game {
public:
    snake snake;
    fruit fruit;
    int score;
    bool gameOver;

    game() {
        score = 0;
        gameOver = false;
    }

    void draw() {
        system("cls");
        for (int i = 0 ; i < width ; i++) cout << "-";
        cout << endl;

        for (int i = 0 ; i < height ; i++) {
            for (int j = 0 ; j < width ; j++) {
                if (j == 0 || j == width - 1)
                    cout << "|";
                else if (snake.x == j && snake.y == i)
                    cout << "O";
                else if (fruit.x == j && fruit.y == i)
                    cout << "X";
                else {
                    bool print = false;
                    for (int k = 0 ; k < snake.nTail ; k++) {
                        if (snake.tailX[k] == j && snake.tailY[k] == i) {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }
            }
            cout << endl;
        }

        for (int i = 0 ; i < width ; i++) cout << "-";
        cout << endl;

        cout << "Score: " << score << endl;
    }

    void input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a':
                    if (snake.dir != RIGHT) snake.changeDirection(LEFT);
                    break;
                case 'w':
                    if (snake.dir != DOWN) snake.changeDirection(UP);
                    break;
                case 'd':
                    if (snake.dir != LEFT) snake.changeDirection(RIGHT);
                    break;
                case 's':
                    if (snake.dir != UP) snake.changeDirection(DOWN);
                    break;
                default:
                    gameOver = true;
                    break;
            }
        }
    }

    void logic() {
        snake.move();

        if (snake.checkCollision()) {
            gameOver = true;
        }

        if (snake.x == fruit.x && snake.y == fruit.y) {
            score += 10;
            snake.grow();
            fruit.respawn();
        }
    }

    bool isGameOver() {
        return gameOver;
    }
};

int main() {
    int choice, speed;
    cout << "snake GAME" << endl << "Levels:" << endl;
    cout << "1. Easy" << endl << "2. Medium" << endl << "3. Hard" << endl;
    cout << "Select your level (Enter choice 1, 2 or 3): ";
    cin >> choice;
    switch(choice) {
        case 1:
            speed = 50;
            break;
        case 2:
            speed = 20;
            break;
        case 3:
            speed = 5;
            break;
        default:
            speed = 35;
            break;
    }

    game game;
    while (!game.isGameOver()) {
        game.draw();
        game.input();
        game.logic();
        Sleep(speed);
    }

    cout << "Well played :)" << endl;
    return 0;
}
