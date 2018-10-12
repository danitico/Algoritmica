#include "funcionesAuxiliares.hpp"
#include "Tiempo.hpp"
#include <iostream>
#include <fstream>
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
            // std::cout << ":)" << '\n';
            combinatorio1=datos[n-1][k-1];
         }

         if(datos[n-1][k]==0){
            combinatorio2=combinatorioConRecursividadyTabla(n-1, k, datos);
            datos[n-1][k]=combinatorio2;
         }
         else{
            // std::cout << ":))" << '\n';
            combinatorio2=datos[n-1][k];
         }

         datos[n][k]=combinatorio1 + combinatorio2;
         return combinatorio1 + combinatorio2;
      }
      else{
         // std::cout << ":)))" << '\n';
         return datos[n][k];
      }
   }
}
void combinatorios(/*int n_minimo, int n_maximo, int repeticiones*/){
   std::vector<std::vector<double> > datos;
   std::vector<double> n1, t1, n2, t2, n3, t3;
   Clock c1, c2, c3;
   double sumatorio=0.0;
   int n_minimo=0, n_maximo=0, repeticiones=0;

   std::cout << "Introduzca el rango inferior de n: ";
   std::cin >> n_minimo;

   std::cout << "Introduzca el rango superior de n: ";
   std::cin >> n_maximo;

   std::cout << "Introduzca el número de repeticiones: ";
   std::cin >> repeticiones;

   for(int i=n_minimo; i<=n_maximo; i++){
      for(int j=0; j<repeticiones; j++){
         c1.start();
         for(int k=0; k<=i; k++){
            combinatorioConRecursividad(i, k);
         }
         c1.stop();
         sumatorio+=c1.elapsed();
      }
      n1.push_back(i);
      t1.push_back(sumatorio/repeticiones);
   }
   guardarDatos(n1, t1, "SoloRecursividad.txt");

////////////////////////////////////////////////////////////////////////////////

   sumatorio=0.0;
   n_minimo=0, n_maximo=0, repeticiones=0;

   std::cout << "Introduzca el rango inferior de n: ";
   std::cin >> n_minimo;

   std::cout << "Introduzca el rango superior de n: ";
   std::cin >> n_maximo;

   std::cout << "Introduzca el número de repeticiones: ";
   std::cin >> repeticiones;

   for(int i=n_minimo; i<=n_maximo; i++){
      for(int j=0; j<repeticiones; j++){
         c2.start();
         for(int k=0; k<=i; k++){
            combinatorioSinRecursividad(i, k);
         }
         c2.stop();
         sumatorio+=c2.elapsed();
      }
      n2.push_back(i);
      t2.push_back(sumatorio/repeticiones);
   }
   guardarDatos(n2, t2, "SinRecursividad.txt");

////////////////////////////////////////////////////////////////////////////////

   sumatorio=0.0;
   n_minimo=0, n_maximo=0, repeticiones=0;

   std::cout << "Introduzca el rango inferior de n: ";
   std::cin >> n_minimo;

   std::cout << "Introduzca el rango superior de n: ";
   std::cin >> n_maximo;

   std::cout << "Introduzca el número de repeticiones: ";
   std::cin >> repeticiones;

   for(int i=n_minimo; i<=n_maximo; i++){
      for(int j=0; j<repeticiones; j++){
         preparacionMatriz(datos, i, i);
         c3.start();
         for(int k=0; k<=i; k++){
            combinatorioConRecursividadyTabla(i, k, datos);
         }
         c3.stop();
         sumatorio+=c3.elapsed();
      }
      n3.push_back(i);
      t3.push_back(sumatorio/repeticiones);
   }
   guardarDatos(n3, t3, "RecursividadConTabla.txt");
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
      std::cout << varilla_origen << "--->>>" << varilla_destino << '\n';
      Hanoi(discos-1, 6-varilla_origen-varilla_destino, varilla_destino, contador);
   }
}
void guardarDatos(std::vector<double> & n, std::vector<double> & t, std::string fichero){
   std::ofstream file(fichero.c_str());
   if(file.is_open()){
      for(int i=0; i<n.size(); i++){
         file<<n[i]<<" "<<t[i]<<std::endl;
      }
      file.close();
   }
}
