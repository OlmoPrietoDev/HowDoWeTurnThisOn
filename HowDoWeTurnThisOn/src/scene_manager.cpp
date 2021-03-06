#include "scene_manager.h"

#include <SFML/System/Clock.hpp>

SceneManager* SceneManager::m_pInstance = NULL;

SceneManager::SceneManager() {
  m_stackScenes = stack<Scene*>();
  m_pCurrentScene = NULL;
  m_fDeltaTime = 0.0f;
  m_fElapsedTime = 0.0f;
}

SceneManager* SceneManager::getInstance() {
  if (m_pInstance == NULL) {
    m_pInstance = new SceneManager();
  }

  return m_pInstance;
}

Scene* SceneManager::getCurrentScene() {
  return m_stackScenes.getTop();
}

unsigned int SceneManager::getNumberOfScenes() {
  return m_stackScenes.size();
}

float SceneManager::getDeltaTime() {
  return m_fDeltaTime;
}

float SceneManager::getGameElapsedTime() {
  return m_fElapsedTime;
}

void SceneManager::pushScene(Scene *scene) {
  if (m_pCurrentScene != scene) {
    m_stackScenes.push(scene);
    m_pCurrentScene = m_stackScenes.getTop();
  } else {
    std::cout << "The scene you are trying to change to is currently being played!\n";
  }
}

void SceneManager::popScene() {
  m_stackScenes.pop();
  m_pCurrentScene = m_stackScenes.getTop();
  playCurrentScene();
}

void SceneManager::playCurrentScene() {
  m_pCurrentScene->loadAssets();
  
  sf::Clock clock;
  clock.restart();
  sf::Time tmp_time;
  
  while (m_pCurrentScene->getExitSceneState() == false) {
    tmp_time = clock.getElapsedTime();
    m_fDeltaTime = tmp_time.asSeconds();
    m_fElapsedTime += m_fDeltaTime;
    clock.restart();
    
    m_pCurrentScene->gameLoop();
  }
}
