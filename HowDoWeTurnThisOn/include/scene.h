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
  bool getExitSceneState() const;
  int getId() const;
  std::string getName() const;

  // SETTERS
  void setExitSceneState(bool state);

  virtual void loadAssets();
  virtual void gameLoop() = 0;
  virtual void processInput();
  virtual void update();
  virtual void draw();

  virtual ~Scene(){};

 private:
 protected:
  /// @brief It tells when you want to exit the scene
  bool m_bExitScene;
  int m_iId;
  std::string m_sName;
  
  float m_fElapsedTime;
};

#endif // __SCENE_H__
