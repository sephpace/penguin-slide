/* Author: Seph Pace * Email:  sephpace@gmail.com
 */

#include "Player.hpp"


/* Constructor. */
Player::Player()
{
  // Load the sprite sheet
  sprite_sheet.loadFromFile("assets/penguin.png");

  // Set up the starting state
  reset();
}


/* Returns the player's sprite for its current state.
 *
 * Returns:
 *    The player's current sprite.
 */
const sf::Sprite Player::get_sprite() const
{
  if(is_walking() && walking_frame == 1)
  {
    return get_sprite(0, 2);
  }
  
  if(is_walking() && walking_frame == 2)
  {
    return get_sprite(1, 0);
  }

  if(is_ducking() || is_sliding())
  {
    return get_sprite(1, 1);
  }

  if(is_dead())
  {
    return get_sprite(2, 1);
  }

  return get_sprite(0, 0);
}


/* Returns the sprite at the given location in the sprite sheet.
 *
 * Layout of the sprites is shown in the table below.
 *
 * +-----------------------+---------+---------------------+
 * |        standing       | jumping |         walk1       |
 * +-----------------------+---------+---------------------+
 * |         walk2         | sliding | Sliding Flippers Up |
 * +-----------------------+---------+---------------------+
 * | Sliding Flippers Down |  Dying  |       Sleeping      |
 * +-----------------------+---------+---------------------+
 *
 * Ex: To get the sprite for "Sliding Flippers Up", row would be 1 and col
 * would be 2.
 *
 * Returns:
 *    The sprite at the given row and col location.
 */
const sf::Sprite Player::get_sprite(int row, int col) const
{
  sf::IntRect rect(col * SPRITE_SIZE, row * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE);
  sf::Sprite current_sprite(sprite_sheet, rect);
  return current_sprite;
}


/* Returns the player's dead state.
 *
 * Returns:
 *    true if the player is dead and false otherwise.
 */
bool Player::is_dead() const
{
  return is_current_state(dead);
}


/* Returns the player's ducking state.
 *
 * Returns:
 *    true if the player is ducking and false otherwise.
 */
bool Player::is_ducking() const
{
  return is_current_state(ducking);
}


/* Returns the player's sliding state.
 *
 * Returns:
 *    true if the player is sliding and false otherwise.
 */
bool Player::is_sliding() const
{
  return is_current_state(sliding);
}


/* Returns the player's walking state.
 *
 * Returns:
 *    true if the player is walking and false otherwise.
 */
bool Player::is_walking() const
{
  return is_current_state(walking);
}


/* Kills the player. */
void Player::kill()
{
  add_state(dead);
}


/* Sets the ducking state to the given value.
 *
 * Parameters:
 *    value - The value to set the ducking state to.
 */
void Player::set_ducking(bool value)
{
  if(value)
  {
    add_state(ducking);
  }
  else
  {
    state_list.remove(ducking);
  }
}


/* Sets the sliding state to the given value.
 *
 * Parameters:
 *    value - The value to set the sliding state to.
 */
void Player::set_sliding(bool value)
{
  if(value)
  {
    add_state(sliding);
  }
  else
  {
    state_list.remove(sliding);
  }
}


/* Sets the walking state to the given value.
 *
 * Parameters:
 *    value - The value to set the walking state to.
 */
void Player::set_walking(bool value)
{
  if(value)
  {
    add_state(walking);
  }
  else
  {
    state_list.remove(walking);
  }
}


/* Resets the player to its original state. */
void Player::reset()
{
  position.x = 0.0;
  position.y = 0.0;
  velocity.x = 0.0;
  velocity.y = 0.0;
  rotation.x = 0.0;
  rotation.y = 0.0;
  // TODO: Figure out what the hitbox size and position should actually be
  hitbox.setRadius(8.0);
  hitbox.setPosition(0.0, 0.0);
  facing_left = false;
  walking_frame = 0;
}


/* Adds the given state to the state list.
 *
 * Does not add duplicate states.
 *
 * Parameters:
 *    s - The state to add.
 */
void Player::add_state(uint8_t s)
{
  // Remove any existing states of this type
  state_list.remove(s);

  // Add the state
  state_list.push_back(s);
}


/* Checks if the given state is the current state.
 *
 * Parameters:
 *    s - The state to check.
 *
 * Returns:
 *    true if the state is current and false otherwise.
 */
bool Player::is_current_state(uint8_t s) const
{
  if(state_list.empty())
  {
    return false;
  }

  return state_list.back() == s;
}
