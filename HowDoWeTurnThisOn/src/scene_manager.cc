#include "scene_manager.h"

SceneManager* SceneManager::instance_ = NULL;

SceneManager::SceneManager() {
  scenes_ = std::vector<Scene*>();
  current_scene_ = NULL;
}

SceneManager* SceneManager::getInstance() {
  if (instance_ == NULL) {
    instance_ = new SceneManager();
  }

  return instance_;
}

Scene* SceneManager::current_scene() {
  return current_scene_;
}

int SceneManager::getNumberOfScenes() {
  return scenes_.size();
}

void SceneManager::set_current_scene(Scene *scene) {
  current_scene_ = scene;
}

void SceneManager::set_current_scene(int id) {
  for (int i = 0; i < scenes_.size(); ++i) {
    if (scenes_[i]->id() == id) {
      current_scene_ = scenes_[i];
      current_scene_->loadAssets(); // load the assets once when entering the scene
      break;
    }
  }
}

void SceneManager::registerScene(Scene* scene) {
  bool repeated = false;
  
  for (int i = 0; i < scenes_.size(); ++i) {
    if (scenes_[i] == scene) {
      repeated = true;
      break;
    }
  }
  if (!repeated) {
    scenes_.push_back(scene);
  }
}

void SceneManager::changeToScene(std::string name) {
  for (int i = 0; i < scenes_.size(); ++i) {
    if (scenes_[i]->name() == name) {
      current_scene_ = scenes_[i];
      current_scene_->set_exit_scene(false);
      current_scene_->loadAssets();
      break;
    }
  }
}

void SceneManager::changeToScene(int id) {
  set_current_scene(id);
}

void SceneManager::playCurrentScene() {
  current_scene_->gameLoop();
}
