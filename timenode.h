#ifndef TIMENODE_H
#define TIMENODE_H


class TimeNode
{
public:
    TimeNode();


    TimeNode *next;

    unsigned long expire;

    void process();

};

#endif // TIMENODE_H
