/** 
 * @file main.cpp
 * @author DECSAI
 * @warning Código incompleto. Completar donde se indica
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"
#include "Idioma.h"
using namespace std;
int main(int narg, char * args[]) {
    /// Completar variables
    Idioma v;
    Bigrama z;
    bool paraasert=false;
    int posicion;
    
    
    if (narg  < 3)  {
        cerr << "Error en la llamada.\n   idioma <bigrama> <fich1.bgr> <fich2.bgr> ..."<<endl;
        return 1;
    }
    /// Completar el main
    cout<<"Abriendo fichero "<<args[2]<<endl;
    if(v.cargarDeFichero(args[2])){
        cout<<"OK"<<endl;
    }
    else{
        cout<<"El fichero "<<args[2]<<" no se ha importado correctamente."<<endl;
        assert(paraasert);
    }
   
    
    
   
    for (int i=3;i<narg;i++){
        cout<<"Abriendo fichero "<<args[i]<<endl;
        if(v.addDeFichero(args[i])){
            cout<<"OK"<<endl;
        }
        else {
        cout<<"El fichero "<<args[i]<<" no se ha importado correctamente."<<endl;
        assert(paraasert);
        }
    }
    z.setBigrama(args[1]);
    posicion=v.findBigrama(z.getBigrama());
    cout<<"La posición del bigrama '"<<z.getBigrama()<<"' es: "<<posicion<<endl;
    cout<<"La frecuencia es: "<<v.getPosicion(posicion).getFrecuencia()<<endl;;
    v.liberarMemoria();
    
    
    return 0;
}

