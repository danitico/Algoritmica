#include "funcionesAuxiliares.hpp"
#include "Tiempo.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
double combinatorioConRecursividad(int n, int k) {
   if(n==k || k==0){
      return 1;
   }
   else{
      return combinatorioConRecursividad(n-1, k-1) + combinatorioConRecursividad(n-1, k);
   }
}
double combinatorioSinRecursividad(int n, int k){
   double numerador=1, denominador=1;
   if(k==0 || k==n){
      return 1;
   }
   else{
      if(n-k < k){
         for(int i=k+1; i<=n; i++){
            numerador*=i;
         }
         for(int j=1; j<= n-k; j++){
            denominador*=j;
         }
      }
      else{
         for(int i=n-k+1; i<=n; i++){
            numerador*=i;
         }
         for(int j=1; j<=k; j++){
            denominador*=j;
         }
      }
      return numerador/denominador;
   }
}
double combinatorioConRecursividadyTabla(int n, int k, std::vector<std::vector<double> > & datos){
   double combinatorio1=0, combinatorio2=0;
   if(n==k || k==0){
      return 1;
   }
   else{
      if(datos[n][k]==0){
         if(datos[n-1][k-1]==0){
            combinatorio1=combinatorioConRecursividadyTabla(n-1, k-1, datos);
            datos[n-1][k-1]=combinatorio1;
         }
         else{
            combinatorio1=datos[n-1][k-1];
         }

         if(datos[n-1][k]==0){
            combinatorio2=combinatorioConRecursividadyTabla(n-1, k, datos);
            datos[n-1][k]=combinatorio2;
         }
         else{
            combinatorio2=datos[n-1][k];
         }

         datos[n][k]=combinatorio1 + combinatorio2;
         return combinatorio1 + combinatorio2;
      }
      else{
         return datos[n][k];
      }
   }
}
void combinatorios1(){
   std::vector<double> n, t;
   std::vector<std::vector<double> > X;
   Clock c;
   double sumatorio=0.0;
   int n_minimo=0, n_maximo=0, repeticiones=0;

   std::cout << BIPURPLE << "Introduzca el rango inferior de n: " << RESET;
   std::cin >> n_minimo;

   std::cout << BIPURPLE << "Introduzca el rango superior de n: " << RESET;
   std::cin >> n_maximo;

   std::cout << BIPURPLE << "Introduzca el número de repeticiones: " << RESET;
   std::cin >> repeticiones;

   for(int i=n_minimo; i<=n_maximo; i++){
      for(int j=0; j<repeticiones; j++){
         c.start();
         for(int k=0; k<=i; k++){
            combinatorioConRecursividad(i, k);
         }
         c.stop();
         sumatorio+=c.elapsed();
      }
      n.push_back(i);
      t.push_back(sumatorio/repeticiones);
   }

   Datos a(n, t);
   std::vector<double> estimado(n.size(), 0);
   std::vector<double> modificado(n.size(), 0);

   for(int i=0; i<n.size(); i++){
      modificado[i]=pow(2, n[i]);
   }

   a.setModifiedN(modificado);
   a.calculoCoeficientes(X, 2);

   for(int i=0; i<estimado.size(); i++){
      estimado[i]=X[0][0]+X[1][0]*pow(2, n[i]);
   }

   a.setEstimado(estimado);
   a.guardarDatos("SoloRecursividad.txt");
   system("../src/grafico.sh SoloRecursividad");

   std::cout << BIBLUE << "Coeficiente de Determinación: " << RESET << IRED << ITALIC << UNDERLINE <<a.coeficienteDeterminacion()<<RESET<<std::endl;
   std::cout << BIBLUE << "La función es: " << RESET;
   std::cout << IRED << ITALIC << UNDERLINE << X[1][0] << "(2^x)" << std::showpos << X[0][0] << std::noshowpos << RESET << std::endl;

   int x=-1;
   while(x!=0){
      std::cout << BIPURPLE << "Introduzca un numero de elementos para calcular el tiempo estimado(0 para salir): " << RESET;
      std::cin >> x;
      if(x!=0){
         std::cout << BIBLUE << "Con n igual a " << RESET << IRED << ITALIC << UNDERLINE << x << RESET << BIBLUE << " tardará " << RESET << IRED << ITALIC << UNDERLINE;
         double tiempo=X[0][0]+X[1][0]*pow(2, x);
         TiempoAlgoritmos(tiempo);
         std::cout << RESET << BIBLUE << " dias" << RESET << std::endl;
      }
   }
}
void combinatorios2(){
   std::vector<double> n, t;
   std::vector<std::vector<double> > X;
   Clock c;
   double sumatorio=0.0;
   int n_minimo=0, n_maximo=0, repeticiones=0;

   std::cout << BIPURPLE << "Introduzca el rango inferior de n: " << RESET;
   std::cin >> n_minimo;

   std::cout << BIPURPLE << "Introduzca el rango superior de n: " << RESET;
   std::cin >> n_maximo;

   std::cout << BIPURPLE << "Introduzca el número de repeticiones: " << RESET;
   std::cin >> repeticiones;

   for(int i=n_minimo; i<=n_maximo; i++){
      for(int j=0; j<repeticiones; j++){
         c.start();
         for(int k=0; k<=i; k++){
            combinatorioSinRecursividad(i, k);
         }
         c.stop();
         sumatorio+=c.elapsed();
      }
      n.push_back(i);
      t.push_back(sumatorio/repeticiones);
   }
   Datos a(n, t);
   std::vector<double> estimado(n.size(), 0);

   a.setModifiedN(n);
   a.calculoCoeficientes(X, 3);

   for(int i=0; i<estimado.size(); i++){
      estimado[i]=X[0][0]+X[1][0]*n[i]+pow(n[i],2)*X[2][0];
   }

   a.setEstimado(estimado);
   a.guardarDatos("SinRecursividad.txt");
   system("../src/grafico.sh SinRecursividad");

   std::cout << BIBLUE << "Coeficiente de Determinación: " << RESET << IRED << ITALIC << UNDERLINE <<a.coeficienteDeterminacion()<<RESET<<std::endl;
   std::cout << BIBLUE << "La función es: " << RESET;
   std::cout << IRED << ITALIC << UNDERLINE << X[2][0] << "x²" << std::showpos << X[1][0] << "x" << X[0][0] << std::noshowpos << RESET << std::endl;

   int x=-1;
   while(x!=0){
      std::cout << BIPURPLE << "Introduzca un numero de elementos para calcular el tiempo estimado(0 para salir): " << RESET;
      std::cin >> x;
      if(x!=0){
         std::cout << BIBLUE << "Con n igual a " << RESET << IRED << ITALIC << UNDERLINE << x << RESET << BIBLUE << " tardará " << RESET << IRED << ITALIC << UNDERLINE;
         double tiempo=X[0][0]+X[1][0]*x+pow(x,2)*X[2][0];
         TiempoAlgoritmos(tiempo);
         std::cout << RESET << BIBLUE << " dias" << RESET << std::endl;
      }
   }
}
void combinatorios3(){
   std::vector<std::vector<double> > datos;
   std::vector<std::vector<double> > X;
   std::vector<double> n, t;
   Clock c;
   double sumatorio=0.0;
   int n_minimo=0, n_maximo=0, repeticiones=0;

   std::cout << BIPURPLE << "Introduzca el rango inferior de n: " << RESET;
   std::cin >> n_minimo;

   std::cout << BIPURPLE << "Introduzca el rango superior de n: " << RESET;
   std::cin >> n_maximo;

   std::cout << BIPURPLE << "Introduzca el número de repeticiones: " << RESET;
   std::cin >> repeticiones;

   for(int i=n_minimo; i<=n_maximo; i++){
      for(int j=0; j<repeticiones; j++){
         preparacionMatriz(datos, i, i);
         c.start();
         for(int k=0; k<=i; k++){
            combinatorioConRecursividadyTabla(i, k, datos);
         }
         c.stop();
         sumatorio+=c.elapsed();
      }
      n.push_back(i);
      t.push_back(sumatorio/repeticiones);
   }
   Datos a(n, t);
   std::vector<double> estimado(n.size(), 0);

   a.setModifiedN(n);
   a.calculoCoeficientes(X, 3);

   for(int i=0; i<estimado.size(); i++){
      estimado[i]=X[0][0]+X[1][0]*n[i]+pow(n[i],2)*X[2][0];
   }

   a.setEstimado(estimado);
   a.guardarDatos("RecursividadConTabla.txt");
   system("../src/grafico.sh RecursividadConTabla");

   std::cout << BIBLUE << "Coeficiente de Determinación: " << RESET << IRED << ITALIC << UNDERLINE <<a.coeficienteDeterminacion()<<RESET<<std::endl;
   std::cout << BIBLUE << "La función es: " << RESET;
   std::cout << IRED << ITALIC << UNDERLINE << X[2][0] << "x²" << std::showpos << X[1][0] << "x" << X[0][0] << std::noshowpos << RESET << std::endl;

   int x=-1;
   while(x!=0){
      std::cout << BIPURPLE << "Introduzca un numero de elementos para calcular el tiempo estimado(0 para salir): " << RESET;
      std::cin >> x;
      if(x!=0){
         std::cout << BIBLUE << "Con n igual a " << RESET << IRED << ITALIC << UNDERLINE << x << RESET << BIBLUE << " tardará " << RESET << IRED << ITALIC << UNDERLINE;
         double tiempo=X[0][0]+X[1][0]*x+pow(x,2)*X[2][0];
         TiempoAlgoritmos(tiempo);
         std::cout << RESET << BIBLUE << " dias" << RESET << std::endl;
      }
   }
}
void preparacionMatriz(std::vector<std::vector<double> > & datos, int filas, int columnas){
   datos.clear();
   datos.resize(filas+1, std::vector<double>(columnas+1, 0));
   for(int i=0; i<filas+1; i++){
      for(int j=0; j<columnas+1; j++){
         if(i==j || j==0){
            datos[i][j]=1;
         }
      }
   }
}
void Hanoi(int discos, int varilla_origen, int varilla_destino, int & contador){
   if(discos>0){
      Hanoi(discos-1, varilla_origen, 6-varilla_origen-varilla_destino, contador);
      contador++;
      Hanoi(discos-1, 6-varilla_origen-varilla_destino, varilla_destino, contador);
   }
}
void datosHanoi(){
   std::vector<double> n, t;
   std::vector<std::vector<double> > X;
   Clock c;
   double sumatorio=0.0;
   int n_minimo=0, n_maximo=0, repeticiones=0, varilla_origen=0 ,varilla_destino=0, contador=0;

   std::cout << BIPURPLE << "Introduzca el rango inferior de n: " << RESET;
   std::cin >> n_minimo;

   std::cout << BIPURPLE << "Introduzca el rango superior de n: " << RESET;
   std::cin >> n_maximo;

   std::cout << BIPURPLE << "Introduzca la varilla inicial: " << RESET;
   std::cin >> varilla_origen;

   std::cout << BIPURPLE << "Introduzca la varilla destino: " << RESET;
   std::cin >> varilla_destino;

   std::cout << BIPURPLE << "Introduzca el número de repeticiones: " << RESET;
   std::cin >> repeticiones;


   for(int i=n_minimo; i<=n_maximo; i++){
      for(int j=0; j<repeticiones; j++){
         c.start();
         Hanoi(i, varilla_origen, varilla_destino, contador);
         c.stop();
         sumatorio+=c.elapsed();
      }
      n.push_back(i);
      t.push_back(sumatorio/repeticiones);
   }

   Datos a(n, t);
   std::vector<double> estimado(n.size(), 0);
   std::vector<double> modificado(n.size(), 0);

   for(int i=0; i<n.size(); i++){
      modificado[i]=pow(2, n[i]);
   }

   a.setModifiedN(modificado);
   a.calculoCoeficientes(X, 2);

   for(int i=0; i<estimado.size(); i++){
      estimado[i]=X[0][0]+X[1][0]*pow(2, n[i]);
   }

   a.setEstimado(estimado);
   a.guardarDatos("Hanoi.txt");
   system("../src/grafico.sh Hanoi");

   std::cout << BIBLUE << "Coeficiente de Determinación: " << RESET << IRED << ITALIC << UNDERLINE <<a.coeficienteDeterminacion()<<RESET<<std::endl;
   std::cout << BIBLUE << "La función es: " << RESET;
   std::cout << IRED << ITALIC << UNDERLINE << X[1][0] << "(2^x)" << std::showpos << X[0][0] << std::noshowpos << RESET << std::endl;

   int x=-1;
   while(x!=0){
      std::cout << BIPURPLE << "Introduzca un numero de elementos para calcular el tiempo estimado(0 para salir): " << RESET;
      std::cin >> x;
      if(x!=0){
         std::cout << BIBLUE << "Con n igual a " << RESET << IRED << ITALIC << UNDERLINE << x << RESET << BIBLUE << " discos tardará " << RESET << IRED << ITALIC << UNDERLINE;
         double tiempo=X[0][0]+X[1][0]*pow(2, x);
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
