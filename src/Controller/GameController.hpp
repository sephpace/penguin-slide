/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <SFML/System.hpp>

#include "../Model/GameWorld.hpp"


/* The game controller is in charge of all game mechanics and logic. It
 * recieves input commands from the user and moves the player. It also uses
 * other controllers to calculate phyics and to play audio.
 */
class GameController
{
  public:
    GameController(GameWorld *world); // Contructor.
    ~GameController();                // Destructor.
    void duck(bool activate);         // Makes the player duck.
    void jump(bool activate);         // Makes the player jump.
    void move_left(bool activate);    // Moves the player to the left.
    void move_right(bool activate);   // Moves the player to the right.
    void update(sf::Int32 delta);     // Updates the game logic for the current frame.

  private:
    GameWorld *world;                 // The game world
};

#endif
