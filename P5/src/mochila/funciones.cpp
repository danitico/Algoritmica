#include "funciones.hpp"
#include "Tiempo.hpp"
#include "Estadistica.hpp"
#include "Solucion.hpp"
#include "../macros.hpp"
void problemaMochila(){
   Solucion solucion;
   Datos datos;

   std::cin >> datos;

   if(datos.getMateriales().size()==0){
      std::cout << BIRED << "La lista de Materiales está vacía" << RESET << std::endl;
   }
   else{
      solucion.setDatos(datos);
      std::vector<std::vector<float> > tabla(datos.getMateriales().size() + 1, std::vector<float>(datos.getVolumenMochila() + 1, 0.0));
      solucion.tablaMochila(tabla);
      solucion.solucionMochila(tabla);
      std::cout << solucion;
   }
   std::cin.ignore();
}
void rendimientoMochila(){
   Clock reloj;
   Datos datos;
   Solucion solucion;
   std::vector<Material> materiales;
   std::vector<double> n;
   std::vector<double> tiempo;
   std::vector<std::vector<float> > tabla;
   int volumenMochila, volumen, precio, repeticiones;
   double tiempoElapsed=0.0;

   std::cout << BIPURPLE << "Introduzca el número de repeticiones: " << RESET;
   std::cin >> repeticiones;

   for(int i=100; i<=200; i++){
      for(int k=0; k<repeticiones; k++){
         tabla.resize(0);
         materiales.resize(0);
         for(int j=0; j<i; j++){
            volumen=rand()%101;
            precio=rand()%101;
            volumenMochila+=volumen;

            materiales.push_back(Material(j, volumen, precio));
         }

         datos.setMateriales(materiales);
         datos.setVolumenMochila(volumenMochila/2);
         solucion.setDatos(datos);
         tabla.resize(datos.getMateriales().size() + 1, std::vector<float>(datos.getVolumenMochila() + 1, 0.0));

         reloj.start();
         solucion.tablaMochila(tabla);
         reloj.stop();

         tiempoElapsed+=reloj.elapsed();
      }
      n.push_back(i);
      tiempo.push_back(tiempoElapsed/repeticiones);
   }

   Estadistica estadistica(n, tiempo);
   std::vector<double> estimado(n.size(), 0);
   std::vector<std::vector<double> > X;

   estadistica.setModifiedN(n);
   estadistica.calculoCoeficientes(X, 3);

   for(int i=0; i<estimado.size(); i++){
      estimado[i]=X[0][0]+X[1][0]*n[i]+pow(n[i],2)*X[2][0];
   }

   estadistica.setEstimado(estimado);
   estadistica.guardarDatos("mochila.txt");
   system("../src/mochila/grafico.sh mochila");

   std::cout << BIBLUE << "Coeficiente de Determinación: " << RESET << IRED << ITALIC << UNDERLINE <<estadistica.coeficienteDeterminacion()<<RESET<<std::endl;
   std::cout << BIBLUE << "La función es: " << RESET;
   std::cout << IRED << ITALIC << UNDERLINE << std::showpos << X[2][0] << "x²" << X[1][0] << "x" << X[0][0] << std::noshowpos << RESET << std::endl;

   int x=-1;
   while(x!=0){
      std::cout << BIPURPLE << "Introduzca un numero de elementos para calcular el tiempo estimado(0 para salir): " << RESET;
      std::cin >> x;
      if(x!=0){
         std::cout << BIBLUE << "Con n igual a " << RESET << IRED << ITALIC << UNDERLINE << x << RESET << BIBLUE << " tardará " << RESET << IRED << ITALIC << UNDERLINE;
         double tiempo=X[0][0]+X[1][0]*x+X[2][0]*pow(x, 2);
         TiempoAlgoritmos(tiempo);
         std::cout << RESET << BIBLUE << " dias" << RESET << std::endl;
      }
   }
}
void TiempoAlgoritmos(double & tiempo){
   tiempo=tiempo/pow(10, 6);
   unsigned long long int tiempoEntero = tiempo;

   unsigned long long int minutos= tiempoEntero/60;
   unsigned long long int segundos= tiempoEntero%60;
   unsigned long long int horas= minutos/60;
   minutos=minutos%60;
   unsigned long long int dias = horas/24;
   horas=horas%24;
   unsigned long long int agnos = dias / 365;
   dias=dias%365;

   std::cout << agnos << "años, " << dias << " dias, " << horas << " horas, " << minutos << " minutos y " << (float)segundos + (float)tiempo - (float)tiempoEntero << " segundos." << std::endl;
}
