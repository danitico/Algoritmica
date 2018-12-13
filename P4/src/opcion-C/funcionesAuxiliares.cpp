#include "funcionesAuxiliares.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "../macros.hpp"
void cargarVertices(Graph & grafo, std::string fichero1, std::string fichero2){
   std::ifstream archivo1(fichero1.c_str());
   std::ifstream archivo2(fichero2.c_str());

   if(!archivo1.is_open() || !archivo2.is_open()){
      std::cout<<BIRED<<"Error al abrir los fichero"<<RESET<<std::endl;
   }
   else{
      if(grafo.getVertexVector().size()==0){
         std::string stream;
         while(getline(archivo1, stream, '\n')){
            grafo.addVertex(stream);
         }
         archivo1.close();

         getline(archivo2, stream, '\n');
         getline(archivo2, stream, '\n');
         int indicex=0, indicey;
         while(getline(archivo2, stream, ' ')){
            indicey=0;
            grafo.setMatrix1(indicex, indicey, atoi(stream.c_str()));

            indicey++;
            for(int i=0; i < grafo.getVertexVector().size() - 2; i++){
               getline(archivo2, stream, ' ');
               grafo.setMatrix1(indicex, indicey, atoi(stream.c_str()));
               indicey++;
            }

            getline(archivo2, stream, '\n');
            grafo.setMatrix1(indicex, indicey, atoi(stream.c_str()));
            indicex++;
         }
         archivo2.close();

         for(int i=0; i<grafo.getVertexVector().size(); i++){
            for(int j=i+1; j<grafo.getVertexVector().size(); j++){
               grafo.addEdge(grafo.getVertexVector()[i], grafo.getVertexVector()[j], grafo.getMatrix1()[i][j]);
               grafo.setMatrix(grafo.getVertexVector()[j].getLabel(), grafo.getVertexVector()[i].getLabel(), grafo.getMatrix()[i][j]);
            }
         }
         std::cout<<BIGREEN<<"Fichero cargado con éxito"<<RESET<<std::endl;
      }
      else{
         std::cout << BIRED << "El grafo ya tiene datos. Tiene que borrarlo pra cargar uno nuevo" << RESET <<std::endl;
      }
   }
}
void mostrarGrafo(Graph & grafo, int & coste_total){
   if(grafo.getVertexVector().size()>0){
      std::cout << BIBLUE << "Los vértices del grafo son:" << RESET <<'\n';
      std::cout <<BIYELLOW<< "ETIQUETA" << RESET << BICYAN <<"\tCIUDAD" << RESET <<std::endl;
      for(int i=0; i<grafo.getVertexVector().size(); i++){
         std::cout << BIYELLOW << grafo.getVertexVector()[i].getLabel() << RESET << BICYAN <<"\t\t"<<grafo.getVertexVector()[i].getNombre()<<std::endl;
      }

      std::cout <<std::endl<<BIYELLOW<< "ORIGEN\t\t" << RESET << BICYAN <<"DESTINO\t\t" << RESET << BIBLUE << "DISTANCIA" << RESET <<std::endl;
      for(int j=0; j<grafo.getEdgeVector().size(); j++){
         std::cout << BIYELLOW << grafo.getEdgeVector()[j].first().getNombre() << RESET;
         std::cout << "\t\t";
         std::cout << BICYAN << grafo.getEdgeVector()[j].second().getNombre() << RESET << std::flush;
         std::cout << "\t\t";
         std::cout << BIBLUE << grafo.getEdgeVector()[j].getData() << RESET;
         std::cout << std::endl;
      }

      std::cout << std::endl << BIBLUE << "El coste total del grafo es: " << coste_total << RESET << std::endl;
   }
   else{
      std::cout << BIRED << "El grafo está vacio" << RESET <<std::endl;
   }
}
Graph TSP(Graph & grafo, int & coste_total){
   Graph optimo;
   int coste;
   coste_total=std::numeric_limits<int>::max();

   for(int nodo_inicio=0; nodo_inicio < grafo.getVertexVector().size(); nodo_inicio++){
      coste = 0;
      Graph resultante;
      // Vector ordenado que tiene las conexiones del grafo original
      std::vector<Edge> vector_ordenado=grafo.getEdgeVector();
      // Vector que contiene los nodos que estan en un mismo conjunto
      std::vector<int> nodos(grafo.getVertexVector().size(), 0);
      // El objetivo es que todos esten en el mismo conjunto, es decir, que todos los elementos sean = 1
      std::vector<int> objetivo(grafo.getVertexVector().size(), 1);

      // Ordenamos los lados de menor a mayor
      std::sort(vector_ordenado.begin(), vector_ordenado.end());

      // Ponemos el nodo 0 en el conjunto 1
      nodos[nodo_inicio]=1;
      // Añadimos el nodo 0 al grafo resultante
      resultante.addVertex(grafo.getVertexVector()[nodo_inicio].getNombre());

      int indice=0; //Indice del vertice deseado que se va a poner en el mismo conjunto
      int minimo=0; //Declaramos una variable para obtener el coste minimo
      Edge ladocandidato;
      Edge ladoDeseado;

      while (nodos!=objetivo){
         ladocandidato.setData(-1);
         ladoDeseado.setData(-1);

         minimo=std::numeric_limits<int>::max();
         for(int i=0; i<nodos.size(); i++){
            if(nodos[i]==1){
               if(resultante.getConnectionsVertex(grafo.getVertexVector()[i]) < 2){//al nodo de inicio hay que ponerle < 1
                  for(int j=0; j<nodos.size(); j++){
                     if(i==nodo_inicio && resultante.getConnectionsVertex(grafo.getVertexVector()[nodo_inicio]) >=1){
                        break;
                     }
                     if(nodos[j]==0){
                        for(int k=0; k<vector_ordenado.size(); k++){
                           if(vector_ordenado[k].has(grafo.getVertexVector()[i]) &&
                              vector_ordenado[k].has(grafo.getVertexVector()[j])){
                              ladocandidato.setFirstVertex(vector_ordenado[k].first());
                              ladocandidato.setSecondVertex(vector_ordenado[k].second());
                              ladocandidato.setData(vector_ordenado[k].getData());
                              break;
                           }
                        }
                        if(ladocandidato.getData() < minimo){
                           ladoDeseado=ladocandidato;
                           minimo=ladocandidato.getData();
                        }
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
               resultante.addVertex(ladoDeseado.second().getNombre());
               Vertex aux=ladoDeseado.second();
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

                  resultante.addVertex(ladoDeseado.first().getNombre());
                  Vertex aux=ladoDeseado.first();
                  aux.setLabel(resultante.getCurrentVertex());
                  ladoDeseado.setFirstVertex(aux);

                  resultante.gotoVertex(ladoDeseado.second());
                  aux=ladoDeseado.second();
                  aux.setLabel(resultante.getCurrentVertex());
                  ladoDeseado.setSecondVertex(aux);
               }
            }

            //añadir el lado entre el vertice anterior y el vectice del conjunto visitados
            //Vamos obteniendo la suma de la ruta del viajante
            coste+=ladoDeseado.getData();
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
      //unimos el origen y el destino
      grafo.gotoVertex(resultante.getVertexVector().front());
      int origen=grafo.getCurrentVertex();
      grafo.gotoVertex(resultante.getVertexVector().back());
      int destino=grafo.getCurrentVertex();

      resultante.addEdge(resultante.getVertexVector().front(), resultante.getVertexVector().back(), grafo.getMatrix1()[origen][destino]);
      resultante.setMatrix(resultante.getVertexVector().back().getLabel(), resultante.getVertexVector().front().getLabel(), resultante.getMatrix()[resultante.getVertexVector().front().getLabel()][resultante.getVertexVector().back().getLabel()]);
      coste+=grafo.getMatrix1()[origen][destino];

      if(coste < coste_total){
         coste_total=coste;
         optimo=resultante;
      }
   }

   return optimo;
}
void problemaTSP(){
   Graph grafo, optimo;
   int coste_total;

   cargarVertices(grafo, "../src/opcion-C/txt/Espana.txt", "../src/opcion-C/txt/matrizEspana.txt");
   optimo = TSP(grafo, coste_total);
   mostrarGrafo(optimo, coste_total);
}
