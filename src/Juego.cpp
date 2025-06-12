#include <SFML/Graphics.hpp>
#include <JuegoCatCross.h>

int main()
{
    JuegoCatCross juego;

    // Mostrar pantalla de inicio
    juego.MostrarPantallaInicio();

    // Iniciar el juego
    juego.IniciarJuego();

    return 0;
}