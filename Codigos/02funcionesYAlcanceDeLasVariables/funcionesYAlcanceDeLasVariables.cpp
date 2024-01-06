#include "funcionesYAlcanceDeLasVariables.hpp"

stComplejo operator *(const stComplejo &a,const stComplejo &b){
    stComplejo resultado;
    resultado.real = (a.real * b.real) - (a.imaginario * b.imaginario);
    resultado.imaginario = (a.real * b.imaginario) + (a.imaginario * b.real);
    return resultado;
}