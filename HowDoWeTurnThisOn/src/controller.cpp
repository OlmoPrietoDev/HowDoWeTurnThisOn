#include "controller.h"

#include <iostream>

Controller *Controller::m_pInstance = NULL;

Controller *Controller::getInstance() {
  if (m_pInstance == NULL) {
    m_pInstance = new Controller();
  }

  return m_pInstance;
}

void Controller::Mouse::setXPos(float value) {
  m_fXPos = value;
}

void Controller::Mouse::setYPos(float value) {
  m_fYPos = value;
}

float Controller::Mouse::getXPos() {
  return m_fXPos;
}

float Controller::Mouse::getYPos() {
  return m_fYPos;
}

void Controller::Mouse::setLeftButtonState(unsigned char state) {
  m_ucLeftButton = state;
}

void Controller::Mouse::setRightButtonState(unsigned char state) {
  m_ucRightButton = state;
}

void Controller::Mouse::setWheelState(float state) {
  m_fWheelState = state;
}

unsigned char Controller::Mouse::getLeftButtonState() {
  return m_ucLeftButton;
}

unsigned char Controller::Mouse::getRightButtonState() {
  return m_ucRightButton;
}

float Controller::Mouse::getWheelState() {
  return m_fWheelState;
}
