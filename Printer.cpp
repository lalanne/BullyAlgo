
#include "Printer.hpp"

using namespace std;
using namespace boost;

mutex Printer::my_mutex;

void Printer::execute(string line, const int id){
    boost::mutex::scoped_lock lock(my_mutex);
    cout<<"["<<id<<"]"<<line<<endl;
}
