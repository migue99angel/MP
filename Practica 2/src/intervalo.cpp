#include <cassert>
#include <iostream>
#include <assert.h>
#include "intervalo.h"
using namespace std;

    Intervalo::Intervalo(){
	cerradoInf=false;
	cerradoSup=false;
	cotaInf=0;
	cotaSup=0;
	}


    Intervalo::Intervalo(double cotaInferior, double cotaSuperior){

	if(cotaInferior<=cotaSuperior){
	   cotaInf=cotaInferior;
	   cotaSup=cotaSuperior;	
	}

	else {
	   cotaInf=cotaSuperior;
	   cotaSup=cotaInferior;
	}

	cerradoSup=true;
	cerradoInf=true;

    }

    Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
	bool valid;
	valid=valido(cotaInferior,cotaSuperior,cerradoInferior,cerradoSuperior);	
	if(valid){
	   cotaInf=cotaInferior;
	   cotaSup=cotaSuperior;
	   cerradoSup=cerradoSuperior;
	   cerradoInf=cerradoInferior;
	}
	else
	    assert(valid);		
    }
    

    double Intervalo::getCotaInf()const{
	return cotaInf;
    }

    double Intervalo::getCotaSup()const{
	return cotaSup;
    }

    bool Intervalo::dentroCotaInf()const{
	return cerradoInf;
    }
  
    bool Intervalo::dentroCotaSup()const{
	return cerradoSup;
    }

    void Intervalo::setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
	bool valid;
	valid=valido(cotaInferior,cotaSuperior,cerradoInferior,cerradoSuperior);	
	if(valid){
	   cotaInf=cotaInferior;
	   cotaSup=cotaSuperior;	
	   cerradoSup=cerradoSuperior;
	   cerradoInf=cerradoInferior;
        }
	else
	    assert(valid);	
    }

    bool Intervalo::esVacio()const{
	bool vacio=false;
	if(cotaInf==cotaSup && !cerradoInf && !cerradoSup){
	   vacio=true;
	}
	return vacio;
    }
  
    bool Intervalo::estaDentro(double n)const {
	bool esta=false;

	if((cotaInf<n && n<cotaSup) || (n==cotaInf && cerradoInf) || (n==cotaSup && cerradoSup)){
	    esta=true;
	}
	return esta;
    }

bool valido(double cinf,double csup, bool cerrinf, bool cerrsup){
    return (( cinf < csup ) || ( cinf == csup && cerrinf == cerrsup));
}


void escribir(const Intervalo &i){
	if(i.dentroCotaInf() && i.dentroCotaSup()){
	   cout<<"["<<i.getCotaInf()<<","<<i.getCotaSup()<<"]"<<endl;
	}
	if(!i.dentroCotaInf() && i.dentroCotaSup()){
	   cout<<"("<<i.getCotaInf()<<","<<i.getCotaSup()<<"]"<<endl;
	}
	if(i.dentroCotaInf() && !i.dentroCotaSup()){
	   cout<<"["<<i.getCotaInf()<<","<<i.getCotaSup()<<")"<<endl;
	}
	if(!i.dentroCotaInf() && !i.dentroCotaSup()){
	   cout<<"("<<i.getCotaInf()<<","<<i.getCotaSup()<<")"<<endl;
	}
}


void leer(Intervalo &i){
    bool cerradoInf = true;
    bool cerradoSup = true;
    double cotaInf, cotaSup;
    char car;
    cin >> car;
    if (car == '(')
        cerradoInf = false;
    cin >> cotaInf;
    cin >> car;
    cin >> cotaSup;
    cin >> car;
    if (car == ')')
        cerradoSup = false;

	i.setIntervalo(cotaInf, cotaSup, cerradoInf, cerradoSup);

}

void comprobarVacio(Intervalo i){
	if(i.esVacio()){
	   cout<<"El intervalo es vacío."<<endl;
	}
	else{
	   cout<<"El intervalo no está vacío."<<endl;
	}
}

Intervalo interseccion ( const Intervalo &i1, const Intervalo &i2){
	Intervalo i3;	
	int cotaInf, cotaSup;
	bool cerradoInf, cerradoSup;

	if(i1.getCotaInf()<i2.getCotaInf()){
	   cotaInf=i2.getCotaInf();
	   cerradoInf=i2.dentroCotaInf();
	}
	else{
	   if(i1.getCotaInf()>i2.getCotaInf()){
		cotaInf=i1.getCotaInf();
		cerradoInf=i1.dentroCotaInf();
	   }
	   else{
		cotaInf=i1.getCotaInf();
		cerradoInf=i1.dentroCotaInf() && i2.dentroCotaInf();
	   }
	}

	if(i1.getCotaSup()<i2.getCotaSup()){
	   cotaSup=i1.getCotaSup();
	   cerradoSup=i1.dentroCotaSup();
	}
	else{
	   if(i1.getCotaSup()>i2.getCotaSup()){
		cotaSup=i2.getCotaSup();
		cerradoSup=i2.dentroCotaSup();
	   }
	   else{
		cotaSup=i1.getCotaSup();
		cerradoSup=i1.dentroCotaSup() && i2.dentroCotaSup();
	   }
	}




	if(valido(cotaInf,cotaSup,cerradoInf,cerradoSup)){
	    i3.setIntervalo(cotaInf,cotaSup,cerradoInf,cerradoSup);
	}

	return i3;
}










