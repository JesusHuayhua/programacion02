all: operadores

operadores: main.cpp Producto.hpp  operadoresSobrecargados.o
	g++  main.cpp Producto.hpp operadoresSobrecargados.o -o operadores

operadoresSobrecargados.o: operadoresSobrecargados.hpp operadoresSobrecargados.cpp
	g++ -c operadoresSobrecargados.hpp operadoresSobrecargados.cpp

clear:
	rm *.o operadores 