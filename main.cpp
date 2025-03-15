#include "Juego.h"
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    Juego juego;
    while (!juego.terminado()) {
        juego.dibujar();
        juego.actualizar();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "\nJuego terminado!" << std::endl;
    return 0;
}
