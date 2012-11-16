
#include "Process.hpp"
#include "Printer.hpp"
#include "Message.hpp"

#include <iostream>
#include <string>

using namespace boost;
using namespace std;

Process::Process(const unsigned int id, 
                shared_ptr<Protocol> protocol,
                Communicator* communicator):
                id(id), 
                my_protocol(protocol),
                my_communicator(communicator){
    my_protocol->set_id(id);
    my_protocol->set_process(this);
}

void Process::start(){
    my_thread = thread(ref(*my_protocol));
}

void Process::wait(){
    my_thread.join();
}

unsigned int Process::get_id() const{
    return id;    
}

void Process::set_container(vector<shared_ptr<Process> >* container){
    this->container = container;
    my_protocol->set_container(container);
}

void Process::send_message(Message msg){
    Printer::execute("sending message", id);
    my_communicator->send_message(msg);    
}

Message Process::get_messages(){
    return my_communicator->get_messages();    
}
