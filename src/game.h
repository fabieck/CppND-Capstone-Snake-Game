#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, int start_x1, int start_y1, int start_x2, int start_y);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  //Player1
  int GetScore1() const;
  int GetSize1() const;
  //Player2
  int GetScore2() const;
  int GetSize2() const;

  std::string GetWinner();

 private:
  Snake snake1;
  Snake snake2;

  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::string winner = "";

  int score1{0};
  int score2{0};


  void PlaceFood();
  void Update();
};

#endif