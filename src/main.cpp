#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  int start_x1 = kGridWidth /2 - 5;
  int start_y1 = kGridHeight /2;
  int start_x2 = kGridWidth /2 + 5;
  int start_y2 = kGridHeight /2;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, start_x1, start_y1, start_x2, start_y2);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Player 1 Score: " << game.GetScore1() << "\n";
  std::cout << "Player 1 Size: " << game.GetSize1() << "\n";
  std::cout << "Player 2 Score: " << game.GetScore2() << "\n";
  std::cout << "Player 2 Size: " << game.GetSize2() << "\n";
  std::cout << game.GetWinner() << " wins the game" << std::endl;
  return 0;
}