

#include "ContadorBigramas.h"

/**
* @brief Constructor base. Es imprescindible pasar la cadena de caracteres válidos para poder dimensionar la matriz 2D
* @param caracteresValidos Cadena que contiene los únicos caracteres que serán considerados para contabilizar bigramas
*/
ContadorBigramas::ContadorBigramas(const std::string& caracteresValidos){
    int n=0;
    while(caracteresValidos[n]!='\0'){
        n++;
    }
    _caracteresValidos=caracteresValidos;
    reservarMemoria(n);
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            _bigramas[i][j]=0;
        }
    }
}
    
/**
* @brief Constructor de copia
* @param orig El objeto que se copia en en el constructor
*/
ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig){
    reservarMemoria(orig.getSize());
    copiar(orig);
}
    
/**
* @brief Destructor de la clase 
*/
ContadorBigramas::~ContadorBigramas(){
    liberarMemoria();
}
/**
 * @brief Devuelve el número de filas de la matriz 2D, que debe coincidir con la longitud de la cadena de caracteres válidos
 * @return El número de filas de la matriz
*/
int ContadorBigramas::getSize() const{
    int i=0;
    while(_caracteresValidos[i]!='\0'){
        i++;
    }
    return i;
}
    
/**
* @brief Devuelve el número de bigramas de la matriz 2D cuya frecuencia es > 0
* @return El número de bigramas con frecuencia > 0
*/
int ContadorBigramas::getBigramasActivos() const{
    int cont=0,n;
    n=getSize();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(_bigramas[i][j]>0){
                cont++;
            }
        }
    }
    return cont;
}
    
/**
* @brief Añade un bigrama a la matriz 2D indicando su frecuencia. Si frecuencia = 0, se incrementará en uno la frecuencia del bigrama añadido, sino se le asigna la frecuencia
* @param cadena[] el bigrama que se desea añadir
* @param la frecuencia del bigrama
* @return Verdadero si el bigrama es valido y se añade a la matriz 2D, falso en otro caso
*/
bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia){ 
    
    int i,a,b;
    
    bool esvalido1=false;
    bool esvalido2=false;
    
    for(i=0;i<getSize() && !esvalido1 ;i++){
        if(cadena[0]==_caracteresValidos[i]){
            a=i;
            esvalido1=true;
        }
    }
    
    for(i=0;i<getSize() && !esvalido2 ;i++){
        if(cadena[1]==_caracteresValidos[i]){
            b=i;
            esvalido2=true;
        }
    }
    if(esvalido1 && esvalido2){
        if(frecuencia==0){
            _bigramas[a][b]=_bigramas[a][b]+1;
        }
        else
            _bigramas[a][b]=frecuencia;
    }
    return(esvalido1&&esvalido2);
}
    
/**
* @brief Sobrecarga del operador de asignación
* @param orig Parámetro de la asignación
* @return this 
*/
ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas& orig){ // Operador asignación
    if(&orig!=this){
        this->liberarMemoria();
        reservarMemoria(orig.getSize());
        copiar(orig);  
    }
    return *this;
}

/**
* @brief Sobrecarga del operador de suma
* @param rgs Parámetro que se usa para sumar
* @return this 
*/ 
ContadorBigramas& ContadorBigramas::operator+=(const ContadorBigramas& rhs){
    for(int i=0;i<getSize();i++){
        for(int j=0;j<getSize();j++){
            this->_bigramas[i][j]=this->_bigramas[i][j]+rhs._bigramas[i][j];
        }
        
    }
    
    return *this;
}


/**
* @brief Carga en la matriz de 2D, los bigramas validos encontrados en el fichero
* @param fichero a leer
* @return Verdadero si se ha podido leer el fichero, falso en otro caso
*/
bool ContadorBigramas::calcularFrecuenciasBigramas(const char* nfichero){
    ifstream fentrada;
    bool error=false;
    bool aniadido;
    char bigramas[3],palabra[100];
    char c1,c2;
    
  
    
    fentrada.open(nfichero);
    
    if(fentrada){
        error=true;
        while(!fentrada.eof()){
            fentrada>>palabra;
            for(int i=0;i<strlen(palabra)-1;i++){
                c1=palabra[i];
                c1=tolower(c1);
                c2=palabra[i+1];
                c2=tolower(c2);
                bigramas[0]=c1;
                bigramas[1]=c2;
                bigramas[2]='\0';
                aniadido=addBigrama(bigramas,0);
            }
        }
    }
    else {
        cout<<"Error al abrir el fichero."<<endl;
        error=false;
        return error;
    }
    fentrada.close();
    return error;
}
    

/**
* @brief Pasa la matriz 2D a un objeto de la clase Idioma
*/
Idioma ContadorBigramas::toIdioma() const{
    Idioma I(getBigramasActivos());
    Bigrama aux;
    char big[2];
    int cont=0;
    
    for(int i=0;i<getSize();i++){
        for(int j=0;j<getSize();j++){
            if(_bigramas[i][j]>0){
                aux.setFrecuencia(_bigramas[i][j]);
                big[0]=_caracteresValidos[i];
                big[1]=_caracteresValidos[j];
                big[2]='\0';
                aux.setBigrama(big);
                I.setPosicion(cont,aux);
                cont++;
            }
        }
    }
    return I;
}
    

/**
* @brief Pasa la los bigramas del objeto Idioma a la matriz 2D
*/     
void ContadorBigramas::fromIdioma(const Idioma &i){
    int nbig=i.getSize();
    Bigrama aux;
    for(int j=0;j<nbig;j++){
        aux=i.getPosicion(j);
        addBigrama(aux.getBigrama(),aux.getFrecuencia());
    }
}

    
//Métodos privados de apoyo a los públicos.
void ContadorBigramas::reservarMemoria(int n){
    _bigramas=new int*[n];
    for (int i=0;i<n;i++){
        _bigramas[i]=new int[n];
    }
                
}

void ContadorBigramas::liberarMemoria(){
    for(int i=0;i<getSize();i++){
        delete [] _bigramas[i];
    }
    delete [] _bigramas;
    _bigramas=0;
}

void ContadorBigramas::copiar(const ContadorBigramas & otro){
    int n=otro.getSize();
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            _bigramas[i][j]=otro._bigramas[i][j];
        }
    }
}

