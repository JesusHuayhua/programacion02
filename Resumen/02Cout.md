# Ostream

Con esta librería vamos a poder escribir secuencias de caracteres y representaciones de los
distintos tipos de datos. Proporcionándonos algunas `clases` para realizar estas operaciones.

## Cout

Se utiliza para producir la salida en el dispositivo de salida estándar(buffer). Y para poder
hacer ser mostrados en la pantalla debemos de hacer uso del operador de inserción `<<`.

```CPP
std::cout << "Lenguaje de Programacion 1\n";
int anho = 2023;
int ciclo = 2;
std::cout << "Anho: " << anho << "-" << ciclo << '\n';
```

## Cerr

`cerr` es el flujo de error estándar que se utilizar para dar salida a los errores. La particularidad de `cerr`
es que no presenta un `buffer` de salida. Este se utiliza para mostrar inmediatamente los mensajes.

```CPP
std::cerrr << "Este es un mensaje de error sin Buffer\n";
```

## Clog

`clog` es el flujo de error estándar con `buffer`. Este, también nos sirve para mostrar los errores, pero 
el mensaje de error se guarda primero en un `buffer`, y se almacena en este hasta que se llene completamente.

```CPP
std::clog << "Este es un mensaje de clog\n";
```

## Comparaciones

Una forma sencilla para ver es esto es si redefinimos el mensaje de salida normal a un archivo `txt`.

```CPP
std::cout << "Este un mensaje desde cout\n";
std::cerr << "Este un mensaje desde cerr\n";
std::clog << "Este un mensaje desde clog\n";
// archivo.exe > archivo.txt
```

SI abrimos el archivo `cout.txt` que se genera al compila el código de ejemplo, podemos percatarnos
que no se están guardando los mensajes de `cerr` y `clog`.

Y esto se debe a que  `cerr` no tiene `buffer` que guarde su información y el `buffer` de `clog` y `cout` son distintos. En C++, no se puede acceder al
`buffer` interno de `clog`, pero se puede redefinir su salida de la siguiente forma.

```CPP
#include <iostream>
#include <fstream>

int main(){
	std::ofstream archivoLog("log.txt",std::ios::out | std::ios::app);
	// guardamos el buffer original de clog para no perderlo
	std::streambuf * bufferDeClogOriginal = std::clog.rdbuf();
	// Redirigmos la salida del buffer original de clog
	std::clog.rdbuf(archivoLog.rdbuf());
	// LOS MENSAJES DE CLOG QUE APARECEN EN EL ARCHIVO
	std::clog.rdbuf(bufferDeClogOriginal);
	//cerramos el archivo
	archivoLog.close();
	return 0;
}
```

> Recomendación se puede hacer algo similar con el buffer de `cout`, así que recomiendo averiguar como por si están interesados.

## Manipuladores

Nosotros podemos manipular la salida del `cout` con sus propios [métodos](https://en.cppreference.com/w/cpp/io/ostrstream), pero están no siempre son las más cómodas de usar. Por lo tanto, vamos a usar
la librería [iomanip](https://en.cppreference.com/w/cpp/header/iomanip) o los que viene en la librería [ios](https://en.cppreference.com/w/cpp/header/ios), la cual ya viene por defecto en la librería [iostream](https://en.cppreference.com/w/cpp/header/iostream)

> Tener en consideración que solo se analizarán las funciones más importantes, investigar en caso falte

#### Ios

| Función                                         | Definición                                                                            |
| ----------------------------------------------- | ------------------------------------------------------------------------------------- |
| boolalpha<br>noboolapha                         | Alterna entre la representación textual y numérica de los booleanos                   |
| showbase <br> noshowbase                        | Controla si se utiliza el prefijo para indicar la base numérica                       |
| left<br> right                     | Determina la ubicación de los caracteres de relleno                                   |
| dec<br>hex<br>oct                               | Cambia la base utilizada para le E/S de enteros                                       |
| fixed<br>scientific<br>defaultfloat | Cambia el formato utilizado para la E/S de coma flotante                              |

### Iomanip

| Función       | Definición                                                            |
| ------------- | --------------------------------------------------------------------- |
| setw          | cambia la anchura del siguiente campo de E/S                          |
| setfill       | Cambia el carácter de relleno                                         |
| setprecision  | Cambia la precisión de coma flotante                                  |
| quoted        | Inserta y extrae cadenas entrecomillas con espacios incrustados       |

> Ahora si pasemos a ver el [código](../Codigos/02Cout/cout.cpp)

[\[01 Compilación 👈\]](01Compilacion.md)  [\[03 Cint 👉\]](03Cin.md)