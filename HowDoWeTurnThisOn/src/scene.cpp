#include "scene.h"

#include "renderer.h"
#include "scene_manager.h"

Scene::Scene() {
  m_bExitScene = false;
  m_iId = -1;
  m_sName = "";
  m_fElapsedTime = 0.0f;
}

void Scene::init(int id, std::string name) {
  m_iId = id;
  m_sName = name;
}

bool Scene::getExitSceneState() const {
  return m_bExitScene;
}

int Scene::getId() const {
  return m_iId;
}

std::string Scene::getName() const {
  return m_sName;
}

void Scene::setExitSceneState(bool state) {
  m_bExitScene = state;
}

void Scene::loadAssets() {
  // Renderer::clean();
}

void Scene::processInput() {
  // maybe fill with actions
}

void Scene::update() {
  m_fElapsedTime += SceneManager::getInstance()->getDeltaTime();
}

void Scene::draw() {
  Renderer::draw();
}
