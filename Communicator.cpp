
#include "Communicator.hpp"
#include "Process.hpp"

#include <iostream>

using namespace std;
using namespace boost;

Communicator::Communicator(const unsigned int id):id(id){}

void Communicator::send_message(Message value){
    queue.put(value);    
}

Message Communicator::get_messages(){
    return queue.get();
}

void Communicator::send_election_message_to_bigger_processes(vector<shared_ptr<Process> >* container){
    for(int i=id; i<container->size(); ++i ){
        Message msg(ELECTION, id);
        ((*container)[i])->send_message(msg);     
    }
}




