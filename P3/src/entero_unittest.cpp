#include "Entero.hpp"
#include <gtest/gtest.h>
TEST(Entero, Constructor){
   Entero a("5001");
   EXPECT_EQ(a.getNumero(), "5001");

   a.setNumero("2500");
   EXPECT_EQ(a.getNumero(), "2500");
}
TEST(Entero, partirCadena){
   Entero a("202030");
   std::string b, c;

   a.partirCadena(b, c);
   EXPECT_EQ(b, "202");
   EXPECT_EQ(c, "030");

   b=c="";

   Entero a1("2020301");
   a1.partirCadena(b, c);
   EXPECT_EQ(b, "2020");
   EXPECT_EQ(c, "301");
}
TEST(Entero, agregarCerosFinal){
   Entero a("25");
   a.agregarCerosFinal(3);

   EXPECT_EQ(a.getNumero(), "25000");
}
TEST(Entero, agregarCerosDelante){
   Entero a("25");
   a.agregarCerosDelante(5);

   EXPECT_EQ(a.getNumero(), "0000025");
}
TEST(Entero, quitarCerosNoSignificativos){
   Entero a("000000250");
   a.quitarCerosNoSignificativos();

   EXPECT_EQ(a.getNumero(), "250");
}
TEST(Entero, multiplicarPotencia10){
   Entero a("25");
   EXPECT_EQ(a.multiplicarPotencia10(3), "25000");
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
