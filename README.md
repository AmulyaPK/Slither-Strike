# Slither-Strike
Welcome to Slither Strike!

This is a classic Snake game implemented in C++ using object-oriented programming principles. The game involves controlling a snake to help the it eat fruit (here, shown by the character 'X') that appears in random locations on the screen. When the snake head coincides with the location of a fruit, the size of the snake increases. The goal of the game is for the snake to eat as much fruit as possible without colliding with the snake's own tail.

Features:
1. Players can choose between easy, meduim and hard levels. These levels determine the speed of the game - hard being the fastest and easy being the slowest.
2. The game uses keyboard input ('W', 'A', 'S', 'D') to change the direction of the snake.
3. If the snake encounters a wall, it just reappears from the opposite wall and the player can continue playing the game.
4. The score is displayed at all times during the game. The score is equal to the number of fruits eaten by the snake till the end of the game.
5. Every time the snake eats a fruit, the length of the tail increases, increasing the difficulty as the player progresses in the game.
6. When the snake head collides with any part of its tail, the game ends.

Gameplay:
1. Choose a difficulty level by entering 1 (Easy), 2 (Medium), or 3 (Hard).
2. Use the following keys to control the snake:
   W: Move Up, 
   A: Move Left, 
   S: Move Down, 
   D: Move Right.
4. The game ends when the snake collides with its own tail.
