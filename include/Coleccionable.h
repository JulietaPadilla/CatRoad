#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Coleccionable {
private:
    std::string tipo;
    int posicionX;
    int posicionY;
    sf::Texture textura;
    sf::Sprite sprite;
    bool recolectado = false; // Indica si el coleccionable ha sido recolectado

public:
    Coleccionable() : tipo(""), posicionX(0), posicionY(0) {}

    // Método para cargar la textura desde un archivo
    bool cargarTextura(const std::string& rutaArchivo) {
        if (!textura.loadFromFile(rutaArchivo)) {
            return false;
        }
        sprite.setTexture(textura);
        return true;
    }

    // Método para establecer la posición del coleccionable
    void setPosicion(int x, int y) {
        posicionX = x;
        posicionY = y;
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    }

    // Método para dibujar el coleccionable en la ventana
    void dibujar(sf::RenderWindow& ventana) {
        if (!recolectado) {
            ventana.draw(sprite);
        }
    }

    // Método para recolectar el coleccionable
    void recolectar() {
        if (!recolectado) {
            recolectado = true;
            sprite.setPosition(-100.0f, -100.0f); // Ocultar el sprite
        }
    }

    // Método para verificar si el coleccionable ha sido recolectado
    bool esRecolectado() const {
        return recolectado;
    }

    // Método para obtener el sprite (para colisiones)
    const sf::Sprite& getSprite() const {
        return sprite;
    }
};
