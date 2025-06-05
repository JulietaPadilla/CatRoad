#pragma once

class Puntaje {
private:
    int valor;

public:
    Puntaje() : valor(0) {}

    void Aumentar(int valor) { this->valor += valor; }
    void Reiniciar() { valor = 0; }
    int ObtenerValor() const { return valor; }
};
