#include "system_input.h"

sf::Event event;
Controller *controller = Controller::getInstance();

void CheckController(sf::RenderWindow *window) {
  while(window->pollEvent(event)) {
    switch (event.type) {// == sf::Event::MouseMoved) {
      case sf::Event::MouseMoved: {
        controller->m_Mouse.setXPos(event.mouseMove.x);
        controller->m_Mouse.setYPos(event.mouseMove.y);
        break;      
      }
      case sf::Event::MouseButtonPressed: {
        switch(event.mouseButton.button) {
          case sf::Mouse::Left: {
            controller->m_Mouse.setLeftButtonState(1);
            break;
          }
          case sf::Mouse::Right: {
            controller->m_Mouse.setRightButtonState(1);
            break;
          }
        }
        break;
      }
      case sf::Event::MouseButtonReleased: {
        switch(event.mouseButton.button) {
          case sf::Mouse::Left: {
            controller->m_Mouse.setLeftButtonState(0);
            break;
          }
          case sf::Mouse::Right: {
            controller->m_Mouse.setRightButtonState(0);
            break;
          }
        }
        break;
      }
    }
  }
}
