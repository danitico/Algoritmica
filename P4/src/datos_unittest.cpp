#include "Datos.hpp"
#include <gtest/gtest.h>
TEST(Material, Constructor){
   Datos a;
   EXPECT_EQ(a.getVolumenMochila(), 0);
   EXPECT_EQ(a.getMateriales().size(), 0);

   Datos b(30, "../src/materiales.txt");
   EXPECT_EQ(b.getVolumenMochila(), 30);
   EXPECT_NE(b.getMateriales().size(), 0);
}
TEST(Material, GettersAndSetters){
   Datos a;
   a.setVolumenMochila(10);
   EXPECT_EQ(a.getVolumenMochila(), 10);

   a.setMateriales("../src/materiales.txt");
   EXPECT_EQ(a.getMateriales().size(), 5);
}
TEST(Material, ordenacion){
   Datos a(30, "../src/materiales.txt");
   std::vector<Material> materiales;

   materiales = a.getMateriales();
   for(int i=0; i<materiales.size() - 1; i++){
      std::cout << materiales[i].getPrecio() << '\n';
      EXPECT_EQ(materiales[i].getPrecio() >= materiales[i+1].getPrecio(), true);
   }
   std::cout << materiales[materiales.size() - 1].getPrecio() << '\n';
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
