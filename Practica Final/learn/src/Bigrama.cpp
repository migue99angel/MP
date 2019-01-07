/** 
 * @file Bigrama.cpp
 * @author DECSAI
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"
#include <string.h>


using namespace std;


Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

const char * Bigrama::getBigrama() const {
    return _bigrama;
}
int Bigrama::getFrecuencia() const {
    return _frecuencia;
}

void Bigrama::setBigrama(const char cadena[]) {
    if (strlen(cadena) <= 2)
        strncpy(_bigrama, cadena,3);
//    strncpy(_bigrama, cadena, 2); // Diferencias, violaciones de _bigrama[] o de cadena[]
}

void Bigrama::setFrecuencia(int frec) {
    _frecuencia = frec;
}




/**
     * @brief Sobrecarga del operador relacional para comparar dos bigramas lexicográficamente
     * @param b el segundo bigrama a comparar
     * @return this->_bigrama < b
     */
bool Bigrama::operator>(const Bigrama &b){
    bool resultado=false;
    
    if(strcmp(this->_bigrama,b.getBigrama())<0){
        resultado=true;
    }
    
    return resultado;
}
    
    
    
/**
 * @brief Sobrecarga del operador de inserción en un stream.
 * @param os El stream de salida en el que se inserta
 * @return @p os para poder encadenar varias inserciones consecutivas
 */
std::ostream& operator<<(std::ostream& os, const Bigrama& bigrama){
    os<<bigrama._bigrama<<" "<<bigrama._frecuencia<<endl;
    return os;
}

/**
 * @brief Sobrecarga del operador de extracción de un stream.
 * @param is El stream de entrada desde el que se extrae
 * @return @p is para poder encadenar varias extracciones consecutivas
 */
std::istream& operator>>(std::istream& is, Bigrama& bigrama){
    char aux[3];
    int utilaux;
    is>>aux>>utilaux;
    bigrama.setBigrama(aux);
    bigrama.setFrecuencia(utilaux);
    return is;
}
