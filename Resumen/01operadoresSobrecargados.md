# Operadores Sobrecargados

La sobrecarga de operadores es una característica que nos permite definir cómo deben 
comportarse los operadores de tipos de datos personalizados.

Ahora los operadores clásicos como +,-,*,/,etc ya tienen definiciones para los tipos
de datos básicos(int,double,char,etc). Sin embargo, cuando trabajamos con objetos que 
nos propios definos, vamos a poder definir como se deben de realizar esas operaciones 
para estos objetos.

```CPP
// sintaxis básica de un operador sobrecargado
tipoDeRetorno operator operador(parametros);
```
Ejemplo:

```CPP
#include <iostream>

struct Punto {
    int x;
    int y;
    
};

// Sobrecarga del operador +
Punto operator+(const Punto punto1,const Punto punto2) {
    Punto resultado;
    resultado.x = punto1.x + punto2.x;
    resultado.y = punto1.y + punto2.y;
    return resultado;
}

int main() {
    Punto punto1;
    Punto punto2;
    Punto resultado;

    punto1.x = 5;
    punto1.y = 10;

    punto2.x = 2;
    punto2.y = 3;

    // Uso del operador sobrecargado +
    resultado = punto1 + punto2;

    std::cout << "Resultado: (" << resultado.x << ", " << resultado.y << ")" << std::endl;

    return 0;
}
```
> [!TIP]
> Los tipos de funciones usadas para la sobrecarga de funciones pueden ser *miembro* o 
> *globales*, pero se va a trabajar con funciones *globales*. La diferencia entre 
> estos tipos de funciones se verán en el siguiente capítulo.

>  [!IMPORTANT]
>  Algo importante a tener en cuenta es que los operadores más usados en el curso son:
>  
>  1. Asignación
>  2. Incremento y decremento
>  3. Comparación
>  4. Lectura y escritura para archivos
> 
>  Por lo tanto, se recomienda tener anotado la definición de clase exterior de 
>  estos operadores. Las cuales pueden ser encontradas en 
> [cppreference](https://en.cppreference.com/w/cpp/language/operators)
 
 