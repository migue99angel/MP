/** 
 * @file main.cpp
 * @author DECSAI
 * @warning Cödigo incompleto
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"

using namespace std;



int main() {
    char s[60];
    int frec, nv1=1, nv2=-1, nv3;
    Bigrama *v1=NULL, *v2=NULL, *v3=NULL;
    
    // Lee número de elementos del primer vector
    do {
        cout<<"Introduce el numero de elementos que quiere almacenar en el primer vector: ";
        cin>>nv1;
    }while(nv1 < 0);

    v1 = new Bigrama [nv1]; 
    // Lee el primer vector
    for (int i=0; i < nv1 ; i++){
        cout<<"Introduzca el bigrama: ";
        cin>>s;
     do {
        cout<<"Introduzca la frecuencia del bigrama: ";
        cin>>frec; 
    }while(frec < 0);


        v1[i].setBigrama(s);
        v1[i].setFrecuencia(frec);
        
    }
   
    // Lee número de elementos del segundo vector
    do {
        cout<<"Introduce el numero de elementos que quiere almacenar en el segundo vector: ";
        cin>>nv2;
    }while(nv2 < 0);
    
    v2 = new Bigrama [nv2]; 
    
    // Lee el segundo vector
    
        for (int i=0; i < nv1 ; i++){
        
        cout<<"Introduzca el bigrama: ";
        cin>>s;

    do {
        cout<<"Introduzca la frecuencia del bigrama: ";
        cin>>frec; 
    }while(frec < 0);
 
        v2[i].setBigrama(s);
        v2[i].setFrecuencia(frec);
        
    }
    cout << endl <<"Contenido de v1" << endl; imprimeBigramas(v1, nv1);
    cout << endl <<"Contenido de v2" << endl; imprimeBigramas(v2, nv2);
   
    // Posibles operaciones intermedias sobre v1 o v2 
    nv3=nv1;
    ordenaAscBigr(v1 , nv1);                                                               
    ordenaAscBigr(v2 , nv2);
    v3 = new Bigrama [nv3];

    sumaBigramas(v1, nv1, v2, nv2, v3, nv3);
    ordenaAscFrec(v3, nv3);
    cout << endl <<"Contenido de v3" << endl; imprimeBigramas(v3, nv3);

    // Limpieza de memoria

    delete [] v1;
    delete [] v2;
    delete [] v3;
    return 0;
}

