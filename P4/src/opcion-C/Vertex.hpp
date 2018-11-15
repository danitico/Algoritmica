#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <stdlib.h>
#include <vector>
   class Vertex{
      private:
         std::string nombre_;
         int label_;
      public:
         inline std::string getNombre() const{
            return nombre_;
         }
         inline int getLabel() const{return label_;}
         void setNombre(std::string const & nombre){
            nombre_=nombre;
         }
         void setLabel(int label){
            label_=label;
         }
         bool operator==(Vertex const & vertice) const;
         bool operator!=(Vertex const & vertice) const;
         Vertex & operator=(Vertex const &vertice);
   };
#endif
