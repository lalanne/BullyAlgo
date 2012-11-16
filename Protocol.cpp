
#include <iostream>

#include "Protocol.hpp"
#include "Process.hpp"
#include "Printer.hpp"
#include "Communicator.hpp"

using namespace std;
using namespace boost;

const unsigned int ANSWER_TIMEOUT_MS = 320;

Protocol::Protocol(Communicator* communicator):my_communicator(communicator){}

Protocol::~Protocol(){
    cout<<"End Protocol "<<id<<endl;    
}

void Protocol::operator()(){
    Printer::execute("executing", id);
    while(true){
        start_election();
        Printer::execute("waiting....... ", id);
        Message msg = my_process->get_messages();
        cout<<id<<" received "<<msg.get_type()<<endl;
        processing_received_message(msg);
        
    }
}

void Protocol::set_id(const unsigned int id){
    this->id=id;
}

void Protocol::set_container(vector<shared_ptr<Process> >* container){
    this->container = container;    
}

void Protocol::set_process(Process* process){
    my_process = process;    
}

void Protocol::processing_received_message(Message msg){
    if(msg.get_type()==ELECTION){
        process_an_election_message(msg);
    }
    else if(msg.get_type()==ANSWER){
        process_an_answer_message(msg);    
    }
}

void Protocol::process_an_election_message(Message msg){
    Printer::execute("ELECTION message received", id);         
    Message answer(ANSWER, id);
    (*container)[msg.get_from()]->send_message(answer);
}

void Protocol::process_an_answer_message(Message msg){
    Printer::execute("ANSWER message received", id);    
    am_i_already_started_an_election = false;
    election_timer.stop();

    /*coordinator*/
}

void Protocol::start_election(){    
    my_communicator->send_election_message_to_bigger_processes(container);
    am_i_already_started_an_election=true;
    Printer::execute("Starting timer for election", id);

    election_timer.start(ANSWER_TIMEOUT_MS);
}


