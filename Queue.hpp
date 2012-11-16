#ifndef QUEUE_HR93FIQENWFQWEHF98
#define QUEUE_HR93FIQENWFQWEHF98

#include "Message.hpp"

#include <iostream>
#include <vector>
#include <boost/thread/thread.hpp>
#include <boost/thread/condition.hpp>

template<typename T>
class Queue{
    public:
        Queue(const unsigned int size);

        void put(T data);
        T get();
        bool is_full() const;
        bool is_empty() const;

    private:
        const unsigned int size;
        std::vector<T> container;
        boost::mutex writer_mx;
        boost::mutex reader_mx;
        boost::condition full;
        boost::condition empty;
        unsigned int start;
        unsigned int index;

};

template<typename T>
Queue<T>::Queue(const unsigned int size = 10):size(size){
    container = std::vector<T>(size);    
    start = 0;
    index = 0;
}

template<typename T>
void Queue<T>::put(T data){
    boost::mutex::scoped_lock lock(writer_mx);
    while(is_full()){
        full.wait(writer_mx);
    }
    container[(start+index)%size] = data;
    ++index;
    empty.notify_one();
}

template<typename T>
T Queue<T>::get(){
    boost::mutex::scoped_lock lock(reader_mx);
    while(is_empty()){
       empty.wait(reader_mx);     
    }
    T data = container[start];
    start = (start+1) % size;
    --index;
    full.notify_one();
    return data;
}

template<typename T>
bool Queue<T>::is_full() const{
    if(index==size) return true;
    else return false;
}

template<typename T>
bool Queue<T>::is_empty() const{
    if(index==0) return true;
    else return false;
}

#endif //QUEUE_HR93FIQENWFQWEHF98
