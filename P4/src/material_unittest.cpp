#include "Material.hpp"
#include <gtest/gtest.h>
TEST(Material, Constructor){
   Material a;
   EXPECT_EQ(a.getEtiqueta(), 0);
   EXPECT_EQ(a.getVolumen(), 0);
   EXPECT_EQ(a.getPrecio(), 0);
   EXPECT_EQ(a.getDisponible(), false);

   Material b(1, 2, 3, true);
   EXPECT_EQ(b.getEtiqueta(), 1);
   EXPECT_EQ(b.getVolumen(), 2);
   EXPECT_EQ(b.getPrecio(), 3);
   EXPECT_EQ(b.getDisponible(), true);
}
TEST(Material, GettersAndSetters){
   Material a;

   a.setEtiqueta(1);
   EXPECT_EQ(a.getEtiqueta(), 1);

   a.setVolumen(2);
   EXPECT_EQ(a.getVolumen(), 2);

   a.setPrecio(3);
   EXPECT_EQ(a.getPrecio(), 3);

   a.setDisponible(true);
   EXPECT_EQ(a.getDisponible(), true);
}
TEST(Material, getTotal){
   Material a(1, 20, 30, true);
   EXPECT_EQ(a.getTotal(), 600);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
