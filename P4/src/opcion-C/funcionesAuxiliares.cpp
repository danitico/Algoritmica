/*!
   \file funcionesAuxiliares.cpp
   \brief Funciones auxiliares
   \author Daniel Ranchal Parrado
   \date
*/
#include "funcionesAuxiliares.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cfloat>
#include <algorithm>
#include "macros.hpp"
void ed::cargarVertices(ed::Graph & grafo, std::string fichero){
   std::ifstream archivo(fichero.c_str());

   if(!archivo.is_open()){
      std::cin.ignore();
      std::cout<<BIRED<<"Error al abrir el fichero"<<RESET<<std::endl;
   }
   else{
      if(grafo.getVertexVector().size()==0){
         std::string stream;
         ed::Punto a;

         while(getline(archivo, stream, ' ')){
            a.setX(atof(stream.c_str()));

            getline(archivo, stream, '\n');
            a.setY(atof(stream.c_str()));

            grafo.addVertex(a);
         }
         archivo.close();

         for(int i=0; i<grafo.getVertexVector().size(); i++){
            for(int j=i+1; j<grafo.getVertexVector().size(); j++){
               grafo.addEdge(grafo.getVertexVector()[i], grafo.getVertexVector()[j], ed::distancia(grafo.getVertexVector()[i].getData(), grafo.getVertexVector()[j].getData()));
               grafo.setMatrix(grafo.getVertexVector()[j].getLabel(), grafo.getVertexVector()[i].getLabel(), grafo.getMatrix()[grafo.getVertexVector()[i].getLabel()][grafo.getVertexVector()[j].getLabel()]);
            }
         }
         std::cin.ignore();
         std::cout<<BIGREEN<<"Fichero cargado con éxito"<<RESET<<std::endl;
      }
      else{
         std::cin.ignore();
         std::cout << BIRED << "El grafo ya tiene datos. Tiene que borrarlo pra cargar uno nuevo" << RESET <<std::endl;
      }
   }
}
void ed::mostrarGrafo(ed::Graph & grafo){
   if(grafo.getVertexVector().size()>0){
      std::cout << BIBLUE << "Los vértices del grafo son:" << RESET <<'\n';
      std::cout <<BIYELLOW<< "ETIQUETA" << RESET << BICYAN <<"\tPOSICION" << RESET <<std::endl;
      for(int i=0; i<grafo.getVertexVector().size(); i++){
         std::cout << BIYELLOW << grafo.getVertexVector()[i].getLabel() << RESET << BICYAN <<"\t\t";
         grafo.getVertexVector()[i].getData().escribirPunto();
         std::cout<<std::endl;
      }

      std::cout <<std::endl<<BIYELLOW<< "1º Vértice" << RESET << BICYAN <<"\t2º Vértice\t" << RESET << BIBLUE << "Coste" << RESET <<std::endl;
      for(int j=0; j<grafo.getEdgeVector().size(); j++){
         std::cout << BIYELLOW;
         grafo.getEdgeVector()[j].first().getData().escribirPunto();
         std::cout << RESET << "\t\t";
         std::cout << BICYAN;
         grafo.getEdgeVector()[j].second().getData().escribirPunto();
         std::cout << RESET << "\t\t";
         std::cout << BIBLUE << grafo.getEdgeVector()[j].getData() << RESET << std::endl;
      }

      std::cout<<std::endl<<BIBLUE<<UNDERLINE<<"Matriz de adyacencias"<<RESET<<std::endl;
      for(int k=0; k<grafo.getMatrix().size(); k++){
         for(int k1=0; k1<grafo.getMatrix().size(); k1++){
            if(grafo.getMatrix()[k][k1]==-1){
               std::cout << "0 ";
            }
            else{
               std::cout << grafo.getMatrix()[k][k1] + 1<<" ";
            }
         }
         std::cout<<std::endl;
      }
   }
   else{
      std::cout << BIRED << "El grafo está vacio" << RESET <<std::endl;
   }
}
void ed::borrarGrafo(ed::Graph & grafo){
   if(grafo.isEmpty()){
      std::cout << BIRED <<"El grafo esta vacío"<< RESET <<std::endl;
   }
   else{
      grafo.goToFirstVertex();
      while(grafo.hasCurrVertex()){
         grafo.removeVertex();
      }
      std::cout << BIGREEN << "Grafo borrado correctamente" << RESET << std::endl;
   }
}
void ed::BorrarVertice(ed::Graph & grafo, ed::Vertex a){
   grafo.gotoVertex(a);

   if(grafo.getCurrentVertex()==-1){
      std::cin.ignore();
      std::cout << BIRED << "El vértice no se encuentra en el grafo, por lo que no se puede borrar" << RESET <<std::endl;
   }
   else{
      grafo.removeVertex();
      std::cin.ignore();
      std::cout << BIGREEN << "El vértice se ha borrado correctamente" << RESET <<std::endl;
   }
}
void ed::borrarLado(ed::Graph & grafo, ed::Vertex a, ed::Vertex b){
   grafo.gotoVertex(a);
   if(grafo.getCurrentVertex()==-1){
      std::cin.ignore();
      std::cout << BIRED << "El vértice origen no se encuentra en el grafo" << RESET << std::endl;
   }
   else{
      grafo.gotoVertex(b);
      if(grafo.getCurrentVertex()==-1){
         std::cin.ignore();
         std::cout << BIRED << "El vértice destino no se encuentra en el grafo" << RESET << std::endl;
      }
      else{
         grafo.gotoEdge(a, b);
         if(grafo.getCurrentEdge()==-1){
            std::cin.ignore();
            std::cout << BIRED << "Esos dos vértices no están conectados" << RESET << std::endl;
         }
         else{
            grafo.removeEdge();
            std::cin.ignore();
            std::cout << BIGREEN << "Conexión borrada correctamente" << RESET <<std::endl;
         }
      }
   }
}
void ed::modificarCosteConexion(ed::Graph & grafo, ed::Vertex a, ed::Vertex b){
   grafo.gotoVertex(a);
   if(grafo.getCurrentVertex()==-1){
      std::cin.ignore();
      std::cout << BIRED << "El vértice origen no se encuentra en el grafo" << RESET << std::endl;
   }
   else{
      grafo.gotoVertex(b);
      if(grafo.getCurrentVertex()==-1){
         std::cin.ignore();
         std::cout << BIRED << "El vértice destino no se encuentra en el grafo" << RESET << std::endl;
      }
      else{
         grafo.gotoEdge(a, b);
         if(grafo.getCurrentEdge()==-1){
            std::cin.ignore();
            std::cout << BIRED << "Esos dos vértices no están conectados" << RESET << std::endl;
         }
         else{
            int coste=0;
            Edge c;
            std::cout << BIBLUE << "El coste actual de lado es " <<RESET <<UNDERLINE<<grafo.currEdge().getData()<<RESET<<std::endl;
            std::cout<<BIPURPLE<<"Introduzca el nuevo peso: "<<RESET;
            std::cin >> coste;

            if(coste!=grafo.currEdge().getData()){
               c=grafo.currEdge();
               c.setData(coste);
               //grafo.getEdgeVector()[grafo.getCurrentEdge()]=c;
               grafo.setEdgeVector(grafo.getCurrentEdge(), c);
               std::cin.ignore();
               std::cout << BIGREEN << "Conexión actualizada correctamente" << RESET <<std::endl;
            }
            else{
               std::cin.ignore();
               std::cout << BIRED << "Se ha introducido el mismo coste" << RESET <<std::endl;
            }
         }
      }
   }
}
void ed::agnadirVertice(ed::Graph & grafo, ed::Punto & a){
   ed::Vertex a1;
   a1.setData(a);
   grafo.gotoVertex(a1);
   if(grafo.getCurrentVertex()!=-1){
      std::cin.ignore();
      std::cout << BIRED << "Ese vértice ya se encuentra en el grafo. No se añade" << RESET <<std::endl;
   }
   else{
      grafo.addVertex(a);
      int i=grafo.getVertexVector().size()-1;
      for(int j=0; j<grafo.getVertexVector().size()-1; j++){
         grafo.addEdge(grafo.getVertexVector()[i], grafo.getVertexVector()[j], ed::distancia(grafo.getVertexVector()[i].getData(), grafo.getVertexVector()[j].getData()));
         grafo.setMatrix(grafo.getVertexVector()[j].getLabel(), grafo.getVertexVector()[i].getLabel(), grafo.getMatrix()[grafo.getVertexVector()[i].getLabel()][grafo.getVertexVector()[j].getLabel()]);
      }
      std::cin.ignore();
      std::cout << BIGREEN << "Vértice añadido correctamente" << RESET << std::endl;
   }
}
ed::Graph ed::kruskal_algorithm(ed::Graph const & grafo, float & coste_total){
   ed::Graph resultante;
   // Vector ordenado que tiene las conexiones del grafo original
   std::vector<ed::Edge> vector_ordenado=grafo.getEdgeVector();
   // Vector que contiene los nodos que estan en un mismo conjunto
   std::vector<int> nodos(grafo.getVertexVector().size(), 0);
   // El objetivo es que todos esten en el mismo conjunto, es decir, que todos los elementos sean = 1
   std::vector<int> objetivo(grafo.getVertexVector().size(), 1);

   // Ordenamos los lados de menor a mayor
   std::sort(vector_ordenado.begin(), vector_ordenado.end());

   // Ponemos el nodo 0 en el conjunto 1
   nodos[0]=1;
   // Añadimos el nodo 0 al grafo resultante
   resultante.addVertex(grafo.getVertexVector()[0].getData());

   int indice=0; //Indice del vertice deseado que se va a poner en el mismo conjunto
   int minimo=0; //Declaramos una variable para obtener el coste minimo
   ed::Edge ladocandidato;
   ed::Edge ladoDeseado;

   while (nodos!=objetivo){
      ladocandidato.setData(-1);
      ladoDeseado.setData(-1);

      minimo=1000;
      for(int i=0; i<nodos.size(); i++){
         if(nodos[i]==1){
            for(int j=0; j<nodos.size(); j++){
               if(nodos[j]==0){
                  for(int k=0; k<vector_ordenado.size(); k++){
                     if(vector_ordenado[k].has(grafo.getVertexVector()[i]) && vector_ordenado[k].has(grafo.getVertexVector()[j])){
                        ladocandidato.setFirstVertex(vector_ordenado[k].first());
                        ladocandidato.setSecondVertex(vector_ordenado[k].second());
                        ladocandidato.setData(vector_ordenado[k].getData());
                        break;
                     }
                  }
                  if(ladocandidato.getData() < minimo){
                     minimo=ladocandidato.getData();
                     ladoDeseado=ladocandidato;
                  }
               }
            }
         }
      }
      if(ladoDeseado.getData()>-1){
         //añadir el vertice que se ha desplegado
         // Se distinguen dos casos, que el vertice que se ha desplegado sea second o first
         // Para saber esto, vemos cual no esta en el conjunto
         // gracias al vector nodos
         if(nodos[ladoDeseado.first().getLabel()]==1){
            indice=ladoDeseado.second().getLabel();

            //Preparamos la etiquetas para el grafo resultante
            resultante.addVertex(ladoDeseado.second().getData());
            ed::Vertex aux=ladoDeseado.second();
            aux.setLabel(resultante.getCurrentVertex());
            ladoDeseado.setSecondVertex(aux);

            resultante.gotoVertex(ladoDeseado.first());
            aux=ladoDeseado.first();
            aux.setLabel(resultante.getCurrentVertex());
            ladoDeseado.setFirstVertex(aux);
         }
         else{
            // En el caso que first sea el que se ha desplegado
            if(nodos[ladoDeseado.second().getLabel()]==1){
               indice=ladoDeseado.first().getLabel();

               resultante.addVertex(ladoDeseado.first().getData());
               ed::Vertex aux=ladoDeseado.first();
               aux.setLabel(resultante.getCurrentVertex());
               ladoDeseado.setFirstVertex(aux);

               resultante.gotoVertex(ladoDeseado.second());
               aux=ladoDeseado.second();
               aux.setLabel(resultante.getCurrentVertex());
               ladoDeseado.setSecondVertex(aux);
            }
         }

         //añadir el lado entre el vertice anterior y el vector conjunto visitados
         // std::cout << "----> " << ladoDeseado.getData() <<'\n';
         // Vamos obteniendo la suma del arbol abarcador minimo
         coste_total+=ladoDeseado.getData();
         // std::cout << "pipo -> " << resultante.getMatrix().size() << '\n';
         // std::cout << ladoDeseado.first().getLabel() <<" " << ladoDeseado.second().getLabel() <<'\n';
         //Añadimos la conexion entre los dos vertices
         resultante.addEdge(ladoDeseado.first(), ladoDeseado.second(), ladoDeseado.getData());
         resultante.setMatrix(ladoDeseado.second().getLabel(), ladoDeseado.first().getLabel(), resultante.getMatrix()[ladoDeseado.first().getLabel()][ladoDeseado.second().getLabel()]);
         // Ponemos el vertice añadido en el mismo conjunto
         nodos[indice]=1;

         //borrar lado del vector ordenado y ordenarlo otra vez
         int etiqueta=0;
         for(; etiqueta<vector_ordenado.size(); etiqueta++){
            if(vector_ordenado[etiqueta].has(ladoDeseado.first()) && vector_ordenado[etiqueta].has(ladoDeseado.second())){
               break;
            }
         }
         std::swap(vector_ordenado[etiqueta], vector_ordenado[vector_ordenado.size()-1]);
         vector_ordenado.resize(vector_ordenado.size()-1);

         std::sort(vector_ordenado.begin(), vector_ordenado.end());
      }
   }
   return resultante;
}
