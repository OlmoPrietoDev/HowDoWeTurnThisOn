/**
 *  scene.h
 *
 *  @brief Generic class for a game scene.
 *
 *    It has declared as virtual those fundamental methods needed to
 *  be overridden by any inheritant. It also stores references to the
 *  game manager, the scene manager and the controller.
 *
 *  @author Olmo
*/

#ifndef __SCENE_H__
#define __SCENE_H__

#include <iostream>

class Scene {
 public:
  Scene();
  void init(int id, std::string name);

  // GETTERS
  bool exit_scene() const;
  int id() const;
  std::string name() const;

  // SETTERS
  void set_exit_scene(bool state);

  virtual void loadAssets() = 0;
  virtual void gameLoop() = 0;
  virtual void processInput() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;

  virtual ~Scene(){};

 private:
 protected:
  /// @brief It tells when you want to exit the scene. Not used
  bool exit_scene_;
  /// @brief The scene manager uses it to change between scenes
  int id_;
  /// @brief The scene manager uses it to change between scenes
  std::string name_;
};

#endif // __SCENE_H__