#ifndef PROTOCOL_OQWEJ09FJ8QWE9FJQEF
#define PROTOCOL_OQWEJ09FJ8QWE9FJQEF

#include "Printer.hpp"
#include "Timer.hpp"

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <vector>

class Process;
class Communicator;
class Message;

class Protocol{
    public:
        Protocol(Communicator* communicator);
        ~Protocol();

        void operator()();
        void set_id(const unsigned int id);
        void set_container(std::vector<boost::shared_ptr<Process> >* container);
        void set_process(Process* process);

    private:
        void start_election();
        void processing_received_message(Message msg);
        void process_an_election_message(Message msg);
        void process_an_answer_message(Message msg);


    private:
        unsigned int id;
        std::vector<boost::shared_ptr<Process> >* container;
        Process* my_process;
        Communicator* my_communicator;
        Timer election_timer;
        bool am_i_already_started_an_election;
};

#endif //PROTOCOL_OQWEJ09FJ8QWE9FJQEF
