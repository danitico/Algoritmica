// Ojo hay que compilar g++ -Wall main.cpp -lrt para incluir las librerías de tiempos.
#ifndef TIEMPO_HPP
#define TIEMPO_HPP
#include <ctime>
#include <cstdio>
#include <cstring> //Para usar memset
#include <stdint.h> // Para usar uint64_t
/*!\brief Models a clock to measure performace.*/
class Clock{
   private:
      timespec _start;
      timespec _stop;
      bool _isStarted;
   public:
      Clock(){
         memset(&_start,0,sizeof(timespec));
         memset(&_stop,0,sizeof(timespec));
         _isStarted=false;
      }
      void start();
      void restart();
      void stop();
      bool isStarted() const;
      uint64_t elapsed() const;
};
#endif
