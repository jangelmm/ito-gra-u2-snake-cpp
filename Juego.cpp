#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <conio.h>
#include <thread>
#include <chrono>

using namespace std;

Juego::Juego() : serpiente(0, 0), direccion('D'), gameOver(false) {
    srand(time(0));
    generarManzana();
}

void Juego::generarManzana() {
    bool manzanaValida;
    do {
        manzana.x = rand() % 20;
        manzana.y = rand() % 20;

        manzanaValida = all_of(serpiente.cuerpo.begin(), serpiente.cuerpo.end(), [&](Punto p) {
            return !(p.x == manzana.x && p.y == manzana.y);
        });
    } while (!manzanaValida);
}

void Juego::dibujar() {
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == serpiente.cuerpo[0].y && j == serpiente.cuerpo[0].x)
                cout << 'O';
            else if (find_if(serpiente.cuerpo.begin() + 1, serpiente.cuerpo.end(), [&](Punto p) { return p.x == j && p.y == i; }) != serpiente.cuerpo.end())
                cout << 'o';
            else if (i == manzana.y && j == manzana.x)
                cout << '*';
            else
                cout << ':';
        }
        cout << endl;
    }
}

void Juego::actualizar() {
    Punto dir = {0, 0};
    if (_kbhit()) {
        char key = _getch();
        if (key == 'w' && direccion != 'B') direccion = 'A';
        if (key == 's' && direccion != 'A') direccion = 'B';
        if (key == 'a' && direccion != 'D') direccion = 'I';
        if (key == 'd' && direccion != 'I') direccion = 'D';
    }

    switch (direccion) {
        case 'A': dir.y = -1; break;
        case 'B': dir.y = 1; break;
        case 'I': dir.x = -1; break;
        case 'D': dir.x = 1; break;
    }

    serpiente.mover(dir);

    if (serpiente.cuerpo[0].x == manzana.x && serpiente.cuerpo[0].y == manzana.y) {
        serpiente.crecer();
        generarManzana();
    }

    if (find_if(serpiente.cuerpo.begin() + 1, serpiente.cuerpo.end(), [&](Punto p) {
        return p.x == serpiente.cuerpo[0].x && p.y == serpiente.cuerpo[0].y;
    }) != serpiente.cuerpo.end()) {
        gameOver = true;
    }
}

bool Juego::terminado() {
    return gameOver;
}
