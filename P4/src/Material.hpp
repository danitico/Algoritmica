#ifndef MATERIAL_HPP
#define MATERIAL_HPP
class Material{
   private:
      int etiqueta_, volumen_, precio_;
      bool disponible_;
   public:
      inline Material(int etiqueta=0, int volumen=0, int precio=0, bool disponible=false){
         this->setEtiqueta(etiqueta);
         this->setVolumen(volumen);
         this->setPrecio(precio);
         this->setDisponible(disponible);
      }
      inline int getEtiqueta(){
         return etiqueta_;
      }
      inline void setEtiqueta(int etiqueta){
         etiqueta_=etiqueta;
      }
      inline int getVolumen(){
         return volumen_;
      }
      inline void setVolumen(int volumen){
         volumen_=volumen;
      }
      inline int getPrecio(){
         return precio_;
      }
      inline void setPrecio(int precio){
         precio_=precio;
      }
      inline bool getDisponible(){
         return disponible_;
      }
      inline void setDisponible(bool disponible){
         disponible_=disponible;
      }
      int getTotal();
};
#endif
