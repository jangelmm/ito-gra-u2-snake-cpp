#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

struct Punto {
    int x, y;
};

class Serpiente {
public:
    vector<Punto> cuerpo;
    bool debeCrecer = false;

    Serpiente(int x, int y) {
        cuerpo.push_back({x, y});
    }

    void mover(Punto direccion) {
        Punto nuevaCabeza = {cuerpo[0].x + direccion.x, cuerpo[0].y + direccion.y};

        // Teletransporte si sale del límite
        if (nuevaCabeza.x >= 20) nuevaCabeza.x = 0;
        if (nuevaCabeza.x < 0) nuevaCabeza.x = 19;
        if (nuevaCabeza.y >= 20) nuevaCabeza.y = 0;
        if (nuevaCabeza.y < 0) nuevaCabeza.y = 19;

        cuerpo.insert(cuerpo.begin(), nuevaCabeza);

        // Solo eliminar la cola si no debe crecer
        if (!debeCrecer) {
            cuerpo.pop_back();
        } else {
            debeCrecer = false; // Resetea el crecimiento
        }
    }

    void crecer() {
        debeCrecer = true;
    }
};

class Juego {
private:
    Serpiente serpiente;
    Punto manzana;
    char direccion;
    bool gameOver;

public:
    Juego() : serpiente(0, 0), direccion('D'), gameOver(false) {
        srand(time(0));
        generarManzana();
    }

    void generarManzana() {
        bool manzanaValida;
        do {
            manzana.x = rand() % 20;
            manzana.y = rand() % 20;

            // Asegura que la manzana no aparezca dentro de la serpiente
            manzanaValida = all_of(serpiente.cuerpo.begin(), serpiente.cuerpo.end(), [&](Punto p) {
                return !(p.x == manzana.x && p.y == manzana.y);
            });
        } while (!manzanaValida);
    }

    void dibujar() {
        system("cls");
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == serpiente.cuerpo[0].y && j == serpiente.cuerpo[0].x)
                    cout << '#';
                else if (find_if(serpiente.cuerpo.begin() + 1, serpiente.cuerpo.end(), [&](Punto p) { return p.x == j && p.y == i; }) != serpiente.cuerpo.end())
                    cout << '#';
                else if (i == manzana.y && j == manzana.x)
                    cout << '*';
                else
                    cout << '.';
            }
            cout << endl;
        }
    }

    void actualizar() {
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

        // Comprobar si come la manzana
        if (serpiente.cuerpo[0].x == manzana.x && serpiente.cuerpo[0].y == manzana.y) {
            serpiente.crecer();
            generarManzana();
        }

        // Comprobar si choca consigo misma
        if (find_if(serpiente.cuerpo.begin() + 1, serpiente.cuerpo.end(), [&](Punto p) {
            return p.x == serpiente.cuerpo[0].x && p.y == serpiente.cuerpo[0].y;
        }) != serpiente.cuerpo.end()) {
            gameOver = true;
        }
    }

    bool terminado() {
        return gameOver;
    }
};

int main() {
    Juego juego;
    while (!juego.terminado()) {
        juego.dibujar();
        juego.actualizar();
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "\nJuego terminado!" << endl;
    return 0;
}