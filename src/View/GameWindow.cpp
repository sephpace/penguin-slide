/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameWindow.hpp"


/* Constructor. */
GameWindow::GameWindow() : window(sf::VideoMode(800, 600), "Penguin Slide") {}


/* Destructor. */
GameWindow::~GameWindow() 
{

}


/* Starts the main game loop.
 *
 * Parameters:
 *    level - The id of the level to load first.
 */
void GameWindow::start(int level)
{
  // Run the main game loop
  while(window.isOpen())
  {
    // Process events
    sf::Event event;
    while(window.pollEvent(event))
    {
      // Close the game window if an exit event occurs
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
      else // Process input events
      {
        handle_inputs(event);
      }
    }

    // Clear the window
    window.clear();

    // Update the window
    window.display();
  }
}


/* Reads the input from the user and calls the appropriate methods from within
 * the game controller. Expected inputs are listed below.
 *
 * w     - jump
 * a     - move/rotate left
 * s     - start sliding
 * d     - move/rotate right
 * space - jump
 *
 * Parameters:
 *    event - An input event
 */
void const GameWindow::handle_inputs(const sf::Event event) const
{
  switch(event.type)
  {
    case sf::Event::KeyPressed:
      key_pressed(event.key.code);
      break;

    case sf::Event::KeyReleased:
      key_released(event.key.code);
      break;

    // Ignore all other event types
    default:
      break;
  }
}


/* Calls the appropriate method of the game controller for when a certain key
 * is pressed.
 *
 *  Parameters:
 *      key - The key that was pressed.
 */
void const GameWindow::key_pressed(const sf::Keyboard::Key key) const
{
  switch(key)
  {
    case sf::Keyboard::W:
      std::cout << "W pressed" << std::endl;
      break;

    case sf::Keyboard::A:
      std::cout << "A pressed" << std::endl;
      break;

    case sf::Keyboard::S:
      std::cout << "S pressed" << std::endl;
      break;

    case sf::Keyboard::D:
      std::cout << "D pressed" << std::endl;
      break;

    case sf::Keyboard::Space:
      std::cout << "Space pressed" << std::endl;
      break;

    // Ignore all other keypresses
    default:
      break;
  }
}


/* Calls the appropriate method of the game controller for when a certain key
 * is released.
 *
 *  Parameters:
 *      key - The key that was pressed.
 */
void const GameWindow::key_released(const sf::Keyboard::Key key) const
{
  switch(key)
  {
    case sf::Keyboard::W:
      std::cout << "W released" << std::endl;
      break;

    case sf::Keyboard::A:
      std::cout << "A released" << std::endl;
      break;

    case sf::Keyboard::S:
      std::cout << "S released" << std::endl;
      break;

    case sf::Keyboard::D:
      std::cout << "D released" << std::endl;
      break;

    case sf::Keyboard::Space:
      std::cout << "Space released" << std::endl;
      break;

    // Ignore all other keypresses
    default:
      break;
  }
}
