/**
   @file paquete.cpp
   @author decsai.ugr.es
**/

#include <cstdlib>
#include <string>
#include <iostream>
#include <assert.h>
#include "paquete.h"

using namespace std;

  Paquete::Paquete() 
   {
       _peso=0;
       _largo=0;
       _ancho=0;
       _alto=0;
       _id=_SIN_IDENT;
   }   


  Paquete::Paquete(int id)
   {
       _id=id;
       _peso=0;
       _largo=0;
       _ancho=0;
       _alto=0;
   }


   Paquete::Paquete(int id, double peso, int largo, int ancho, int alto){
       bool paquetevalido= (MedidaValida(peso) && MedidaValida(ancho) && MedidaValida(alto) && PesoValido(peso) && IdValido(id));
       if(paquetevalido){
       _id = id;        
       _peso = peso;
       _largo = largo;
       _ancho = ancho;
       _alto = alto;
       }
   }
   

   void Paquete::setId(int id){
       if(IdValido(id))
       _id = id;
   }

   
   int  Paquete::getId() const{
       return _id;
   }


   
   void Paquete::setPeso(double peso){
       if(PesoValido(peso)){
           
           _peso = peso;
       }
   }

   
   double Paquete::getPeso() const{
       return _peso;
   }

   
   void Paquete::setLargo(int largo){
       if(MedidaValida(largo)){
           _largo=largo;
       }
   }

   
   int Paquete::getLargo() const{
       return _largo;
   }

   
   void Paquete::setAncho(int ancho){
       if(MedidaValida(ancho)){
           _ancho=ancho;
       }
   }

   
   int Paquete::getAncho() const {
       return _ancho;
   }

   
   void Paquete::setAlto(int alto){
       if(MedidaValida(alto)){
           _alto = alto;
       }
   }

   
   int Paquete::getAlto()const{
       return _alto;
   }


   
   void Paquete::setPaquete(int id, double peso, int largo, int ancho, int alto){
       bool paquetevalido=(MedidaValida(peso) && MedidaValida(ancho) && MedidaValida(alto) && PesoValido(peso) && IdValido(id));
       if(paquetevalido){
       _id = id;        
       _peso = peso;
       _largo = largo;
       _ancho = ancho;
       _alto = alto;
       }
   }

   
   double Paquete::getVolumen()const {
       return _alto*_largo*_ancho;
   }

   
   double Paquete::calculaPesoVolumetrico()const{
       return (getVolumen()/_FACTORVOLUMETRICO);
   }


   
   double Paquete::getFactura() const{
       double precio;
       Paquete p;
       double pv=calculaPesoVolumetrico();
       if(calculaPesoVolumetrico() >= _peso )
           precio=p.tarifa(pv);
       else 
           precio=p.tarifa(_peso);
       return(precio* _IVA + precio);
   }

     
   bool Paquete::PesoValido(const double peso){
       bool valido=false;
       if(peso > 0 && peso <=_RANGO3 ){
           valido=true;
       }
       else 
       {
           assert(valido);
       }
       return valido;
   }
   
   bool Paquete::MedidaValida(double medida){
       bool valido = false;
       if (medida > 0){
           valido = true;
     }
       else
       {
           assert(valido);
       }
       return valido;
   }
   bool Paquete::IdValido(int id){
       bool valido=false;
       if(id ==_SIN_IDENT || id > 0){
           valido=true;
       }
       else{
           assert(valido);
       }
       return (valido); 
   }

   double Paquete::tarifa(double peso){
       double devolver;
       if(peso<=2){
           devolver=_TARIFA1;
       }
       else{
           if(peso <= 5 ){
               devolver = _TARIFA2;
           }
           else{
               devolver =_TARIFA3;
           }
           }
       return devolver;
   }
   
   
 