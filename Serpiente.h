#ifndef SERPIENTE_H
#define SERPIENTE_H

#include <vector>
#include "Punto.h"

class Serpiente {
public:
    std::vector<Punto> cuerpo;
    bool debeCrecer = false;

    Serpiente(int x, int y);
    void mover(Punto direccion);
    void crecer();
};

#endif
