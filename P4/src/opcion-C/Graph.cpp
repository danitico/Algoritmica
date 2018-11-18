#include "Graph.hpp"
#include <iostream>
bool Graph::isEmpty() const{
   return vertexes_.empty() && edges_.empty() && matrix_.empty();
}
bool Graph::isDirected() const{
   for(int i=0; i<matrix_.size(); i++){
      for(int j=0; j<matrix_.size(); j++){
         if((matrix_[i][j] != matrix_[j][i]) && i!=j){
            return true;
         }
      }
   }

   return false;
}
bool Graph::adjacent(Vertex u, Vertex v) const{
   if(matrix_[u.getLabel()][v.getLabel()] >= 0){
      return true;
   }
   else{
      return false;
   }
}
bool Graph::hasCurrVertex() const{
   if(currentVertex_==-1){
      return false;
   }
   else{
      return true;
   }
}
Vertex Graph::currVertex() const{
   if(hasCurrVertex()){
      return vertexes_[currentVertex_];
   }
}
bool Graph::hasCurrEdge() const{
   if(currentEdge_==-1){
      return false;
   }
   else{
      return true;
   }
}
Edge Graph::currEdge() const{
   if(hasCurrEdge()){
      return edges_[currentEdge_];
   }
}
void Graph::setMatrix(int x, int y, int data){
   matrix_[x][y]=data;
}
void Graph::setMatrix1(int x, int y, int data){
   matrix1_[x][y]=data;
}
void Graph::setEdgeVector(int x, Edge & a){
   edges_[x]=a;
}
void Graph::addVertex(std::string nombre){
   Vertex a;

   a.setNombre(nombre);
   a.setLabel(etiquetas_);
   etiquetas_++;
   vertexes_.push_back(a);
   currentVertex_=vertexes_.size()-1;

   matrix_.resize(matrix_.size() + 1);
   matrix1_.resize(matrix1_.size() + 1);
   for(int i=0; i<matrix_.size(); i++){
      matrix_[i].resize(matrix_.size(), -1);
      matrix1_[i].resize(matrix1_.size(), -1);
   }
}
void Graph::addEdge(Vertex const & u, Vertex const & v, float distancia){
   Edge e;

   e.setFirstVertex(u);
   e.setSecondVertex(v);
   e.setData(distancia);

   edges_.push_back(e);
   // currentEdge=edges_.size()-1;

   matrix_[u.getLabel()][v.getLabel()]=edges_.size()-1;
   // matrix_[v.getLabel()][u.getLabel()]=edges_.size()-1;
}
void Graph::gotoVertex(Vertex const & v){
   currentVertex_=-1;
   for(int i=0; i<vertexes_.size(); i++){
      if(vertexes_[i]==v){
         currentVertex_=i;
         break;
      }
   }
}
void Graph::gotoEdge(Vertex const & u, Vertex const & v){
   currentEdge_=-1;
   for(int i=0; i<edges_.size(); i++){
      if(edges_[i].has(u) && edges_[i].has(v)){
         currentEdge_=i;
         break;
      }
   }
}
void Graph::goToFirstVertex(){
   if(vertexes_.size()==0){
      currentVertex_=-1;
   }
   else{
      currentVertex_=0;
   }
}
void Graph::nextVertex(){
   if(currentVertex_+1 < vertexes_.size()){
      currentVertex_++;
   }
   else{
      currentVertex_=-1;
   }
}
void Graph::goToFirstEdge(){
   if(edges_.size()==0){
      currentEdge_=-1;
   }
   else{
      for(int i=0; i<edges_.size(); i++){
         if(edges_[i].has(vertexes_[currentVertex_])){
            currentEdge_=i;
            break;
         }
      }
      // currentEdge_=0;
   }
}
void Graph::nextEdge(){
   int ultimoEdgeconocido=currentEdge_;
   currentEdge_=-1;
   for(int i=ultimoEdgeconocido+1; i<edges_.size(); i++){
      if(edges_[i].has(vertexes_[currentVertex_])){
         currentEdge_=i;
         break;
      }
   }
}
int Graph::getConnectionsVertex(Vertex const & u){
   int oldEdge=getCurrentEdge();
   int oldVertex=getCurrentVertex();
   int contador=0;

   gotoVertex(u);
   if(getCurrentVertex()==-1){
      return 0;
   }
   else{
      goToFirstEdge();
      if(getCurrentEdge()==oldEdge){
         return 0;
      }
      else{
         contador++;
         nextEdge();
         while(getCurrentEdge()!=-1){
            contador++;
            nextEdge();
         }
      }
   }
   currentVertex_=oldVertex;
   currentEdge_=oldEdge;

   return contador;
}
Graph & Graph::operator=(Graph const &g){
   this->vertexes_=g.vertexes_;
   this->edges_=g.edges_;
   this->matrix_=g.matrix_;
   this->etiquetas_=g.etiquetas_;
   this->currentVertex_=g.currentVertex_;
   this->currentEdge_=g.currentEdge_;

   return *this;
}
