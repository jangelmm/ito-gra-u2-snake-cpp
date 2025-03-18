#include "Serpiente.h"
#include <stdexcept>

Serpiente::Serpiente(int x, int y) {
    cuerpo.push_back({x, y});
}

void Serpiente::mover(Punto direccion) {
    Punto nuevaCabeza = {cuerpo[0].x + direccion.x, cuerpo[0].y + direccion.y};

    // Detectar colisión con los límites del mapa
    if (nuevaCabeza.x >= 20 || nuevaCabeza.x < 0 || nuevaCabeza.y >= 20 || nuevaCabeza.y < 0) {
        throw runtime_error("Game Over: La serpiente choco contra la pared!");
    }

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
