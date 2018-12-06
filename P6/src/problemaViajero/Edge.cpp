#include "Edge.hpp"
bool Edge::has(Vertex const & u) const{
   if(u==first() || u==second()){
      return true;
   }
   else{
      return false;
   }
}
Vertex Edge::other(Vertex const & u) const{
   if(u==first()){
      return second();
   }
   else{
      if(u==second()){
         return first();
      }
   }
}
bool Edge::operator<(Edge const & lado){
   if(this->getData() < lado.getData()){
      return true;
   }
   else{
      return false;
   }
}
Edge & Edge::operator=(Edge const & lado){
   this->setFirstVertex(lado.first());
   this->setSecondVertex(lado.second());
   this->setData(lado.getData());
   return *this;
}
