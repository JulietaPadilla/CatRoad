#pragma once
#include <Gatito.h>
#include <Nivel.h>
#include <Sonido.h>
#include <Ventana.h>
#include <Puntaje.h>
#include <SFML/Graphics.hpp>

class JuegoCatCross {
private:
    Gatito personaje;
    Nivel nivelActual;
    Sonido sonido;
    Ventana ventana;
    Puntaje puntaje;

public:
    JuegoCatCross() {}

    void IniciarJuego() {
        while (ventana.EstaAbierta()) {
            ventana.ManejarEventos();
            ventana.Mostrar();
        }
    }
};
