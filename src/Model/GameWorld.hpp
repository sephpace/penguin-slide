/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP

#include "Player.hpp"


/* The game world contains the player, all of the levels and any other entity
 * in the game. It stores state information to be manipulated by the game
 * controller and graphical information to be rendered by the game window.
 */
class GameWorld
{
  public:
    long score;

    GameWorld(int start_level); // Constructor.
    ~GameWorld();               // Destructor.
    Player* get_player() const; // Returns a pointer to the player object.

  private:
    Player *player;
};

#endif
