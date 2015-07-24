#include "drawable_element.h"

DrawableElement::DrawableElement() {
  m_bIsVisible = true;
  m_uLayer = 0;
}

void DrawableElement::setIsVisible(bool state) {
  m_bIsVisible = state;
}

void DrawableElement::setLayer(unsigned char layer) {
  m_uLayer = layer;
}

bool DrawableElement::isVisible() {
  return m_bIsVisible;
}

unsigned char DrawableElement::getLayer() {
  return m_uLayer;
}
