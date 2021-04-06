/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <tuple>

#include <SFML/Graphics.hpp>


/* Contains the assets and state information for the player. */
class Player
{
  public:
    const double WALK_SPEED = 4.0;        // The speed at which the player walks.
    sf::Vector2<double> position;         // The current position of the player.
    sf::Vector2<double> velocity;         // The current velocity of the player.
    sf::Vector2<double> rotation;         // The current rotation of the player.
    sf::CircleShape hitbox;               // The player's hitbox.
    bool ducking;                         // The ducking player state.
    bool jumping;                         // The jumping player state.
    bool sliding;                         // The sliding player state.
    
    Player();                             // Constructor.
    const sf::Sprite get_sprite() const;  // Returns the player sprite.
    const bool is_dead() const;           // Returns the dead player state.
    void kill();                          // Kills the player.
    void set_sprite(int row, int col);    // Sets the sprite to the selected col and row in the spritesheet.
    void reset();                         // Resets the player to its original state.
  
  private:
    const int SPRITE_SIZE = 32;           // The size of each sprite in pixels.
    bool dead;                            // The dead player state.
    sf::Texture sprite_sheet;             // The sprite sheet for the player.
    std::tuple<int, int> sprite;          // The row and column of the current sprite in the sprite sheet.
};

#endif
