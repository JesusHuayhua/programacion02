# Istream

La librería `istream`, tratan con ofrecer representaciones de cadenas de caracteres de tipos 
incorporados y pueden ampliarse fácilmente para tratar tipos definidos por el usuario.

## Cin

La instancia de flujo de entrada estándar `cin`, nos proporciona una interfaz para la entrada 
de datos del teclado. Para esto esto vamos a usar el operador `<<` (get from).

```CPP
int numero;
char caracter;
double flotante;
std::cin >> numero >> caracter >> flotante;
std::cout << numero << ' ' << caracter << ' ' << flotante[]();
```

> Dentro del archivo `compilacion.sh` se esta ingresando los datos desde un archivo `txt` y dirigiendo su salida
> a un archivo `cin.txt`; esto para que sea mas fácil las pruebas. Con el siguiente comando es el siguiente:

```bash
cin.exe < input.txt > cin.txt
```

## Manipuladores

De igual manera que para `cout`, también contamos con manipuladores para e `cin`.

### Ios

| Función                                         | Definicion                                                                            |
| ----------------------------------------------- | ------------------------------------------------------------------------------------- |
| dec<br>hex<br>oct                               | Cambia la base utilizada para le E/S de enteros                                       |

### Iomanip

| Función       | Definición                                                            |
| ------------- | --------------------------------------------------------------------- |
| setw          | cambia la anchura del siguiente campo de E/S                          |
| quoted        | Inserta y extrae cadenas entrecomillas con espacios incrustados       |

> tener en consideración que `quoted`, solo funciona con las variables de tipo `string`

### Métodos

Como `std::cin` es una instancia de clase, tiene varios métodos que nos van a poder ayudar bastante.

| Método    | Definición                                                                                                                                                                                 |
| --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| ignore()  | Ignora caracteres de la entrada                                                                                                                                                           |
| getline() | Lee un línea completa de texto desde la entrada estándar                                                                                                                                   |
| get()     | Lee un solo carácter desde la entrada                                                                                                                                                      |
| unget()   | Permite devolver el ultimo carácter leído al flujo de de entrada                                                                                                                           |
| peek()    | Permite ver el siguiente carácter en la entrada sin extraerlo                                                                                                                              |
| putback() | Devuelve un carácter a la entrada                                                                                                                                                          |
| gcount()  | Devuelve la cantidad de caracteres extraídos por la última operación de entrada.                                                                                                           |
| fail()    | Podemos verificar si la última operación de lectura falló                                                                                                                                  |
| clear()   | Se utiliza para restablecer el estado del flujo. Normalmente después de que se haiga producido un error                                                                                    |
| eof()     | Nos permite conocer cuando se encuentra el final del archivo, lo que significa que ya no tenemos más datos que leer                                                                        |

[\[02 Cout👈\]](02Cout.md)
