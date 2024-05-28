- [Programación Orientada a Objetos](#programación-orientada-a-objetos)
  - [Objetos](#objetos)
  - [Clases](#clases)
  - [Zona public y private](#zona-public-y-private)
  - [Constructores](#constructores)
  - [Puntero this](#puntero-this)
  - [Getter y Setter](#getter-y-setter)
    - [Getters](#getters)
    - [Setter](#setter)

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
## Puntero this

El puntero `this`, es un puntero que se encuentra disponible en todos los métodos estáticos de una clase.
Apuntando al objeto actual sobre el cual se está invocando el método.

Esta característica, sirve principalmente para acceder y manipular los atributos del objeto que llamó al método.

```CPP
void Persona::Persona(){
  this->nombre =nullptr;
  this->apellido = nullptr;
  this->edad = 0;
  this->fecha_de_nacimiento = 0;
}
```

## Getter y Setter

Estos son métodos utilizados para acceder y modificar los atributos privados de una clase.
Su uso es para mantener el principio de encapsulamiento.

### Getters

Se utiliza para obtener el valor de un atributo privado en una clase. Los getters permiten
acceder a estos atributos desde afuera de una manera controlada.

> [!IMPORTANT]
> Si vamos a trabajar con punteros, estos no tienen que retornar el puntero; sino
> una copia del valor al que esta apuntando, porque al retornar el puntero le estamos dando
> la oportunidad de cambiar el valor directamente, rompiendo el encapsulamiento.

```CPP
// Esto no se tiene que hacer
char *Persona::GetNombre(){
  return this->nombre;
}
// Esto seria una forma de como acceder a lo solicitado y la recomendada para el curso
void Persona::GetNombre(char *nombre){
  if(this->nombre == nullptr) nombre[0] = 0;
  else strcpy(nombre, this->nombre);s
}
int Persona::GetEdad(){
  return this->edad;
}
```

### Setter

Un setter es un método que se utiliza para modificar el valor de un atributo privado de una clase.
Los setters permiten cambiar el valor de estos atributos desde fuera de la clase, también de una manera controlada.

```CPP
void Persona::SetNombre(const char *nombre){
  if(this->nombre != nullptr) delete this->nombre;
  this->nombre = new char[strlen(nombre) + 1];
  strcpy(this->nombre, nombre);
}

void Persona::SetEdad(int edad){
  this->edad = edad;
}
```



