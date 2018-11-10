#include "Solucion.hpp"
#include <gtest/gtest.h>
TEST(Solucion, Constructor){
   Solucion a;
   EXPECT_EQ(a.getUtilizados().size(), 0);
}
TEST(Solucion, GettersAndSetters){
   Solucion a;
   Datos datos(20, "../src/opcion-B/materiales.txt");

   a.setDatos(datos);
   EXPECT_EQ(a.getDatos(), datos);
}
TEST(Solucion, mochila){
   Solucion a;
   Datos datos(86, "../src/opcion-B/materiales.txt");
   a.setDatos(datos);

   a.Mochila();
   std::cout << a;
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
