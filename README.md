# Snake Game – Bresenham y Traslaciones

**Autores:**  
- Diego García Jennifer  
- Martínez Mendoza Jesús Ángel  

**Instituto Tecnológico de Oaxaca | TecNM Campus Oaxaca**  
**Carrera:** Ingeniería en Sistemas Computacionales  
**Semestre:** 6to  
**Materia:** Graficación  
**Versión:** 2.0

---

## Descripción

Este proyecto es una implementación del clásico juego Snake en C++ para consola. Se utiliza una matriz de 20x20 para renderizar el juego y se aplican traslaciones para mover la serpiente. Además, se implementa el algoritmo de Bresenham de forma manual para dibujar líneas en la consola, lo que permite renderizar de manera continua el cuerpo de la serpiente, especialmente al girar.

El juego finaliza si la serpiente choca consigo misma o con los bordes del área de juego.

---

## Características

- **Movimiento en 4 direcciones:** Arriba, Abajo, Izquierda y Derecha.
- **Crecimiento de la serpiente:** Al consumir una manzana (`*`), la serpiente crece.
- **Detección de colisiones:** El juego termina si la serpiente colisiona con su propio cuerpo o con los límites de la matriz.
- **Renderizado con Bresenham:** Se utiliza el algoritmo de Bresenham para dibujar líneas continuas que representen el cuerpo de la serpiente.
- **Interfaz en consola:** El juego se actualiza en tiempo real, mostrando la matriz, el puntaje y las instrucciones de control.

---

## Estructura del Código

- **Punto.h:**  
  Define la estructura `Punto` que almacena coordenadas `(x, y)`.

- **Serpiente.h / Serpiente.cpp:**  
  Implementan la clase `Serpiente`, que maneja el cuerpo de la serpiente, su movimiento, crecimiento y colisiones con el entorno.

- **Juego.h / Juego.cpp:**  
  Implementan la clase `Juego`, que gestiona la lógica global: renderizado, entrada del usuario, generación de manzanas y detección de colisiones (incluyendo colisiones con los bordes).

- **Bresenham.h:**  
  Contiene la implementación del algoritmo de Bresenham para dibujar líneas en la consola. Esta función se utiliza para renderizar los segmentos del cuerpo de la serpiente de forma continua cuando ésta gira.

- **main.cpp:**  
  Función principal que inicializa y ejecuta el bucle del juego.

---

## Algoritmo de Funcionamiento

### 1. Inicialización

- Se crea una matriz de 20x20 para el área de juego.
- Se genera una manzana en una posición aleatoria que no esté ocupada por la serpiente.
- La serpiente se inicializa en la posición `(0,0)` y se establece la dirección inicial a "derecha" (`D`).

### 2. Bucle principal

Mientras el juego no termine:

- **Dibujo del Frame:**  
  Se reconstruye el tablero usando una matriz de caracteres.  
  - La manzana se dibuja en su posición.
  - El cuerpo de la serpiente se renderiza utilizando el algoritmo de Bresenham para conectar los puntos de giro con líneas continuas.
  
- **Lectura de Entrada:**  
  Se detecta la entrada del usuario para actualizar la dirección (usando `W`, `A`, `S`, `D`).

- **Movimiento y Lógica:**  
  - La serpiente se mueve en la dirección actual.
  - Si la serpiente consume la manzana, crece y se genera una nueva manzana.
  - Se verifica si la serpiente colisiona consigo misma o con los bordes de la matriz; en ese caso, el juego finaliza.

- **Retraso:**  
  Se espera 200 ms entre cada frame para mantener una velocidad de juego constante.

### 3. Finalización

- Se muestra un mensaje de "Juego terminado" junto con el puntaje final cuando la serpiente choca contra una pared o consigo misma.

---

## Instrucciones de Ejecución

### Compilación

Asegúrate de tener instalado un compilador de C++ (por ejemplo, g++). Desde la terminal, posicionado en la carpeta del proyecto, ejecuta:

```bash
cd "Ruta_del_proyecto" ; if ($?) { g++ main.cpp Juego.cpp Serpiente.cpp -o main } ; if ($?) { .\main }
```

**Ejemplo:**

```bash
cd "d:\Documentos\Programacion\Cpp\ito\Graficacion\snake\" ; if ($?) { g++ main.cpp Juego.cpp Serpiente.cpp -o main } ; if ($?) { .\main }
```

### Ejecución

- En Windows, haz doble clic en `main.exe` o ejecútalo desde la terminal.
- En otros sistemas, ejecuta `./main` en la terminal.

### Prueba de Ejecución
![SnakeGame](https://github.com/user-attachments/assets/2602484a-fee8-4fdf-9138-84ffb4104d53)

---

## Notas Adicionales

- **Algoritmo de Bresenham:**  
  Se implementa manualmente para dibujar líneas entre los puntos de la serpiente, logrando que el cuerpo se vea continuo incluso al girar.

- **Traslaciones:**  
  Se usan para mover la serpiente en el tablero.

- **Colisiones:**  
  El juego finaliza si la serpiente choca con los bordes o consigo misma, aumentando el desafío.

