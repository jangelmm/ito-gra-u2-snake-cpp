#ifndef JUEGO_H
#define JUEGO_H

#include "Serpiente.h"
#include "Punto.h"

class Juego {
private:
    Serpiente serpiente;
    Punto manzana;
    char direccion;
    bool gameOver;

    void generarManzana();
    void manejarEntrada();

public:
    Juego();
    void dibujar();
    void actualizar();
    bool terminado();
};

#endif
