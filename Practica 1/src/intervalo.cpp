
#include <iostream>
#include <assert.h>
#include "intervalo.h"

using namespace std;

    Intervalo::Intervalo(){
	cerradoInf=true;
	cerradoSup=true;
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
	if(cotaInferior<=cotaSuperior){
	   cotaInf=cotaInferior;
	   cotaSup=cotaSuperior;	
	}

	else {
	   cotaInf=cotaSuperior;
	   cotaSup=cotaInferior;
	}

	cerradoSup=cerradoSuperior;
	cerradoInf=cerradoInferior;	
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
	if(cotaInferior<=cotaSuperior){
	   cotaInf=cotaInferior;
	   cotaSup=cotaSuperior;	
	}

	else {
	   cotaInf=cotaSuperior;
	   cotaSup=cotaInferior;
	}

	cerradoSup=cerradoSuperior;
	cerradoInf=cerradoInferior;	
    }

    bool Intervalo::esVacio()const{
	bool vacio=false;
	if(cotaInf==cotaSup){
	   vacio=true;
	}
	return vacio;
    }
  
    bool Intervalo::estaDentro(double n)const {
	bool esta=false;
	if(cerradoInf==true && n>=cotaInf && n<=cotaSup && cerradoSup==true){
	   esta=true;
	}
	if(cerradoInf==false && n>cotaInf && n<=cotaSup && cerradoSup==true){
	   esta=true;
	}
	if(cerradoInf==true && n>=cotaInf && n<cotaSup && cerradoSup==false){
	   esta=true;
	}
	if(cerradoInf==false && n>cotaInf && n<cotaSup && cerradoSup==false){
	   esta=true;
	}
	return esta;

    }




    bool valido(double cotaInferior,double cotaSuperior, bool,bool){
	bool esvalido=false;	
	if(cotaInferior<=cotaSuperior){
	   esvalido=true;
	}
	return esvalido;
    }


void escribir(const Intervalo &i){
	if(i.dentroCotaInf()==true && i.dentroCotaSup()==true){
	   cout<<"["<<i.getCotaInf()<<","<<i.getCotaSup()<<"]"<<endl;
	}
	if(i.dentroCotaInf()==false && i.dentroCotaSup()==true){
	   cout<<"("<<i.getCotaInf()<<","<<i.getCotaSup()<<"]"<<endl;
	}
	if(i.dentroCotaInf()==true && i.dentroCotaSup()==false){
	   cout<<"["<<i.getCotaInf()<<","<<i.getCotaSup()<<")"<<endl;
	}
	if(i.dentroCotaInf()==false && i.dentroCotaSup()==false){
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


