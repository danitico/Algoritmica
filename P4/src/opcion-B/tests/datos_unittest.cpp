#include "../Datos.hpp"
#include <gtest/gtest.h>
TEST(Material, Constructor){
   Datos a;
   EXPECT_EQ(a.getVolumenMochila(), 0);
   EXPECT_EQ(a.getMateriales().size(), 5);

   Datos b(30);
   EXPECT_EQ(b.getVolumenMochila(), 30);
   EXPECT_NE(b.getMateriales().size(), 0);
}
TEST(Material, GettersAndSetters){
   Datos a;
   std::vector<Material> materiales;
   a.setVolumenMochila(10);
   EXPECT_EQ(a.getVolumenMochila(), 10);

   materiales = a.getMateriales();
   for(int i=0; i<materiales.size() - 1; i++){
      EXPECT_EQ(materiales[i].getPrecio() >= materiales[i+1].getPrecio(), true);
   }
   EXPECT_EQ(a.getMateriales().size(), 5);
}
TEST(Material, ordenacion){
   Datos a(30);
   std::vector<Material> materiales;

   materiales = a.getMateriales();
   for(int i=0; i<materiales.size() - 1; i++){
      std::cout << materiales[i] << std::endl;
      EXPECT_EQ(materiales[i].getPrecio() >= materiales[i+1].getPrecio(), true);
   }
   std::cout << materiales[materiales.size() - 1] << std::endl;
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
