#pragma once
#include <string>

class Obstaculo {
private:
    std::string tipo;
    int posicionX;
    int posicionY;

public:
    Obstaculo() : tipo(""), posicionX(0), posicionY(0) {}

    void Mover() {}
};
