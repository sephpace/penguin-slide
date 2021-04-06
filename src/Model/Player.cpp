/* Author: Seph Pace
 * Email:  sephpace@gmail.com
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

/* Returns the player's current sprite. 
 *
 * Returns:
 *    The player's current sprite.
 */
const sf::Sprite Player::get_sprite() const
{
  int row = std::get<0>(sprite);
  int col = std::get<1>(sprite);
  sf::IntRect rect(row * SPRITE_SIZE, col * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE);
  sf::Sprite current_sprite(sprite_sheet, rect);
  return current_sprite;
}


/* Returns the player's dead state.
 *
 * Returns:
 *    true if the player is dead and false otherwise.
 */
const bool Player::is_dead() const
{
  return dead;
}


/* Kills the player. */
void Player::kill()
{
  dead = true;
}

/* Sets the sprite to the selected column and row in the sprite sheet. Rows and
 * columns both start at 0 and end at 2. Each sprite is labelled in the table
 * below.
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
 * Parameters:
 *    row - The row of the sprite sheet (0-2).
 *    col - The column of the sprite sheet (0-2).
 */
void Player::set_sprite(int row, int col)
{
  std::get<0>(sprite) = row;
  std::get<1>(sprite) = col;
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
  ducking = false;
  jumping = false;
  sliding = false;
  dead = false;
  std::get<0>(sprite) = 0;
  std::get<1>(sprite) = 0;
}
