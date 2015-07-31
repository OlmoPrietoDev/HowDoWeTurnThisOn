#include "sprite.h"

#include "renderer.h"

#include <iostream>

Sprite::Sprite() {
  m_pSprite = NULL;
  m_fXPos = 0.0f;
  m_fYPos = 0.0f;  
  m_fWidth = 0.0f;
  m_fHeight = 0.0f;

  Renderer::registerElement(this);
}

Sprite::Sprite(Sprite *other) {
  m_pSprite = other->getDrawableAddress();
  std::cout << "DESDE EL INTERIOOOOR " << m_pSprite << std::endl;
  m_fXPos = other->getPosition().x;
  m_fYPos = other->getPosition().y;
  m_fWidth = other->getBoundingBox().width;
  m_fHeight = other->getBoundingBox().height;
}

Sprite::Sprite(char *path) {
  sf::Texture *texture = new sf::Texture();
  if (texture->loadFromFile(path)) {
    m_pSprite = new sf::Sprite(*texture);
    m_fWidth = m_pSprite->getLocalBounds().width;
    m_fHeight = m_pSprite->getLocalBounds().height;
  } else {
    m_fXPos = 0.0f;
    m_fYPos = 0.0f;
    m_fWidth = 0.0f;
    m_fHeight = 0.0f; 

    std::cout << "Failed to load " << path << std::endl;
  }

  Renderer::registerElement(this);

  //delete texture;
}

Sprite::Sprite(std::string path) {
  Sprite(path.c_str());
}

Sprite::Sprite(const sf::Texture &other) {
  if (&other != NULL) {
    m_pSprite = new sf::Sprite(other);
    m_fWidth = m_pSprite->getLocalBounds().width;
    m_fHeight = m_pSprite->getLocalBounds().height;
  } else {
    m_fXPos = 0.0f;
    m_fYPos = 0.0f;
    m_fWidth = 0.0f;
    m_fHeight = 0.0f;

    std::cout << "The given texture is null\n";
  }
  
  Renderer::registerElement(this);
}

Sprite::~Sprite() {
  Renderer::deleteElement(this);

  if (m_pSprite != NULL) {
    delete m_pSprite;
  }
}

void Sprite::setTextureFromFile(char *path) {
  sf::Texture *texture = new sf::Texture;
  if (texture->loadFromFile(path)) {
    m_pSprite->setTexture(*texture);
    m_fWidth = m_pSprite->getLocalBounds().width;
    m_fHeight = m_pSprite->getLocalBounds().height;
  } else {
    std::cout << "Failed to load " << path << std::endl;
    Renderer::deleteElement(this);
  }

  //delete texture;
}

void Sprite::setTextureFromTexture(const sf::Texture &other) {
  if (&other != NULL) {
    m_pSprite->setTexture(other);
    m_fWidth = m_pSprite->getLocalBounds().width;
    m_fHeight = m_pSprite->getLocalBounds().height;
  } else {
    std::cout << "The given texture is null\n";
    Renderer::deleteElement(this);
  }
}

void Sprite::setBoundingBox(float width, float height) {
  m_fWidth = width;
  m_fHeight = height;
}

void Sprite::setBoundingBox(const Rect &box) {
  m_fWidth = box.width;
  m_fHeight = box.height;
}

void Sprite::setPosition(float x, float y) {
  m_pSprite->setPosition(x, y);
  m_fXPos = x;
  m_fYPos = y;
}

void Sprite::setPosition(const Vec2 &pos) {
  m_pSprite->setPosition(pos.x, pos.y);
  m_fXPos = pos.x;
  m_fYPos = pos.y;
}

void Sprite::setRotation(float angle) {
  m_pSprite->setRotation(angle);
}

void Sprite::setScale(float scale_x, float scale_y) {
  m_pSprite->setScale(scale_x, scale_y);
}

void Sprite::setScale(const Vec2 &scales) {
  m_pSprite->setScale(scales.x, scales.y);
}

void Sprite::setOrigin(float x, float y) {
  m_pSprite->setOrigin(x, y);
}

void Sprite::setOrigin(const Vec2 &origin) {
  m_pSprite->setOrigin(origin.x, origin.y);
}

const Rect &Sprite::getBoundingBox() const {
  return Rect(m_fWidth, m_fHeight);
}

const Vec2 &Sprite::getPosition() const {
  return Vec2(m_fXPos, m_fYPos);
}

const float Sprite::getRotation() const {
  return m_pSprite->getRotation();
}

const Vec2 &Sprite::getScale() const {
  Vec2 tmp(m_pSprite->getScale().x, 
    m_pSprite->getScale().y);

  return tmp;
}

const Vec2 &Sprite::getOrigin() const {
  Vec2 tmp(m_pSprite->getOrigin().x, 
    m_pSprite->getOrigin().y);

  return tmp;
}

void Sprite::moveBy(float off_x, float off_y) {
  m_fXPos += off_x;
  m_fYPos += off_y;
}

void Sprite::moveBy(const Vec2 &offset) {
  m_fXPos += offset.x;
  m_fYPos += offset.y;
}

void Sprite::rotate(float angle) {
  m_pSprite->rotate(angle);
}

void Sprite::scale(float scale_x, float scale_y) {
  m_pSprite->scale(scale_x, scale_y);
}

void Sprite::scale(const Vec2 &scales) {
  m_pSprite->scale(scales.x, scales.y);
}

sf::Sprite Sprite::getDrawable() {
  return *m_pSprite;
}

sf::Sprite *Sprite::getDrawableAddress() {
  return m_pSprite;
}
