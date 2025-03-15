#pragma once

#include <vector>
#include "Punto.h"

using namespace std;

class Serpiente {
public:
    vector<Punto> cuerpo;
    bool debeCrecer = false;

    Serpiente(int x, int y);
    void mover(Punto direccion);
    void crecer();
};
