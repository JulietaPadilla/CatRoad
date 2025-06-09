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

        const int anchoVentana = 800;
        const int altoVentana = 600;
        
        //creacion del objeto y carga de la fuente
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            // Manejo de error: fuente no encontrada
        }
        while (ventana.EstaAbierta()) {
            ventana.ManejarEventos();


            // Manejo de teclado para mover al gatito con límites de ventana
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                personaje.MoverArriba(0); // Límite superior
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                personaje.MoverAbajo(altoVentana);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                personaje.MoverIzquierda(0); // Límite izquierdo
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                personaje.MoverDerecha(anchoVentana);
            }
            ventana.Mostrar();
        
            //manda llamar el metodo 
            puntaje.Dibujar(ventana.window, font, 10, 10);
        }
    }
};
