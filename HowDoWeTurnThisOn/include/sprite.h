#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <iostream>

#include "drawable_element.h"
#include "utils.h"

class Sprite : public DrawableElement {
  public:
    Sprite();
    Sprite(Sprite *other);
    Sprite(char *path);
    Sprite(std::string path);
    Sprite(const sf::Texture &other);
    ~Sprite();
  
    void setTextureFromFile(char *path);
    void setTextureFromTexture(const sf::Texture &other);
    void setBoundingBox(float width, float height);
    void setBoundingBox(const Rect &box);
    void setPosition(float x, float y);
    void setPosition(const Vec2 &pos);
    void setRotation(float angle);
    void setScale(float scale_x, float scale_y);
    void setScale(const Vec2 &scales);
    void setOrigin(float x, float y); // local to the sprite
    void setOrigin(const Vec2 &origin);

    const Rect &getBoundingBox() const;
    const Vec2 &getPosition() const;
    const float getRotation() const;
    const Vec2 &getScale() const;
    const Vec2 &getOrigin() const;

    void moveBy(float off_x, float off_y);
    void moveBy(const Vec2 &offset);
    void rotate(float angle);
    void scale(float scale_x, float scale_y);
    void scale(const Vec2 &scales);
    
    sf::Sprite getDrawable();
    sf::Sprite *getDrawableAddress();  

  private:
    sf::Sprite *m_pSprite;
    float m_fXPos;
    float m_fYPos;
    float m_fWidth;
    float m_fHeight;
};

#endif // __SPRITE_H__
