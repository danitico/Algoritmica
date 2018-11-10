/*!
   \file Edge.cpp
   \brief Fichero de la clase Edge
   \author Daniel Ranchal Parrado
   \date
*/
#include "Edge.hpp"
bool ed::Edge::has(ed::Vertex const & u) const{
   if(u==first() || u==second()){
      return true;
   }
   else{
      return false;
   }
}
ed::Vertex ed::Edge::other(ed::Vertex const & u) const{
   if(u==first()){
      return second();
   }
   else{
      if(u==second()){
         return first();
      }
   }
}
bool ed::Edge::operator<(Edge const & lado){
   if(this->getData() < lado.getData()){
      return true;
   }
   else{
      return false;
   }
}
ed::Edge & ed::Edge::operator=(ed::Edge const & lado){
   this->setFirstVertex(lado.first());
   this->setSecondVertex(lado.second());
   this->setData(lado.getData());

   return *this;
}
