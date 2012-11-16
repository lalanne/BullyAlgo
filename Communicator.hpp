#ifndef COMMUNICATOR_QIER98ER9NERNEIRNV
#define COMMUNICATOR_QIER98ER9NERNEIRNV

#include "Queue.hpp"

class Process;
class Message;

class Communicator{
    public:
        Communicator(const unsigned int id);

        void send_message(Message value);
        Message get_messages();
        void send_election_message_to_bigger_processes(std::vector<boost::shared_ptr<Process> >* container);

    private:
        const unsigned int id;
        Queue<Message> queue;
};

#endif //COMMUNICATOR_QIER98ER9NERNEIRNV
