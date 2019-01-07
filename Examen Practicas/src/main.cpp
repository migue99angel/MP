/**
 * @file main.cpp
 * @brief Examen de laboratorio 
 * Universidad de Granada
 * Metodología de la Programación 
 * @nombre_del_alumno:Miguel Ángel Posadas Arráez  
 * @dni_del_alumno:75943170E
 * @ordenador:ei140180
 * 
 * @warning Por favor, rellene las funciones que se indican
*/
#include <iostream>
#include <string>
using namespace std;

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(const string *v, const int n)  {
    if (v != NULL && n > 0)  {
        cout << n << " elementos" << endl;
        for (int i=0; i<n; i++)
                cout << "["<<i<<"] = " << v[i] << endl;
    }
    else
        cerr << "ERROR: Vector de datos vacío" << endl;
}

/**
 * @brief Implementa la función del enunciado 
 * @param v1 Primer vector
 * @param nv1 Número de elementos de @a v1
 * @param v2 Segundo vector
 * @param nv2 Número de elementos de @a v2
 * @param v3 Vector resultado. Debe reservarse memoria dentro de la función
 * @param nv3 Número de elementos de @a v3
 */
void funcion(string const *v1, int nv1, string *v2, int nv2, string * &v3, int &nv3)  {
    string * aux=NULL;
    int contador=0;
    int k=0;
    
    //Metemos en un vector auxiliar todos los elementos de v1
    //Esto se debe a que v1 es constante por lo que no podemos modificarlo
    //Por tanto reservamos memoria para un vector igual de grande que v1
    
    aux = new string [nv1];
    
    for ( int i = 0; i<nv1; i++ ){
        aux[i]=v1[i];
        }
    //Cambio a " " los elementos de aux que esten en v2
    for ( int i = 0; i<nv1; i++){
        for (int j= 0; j < nv2;j++ ){
            if(aux[i]==v2[j]){
                aux[i]=" ";
                contador++;
            }
        }
    }
    nv3=nv1-contador;
    //Reservo memoria para v3 que tendrá alamacenado los elementos de v1 menos los " "
    v3 = new string [nv3];
    for (int i = 0; i<nv1;i++ ){
        if(aux[i]!=" "){
            v3[k]=aux[i];
            k++;
        }
    }
    delete [] aux;
    aux=NULL;
    
}


int main()  {
    int nv1=0, nv2=0, nv3=0;
    string *v1=NULL, *v2=NULL, *v3=NULL;

    // Examen: Leer vector v1
    //Filtro para que se introduzca un util valido
    do{
        cout<<"Introduzca la cantidad de elementos a almacenar en el primer array: ";
        cin>>nv1;
    }while(nv1<=0);
    //Reservo memoria dinámica para v1
    v1 = new string [nv1];
    for (int i = 0; i<nv1;i++ ){
        cout<<"Introduzca la componente del array que ocupa la posicion "<<i<<": ";
        cin>>v1[i];
    }
    imprimirVector(v1, nv1);

    // Examen: Leer vector B
    do{
        cout<<"Introduzca la cantidad de elementos a almacenar en el segundo array: ";
        cin>>nv2;
    }while(nv2<=0);
    //Reservo memoria dinámica para v2
    v2 = new string [nv2];
    for (int i = 0; i<nv2;i++ ){
        cout<<"Introduzca la componente del array que ocupa la posicion "<<i<<": ";
        cin>>v2[i];
    }
    // ...
    imprimirVector(v2, nv2);

    // Examen: Calcular resultado
    funcion(v1, nv1, v2, nv2, v3, nv3);
    
    // Examen: Mostrar resultado
    imprimirVector(v3, nv3);

    // Examen: Terminación del programa
    delete [] v1;
    delete [] v2;
    delete [] v3;
    v1=v2=v3=NULL;
            
    // ...
    return 0;
}
