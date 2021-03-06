#include "scene_test1.h"

SceneTest1::SceneTest1() {
  circle_ = sf::CircleShape(30.0f);
  circle_.setPosition(100.0f, 100.0f);
}

void SceneTest1::loadAssets() {
  
}

void SceneTest1::gameLoop() {
  while (!exit_scene_) {
    processInput();
    update();
    draw();
  }
}

void SceneTest1::processInput() {

}

void SceneTest1::update() {

}

void SceneTest1::draw() {
  window_->clear(sf::Color(0, 0, 0, 255));
  window_->draw(circle_);
  window_->display();
}

void SceneTest1::setRenderTarget(sf::RenderWindow *window) {
  window_ = window;
}
