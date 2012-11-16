
#include "Process.hpp"
#include "Protocol.hpp"
#include "Printer.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <string>


using namespace std;
using namespace boost;

const unsigned int NUMBER_OF_PROCESSES = 2;

void wait_for_process(shared_ptr<Process> p){
    cout<<"waiting for process: "<<p->get_id()<<endl;
    p->wait();    
}

void start_processes(shared_ptr<Process> p){
    p->start();    
}

void set_container(shared_ptr<Process> p){
        
}

int main(int argc, const char *argv[]){
    vector<shared_ptr<Process> > process_container;

    Printer::execute("Bully Algorith", -1);

    for(int i=0; i<NUMBER_OF_PROCESSES; ++i){
        Communicator* communicator = new Communicator(i);
        shared_ptr<Protocol> protocol(new Protocol(communicator));
        shared_ptr<Process> process(new Process(i, 
                                                protocol,
                                                communicator));
        process_container.push_back(process);
        process->set_container(&process_container);
    }

    for_each(process_container.begin(), process_container.end(), start_processes);

    //sleep(5);
    cout<<endl<<endl;

    for_each(process_container.begin(), process_container.end(), wait_for_process); 

    Printer::execute("End of Bully Algorith", 0);
    return 0;
}



