#ifndef ESTADISTICA_HPP
#define ESTADISTICA_HPP
#include <vector>
#include <string>
#include <cmath>
class Estadistica{
   private:
      std::vector<double> n;
      std::vector<double> n_modificado;
      std::vector<double> t;
      std::vector<double> estimado;
   public:
      inline Estadistica(std::vector<double> & n, std::vector<double> & t){
         setN(n);
         setT(t);
      }
      inline void setN(std::vector<double> & n){
         this->n=n;
      }
      inline void setModifiedN(std::vector<double> & n_modificado){
         this->n_modificado=n_modificado;
      }
      inline void setT(std::vector<double> & t){
         this->t=t;
      }
      inline void setEstimado(std::vector<double> & estimado){
         this->estimado=estimado;
      }
      void guardarDatos(std::string fichero);
      double coeficienteDeterminacion();
      double sumatorio(int a, int b);
      void calculoCoeficientes(std::vector<std::vector<double> > & X, int orden);
};
#endif
