#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

class InputManager{
public:
                    InputManager();
                    ~InputManager();

    void            captureInputs();
    void            translateInputs();
};

#endif // INPUTMANAGER_H