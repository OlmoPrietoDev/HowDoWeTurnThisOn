#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

#include "sprite.h"

// cacota sideral

class Renderer {
  public:
    Renderer() {}
    Renderer(sf::RenderWindow *target);
    ~Renderer() {}

    static void init();
    static void init(sf::RenderWindow *target);

    static sf::RenderWindow *getRenderTarget();

    static void draw();
    // it can be repeated
    static void registerElement(Sprite *element);
    static void deleteElement(Sprite *element);
    static int size();

  private:
    static sf::RenderWindow *m_pTarget;
    static std::vector<DrawableElement*> m_vElements;
    static int m_iNumElements;
};

#endif // __RENDERER_H__
