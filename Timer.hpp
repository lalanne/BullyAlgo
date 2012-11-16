#ifndef TIMER_9Q8WJEG9Q8WEJGLQKMASDJGLKMA
#define TIMER_9Q8WJEG9Q8WEJGLQKMASDJGLKMA

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Timer{
    public:
        Timer();

        void start(const unsigned int lap);
        void stop();

    private:
        boost::asio::io_service io;
        boost::asio::deadline_timer timer;
        
};

#endif //TIMER_9Q8WJEG9Q8WEJGLQKMASDJGLKMA
