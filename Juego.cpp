#include "Juego.h"
#include "Bresenham.h"
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
    const int filas = 20, cols = 20;
    char board[filas][cols+1]; 

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = ':'; // fondo
        }
        board[i][cols] = '\0';
    }
    
    board[manzana.y][manzana.x] = '*'; //Manzanita :)
    
    //Dibujar la serpiente
    if (serpiente.cuerpo.size() == 1) {
        board[serpiente.cuerpo[0].y][serpiente.cuerpo[0].x] = 'O'; // cabeza
    } else {
        for (size_t i = 0; i < serpiente.cuerpo.size() - 1; i++) {
            vector<Punto> linea = bresenham(serpiente.cuerpo[i], serpiente.cuerpo[i+1]);
            // O es la cabeza, o es el cuerpo
            char caracter = (i == 0) ? 'O' : 'o';
            for (Punto p : linea) {
                // Revisar si esta dentro
                if (p.x >= 0 && p.x < cols && p.y >= 0 && p.y < filas)
                    board[p.y][p.x] = caracter;
            }
        }
    }
    
    system("cls");

    cout << "\t.: ~~~*SNAKE GAME*~~~ :." << endl;
    cout << "--------------------" << endl;
    
    for (int i = 0; i < filas; i++) {
        cout << board[i] << endl;
    }
    
    cout << "--------------------" << endl;
    cout << "\nPuntaje: " << serpiente.cuerpo.size() - 1 << endl;
    cout << "Controles: W, A, S, D" << endl;
    cout << "Presiona CTRL + C para salir" << endl;
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

    try {
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

    } catch (const runtime_error& e) {
        cout << e.what() << endl;
        gameOver = true;
    }
}

bool Juego::terminado() {
    return gameOver;
}
