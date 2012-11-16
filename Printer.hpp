
#ifndef PRINTER_PEHRP9HERGPIUHEGIHUERG
#define PRINTER_PEHRP9HERGPIUHEGIHUERG

#include <iostream>
#include <string>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

class Printer{
    public:
        static void execute(std::string line, const int id);

    private:
        static boost::mutex my_mutex;
};

#endif //PRINTER_PEHRP9HERGPIUHEGIHUERG
