/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <SFML/Graphics.hpp>


/* The game window controls all visual aspects of the game. It renders the
 * player, the world, and the menu. It also contains the main game loop that
 * updates the game controller.
 */
class GameWindow
{
  public:
    GameWindow();                                                  // Constructor.
    ~GameWindow();                                                 // Destructor.
    void start(int level = 1);                                     // Starts the game loop.

  private:
    sf::RenderWindow window;                                       // The main render window.

    void const handle_inputs(const sf::Event event) const;         // Read inputs from the user and call controller methods.
    void const key_pressed(const sf::Keyboard::Key key) const;  // Read key press events.
    void const key_released(const sf::Keyboard::Key key) const; // Read key release events.
};

#endif
