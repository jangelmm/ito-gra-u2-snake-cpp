#pragma once
#include <vector>
#include <cstdlib>
#include "Punto.h"

using namespace std;

// Calcula los puntos de una línea entre p0 y p1 usando el algoritmo de Bresenham.

vector<Punto> bresenham(Punto p0, Punto p1) {
    vector<Punto> puntos;
    int x0 = p0.x, y0 = p0.y;
    int x1 = p1.x, y1 = p1.y;
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy; // error acumulado

    while (true) {
        puntos.push_back({x0, y0});
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { 
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y0 += sy;
        }
    }
    return puntos;
}
