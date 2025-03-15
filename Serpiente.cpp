#include "Serpiente.h"

Serpiente::Serpiente(int x, int y) {
    cuerpo.push_back({x, y});
}

void Serpiente::mover(Punto direccion) {
    Punto nuevaCabeza = {cuerpo[0].x + direccion.x, cuerpo[0].y + direccion.y};

    // Teletransporte si sale del límite
    if (nuevaCabeza.x >= 20) nuevaCabeza.x = 0;
    if (nuevaCabeza.x < 0) nuevaCabeza.x = 19;
    if (nuevaCabeza.y >= 20) nuevaCabeza.y = 0;
    if (nuevaCabeza.y < 0) nuevaCabeza.y = 19;

    cuerpo.insert(cuerpo.begin(), nuevaCabeza);

    if (!debeCrecer) {
        cuerpo.pop_back();
    } else {
        debeCrecer = false;
    }
}

void Serpiente::crecer() {
    debeCrecer = true;
}
