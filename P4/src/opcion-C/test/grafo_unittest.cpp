#include "../funcionesAuxiliares.hpp"
#include <gtest/gtest.h>
#include <limits>
TEST(Material, Constructor){
   Graph a, b, max;
   cargarVertices(a, "/home/daniel/Desktop/TERCERO_CARRERA/Algoritmica/P4/src/opcion-C/txt/Andalucia.txt", "/home/daniel/Desktop/TERCERO_CARRERA/Algoritmica/P4/src/opcion-C/txt/matrizAndaluciaCompleta.txt");

   int costeMin=std::numeric_limits<int>::max();
   int coste=0;
   for(int i=0; i < a.getVertexVector().size(); i++){
      b = TSP(a, coste, i);

      if(coste < costeMin){
         costeMin = coste;
         max = b;
      }
      coste=0;
   }
   mostrarGrafo(max, costeMin);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
