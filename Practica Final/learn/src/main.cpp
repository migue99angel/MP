

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
    bool crearNuevo=false;
    bool requisito=false;
    ContadorBigramas M(valid);
    const char *fsal="data/out.bgr";
    bool hayfsalida=false;
    bool hayIdioma=false;
    Idioma I;
    int cont=0,salida,idioma;
    
    //COMPROBACIONES
    if (argc  < 2)  {
        cerr << "Error en la llamada.\n   learn {−c|−a} [−l nombreIdioma] [−f ficheroSalida] texto1.txt {texto2.txt texto3.txt}"<<endl;
        return 1;
    }
    
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i],"-c")==0 || strcmp(argv[i],"-a")==0){
            if(strcmp(argv[i],"-c")==0){
                crearNuevo=true;
                cont++;
            }
            requisito=true;
        }
        
        if(strcmp(argv[i],"-l" )==0){
            idioma=i+1;
            hayIdioma=true;
            cont=cont+2;
        }
        
        if(strcmp(argv[i],"-f")==0){
            hayfsalida=true;
            salida=i+1;
            cont=cont+2;
        }
    }
    
    
    if(!requisito){
        cout<<"Error. El parámetro '-c' o '-a' es obligatorio."<<endl;
        cout<<"Sintaxis: learn {−c|−a} [−l nombreIdioma] [−f ficheroSalida] texto1.txt {texto2.txt texto3.txt}"<<endl;
        return 1;
    }
    
    //PROCESO
    if(!crearNuevo){
        if(hayfsalida){
            if(!I.cargarDeFichero(argv[salida])){
                cout<<"El fichero de entrada no existe."<<endl;
                return 1;
            }
        }
        else
            if(!I.cargarDeFichero(fsal)){
                cout<<"El fichero de entrada no existe."<<endl;
                return 1;
            }
        
        M.fromIdioma(I);
    }
    
    for(int i=cont+1;i<argc;i++){
        if(M.calcularFrecuenciasBigramas(argv[i])){
            cout<<"Bigramas y frecuencias de "<<argv[i]<<" calculadas con éxito."<<endl;
        }
        else{
            cout<<"Ha habido un problema en el cálculo de bigramas de "<<argv[i]<<". Revise el fichero."<<endl;
            return 1;
        }
    }
    
    I=M.toIdioma();
    
    if(hayIdioma){
        I.setIdioma(argv[idioma]);
    }
    
    if(crearNuevo){
        if(hayfsalida && I.salvarAFichero(argv[salida])){
            cout<<"Fichero "<<argv[salida]<<" salvado correctamente."<<endl;
        }
        else
            if(I.salvarAFichero(fsal)){
                cout<<"Fichero "<<fsal<<" salvado correctamente."<<endl;
            }
    }
    else{
        if(I.salvarAFichero(argv[salida])){
            cout<<"Fichero "<<argv[salida]<<" salvado correctamente."<<endl;
        }
        
        
    }

    
    return 0;
}

