#include "Entero.hpp"
#include "funciones.hpp"
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
   Entero b, c;

   a.partirCadena(b, c);
   EXPECT_EQ(b.getNumero(), "202");
   EXPECT_EQ(c.getNumero(), "030");

   Entero a1("2020301");
   a1.partirCadena(b, c);
   EXPECT_EQ(b.getNumero(), "2020");
   EXPECT_EQ(c.getNumero(), "301");
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
   Entero b("25000");
   EXPECT_EQ(a.multiplicarPotencia10(3), b);
}
TEST(Entero, Operadores){
   Entero a("43787897989778978978978787878978954787654356789087654324567"), c;
   Entero b("3456537898423236743289742398");
   Entero resultado;
   c=a;

   EXPECT_EQ(a, c);
   EXPECT_EQ(a==c, true);

   resultado=a*b;
   EXPECT_EQ(resultado.getNumero(), "151354528893961704825283038561660183275303663347354852745671378829223439161476112891666");

   resultado=a+b;
   EXPECT_EQ(resultado.getNumero(), "43787897989778978978978787878982411325552780025830944066965");
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
