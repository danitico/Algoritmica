#include "Graph.hpp"
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
ed::Edge Graph::currEdge() const{
   if(hasCurrEdge()){
      return edges_[currentEdge_];
   }
}
void Graph::setMatrix(int x, int y, int data){
   matrix_[x][y]=data;
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
   for(int i=0; i<matrix_.size(); i++){
      matrix_[i].resize(matrix_.size(), -1);
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
   //matrix_[v.getLabel()][u.getLabel()]=edges_.size()-1;
}
void Graph::removeVertex(){//de la manera qu lo voy a hacer, hay que hacer el operator =
   Graph aux;

   //Recorremos el vector de vertices y solo metemos en el nuevo grafo aquel que no sea el current
   for(int i=0; i<vertexes_.size(); i++){
      if(!(vertexes_[i].getNombre() == vertexes_[currentVertex_].getNombre())){
         aux.addVertex(vertexes_[i].getNombre());
      }
   }

   //Vamos viendo las distintas conexiones, ya que es un grafo conexo
   for(int j=0; j<aux.vertexes_.size(); j++){
      for(int k=j+1; k<aux.vertexes_.size(); k++){
         //hay que ver esto, esta mal, :(
         aux.addEdge(aux.vertexes_[j], aux.vertexes_[k], ed::distancia(aux.vertexes_[j].getData(), aux.vertexes_[k].getData()));
      }
   }

   *this=aux;
}
void Graph::removeEdge(){
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
void Graph::gotoVertex(Vertex const & v){
   currentVertex_=-1;
   for(int i=0; i<vertexes_.size(); i++){
      if(vertexes_[i]==v){
         currentVertex_=i;
         break;
      }
   }
}
void Graph::gotoEdge(ed::Vertex const & u, Vertex const & v){
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
Graph & Graph::operator=(Graph const &g){
   this->vertexes_=g.vertexes_;
   this->edges_=g.edges_;
   this->matrix_=g.matrix_;
   this->etiquetas_=g.etiquetas_;
   this->currentVertex_=g.currentVertex_;
   this->currentEdge_=g.currentEdge_;

   return *this;
}
