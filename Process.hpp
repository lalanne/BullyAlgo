#ifndef PROCESS_IUQEHWFIUHWEIUHWEF
#define PROCESS_IUQEHWFIUHWEIUHWEF

#include "Protocol.hpp"
#include "Communicator.hpp"

#include <iostream>
#include <boost/thread/thread.hpp>
#include <vector>

class Message;

class Process{
    public:
        Process(const unsigned int id, 
                boost::shared_ptr<Protocol> protocol,
                Communicator* communicator);
        void start();
        void wait();
        unsigned int get_id() const;
        void set_container(std::vector<boost::shared_ptr<Process> >* container);
        void send_message(Message msg);
        Message get_messages();

    private:
       boost::shared_ptr<Protocol> my_protocol;
       boost::thread my_thread;
       const unsigned int id;
       Communicator* my_communicator;
       std::vector<boost::shared_ptr<Process> >* container;
};

#endif //PROCESS_IUQEHWFIUHWEIUHWEF
