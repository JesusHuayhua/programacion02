# Compilación de un programa

![Compiler](Img/00Compiler.PNG)

## ¿Que es la compilación?

Cuando hacemos mencionamos que `compilamos nuestro programa`, hacemos referencia al proceso que pasa nuestro *código fuente*
escrito en un lenguaje de programación, para ser transformado en un programa ejecutable, el cual fácilmente entendido por nuestro computador.

## Compilación de un programa en C

Para la compilación de unprograma en `C` pasa por 4 pasos antes de generar nuestro archivo ejectuable.

1. Preprocessing
2. Compling
3. Assembling
4. Linking

### Preprocessing

En este primer paso de compilación se realiza con una herramienta llamada `pre-processor`.

1. Primero se eliminan todos los comentarios que realizamos.
2. Interpreta y procesa todas las directiva que estén precedidas por el símbolo  `#`, hasta que no tengamos ninguno de estos símbolos.
3. Aquí nuestras librerías clásicas como: `<stdio.h>, <math.h>, <stdlib.h>,etc`, son reemplazadas por su respectivo contenido en los archivos de encabezados correspondientes.
4. Otra directiva común es el `#define`, aquí nuestro `pre-processor` reemplaza todas las coincidencias de nuestra declaración, a excepción si se encuentra entre comillas.
5. Aquí también la herramienta realizar la `conditional compilation`, esto implica generar o evitar que cierto bloque de código sea ejecutado. Par esto reemplaza las directivas con un código de ensamblador predefinido. Algunas de las `conditional compilation` más conocidas son:
	1. `#ifdef`
	2. `#endif`
	3. `#ifndef`
	4. `#else`
	5. `#elif`

> Si desean generar el `archivo.i`, tienen que hacer uso del siguiente comando en su terminal
```bash
gcc -E -o archivo.i programa.c
```


### Compling

La fase de compilación en `C` utiliza un software de compilación incorporado para convertir el archivo intermedio (.i) en un archivo ensamblador (.s) que contiene instrucciones a nivel
de ensamblador(este es el nivel más bajo que podemos llegar humanamente posible). Así mismo, es en esta parte donde se detectan errores de sintaxis o advertencias presentes
en el código fuente.

>Para generar archivos `.s`, va a depender del compilador que estemos utilizando, pero como a la par de este curso se ve tambien el curso de `Organización y Arquitectura de Computadoras`, el siguiente comando es para GCC(GNU Compiler Collections).
>
> El archivo.s, va a ser distinto si se genera en Windows o Linux.

```bash
gcc -S -o archivo.s programa.c
```
### Assembling

El código ensamblador se convierte en un código comprensible por el computador, esto gracias a un programa ya pre-escrito, este nuevo código, es conocido como código objeto.

El archivo objeto, presenta una extensio (.obj) en DOS y (.o) en UNIX.

>  Aquí el comando para que puedan generar el archivo objeto:

```bash
gcc -c -o archivo.o programa.c
```

### Linking

El enlace es el proceso de incluir los archivos de biblioteca en nuestro programa. Los archivos de bibliotecas son archivos predefinidos que contienen la definición
de las funciones en lenguaje máquina, y estos archivos tienen una extensión `.lib`. El proceso de enlace es el que genera un archivos ejectuable con una extensión `.exe` en DOS
y `.out` en sistemas operativos UNIX.

```bash
gcc -o archivo.exe programa.c #para los que estan en windows
# gcc -o ejecutable programa.c #para linux
```

# Diferencias entre C y CPP

CPP lo que hizo fue tomar el núcleo de C y en base a eso generar un nuevo lenguaje de programación el cual contiene
nuevas funcionalidades, paradigmas de programación, entre otro. Por lo tanto, todo lo que conocemos sobre el 
lenguaje C se puede aplicar en CPP, pero no todo lo de CPP se puede aplicar en C.

Aquí, dejo un [link](https://www.geeksforgeeks.org/difference-between-c-and-c/), con las diferencias mas notables que existen entre estos 2 lenguajes de programación.

# Bibliografia

- [Scaler - Compilation Process in C](https://www.scaler.com/topics/c/compilation-process-in-c/)
- [Scaler - How is a C++ Program Compiler and Executed?](https://www.scaler.com/topics/how-to-compile-cpp/)
- [El modelo de compilación en C](https://www.it.uc3m.es/~pedmume/asignaturas/2005/LAO/Lab2/tutorial4/www-etsi2.ugr.es/depar/ccia/mp2/old/apoyo/modelo/modelo.html)

[Siguiente tema :point_right:](01EntradaYSalidaDeDatos.md)