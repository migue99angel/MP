

#include <cstdlib>
#include <iostream>
#include <string.h>
#include "Idioma.h"
#include "ContadorBigramas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    std::string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";
   
    //COMPROBACIONES
    if (argc <2 )  {
        cerr << "Error en la llamada.\n   classify ficheroIdiomaDesconocido.txt ficheroIdiomaEspanol.bgr ficheroIdiomaIngles.bgr ..."<<endl;
        return 1;
    }
    double dist,dist2;
    Idioma id1,Des;
    ContadorBigramas M(valid);
    
    if(!M.calcularFrecuenciasBigramas(argv[1])){
        cout<<"Revisar "<<argv[1]<<endl;
        return 1;
    }
    Des=M.toIdioma();
    Des.ordenar();
    
    
    
    if(id1.cargarDeFichero(argv[2])){
    id1.ordenar();
    dist=Des.distancia(id1); 
    
    cout<<"Fichero "<<argv[2]<<" leido correctamente."<<endl;
    }
    
    
    
    for(int i=3;i<argc;i++){
        Idioma id2;
        if(id2.cargarDeFichero(argv[i])){
            cout<<"Fichero "<<argv[i]<<" leido correctamente."<<endl;
        }
        id2.ordenar();
        dist2=Des.distancia(id2);
        if(dist>dist2){
            dist=dist2;
            id1=id2;
        }
        
        
    }
    
    cout<<"El idioma del fichero "<<argv[1]<<" es: "<<id1.getIdioma()<<endl;
    
    return 0;
}

