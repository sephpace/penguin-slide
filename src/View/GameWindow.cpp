/* Author: Seph Pace
 * Email:  sephpace@gmail.com
 */

#include "GameWindow.hpp"

#include <iostream>

/* Constructor.
 *
 * Parameters:
 *    level - The id of the level to load first.
 */
GameWindow::GameWindow(int level)
{
  window = new sf::RenderWindow(sf::VideoMode(800, 600), "Penguin Slide");
  world = new GameWorld(level);
  controller = new GameController(this->world);
}


/* Destructor. */
GameWindow::~GameWindow() 
{
  delete window;
  delete world;
  delete controller;
}


/* Starts the main game loop. */
void GameWindow::start()
{
  // Set up the clock
  sf::Clock clock;

  // Run the main game loop
  while(window->isOpen())
  {
    // Process events
    sf::Event event;
    while(window->pollEvent(event))
    {
      // Close the game window if an exit event occurs
      if(event.type == sf::Event::Closed)
      {
        window->close();
      }
      else // Process input events
      {
        handle_inputs(event);
      }
    }

    // Update game logic
    sf::Time delta = clock.restart();
    controller->update(delta.asMilliseconds());

    // Clear the window
    window->clear();

    // Render the player
    render_player(world->get_player());

    // Update the window
    window->display();
  }
}


/* Calculates the scale for each sprite to render based on the current size of
 * the window.
 *
 * Returns:
 *    The value of which to scale all sprites.
 */
const float GameWindow::calculate_scale() const
{
  // TODO: Actually calculate this based on the window size
  return 3;
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
const void GameWindow::handle_inputs(const sf::Event event) const
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
const void GameWindow::key_pressed(const sf::Keyboard::Key key) const
{
  switch(key)
  {
    case sf::Keyboard::W:
      controller->jump(true);
      break;

    case sf::Keyboard::A:
      controller->move_left(true);
      break;

    case sf::Keyboard::S:
      controller->duck(true);
      break;

    case sf::Keyboard::D:
      controller->move_right(true);
      break;

    case sf::Keyboard::Space:
      controller->jump(true);
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
const void GameWindow::key_released(const sf::Keyboard::Key key) const
{
  switch(key)
  {
    case sf::Keyboard::W:
      controller->jump(false);
      break;

    case sf::Keyboard::A:
      controller->move_left(false);
      break;

    case sf::Keyboard::S:
      controller->duck(false);
      break;

    case sf::Keyboard::D:
      controller->move_right(false);
      break;

    case sf::Keyboard::Space:
      controller->jump(false);
      break;

    // Ignore all other keypresses
    default:
      break;
  }
}


/* Renders the player.
 *
 * Parameters:
 *    player - The player object.
 */
const void GameWindow::render_player(Player *player) const
{
  // Get the player sprite from the world
  sf::Sprite sprite = player->get_sprite();

  // Scale the player
  float scale_value = calculate_scale();
  sprite.scale(scale_value, scale_value);

  // Center the player on the screen
  sf::Rect<float> sprite_rect = sprite.getGlobalBounds();
  sf::Vector2u window_size = window->getSize();
  sprite.setPosition(((float)window_size.x - sprite_rect.width)  / 2,
                     ((float)window_size.y - sprite_rect.height) / 2);

  // Adjust the player's position depeding on its state
  if(player->is_ducking() || player->is_sliding())
  {
    sf::Vector2f pos = sprite.getPosition();
    sprite.setPosition(pos.x, pos.y + sprite_rect.height / 4);
  }

  // Flip the player if facing left
  if(player->facing_left)
  {
    sprite.scale(-1.f, 1.f);
    sf::Vector2f pos = sprite.getPosition();
    sprite.setPosition(pos.x + sprite_rect.width, pos.y);
  }

  // Draw the player to the screen
  window->draw(sprite);
}

