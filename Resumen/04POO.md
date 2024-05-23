- [Programación Orientada a Objetos](#programación-orientada-a-objetos)
  - [Objetos](#objetos)
  - [Clases](#clases)
  - [Zona public y private](#zona-public-y-private)
  - [Constructores](#constructores)
  - [Getter y Setter](#getter-y-setter)
    - [Getters](#getters)

# Programación Orientada a Objetos

## Objetos

Cuando abordamos un problema de programación orientada a objetos, ya no preguntas
cómo se dividirá el problema en funciones, sino cómo se dividirá en objetos. Pensar
en términos de objetos, más que de funciones, tiene un efecto sorporendete útil sobre 
la facilidad con la que se pueden diseñar programas.

## Clases

En POO, decimos que los objetos son miembros de la clase.¿Qué quiere decir esto?.
Veamos una analogía. Casi todos los lenguajes informáticos tiene tipos de datos
integrados. Por ejemplo, el tipo `int`, con la cual podemos declarar tantas variables
de tipo int como necesitemos en nuestro programa.

De manera similar, podemos definir muchos objetos de la misma clase. La clase sirve
como plan o modelo. Específica que datos y qué funciones se incluirán en los objetos
de esa clase.

```C++
// estructura principal de una clase
class <nombre_de_la_clase> {
public: // zona publica

private: // zona privada

};
```

## Zona public y private

Una clave de la programación orientada a objetos es la ocultación de datos.
Esto significa, que los datos se ocultan dentro de la clase, para no ser accedidos
erróneamente por funciones ajenas a la clase.

El mecanismo más sencillo es colocar los atributos(variables) dentro de la zona
privada, para que solamente se pueda acceder desde dentro de la clase.


```C++
class Persona{
  private:
  char *nombre;
  char *apellido;
  int edad;
  int fecha_de_nacimiento;
  public:
  ...
};
```

## Constructores

Como veremos más adelantes, se va a tener funciones que permitan modificar el
valor de los atributos o para mostrar su valor. Sin embargo, es conveniente
que cuando se inicialicemos un objetos este cuente con ya ciertos valores por defecto.

A esta función especial se le denomina `constructor` la cual se ejecuta automáticamente
cuando se crea un objeto. En `C++` la función constructor va a tener el mismo
nombre de nuestra clase.

```C++
// Persona.hpp
class Persona{
  private:
  char *nombre;
  char *apellido;
  int edad;
  int fecha_de_nacimiento;
  public:
  Persona();
    
  ...
};
// Persona.cpp
/**
 * se coloca <nombre-de-la-clase>::<nombre-de-la-funcion> para indicar
 que la funcion pertenece a la clase.*/
void Persona::Persona(){
  nombre =nullptr;
  apellido = nullptr;
  edad = 0;
  fecha_de_nacimiento = 0;
}
```

## Getter y Setter

Estos son métodos utilizados para acceder y modificar los atributos privados de una clase.
Su uso es para mantener el principio de encapsulamiento.

### Getters

Se utiliza para obtener el valor de un atributo privado en una clase. Los getters permiten
acceder a estos atributos desde afuera de una manera controlada.

> [!IMPORTANT]
> 
