echo "Estamos compilando el codigo"

gcc -E -o archivo.i main.c
echo "main.i listo"

gcc -S -o main.s main.c
echo "main.s listo"

gcc -c -o main.o main.c
echo "main.o listo"

gcc -o main.exe main.c aditional.c aditional.h

echo "Compilacion exitosa"
