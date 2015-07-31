#include "renderer.h"

sf::RenderWindow* Renderer::m_pTarget = NULL;

std::vector<DrawableElement*> Renderer::m_vElements = std::vector<DrawableElement*>();

int Renderer::m_iNumElements = 0;

Renderer::Renderer(sf::RenderWindow *target) {
  m_pTarget = new sf::RenderWindow(sf::VideoMode(800, 600), "HOLIIS");
}

void Renderer::init() {
  m_pTarget = new sf::RenderWindow(sf::VideoMode(800, 600), "HOLIIS");
}

void Renderer::init(sf::RenderWindow *target) {
  m_pTarget = new sf::RenderWindow(sf::VideoMode(800, 600), "HOLIIS");
}

sf::RenderWindow *Renderer::getRenderTarget() {
  return m_pTarget;
}

void Renderer::draw() {
  m_pTarget->clear();

  //m_pTarget->draw(m_vElements[0]->getDrawable());  

  for (int i = 0; i < m_vElements.size(); ++i) {
    if (m_vElements[i]->isVisible()) {  
      m_pTarget->draw(m_vElements[i]->getDrawable());
    }
  }

  m_pTarget->display();
}

void Renderer::registerElement(Sprite *element) {
  //Sprite *tmp = new Sprite(element);
  //std::cout << tmp->getDrawableAddress() << std::endl;
  m_vElements.push_back(element);
  //tmp = NULL;

  /*Sprite tmp = element;
  m_vElements.push_back(&tmp);
  ++m_iNumElements;
  std::cout << "Internal size: " << m_vElements.size() << std::endl;*/
}

void Renderer::deleteElement(Sprite *element) {
  std::vector<DrawableElement*>::iterator it = m_vElements.begin();

  for (int i = 0; i < m_iNumElements; ++i, ++it) {
    Sprite *tmp = (Sprite*)*it;  
    if (tmp == element) {
      //m_vElements.erase(it);
      //--m_iNumElements;
      break;
    }
  }
}

int Renderer::size() {
  return m_vElements.size();
}
