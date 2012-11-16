#ifndef MESSAGE_9W8HERG9W8EHRGJKWERNGKJWEHRGK
#define MESSAGE_9W8HERG9W8EHRGJKWERNGKJWEHRGK

enum MESSAGE_TYPES{
    ELECTION=1,
    COORDINATOR,
    ANSWER
};

class Message{
    public:
        Message();
        Message(const unsigned int type, const unsigned int from);

        unsigned int get_type() const;
        unsigned int get_from() const;
        
    private:
        unsigned int type;
        unsigned int from;
};

#endif
