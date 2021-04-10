/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>

#include <SFML/Graphics.hpp>


/* Contains the assets and state information for the player. */
class Player
{
  // Possible player states
  enum states {dead, ducking, sliding, walking};

  public:
    const double WALK_SPEED = 4.0;          // The speed at which the player walks.
    sf::Vector2<double> position;           // The current position of the player.
    sf::Vector2<double> velocity;           // The current velocity of the player.
    sf::Vector2<double> rotation;           // The current rotation of the player.
    sf::CircleShape hitbox;                 // The player's hitbox.
    bool facing_left;                       // Used to determine sprite direction.
    int walking_frame;                      // The current frame of the walking animation.
    
    Player();                               // Constructor.
    const sf::Sprite get_sprite() const;    // Returns the player sprite.
    const sf::Sprite get_sprite(int row, int col) const; // Returns the sprite at the given location.
    bool is_dead() const;                   // Returns the dead player state.
    bool is_ducking() const;                // Returns the ducking player state.
    bool is_sliding() const;                // Returns the sliding player state.
    bool is_walking() const;                // Returns teh walking player state.
    void kill();                            // Kills the player.
    void set_ducking(bool value);           // Sets ducking to the given value.
    void set_sliding(bool value);           // Sets sliding to the given value.
    void set_walking(bool value);           // Sets walking to the given value.
    void reset();                           // Resets the player to its original state.
  
  private:
    const int SPRITE_SIZE = 32;             // The size of each sprite in pixels.
    sf::Texture sprite_sheet;               // The sprite sheet for the player.
    std::list<uint8_t> state_list;          // The states that need reactivating.

    void add_state(uint8_t s);              // Adds a state to the state list.
    bool is_current_state(uint8_t s) const; // Checks if a state is the current state.
};

#endif
