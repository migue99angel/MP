/** 
 * @file Idioma.cpp
 * @author DECSAI
 * @warning Código incompleto. Implementar la clase completa
*/
#include "Bigrama.h"
#include "Idioma.h"
/**
 * @class Idioma
 * @brief Representa el conjunto los bigramas asociados a un idioma junto con el 
 * identificador del idioma
 */

    /**
     * @brief Constructor base
     */
Idioma::Idioma(){
    _idioma="Unknow";
    _nBigramas=0;
    _conjunto=0;
}
    
    /**
     * @brief Constructor para pre-reservar memoria
     * @param nbg Número de bigramas pre-reservados
     */
Idioma::Idioma(int nbg){
    _idioma="Unknow";
    _nBigramas=nbg;
    _conjunto=new Bigrama[nbg];
}
    
	 /**
	  * @brief reserva memoria para @a n bigramas,
	  * en caso de que ya hubiese memoria reservada, esta
	  * debe eliminarse
	  * @param n número de bigramas a reservar
	  */
void Idioma::reservarMemoria(int n){
    if(this->_conjunto!=NULL){
        delete [] _conjunto;
    }
    _conjunto=new Bigrama[n];
    _nBigramas=n;
}

	 /**
	  * @brief reserva memoria para @a n bigramas adicionales
	  * a los que ya haya reservados, manteniendo los datos
	  * que hubiese podido haber reservados
	  * @param n número de bigramas a ampliar
	  */
void Idioma::ampliarMemoria(int n){
    Bigrama *aux;
    int utilaux=this->_nBigramas;
    aux=new Bigrama [utilaux];
    
    for (int i=0;i<utilaux;i++){
        aux[i]=this->_conjunto[i];
    }
    
    delete [] this->_conjunto;
    _nBigramas=utilaux +n;
    _conjunto=new Bigrama [_nBigramas];
    
    for (int i=0;i<utilaux;i++){
        _conjunto[i]=aux[i];
    }
    
    delete [] aux;
}

    /**
     * @brief Libera la memoria
     */
void Idioma::liberarMemoria(){
    delete [] this->_conjunto;
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
    bool esta=false;
    if (p<_nBigramas && p >0){
        esta=true;
    }
    else
        assert (esta);
    return this->_conjunto[p];
}
    
    /**
     * @brief Añade un nuevo bigrama
     * @param p La posición en la que se quiere insertar el bigrama
     * @precond La posición @p p es correcta
     * @param bg El bigrama a insertar
     */
void Idioma::setPosicion(int p, const Bigrama & bg){
    bool as=false;
    this->ampliarMemoria(_nBigramas+1);
    if(p<=_nBigramas && p>=0){
        for (int i=_nBigramas; i>p; i--){
            _conjunto[i]=_conjunto[i-1];
        }
        _conjunto[p].setBigrama(bg.getBigrama());
    }
    else{
        if ( p<=_nBigramas+1 && p>0){
            this->ampliarMemoria(1);
            _conjunto[p].setBigrama(bg.getBigrama());
        }
        else 
            assert(as);
    }
    
        
}
                           
    /**
     * @brief Busca un bigrama en la lista de bigramas
     * @param bg El bigrama que se está buscando
     * @return La posición que ocupa @p bg en la lista, -1 si no está en la lista
     */
int Idioma::findBigrama(const std::string bg) const{
    int pos=-1;
    for (int i=0; i<_nBigramas; i++){
        if(_conjunto[i].getBigrama()== bg){
            pos=i;
        }
    }
    return pos;
}

	 /**
	  * @brief Añade un nuevo bigrama a la lista. Si el bigrama se añade por primera vez
	  * se debe incrementar el tamaño del vector para alojar el nuevo bigrama. Si el bigrama
	  * ya existe, se deben de sumar ambas frecuencias, la existente y la nueva
	  * @param bg El bigrama a añadir
	  */
void Idioma::addBigrama(const Bigrama & bg){
    int pos=this->findBigrama(bg.getBigrama());
    int frec;
    if(pos != -1){
        frec=this->_conjunto[pos].getFrecuencia();
        this->_conjunto[pos].setFrecuencia(frec + bg.getFrecuencia());
    }
    else {
        this->ampliarMemoria(1);
        this->_conjunto[this->_nBigramas-1]=bg;
        
    }
    
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
    int nbig, frecuencia;
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
        for(int i=0;i<nbig;i++){
            fentrada>>bigramas;
            fentrada>>frecuencia;
            aux.setBigrama(bigramas);
            aux.setFrecuencia(frecuencia);
            
            this->_conjunto[i]=aux;
            
        }
    }
    else
        nerror=false;
    fentrada.close();
    return nerror;
}

	 /**
	  * @brief Método similar a @a cargarDeFichero pero en vez de cargar un idioma nuevo
	  * desde el fichero (que debe contener un idioma serializado), los bigramas del fichero
	  * se añaden al diccionario que ya existe.
	  * @param fichero Contiene los bigramas a añadir al idioma existente
     * @return @b false si ha habido algún tipo de error, @b true en otro caso
	  * @pre El objeto ya debe tener un idioma cargado y deben coincidir ambos
	  */
bool Idioma::addDeFichero(const char *fichero){
    ifstream fentrada;
    bool error=false;
    char bigramas[3];
    char cabecera[70];
    char idioma[15];
    int nbig, frecuencia;
    
    fentrada.open(fichero);
    if(fentrada){
        error=true;
        fentrada>>cabecera;
        fentrada>>idioma;
        cout<<"Idioma detectado: "<<idioma<<endl;
        fentrada>>nbig;
        cout<<"Leyendo "<<nbig<<" bigramas."<<endl;
        Bigrama fich;
        if(idioma==_idioma){
            for(int i=0;i<nbig;i++){
                fentrada>>bigramas;
                fentrada>>frecuencia;
                fich.setBigrama(bigramas);
                fich.setFrecuencia(frecuencia);
                addBigrama(fich);
            }
        }
        else 
            error=false;
    }
    else 
        error=false;
    fentrada.close();
    return error;
}
	 
