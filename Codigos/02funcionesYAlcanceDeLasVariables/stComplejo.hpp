#ifndef STCOMPLEJO_HPP
#define STCOMPLEJO_HPP

struct stComplejo{
    double real;
    double imaginario;
    // funcion miembro
    stComplejo operator+(const stComplejo &otro) const{
        stComplejo resultado;
        resultado.real = real + otro.real;
        resultado.imaginario = imaginario + otro.imaginario;
        return resultado;
    }
};


#endif /*STCOMPLEJO_HPP*/