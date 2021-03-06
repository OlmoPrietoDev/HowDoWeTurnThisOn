//============================================================================
// Name        : HowDoWeTurnThisOn.cpp
// Author      : Guillermo Barco
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

#include <SFML/Graphics.hpp>

#include "controller.h"
#include "renderer.h"
#include "sprite.h"
#include "system_input.h"

int main() {

  Renderer::init();

  Sprite sprite("resources/tux.png");
  sprite.setOrigin(sprite.getBoundingBox().width / 2, sprite.getBoundingBox().height / 2);

  Controller *controller = Controller::getInstance();

	while (true) {
    CheckController(Renderer::getRenderTarget());

    sprite.setPosition(controller->m_Mouse.getXPos(), controller->m_Mouse.getYPos());

    if (controller->m_Mouse.getLeftButtonState() == 1) {
      std::cout << "Pressed!\n";
    }

		Renderer::draw();
	}
	
	return 0;
}
