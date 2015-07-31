/**
 *  scene_manager.h
 *
 *  @brief Class that manages the scene-switching
 *
 *    It's implemented by Singleton design pattern. It has a std::vector
 *  used to store scenes, and to do so you need to register them with the 
 *  method registerScene(), which checks if the scene already exist. You can
 *  switch from the current scene to another by id or by name.
 *
 *  @author Olmo
*/

#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include <iostream>
#include <vector>

#include "scene.h"
#include "stack.h"

class SceneManager {
 public:
  static SceneManager* getInstance();

  // GETTERS
  Scene* getCurrentScene();
  unsigned int getNumberOfScenes();
  float getDeltaTime();
  float getGameElapsedTime();

  void pushScene(Scene *scene);
  void popScene();
  /// @brief Calls the GameLoop of current_scene_
  void playCurrentScene();

  ~SceneManager();

 private:
  SceneManager();
  
  static SceneManager *m_pInstance;
  
  stack<Scene*> m_stackScenes;
  Scene *m_pCurrentScene;
  float m_fDeltaTime;
  float m_fElapsedTime;
};

#endif // __SCENE_MANAGER_H__
