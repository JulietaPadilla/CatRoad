#pragma once
#include <Gatito.h>
#include <Nivel.h>
#include <Sonido.h>
#include <Ventana.h>
#include <Puntaje.h>
#include <SFML/Graphics.hpp>
#include "Coleccionable.h"
#include <vector>

class JuegoCatCross {
private:
    Gatito personaje;
    Nivel nivelActual;
    Sonido sonido;
    Ventana ventana;
    Puntaje puntaje;
    std::vector<Coleccionable> coleccionables; // Lista de coleccionables

public:
    JuegoCatCross() {}

    void inicializarColeccionables() {
        Coleccionable c1;
        c1.cargarTextura("assets/coleccionable1.png");
        c1.setPosicion(100, 200);
        coleccionables.push_back(c1);

        Coleccionable c2;
        c2.cargarTextura("assets/coleccionable2.png");
        c2.setPosicion(300, 400);
        coleccionables.push_back(c2);
    }

    void dibujarColeccionables(sf::RenderWindow& ventana) {
        for (auto& coleccionable : coleccionables) {
            coleccionable.dibujar(ventana);
        }
    }

    void verificarColisionesColeccionables() {
        sf::FloatRect jugadorBounds = personaje.getSprite(); // Obtener los límites del sprite del personaje
        for (auto& coleccionable : coleccionables) {
            if (!coleccionable.esRecolectado() && coleccionable.getSprite().getGlobalBounds().intersects(jugadorBounds)) {
                coleccionable.recolectar();
                puntaje.Aumentar(10); // Incrementar puntaje al recolectar
            }
        }
    }

    void IniciarJuego() {

        const int anchoVentana = 800;
        const int altoVentana = 600;
        
        //creacion del objeto y carga de la fuente
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            // Manejo de error: fuente no encontrada
        }
        inicializarColeccionables();
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
            dibujarColeccionables(ventana.window);
            verificarColisionesColeccionables();
            ventana.Mostrar();
        
            //manda llamar el metodo 
            puntaje.Dibujar(ventana.window, font, 10, 10);
        }
    }
};
