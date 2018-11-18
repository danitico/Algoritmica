#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Edge.hpp"
#include <vector>
#include <vector>
class Graph{
   private:
      std::vector<Vertex> vertexes_;
      std::vector<Edge> edges_;
      std::vector<std::vector<int> > matrix_;
      std::vector<std::vector<int> > matrix1_;
      int currentVertex_;
      int currentEdge_;
      int etiquetas_;
   public:
      inline Graph(){
         vertexes_.resize(0);
         edges_.resize(0);
         matrix_.resize(0);
         matrix1_.resize(0);
         currentVertex_=-1;
         currentEdge_=-1;
         etiquetas_=0;
      }
      inline std::vector<Vertex> getVertexVector() const{
         return vertexes_;
      }
      inline std::vector<Edge> getEdgeVector() const{
         return edges_;
      }
      inline std::vector<std::vector<int> > getMatrix() const{
         return matrix_;
      }
      inline std::vector<std::vector<int> > getMatrix1() const{
         return matrix1_;
      }
      inline int getCurrentVertex() const{
         return currentVertex_;
      }
      inline int getCurrentEdge() const{
         return currentEdge_;
      }
      inline int getEtiquetas() const{
         return etiquetas_;
      }
      bool isEmpty() const;
      bool isDirected() const;
      bool adjacent(Vertex u, Vertex v) const;
      bool hasCurrVertex() const;
      Vertex currVertex() const;
      bool hasCurrEdge() const;
      Edge currEdge() const;
      void setEdgeVector(int x, Edge & a);
      void setMatrix(int x, int y, int data);
      void setMatrix1(int x, int y, int data);
      void addVertex(std::string nombre);
      void addEdge(Vertex const & u, Vertex const & v, float distancia);
      void gotoVertex(Vertex const & v);
      void gotoEdge(Vertex const & u, Vertex const & v);
      void goToFirstVertex();
      void nextVertex();
      void goToFirstEdge();
      void nextEdge();
      int getConnectionsVertex(Vertex const & u);
      Graph & operator=(Graph const &g);
};
#endif
