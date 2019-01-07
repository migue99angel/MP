//José Antonio Pascual Gómez	
//Miguel Ángel Posadas Arráez

#ifndef INTERVALO_H
#define INTERVALO_H

class Intervalo{
private:
    bool cerradoInf;
    bool cerradoSup;
    double cotaInf;
    double cotaSup;

public:
    Intervalo();
    Intervalo(double cotaInferior, double cotaSuperior);
    Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    double getCotaInf()const ;
    double getCotaSup()const ;
    bool dentroCotaInf()const ;
    bool dentroCotaSup()const ;
    void setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    bool esVacio()const;
    bool estaDentro(double n)const ;
};


bool valido(double cotaInferior,double cotaSuperior, bool,bool);

void escribir(const Intervalo &i);

void leer(Intervalo &i);

void comprobarVacio(Intervalo i);




#endif
