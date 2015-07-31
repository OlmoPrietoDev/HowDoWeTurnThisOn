#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class Controller {
  public:
    struct Mouse {
      private:
        float m_fXPos;
        float m_fYPos;
        unsigned char m_ucLeftButton;
        unsigned char m_ucRightButton;
        float m_fWheelState;

      public:
        void setXPos(float pos);
        void setYPos(float pos);
        float getXPos();
        float getYPos();
        void setLeftButtonState(unsigned char state);
        void setRightButtonState(unsigned char state);
        void setWheelState(float state);
        unsigned char getLeftButtonState();
        unsigned char getRightButtonState();
        float getWheelState();
    };

    static Controller *getInstance();

    Mouse m_Mouse;

  private:
    Controller() {}
    ~Controller() {}

    static Controller *m_pInstance;
};

#endif // __CONTROLLER_H__
