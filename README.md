# CHESS BOARD

 <img src="https://github.com/YLMV-2020/BMG-CHESS-BOARD/blob/cmake/screenshot/game.png" width="300px">

## Problema 🚀

Implementar una función que dibuje un tablero de ajedrez con la posición de las piezas pasada como parámetro.

El parámetro a pasar será una cadena compuesta solamente de los siguientes caracteres:

```
p, r, b, n, q, k, /, 1, 2, 3, 4, 5, 6, 7, 8
```

Donde cada pieza es representada por una carácter, siendo las negras caracteres en minúscula y las blancas caracteres en mayúsculas. Los caracteres son:

```
p = peón
r = torre
b = alfil
n = caballo
q = reina
k = rey
```

Para separar las filas dentro de la cadena se emplea el carácter "/", existen exactamente 8 filas en la cadena.

Para indicar espacios vacíos en la fila se colocan los números del 1 al 8. Por ejemplo la fila "4p3" esta compuesta por 4 celdas vacías, un peón y finalmente tres celdas vacías El numero de celdas por fila debe ser siempre 8. 

Así por ejemplo la posición inicial de ajedrez se representa por:
```
"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"
```
Implementar la función: **drawChessBoard( initPosition )**

