/**
   @file secuenciapaquete.cpp
   @author decsai.ugr.es
**/
#include "paquete.h"


/**
 * @brief Pone todos los paquetes del vector como paquetes vacíos y pone los componentes
 * útiles a 0
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 */
void cleanSecuenciaPaq(Paquete s[], int &util){
    util=0;
}

/**
 * @brief Añade un nuevo paquete a la lista de la clase por el final. Comprueba si cabe
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return @retval true si se ha podido hacer la inserción @retval false en otro caso 
 */
bool addSecuenciaPaq(Paquete s[], int &util, const Paquete &p){
    bool insertado=false;
    if(util<MAXPAQ){
       s[util]=p;
       util++;
       insertado=true;
        }
    return insertado;
    }
/**
 * @brief Calcula el precio de todos los paquetes de la lista según las tarifas
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return El precio total de la lista de paquetes
 */
double getTotalSecuenciaPaq(const Paquete s[], int util){
    double total=0;
    for (int i=0;i<util;i++){
        total=total + s[i].getFactura();
    }
    return total;
}
    
    
    

/**
 * @brief Devuelve el paquete con mayor volumen.
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return El paquete
 */
Paquete paqueteMayorSecuenciaPaq(const Paquete s[], int util){
    Paquete mayor(0);
   
    for(int i=0;i<util;i++){
        if(mayor.getVolumen() < s[i].getVolumen())
            mayor=s[i];
    }
    return mayor;
}

/**
 * @brief Calcula la media de precio facturado.
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return La media de sprecio
 */ 
double getMediaSecuenciaPaq( const Paquete s[],  int util){
    double media;
    media=(getTotalSecuenciaPaq(s, util));
    return media/util;
}

/**
 * @brief Devuelve cuántos paquetes son mayores que un valor dado en altura
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @param altura en cm
 * @return El número de paquetes
 */
int numPaqueteAltosSecuenciaPaq( const Paquete s[],  int util, int altura){
    int contador=0;
    for(int i=0;i<util;i++){
        if(s[i].getAlto()>altura){
            contador++;
        }
    }
    return contador;
}

/**
 * @brief Devuelve el numero de paquetes que tienen precio superior a la media.
 * @param s Un vector de paquetes
 * @param util Número de componentes útiles de @a s 
 * @return El número de paquetes
 */
int numPaquetesSuperiorSecuenciaPaq( const Paquete s[], int util){
    int contador=0;
    double media=getMediaSecuenciaPaq(s,util);
    for(int i=0;i<util;i++){
        if(s[i].getFactura()>media)
            contador++;
    }
    return contador;
}