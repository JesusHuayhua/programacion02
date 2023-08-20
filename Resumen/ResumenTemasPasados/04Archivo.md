# Archivos

En esta etapa se veía los archivos de text `txt`, binario `bin` y los archivo `csv`.
Ahora solo se tiene que leer los archivos `txt` y `csv`. Al no ser un tema que se
explicó en el curso previó, solo explicaré sencilla sobre como leer estos tipos
de archivos.

> La biblioteca definida en `CPP` es `fstream`.
> 
> Con las clases definidas: `ofstream` y `ifstream`

## Apertura de un archivo

### Creación
Para poder crear un archivo `txt`, o sobreescribir el archivo.
```CPP
std::ofstream arch("nombre_del_archivo.txt",std::ios::out);
// Otra forma:
std::ofstream arch
arch.open("nombre_del_archivo.txt",std::ios::out);
// arch: Es el nombre que manejará el archivo, algo así como una variable
// std::ios::out Es el modo de apertura
```
> Si el archivo no existe lo crea, y si en caso si exista borra todo su contenido

### Lectura

Leer el contenido de un archivo `txt`.
```CPP
std::ifstream arch("nombre_del_archivo.txt",std::ios::in);
// Otra forma:
std::ifstream arch
arch.open("nombre_del_archivo.txt",std::ios::in);
// arch: Es el nombre que manejará el archivo, algo así como una variable
// std::ios::in Es el modo de apertura
```

### Añadidura

Añadir archivos información al final del archivo, sin borrar la información previa.
```CPP
std::ofstream arch("nombre_del_archivo.txt",std::ios::app);
// Otra forma:
std::ofstream arch
arch.open("nombre_del_archivo.txt",std::ios::app);
// arch: Es el nombre que manejará el archivo, algo así como una variable
// std::ios::app Es el modo de apertura
```

### Adicionales


#### Lectura y Escritura

```CPP
std::fstream arch("nombre_del_archivo.txt",std::ios::in | std::ios::out);
// Otra forma:
std::ofstream arch
arch.open("nombre_del_archivo.txt",std::ios::in | std::ios::out);
// arch: Es el nombre que manejará el archivo, algo así como una variable
// std::ios::app Es el modo de apertura
```

#### Lectura al final del archivos

También podemos empezar a leer desde el final del archivo e ir avanzando.

```CPP
std::ifstream arc("nombre_del_archivo.txt",std::ios::ate);
```
## Error de Apertura

Ya sea que abramos el archivo `txt` o `csv`, para leerlo o abrirlo, tenemos que verificar
que este fue abierto satisfactoriamente, esto debido a que el compilador no nos
lo indicará como error.

```CPP
if(!arch){
    std::cerr << "ERROR: No se puedo abrir el archivo NOMBRE-DEL-ARCHIVO\n" << std::endl;
    exit(1);
}
```

> Adicionalmente como se vio anteriormente con los manipuladores para `cin` y `cout`
> de igual manera se pueden usar con los archivos de texto.

## Cerrar archivos

Cuando ya no sea necesario usar el archivo que estemos usando, tenemos que cerrarlo
de la siguiente manera:

```CPP
arch.close();
```

> Ahora si pasemos a ver el [código](../../Codigos/TemasPasados/04Archivos/archivos.cpp)

[\[03 Cin👈\]](03Cin.md)
