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
  elapsed_time = 0;
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
  world->get_player()->set_ducking(activate);
}


/* Makes the player jump. 
 *
 * Parameters:
 *    activate - Activate jumping if true and deactivate it otherwise.
 */
void GameController::jump(bool activate)
{
  // TODO: Add jumping mechanics here
}


/* Moves the player to the left.
 *
 * Parameters:
 *    activate - Activate moving left if true and deactivate it otherwise.
 */
void GameController::move_left(bool activate)
{
  Player *player = world->get_player();
  if(player->is_sliding())
  { 
    // TODO: Rotate left
  }
  else
  {
    // Start walking left
    if(activate)
    {
      player->velocity.x = -player->WALK_SPEED;
      player->set_walking(true);
      player->facing_left = true;
    }
    // Stop walking (unless the player has started walking right)
    else if(player->facing_left)
    {
      player->velocity.x = 0.0;
      player->set_walking(false);
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
  if(player->is_sliding())
  { 
    // TODO: Rotate right
  }
  else
  {
    // Start walking right
    if(activate)
    {
      player->velocity.x = player->WALK_SPEED;
      player->set_walking(true);
      player->facing_left = false;
    }
    // Stop walking (unless the player has started walking left)
    else if(!player->facing_left)
    {
      player->velocity.x = 0.0;
      player->set_walking(false);
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
  // Calculate the elapsed time
  elapsed_time += delta;

  // Only progress the frame if the correct amount of time has passed
  if(elapsed_time >= FRAME_DURATION)
  {
    // Reset elapsed time
    elapsed_time -= FRAME_DURATION;

    // Get the player from the world
    Player *player = world->get_player();

    // Update frames for walking animation
    if(player->is_walking())
    {
      if(player->walking_frame == 1)
      {
        player->walking_frame = 2;
      }
      else
      {
        player->walking_frame = 1;
      }
    }
  }
}
