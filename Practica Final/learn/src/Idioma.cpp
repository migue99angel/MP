/** 
 * @file Idioma.cpp
 * @author DECSAI
 * @warning Código incompleto. Implementar la clase completa
*/
#include "Bigrama.h"
#include "Idioma.h"
#include <assert.h>
#include <cmath>
using namespace std;

/**
 * @class Idioma
 * @brief Representa el conjunto los bigramas asociados a un idioma junto con el 
 * identificador del idioma
 */

/**
 * @brief Constructor base
*/
Idioma::Idioma(){
    _idioma="unknown";
    _nBigramas=0;
    _conjunto=0;
}
    
/**
 * @brief Constructor para pre-reservar memoria
 * @param nbg Número de bigramas pre-reservados
*/
Idioma::Idioma(int nbg){
    _idioma="unknown";
    _nBigramas=nbg;
    this->reservarMemoria(nbg);
}


/**
 * @brief Constructor de copia
 * @param orig El idioma que se quiere copiar
*/
Idioma::Idioma(const Idioma& orig){
    this->_conjunto=orig._conjunto;
    this->_idioma=orig.getIdioma();
    this->_nBigramas=orig.getSize();
    this->reservarMemoria(_nBigramas);
    copiar(orig);
    
}
    
/**
 * @brief Destructor
*/
Idioma::~Idioma(){
    this->liberarMemoria();
}
    
    
/**
 * @brief Sobrecarga del operador de asignación
 * @param orig Parámetro rhs de la asignación
 * @return this para concatenación de asignaciones de derecha a izquierda
*/
Idioma& Idioma::operator=(const Idioma& orig){
    if(&orig!=this){
        this->liberarMemoria();
        this->_conjunto=orig._conjunto;
        this->_idioma=orig.getIdioma();
        this->_nBigramas=orig.getSize();
        this->reservarMemoria(_nBigramas);
        copiar(orig);
    }
    return *this;
}

/**
 * @brief reserva memoria para @a n bigramas,
 * en caso de que ya hubiese memoria reservada, esta
 * debe eliminarse
 * @param n número de bigramas a reservar
*/
void Idioma::reservarMemoria(int n){
    _conjunto=new Bigrama[n];
    _nBigramas=n;
}


/**
 * @brief Libera la memoria
*/
void Idioma::liberarMemoria(){
    delete [] this->_conjunto;
    this->_conjunto=NULL;
}
    
/**
 * @brief Consulta el ID del idioma
 * @return ID del idioma
*/
std::string Idioma::getIdioma() const{
    return this->_idioma;
}
    
/**
 * @brief Establece el ID del idioma
 * @param id Nuevo ID del idioma
*/
void Idioma::setIdioma(const std::string& id){
        _idioma=id;
}
/**
 * @brief Consulta la lista de bigramas
 * @param p La posición de la lista que se quiere consultar
 * @precond La posición @p p es correcta
 * @return El bigrama que ocupa la posición @p p
*/
Bigrama Idioma::getPosicion(int p) const{
    return this->_conjunto[p];
}
    
/**
 * @brief Añade un nuevo bigrama
 * @param p La posición en la que se quiere insertar el bigrama
 * @precond La posición @p p es correcta
 * @param bg El bigrama a insertar
*/
void Idioma::setPosicion(int p, const Bigrama & bg){
    if(p<_nBigramas && p>=0){
        _conjunto[p].setBigrama(bg.getBigrama());
        _conjunto[p].setFrecuencia(bg.getFrecuencia());
    }
}
                           
