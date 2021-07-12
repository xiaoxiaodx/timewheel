#ifndef TIMEWHEEL_H
#define TIMEWHEEL_H

#include <vector>
#include "timenode.h"


const unsigned long first_level_tick = 64;
const unsigned long high_level_tick = 32;
const unsigned long level_num = 4;

struct LinkList{


    TimeNode head;
    TimeNode *tail;

};

// 10毫秒精度，100
class TimeWheel
{
public:
    TimeWheel();

    LinkList near[first_level_tick];
    LinkList wheel[level_num][high_level_tick];


    void addNode(TimeNode *node);

    void linkNode(LinkList *link,TimeNode*node);



    void excuteTimer();

    void addjustList();

    void adjustList(int level,int index);

    unsigned long time;//时间轮自定义的时间,索引

    unsigned long actualtime;


};

#endif // TIMEWHEEL_H
