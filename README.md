# Algoritmo de Funcionamiento

> Hola Jenny c:

## Instrucciones 

>Crear el juego del gusanito.
>Todo a mano y a consola en forma de matriz.
>Usar translaciones

## Algoritmo General (Inicio)

```
Clases:

Serpiente:
- puntoInicial
- cuerpo[puntos]  //un Vector de puntos usando vector.h
+ crecerUnPunto()
+ moverArriba
+ moverAbajo
+ moverIzquierda
+ moverDerecha

moverDerecha(
	recorrer cada punto a la derecho
		si(posicion punto == 19) actualizer a 0,0
misma lógica para los otros metodos


Punto
- x
- y
+ moverArriba
+ moverAbajo
+ moverIzquierda
+ moverDerecha

main

1. Crear una matriz de 20 x 20 
2. Crear un punto aleatorio que se llamara manzana "0" 
3. Crear la serpiente (0,0) 0
4. Direccion = D, que avance una posición cada Segundo, al igual que se actualice cada segundo
5. Repetir el siguiente bucle
	dibujar la matriz con manzana y serpiente
	segun (Direccion)
		case D:
			mover serpiente a la derecho()
		case I: 
			mover serpiente a la izquierda()
		Case A: 
			mover serpiente a la Arriba()
		Case B: 
			mover serpiente a la Abajo()

si (punto_inicial == manzana)
	crecer en punto (usando los dos últimos puntos de dirección que concidan, por ejemplo si tienen la misma x, o la misma y, en esa dirección crecen i es >=3) o usando la cabeza

si (cabeza == algunPunto) entonces
	fin el juego


```
## Algoritmo detallado según las clases

#### **Clase Serpiente**

- **Atributos:**
    
    - `vector<Punto> cuerpo`: Guarda las coordenadas de cada parte de la serpiente.
    - `bool debeCrecer`: Indica si la serpiente debe crecer tras comer una manzana.
- **Métodos:**
    
    - `Serpiente(int x, int y)`: Crea una serpiente con una cabeza en `(x, y)`.
    - `mover(Punto direccion)`: Mueve la cabeza de la serpiente según la dirección dada.
        - Si la serpiente sale de los límites, reaparece en el lado opuesto (efecto "teletransporte").
        - Si `debeCrecer` es `true`, no elimina la cola, haciendo que la serpiente crezca.
    - `crecer()`: Activa la bandera `debeCrecer` para el próximo movimiento.

---

#### **Clase Punto**

- **Atributos:**
    - `int x, y`: Coordenadas del punto.

---

#### **Clase Juego**

- **Atributos:**
    
    - `Serpiente serpiente`: Objeto serpiente controlado por el jugador.
    - `Punto manzana`: Coordenadas de la manzana.
    - `char direccion`: Dirección actual (`W`, `A`, `S`, `D`).
    - `bool gameOver`: Marca si el juego ha terminado.
- **Métodos privados:**
    
    - `generarManzana()`: Genera una manzana en una posición aleatoria que no choque con la serpiente.
    - `manejarEntrada()`: Lee el teclado para actualizar la dirección.
- **Métodos públicos:**
    
    - `Juego()`: Inicializa el juego con la serpiente en `(0,0)` y una dirección inicial (`D`).
    - `dibujar()`: Dibuja el tablero de 20x20, la serpiente (`O` y `o`) y la manzana (`*`).
    - `actualizar()`:
        - Mueve la serpiente en la dirección actual.
        - Verifica si la serpiente come la manzana (crece y genera nueva manzana).
        - Comprueba si la cabeza choca con el cuerpo (termina el juego).
    - `terminado()`: Retorna si el juego ha terminado.

---

### **Flujo principal (main)**

1. **Inicialización**
    
    - Crea el juego y muestra el tablero.
    - La serpiente inicia en `(0,0)` y la dirección inicial es `D` (derecha).
2. **Bucle principal**  
    **Mientras el juego no termine:**
    
    - **Dibuja** el tablero actualizado.
    - **Lee** la entrada del usuario (`W`, `A`, `S`, `D`) para cambiar la dirección.
    - **Mueve** la serpiente según la dirección.
    - **Verifica** colisiones (manzana o cuerpo).
    - **Espera** 200 ms para mantener la velocidad constante.
3. **Fin del juego**
    
    - Muestra el mensaje "Juego terminado" cuando la serpiente choca consigo misma.

## Instrucciones de Ejecución

Para ejecutar solo da doble click en `main.exe`

Para compilar presiona (ya posicionado en el archivo `main.cpp`) en VS code `CTRL + ALT + N`

Modifica la instruccion de la terminal por lo siguiente

```
cd "Ruta" ; if ($?) { g++ main.cpp Juego.cpp Serpiente.cpp -o main } ; if ($?) { .\main }
```

**Ejemplo**

```
cd "d:\Documentos\Programacion\Cpp\ito\Graficacion\snake\" ; if ($?) { g++ main.cpp Juego.cpp Serpiente.cpp -o main } ; if ($?) { .\main }
```