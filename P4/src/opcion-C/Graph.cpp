/*!
   \file Graph.cpp
   \brief Fichero de la clase Graph
   \author Daniel Ranchal Parrado
   \date
*/
#include "Graph.hpp"
bool ed::Graph::isEmpty() const{
   return vertexes_.empty() && edges_.empty() && matrix_.empty();
}
bool ed::Graph::isDirected() const{
   for(int i=0; i<matrix_.size(); i++){
      for(int j=0; j<matrix_.size(); j++){
         if((matrix_[i][j] != matrix_[j][i]) && i!=j){
            return true;
         }
      }
   }

   return false;
}
bool ed::Graph::adjacent(ed::Vertex u, ed::Vertex v) const{
   if(matrix_[u.getLabel()][v.getLabel()] >= 0){
      return true;
   }
   else{
      return false;
   }
}
bool ed::Graph::hasCurrVertex() const{
   if(currentVertex_==-1){
      return false;
   }
   else{
      return true;
   }
}
ed::Vertex ed::Graph::currVertex() const{
   if(hasCurrVertex()){
      return vertexes_[currentVertex_];
   }
}
bool ed::Graph::hasCurrEdge() const{
   if(currentEdge_==-1){
      return false;
   }
   else{
      return true;
   }
}
ed::Edge ed::Graph::currEdge() const{
   if(hasCurrEdge()){
      return edges_[currentEdge_];
   }
}
void ed::Graph::setMatrix(int x, int y, int data){
   matrix_[x][y]=data;
}
void ed::Graph::setEdgeVector(int x, ed::Edge & a){
   edges_[x]=a;
}
void ed::Graph::addVertex(Punto p){
   ed::Vertex a;

   a.setData(p);
   a.setLabel(etiquetas_);
   etiquetas_++;
   vertexes_.push_back(a);
   currentVertex_=vertexes_.size()-1;

   matrix_.resize(matrix_.size() + 1);
   for(int i=0; i<matrix_.size(); i++){
      matrix_[i].resize(matrix_.size(), -1);
   }
}
void ed::Graph::addEdge(Vertex const & u, Vertex const & v, float distancia){
   ed::Edge e;

   e.setFirstVertex(u);
   e.setSecondVertex(v);
   e.setData(distancia);

   edges_.push_back(e);
   // currentEdge=edges_.size()-1;

   matrix_[u.getLabel()][v.getLabel()]=edges_.size()-1;
   //matrix_[v.getLabel()][u.getLabel()]=edges_.size()-1;
}
void ed::Graph::removeVertex(){//de la manera qu lo voy a hacer, hay que hacer el operator =
   ed::Graph aux;

   //Recorremos el vector de vertices y solo metemos en el nuevo grafo aquel que no sea el current
   for(int i=0; i<vertexes_.size(); i++){
      if(!(vertexes_[i].getData() == vertexes_[currentVertex_].getData())){
         aux.addVertex(vertexes_[i].getData());
      }
   }

   //Vamos viendo las distintas conexiones, ya que es un grafo conexo
   for(int j=0; j<aux.vertexes_.size(); j++){
      for(int k=j+1; k<aux.vertexes_.size(); k++){
         aux.addEdge(aux.vertexes_[j], aux.vertexes_[k], ed::distancia(aux.vertexes_[j].getData(), aux.vertexes_[k].getData()));
      }
   }

   *this=aux;
}
void ed::Graph::removeEdge(){
   int posicion=currentEdge_;

   std::swap(edges_[currentEdge_], edges_[edges_.size() - 1]);
   currentEdge_=edges_.size()-1;

   for(int i=0; i<matrix_.size(); i++){
      for(int j=0; j<matrix_.size(); j++){
         if(matrix_[i][j]==currentEdge_){
            matrix_[i][j]=posicion;
         }
         else{
            if(matrix_[i][j]==posicion){
               matrix_[i][j]=-1;
            }
         }
      }
   }
   currentEdge_=-1;
   edges_.resize(edges_.size()-1);
}
void ed::Graph::gotoVertex(ed::Vertex const & v){
   currentVertex_=-1;
   for(int i=0; i<vertexes_.size(); i++){
      if(vertexes_[i]==v){
         currentVertex_=i;
         break;
      }
   }
}
void ed::Graph::gotoEdge(ed::Vertex const & u, ed::Vertex const & v){
   currentEdge_=-1;
   for(int i=0; i<edges_.size(); i++){
      if(edges_[i].has(u) && edges_[i].has(v)){
         currentEdge_=i;
         break;
      }
   }
}
void ed::Graph::goToFirstVertex(){
   if(vertexes_.size()==0){
      currentVertex_=-1;
   }
   else{
      currentVertex_=0;
   }
}
void ed::Graph::nextVertex(){
   if(currentVertex_+1 < vertexes_.size()){
      currentVertex_++;
   }
   else{
      currentVertex_=-1;
   }
}
void ed::Graph::goToFirstEdge(){
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
void ed::Graph::nextEdge(){
   int ultimoEdgeconocido=currentEdge_;
   currentEdge_=-1;
   for(int i=ultimoEdgeconocido+1; i<edges_.size(); i++){
      if(edges_[i].has(vertexes_[currentVertex_])){
         currentEdge_=i;
         break;
      }
   }
}
ed::Graph & ed::Graph::operator=(Graph const &g){
   this->vertexes_=g.vertexes_;
   this->edges_=g.edges_;
   this->matrix_=g.matrix_;
   this->etiquetas_=g.etiquetas_;
   this->currentVertex_=g.currentVertex_;
   this->currentEdge_=g.currentEdge_;

   return *this;
}
