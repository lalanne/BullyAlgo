
#include "Timer.hpp"

#include <iostream>

using namespace boost;
using namespace std;


void print(const boost::system::error_code& /*e*/)
{
  std::cout << "Hello, world!\n";
}

Timer::Timer():timer(io){}

void Timer::start(const unsigned int ms){
    timer.expires_from_now(posix_time::milliseconds(ms));    
    timer.async_wait(print);
    io.run();
}

void Timer::stop(){
    timer.cancel();
    io.reset();    
}

