#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, int start_x1, int start_y1, int start_x2, int start_y2)
    : snake1(grid_width, grid_height, start_x1, start_y1),
      snake2(grid_width, grid_height, start_x2, start_y2),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake1, snake2);
    Update();
    renderer.Render(snake1, snake2, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score1, score2, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake1.SnakeCell(x, y) && !snake2.SnakeCell(x,y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake1.alive || !snake2.alive){
    if(!snake1.alive){
      winner = "Player 2";
    }
    else{
      winner = "Player 1";
    }
    return;
  } 

  snake1.Update(snake2);
  snake2.Update(snake1);

  //Player 1
  int new_x1 = static_cast<int>(snake1.head_x);
  int new_y1 = static_cast<int>(snake1.head_y);
  //Player2
  int new_x2 = static_cast<int>(snake2.head_x);
  int new_y2 = static_cast<int>(snake2.head_y);

  // Check if there's food over here
  //Player 1
  if (food.x == new_x1 && food.y == new_y1) {
    score1++;
    
    PlaceFood();
    // Grow snake and increase speed.
    snake1.GrowBody();
    snake1.speed += 0.02;
  }
  //Player2
  else if(food.x == new_x2 && food.y == new_y2)
  {
    score2++;
    
    PlaceFood();
    // Grow snake and increase speed.
    snake2.GrowBody();
    snake2.speed += 0.02;
  }
}

int Game::GetScore1() const { return score1; }
int Game::GetSize1() const { return snake1.size; }


int Game::GetScore2() const { return score2; }
int Game::GetSize2() const { return snake2.size; }

std::string Game::GetWinner()
{
  return winner;
}