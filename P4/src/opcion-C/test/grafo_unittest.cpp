#include "../funcionesAuxiliares.hpp"
#include <gtest/gtest.h>
TEST(Material, Constructor){
   Graph a, b;
   cargarVertices(a, "/home/daniel/Desktop/TERCERO_CARRERA/Algoritmica/P4/src/opcion-C/txt/nuevo1.txt", "/home/daniel/Desktop/TERCERO_CARRERA/Algoritmica/P4/src/opcion-C/txt/nuevo.txt");

   int tam=a.getMatrix1().size();
   for(int i=0; i<tam; i++){
      for(int j=0; j<tam; j++){
         std::cout << a.getMatrix1()[i][j] << " ";
      }
      std::cout << std::endl;
   }

   float coste=0.0;
   b = kruskal_algorithm(a, coste);
   mostrarGrafo(b);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
