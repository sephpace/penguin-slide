/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <SFML/Graphics.hpp>

#include "../Controller/GameController.hpp"
#include "../Model/GameWorld.hpp"


/* The game window controls all visual aspects of the game. It renders the
 * player, the world, and the menu. It also contains the main game loop that
 * updates the game controller.
 */
class GameWindow
{
  public:
    GameWindow(int level = 1);                                  // Constructor.
    ~GameWindow();                                              // Destructor.
    void start();                                               // Starts the game loop.

  private:
    GameController *controller;                                 // The main game controller.
    sf::RenderWindow *window;                                   // The main render window.
    GameWorld *world;                                           // The game world.
    const float calculate_scale() const;                        // Returns the scale value.

    const void handle_inputs(const sf::Event event) const;      // Read inputs from the user and call controller methods.
    const void key_pressed(const sf::Keyboard::Key key) const;  // Read key press events.
    const void key_released(const sf::Keyboard::Key key) const; // Read key release events.
    const void render_player(Player *player) const;             // Render the player.
};

#endif
