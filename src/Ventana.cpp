#include <Ventana.h>

int main() {
    Ventana ventana;
    // Cargar la imagen antes del bucle principal. Cambia la ruta por la de tu imagen real
    if (!ventana.CargarImagen("assets/imagenes/mi_imagen.png")) {
        return 1; // Error al cargar la imagen
    }
    while (ventana.EstaAbierta()) {
        ventana.ManejarEventos();
        ventana.Mostrar();
    }
    return 0;
}
