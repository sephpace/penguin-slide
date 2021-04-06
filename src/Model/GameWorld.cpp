/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#include "GameWorld.hpp"


/* Constructor. 
 *
 * Parameters:
 *    start_level - The index of the starting level.
 */
GameWorld::GameWorld(int start_level)
{
  player = new Player(); 
}


/* Destructor */
GameWorld::~GameWorld()
{
  delete player;
}


/* Returns a pointer to the player object.
 *
 * Returns:
 *    A pointer to the player object.
 */
Player* GameWorld::get_player() const
{
  return player;
}
