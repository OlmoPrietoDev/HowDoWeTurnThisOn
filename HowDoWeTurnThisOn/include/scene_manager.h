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

class SceneManager {
 public:
  static SceneManager* getInstance();

  // GETTERS
  Scene* current_scene();
  int getNumberOfScenes();

  // SETTERS
  void set_current_scene(Scene *scene);
  void set_current_scene(int id);

  /// @brief Checks if scene is in the vector, and adds it if not
  void registerScene(Scene *scene);
  void changeToScene(std::string name);
  void changeToScene(int id);
  /// @brief Calls the GameLoop of current_scene_
  void playCurrentScene();

  ~SceneManager();

 private:
  SceneManager();

  std::vector<Scene*> scenes_;
  Scene *current_scene_;

  static SceneManager *instance_;

};

#endif // __SCENE_MANAGER_H__
