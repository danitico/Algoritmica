#include "Tiempo.hpp"
#include <cassert>
void Clock::start(){
   assert (!isStarted());
   clock_gettime (CLOCK_REALTIME, &_start);
   _isStarted=true;
}
void Clock::restart(){
   clock_gettime (CLOCK_REALTIME, &_start);
   _isStarted=true;
}
void Clock::stop(){
   assert (_isStarted);
   clock_gettime (CLOCK_REALTIME, &_stop);
   _isStarted=false;
}
bool Clock::isStarted() const{
   return _isStarted;
}
uint64_t Clock::elapsed() const{
   assert (!_isStarted);
   uint64_t startT = (uint64_t)_start.tv_sec * 1000000LL + (uint64_t)_start.tv_nsec / 1000LL;
   uint64_t stopT = (uint64_t)_stop.tv_sec * 1000000LL + (uint64_t)_stop.tv_nsec / 1000LL;
   return stopT-startT;
}
