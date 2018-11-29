#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include <iostream>
class Material{
   private:
      int etiqueta_, volumen_;
      // int precio_;
      float precio_;
      bool disponible_;
   public:
      inline Material(int etiqueta=0, int volumen=0, float precio=0.0, bool disponible=false){
         this->setEtiqueta(etiqueta);
         this->setVolumen(volumen);
         this->setPrecio(precio);
         this->setDisponible(disponible);
      }
      inline int getEtiqueta() const{
         return etiqueta_;
      }
      inline void setEtiqueta(int etiqueta){
         etiqueta_=etiqueta;
      }
      inline int getVolumen() const{
         return volumen_;
      }
      inline void setVolumen(int volumen){
         volumen_=volumen;
      }
      inline float getPrecio() const{
         return precio_;
      }
      inline void setPrecio(float precio){
         precio_=precio;
      }
      inline bool getDisponible() const{
         return disponible_;
      }
      inline void setDisponible(bool disponible){
         disponible_=disponible;
      }
      float getTotal() const;
      friend std::ostream & operator<<(std::ostream & stream, const Material & a);
      void operator=(const Material & a);
      bool operator==(const Material & b) const;
};
#endif
