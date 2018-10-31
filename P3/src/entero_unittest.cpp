#include "Entero.hpp"
#include <gtest/gtest.h>
TEST(Entero, Constructor){
   Entero a("5001");
   EXPECT_EQ(a.getNumero(), "5001");

   a.setNumero("2500");
   EXPECT_EQ(a.getNumero(), "2500");

   Entero b;
   EXPECT_EQ(b.getNumero(), "");
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
TEST(Entero, Operadores){
   Entero a("43787897989778978978978787878978954787654356789087654324567"), c;
   c=a;

   EXPECT_EQ(a.getNumero(), c.getNumero());
   // std::cout << "El número es: " << a << std::endl;

   // el operador << va perfecto.
   // std::cin >> c;
   // EXPECT_EQ(c.getNumero(), "20");

   Entero b("3456537898423236743289742398");
   Entero resultado;

   // resultado=a+b;
   // EXPECT_EQ(resultado.getNumero(), "24");

   resultado=a*b;
   EXPECT_EQ(resultado.getNumero(), "151354528893961704825283038561660183275303663347354852745671378829223439161476112891666");
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
