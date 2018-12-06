#ifndef EDGE_HPP
#define EDGE_HPP
#include "Vertex.hpp"
class Edge{
   private:
      float distancia_;
      Vertex inicio_;
      Vertex fin_;
   public:
      inline float getData() const{return distancia_;}
      bool has(Vertex const & u) const;
      Vertex other(Vertex const & u) const;
      inline Vertex first() const{return inicio_;}
      inline Vertex second() const{return fin_;}
      inline void setData(float const & distancia){distancia_=distancia;}
      inline void setFirstVertex(Vertex const & u){inicio_=u;}
      inline void setSecondVertex(Vertex const & u){fin_=u;}
      bool operator<(Edge const & lado);
      Edge & operator=(Edge const & lado);
};
#endif
