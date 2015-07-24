#ifndef __DRAWABLE_ELEMENT_H__
#define __DRAWABLE_ELEMENT_H__

#include <SFML/Graphics/Sprite.hpp>

class DrawableElement {
  public:
    DrawableElement();
    ~DrawableElement() {}

    void setIsVisible(bool state);
    void setLayer(unsigned char layer);

    bool isVisible();
    unsigned char getLayer();

    virtual sf::Sprite getDrawable() = 0;

  private:
    bool m_bIsVisible;
    unsigned char m_uLayer;
};

#endif // __DRAWABLE_ELEMENT_H__
