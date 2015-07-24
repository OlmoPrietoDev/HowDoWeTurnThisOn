#include "scene.h"

Scene::Scene() {
  exit_scene_ = false;
  id_ = -1;
  name_ = "";
}

void Scene::init(int id, std::string name) {
  id_ = id;
  name_ = name;
}

bool Scene::exit_scene() const {
  return exit_scene_;
}

int Scene::id() const {
  return id_;
}

std::string Scene::name() const {
  return name_;
}

void Scene::set_exit_scene(bool state) {
  exit_scene_ = state;
}