/**
 * @brief Busca un bigrama en la lista de bigramas
 * @param bg El bigrama que se está buscando
 * @return La posición que ocupa @p bg en la lista, -1 si no está en la lista
*/
int Idioma::findBigrama(const std::string& bg) const{
    int pos=-1;
    for (int i=0; i<_nBigramas; i++){
        if(_conjunto[i].getBigrama()== bg){
            pos=i;
        }
    }
    return pos;
}

	     
/**
 * @brief Recupera una serialización de un idioma desde un fichero y 
 * reconstruye el idioma. Muestra en pantalla el idioma cargado
 * @param fichero Fichero que contiene un idioma serializado
 * @return @b false si ha habido algún tipo de error, @b true en otro caso
*/
bool Idioma::cargarDeFichero(const char *fichero){
    ifstream fentrada;
    bool nerror=true;
    char bigramas[3];
    char cabecera[70];
    char idioma[15];
    int nbig, frecuencia,i;
    Bigrama aux;
    
    fentrada.open(fichero);
    if(fentrada){
        
    
        fentrada>>cabecera;
        fentrada>>idioma;
        cout<<"Idioma detectado: "<<idioma<<endl;
        fentrada>>nbig;
        cout<<"Leyendo "<<nbig<<" bigramas."<<endl;
        _idioma=idioma;
    
        this->reservarMemoria(nbig);
        for( i=0;i<nbig && nerror;i++){
            fentrada>>bigramas;
            fentrada>>frecuencia;
            if(!fentrada){
                cout<<"Error en la carga de datos."<<endl;
                nerror=false;
                return nerror;
            }
            aux.setBigrama(bigramas);
            aux.setFrecuencia(frecuencia);
            this->setPosicion(i,aux);
            
        }
    }
    else{
        cout<<"Error. No existe el fichero."<<endl;
        nerror=false;
    }
    fentrada.close();
    
    return nerror;
}
    
     /**
     * @brief Serializa y guarda un idioma en un fichero
     * @param fichero El fichero de salida
     * @return @b false si ha habido algún tipo de error, @b true en otro caso
     */
    bool Idioma::salvarAFichero(const char *fichero) const{
        bool salvado=false;
        ofstream fsalida;
        fsalida.open(fichero);
        if(fsalida){
            salvado=true;
            fsalida<<"MP−BIGRAMAS-IDIOMA-T-1.0"<<endl;
            fsalida<<getIdioma()<<endl;
            fsalida<<getSize()<<endl;
            
            for(int k=0;k<_nBigramas;k++){
                fsalida<<getPosicion(k);
             }       
        }
        fsalida.close();
        return salvado;
    }
   
    int Idioma::ranking(const std::string& bg) const{
        int fin=getSize();
        int tope=fin;
        bool encontrado=false;
        for (int i=0; i<tope && !encontrado; i++){
            if(_conjunto[i].getBigrama()== bg){
                fin=i;
                encontrado=true;
            }
        }
        return fin;
    }
 /**
     * @brief Calcula la distancia entre dos idiomas
     * @param otro El segundo idioma para consultar la distancia
     * @return resultado de la distancia, valor entre 0 y 1
     */
    double Idioma::distancia(const Idioma& otro) const{
        double distancia=0,funcion;
        Bigrama aux;
        for(int i=0;i<otro.getSize();i++){
            aux=otro.getPosicion(i);
            
            funcion=abs(ranking(aux.getBigrama())-i);
            distancia=distancia+funcion/(otro.getSize()*otro.getSize());
        }
        return distancia;
    }
    
    /**
     * @brief Ordena la lista de bigramas de mayor a menor frecuencia
     */
    void Idioma::ordenar(){
        Bigrama tmp;
        int n=getSize();
        for(int izda=0; izda<n ;izda++){
            for (int j=n-1;j>izda;j--){
                if (getPosicion(j).getFrecuencia() > getPosicion(j-1).getFrecuencia()){
                    tmp=getPosicion(j);
                    setPosicion(j,getPosicion(j-1));
                    setPosicion(j-1,tmp);
                }
            }
        }
    }
   
    
    void Idioma::copiar(const Idioma& otro){
        for(int i=0;i<otro.getSize();i++){
            setPosicion(i,otro.getPosicion(i));
        }
    }
    
    
    
    /**
 * @brief Serialización de un idioma para su inserción en un flujo de salida
 * @param os Flujo de salida
 * @param i Idioma a serializar
 * @return El mismo flujo de salida para inserciones consecutivas
 */
std::ostream & operator<<(std::ostream & os, const Idioma & i){
    os<<"MP−BIGRAMAS-IDIOMA-T-1.0"<<endl;
    os<<i.getIdioma()<<endl;
    os<<i.getSize()<<endl;
    for(int k=0;k<i._nBigramas;k++){
        os<<i.getPosicion(k)<<endl;
    }
    return os;
}


/**
 * @brief Reconstruye un Idioma a partir de una serialización
 * @param is Flujo de entrada desde el que se extrae la serialización
 * @param i Idioma reconstruido
 * @return El mismo flujo de entrada para extracciones consecutivas
 */
std::istream & operator>>(std::istream & is, Idioma & i){
    char cabecera[60],big[2];
    char idioma[20];
    int nbig,frec;
    Bigrama aux;
    is>>cabecera;
    is>>idioma;
    i.setIdioma(idioma);
    is>>nbig;
    for(int j=0;j<nbig;j++){
        is>>big;
        is>>frec;
        aux.setBigrama(big);
        aux.setFrecuencia(frec);
        i.setPosicion(j,aux);
    }
    return is;
}



    