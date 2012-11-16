
#include "Message.hpp"

Message::Message():type(0){}
Message::Message(const unsigned int type, const unsigned int from):type(type), from(from){}

unsigned int Message::get_type() const{
    return type;    
}

unsigned int Message::get_from() const{
    return from;    
}
