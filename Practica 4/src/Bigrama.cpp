/** 
 * @file Bigrama.cpp
 * @author DECSAI
*/

#include <cstring>
#include <stdio.h>
#include <string.h>
#include "Bigrama.h"
#include <assert.h>

using namespace std;


Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

    /**
     * @brief Devuelve el bigrama almacenado
     * @return el bigrama
     */
const char* Bigrama::getBigrama() const{
    return _bigrama;
}
    
    /**
     * @brief Devuelve la frecuencia almacenada
     * @return la frecuencia
     */
int Bigrama::getFrecuencia() const{
    return _frecuencia;
}

    /**
     * @brief Actualiza el bigrama, siempre que sea de la longitud adecuada, 
     *  en otro caso, no se actualiza, para evitar desbordamientos del vector
     * @param cadena El nuevo valor del bigrama
     */
void Bigrama::setBigrama(const char cadena[]){
        
            _bigrama[0]=cadena[0];
            _bigrama[1]=cadena[1];
            _bigrama[2]='\0';
}
       


    /**
     * @brief Actualiza la frecuencia almacenada
     * @param frec La nueva frecuencia
     */
void Bigrama::setFrecuencia(int frec){
    _frecuencia=frec;
}

    

/**
 * @brief Ordena un vector de bigramas de forma ascendente por frecuencias
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void ordenaAscFrec(Bigrama *v, int n){
    Bigrama tmp;
    for(int izda=0; izda<n ;izda++){
        for (int j=n-1;j>izda;j--){
            if (v[j].getFrecuencia() < v[j-1].getFrecuencia()){
                tmp=v[j];
                v[j]=v[j-1];
                v[j-1]=tmp;
            }
        }
    }

}

/**
 * @brief Ordena un vector de bigramas de forma ascendente por bigramas
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */

void ordenaAscBigr(Bigrama *v, int n){
    Bigrama tmp;
    for(int izda=0; izda<n ;izda++){
        for (int j=n-1;j>izda;j--){
            if (strcmp(v[j].getBigrama(),v[j-1].getBigrama()) < 0) {
                tmp=v[j];
                v[j]=v[j-1];
                v[j-1]=tmp;
            }
        }
    }
    
}

/**
 * @brief Imprime un vector de bigramas
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void imprimeBigramas(const Bigrama *v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i].getBigrama()<<"-"<<v[i].getFrecuencia()<<"  ";
    }
}

/**
 * @brief Suma dos listas de bigramas y devuelve el resultado
 * @param v1 Primer vector de bigramas
 * @param nv1 Tamaño de @a v1
 * @param v2 Segundo vector de bigramas
 * @param nv2 Tamaño de @a v2
 * @param res Vector resultado creado en memoria dinámica
 * @param nres Tamaño de @a res
 * @pre @a v1 y @a v2 deben tener el mismo tamaño y los mismos bigramas aunque las frecuencias sean distintas
 */
void sumaBigramas(const Bigrama *v1, int nv1, const Bigrama *v2, int nv2, Bigrama *&res, int & nres){
    bool igualutil=false, mismosbigramas=true;
    if (nv1 == nv2){
        igualutil=true;
        nres=nv1;
        for (int i=0;i<nv1;i++){
            if(strcmp(v1[i].getBigrama(),v2[i].getBigrama()) != 0 ){
                mismosbigramas=false;
            }
          }
        }
    if (igualutil){
        if(mismosbigramas){
            for (int i=0;i < nres; i++){
                res[i].setBigrama(v1[i].getBigrama());
            }
            for (int j = 0; j < nres ;j++ ){
                res[j].setFrecuencia(v1[j].getFrecuencia()+v2[j].getFrecuencia());
                }
        
    
        }
        else 
            assert (!mismosbigramas);
        }
    else
        assert(!igualutil);
}
