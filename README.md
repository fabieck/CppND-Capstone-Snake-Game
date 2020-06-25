# Which Project has been chosen?
Project 2 is chosen for the Capstone Project

# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses. In addition to the normal game, this snack game has a pure multiplayer mode. 

# Controls
Player 1: Left - Left Arrow, Right - Right Arrow, Up - Up Arrow, Down - Down Arrow
Player 2: Left - a,          Right - d,           Up - w,        Down - s

# Rules 
The Player who is alive at end of the game wins the game. 

# Acceptance Criteria:
1. The project uses Object Oriented Programming techniques. (all)

2. Classes use appropriate access specifiers for class members. (game.cpp line 119)

3. The project makes use of references in function declarations. (snake.cpp line 5)

4. The project accepts user input and processes the input. (cortroller.cpp line 49-51 )

5. Class constructors utilize member initialization lists. (game.cpp line 5)

# File Class Structure
in src you can find these files

main.cpp -> starts the game, instanciate controller, renderer and game and gives output of score and winner at the end

game.cpp/h -> manages the gameplay

controller.cpp/h -> user input

renderer.cpp/h -> Renders objects for screen

snake.cpp/h -> creates properties of snake


The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.