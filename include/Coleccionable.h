#pragma once
#include <string>

class Coleccionable {
private:
    std::string tipo;
    int posicionX;
    int posicionY;

public:
    Coleccionable() : tipo(""), posicionX(0), posicionY(0) {}

    void Recolectar() {}
};
