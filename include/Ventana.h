#pragma once

#include <SFML/Graphics.hpp>

class Ventana {
private:
    int ancho;
    int alto;
    
public:
    sf::RenderWindow window;
    Ventana() : ancho(800), alto(600), window(sf::VideoMode(ancho, alto), "Juego") {}

    void Mostrar() {
        window.clear();
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        window.draw(shape);
        window.display();
    }

    void ManejarEventos() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    bool EstaAbierta() const {
        return window.isOpen();
    }
};
