#include "Coleccionable.h"
#include <SFML/Graphics.hpp>

void Coleccionable::Actualizar() {
    // Lógica de actualización del coleccionable
}

void Coleccionable::Renderizar(sf::RenderWindow& ventana) const {
    ventana.draw(sprite);
}
