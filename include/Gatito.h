#pragma once
#include <string>

class Gatito {
private:
    std::string nombre;
    int posicionX;
    int posicionY;
    int vidas;
    int energia;

public:
    Gatito() : nombre(""), posicionX(0), posicionY(0), vidas(0), energia(0) {}

    void MoverArriba() {}
    void MoverAbajo() {}
    void MoverIzquierda() {}
    void MoverDerecha() {}
    void UsarPoderEspecial() {}
};
