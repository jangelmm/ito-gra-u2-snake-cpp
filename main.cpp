#include "Juego.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

int main() {
    Juego juego;

    while (!juego.terminado()) {
        juego.dibujar();
        juego.actualizar();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    cout<< "\nJuego terminado!" <<endl;
    cin.ignore();
    return 0;
}
