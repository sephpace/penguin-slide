/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#include "GameController.hpp"


/* Constructor.
 *
 * Parameters:
 *    
 */
GameController::GameController(GameWorld *world)
{
  this->world = world;  
}

/* Destructor. */
GameController::~GameController()
{

}


/* Makes the player duck.
 *
 * Parameters:
 *    activate - Activate ducking if true and deactivate it otherwise.
 */
void GameController::duck(bool activate)
{
  world->get_player()->ducking = activate;
}


/* Makes the player jump. 
 *
 * Parameters:
 *    activate - Activate jumping if true and deactivate it otherwise.
 */
void GameController::jump(bool activate)
{
  world->get_player()->jumping = activate;
}


/* Moves the player to the left.
 *
 * Parameters:
 *    activate - Activate moving left if true and deactivate it otherwise.
 */
void GameController::move_left(bool activate)
{
  Player *player = world->get_player();
  if(player->sliding)
  { 
    // TODO: Rotate left
  }
  else
  {
    if(activate)
    {
      player->velocity.x = -player->WALK_SPEED;
    }
    else
    {
      player->velocity.x = 0.0;
    }
  }
}


/* Moves the player to the right.
 *
 * Parameters:
 *    activate - Activate moving right if true and deactivate it otherwise.
 */
void GameController::move_right(bool activate)
{
  Player *player = world->get_player();
  if(player->sliding)
  { 
    // TODO: Rotate right
  }
  else
  {
    if(activate)
    {
      player->velocity.x = player->WALK_SPEED;
    }
    else
    {
      player->velocity.x = 0.0;
    }
  }
}


/* Updates the game controller by calculating all of the game logic needed for
 * each frame.
 *
 * Parameters:
 *    delta - The amount of time (in milliseconds) that has elapsed since the previous frame.
 */
void GameController::update(sf::Int32 delta)
{

}
