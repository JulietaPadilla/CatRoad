#pragma once
#include <Obstaculo.h>
#include <Coleccionable.h>
#include <string>
#include <vector>

class Nivel {
private:
    std::string tema;
    std::vector<Obstaculo> obstaculos;
    std::vector<Coleccionable> coleccionables;

public:
    Nivel() : tema("") {}

    void GenerarObstaculos() {}
    void GenerarColeccionables() {}
    void Actualizar() {}
};
