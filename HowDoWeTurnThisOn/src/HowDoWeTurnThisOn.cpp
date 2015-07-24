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

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "PENE");
	sf::CircleShape circle(30);


	while (window.isOpen()) {

		window.clear();
		window.draw(circle);
		window.display();
	}

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
