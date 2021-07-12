#include "timewheel.h"
#include <QDateTime>
#include <QThread>
#include <QDebug>
TimeWheel::TimeWheel()
{

    time = QDateTime::currentMSecsSinceEpoch();

    actualtime = time;
}



void TimeWheel::excuteTimer(){

    int index = time & (first_level_tick-1);

    LinkList *linklist = &near[index];

    while(linklist->head.next != nullptr){

        linklist->head.next->process();

    }


}


void TimeWheel::addjustList(){


    //





   int divisor = time >> 6;

   int remainer = time & (first_level_tick);

   while (remainer == 0) {

   }

}

void TimeWheel::adjustList(int level,int index)
{



}
//单位毫秒
void TimeWheel::addNode(TimeNode *node)
{


    unsigned long dtime = node->expire - time;


    if(dtime< first_level_tick*10 ){


        linkNode(&near[dtime&(first_level_tick*10-1)],node);

    }else if(dtime < first_level_tick*10*high_level_tick*high_level_tick){

        linkNode(&wheel[0][dtime&(first_level_tick*10*high_level_tick-1)],node);

    }else if(dtime < first_level_tick*10*high_level_tick*high_level_tick*high_level_tick){

        linkNode(&wheel[1][dtime&(first_level_tick*10*high_level_tick*high_level_tick-1)],node);

    }else if(dtime < first_level_tick*10*high_level_tick*high_level_tick*high_level_tick*high_level_tick){

        linkNode(&wheel[2][dtime&(first_level_tick*10*high_level_tick*high_level_tick*high_level_tick-1)],node);

    }else if(dtime < first_level_tick*10*high_level_tick*high_level_tick*high_level_tick*high_level_tick*high_level_tick){

        linkNode(&wheel[3][dtime&(first_level_tick*10*high_level_tick*high_level_tick*high_level_tick*high_level_tick-1)],node);

    }else if(dtime < first_level_tick*10*high_level_tick*high_level_tick*high_level_tick*high_level_tick*high_level_tick*high_level_tick){

        linkNode(&wheel[4][dtime&(first_level_tick*10*high_level_tick-1)],node);
    }


}


void TimeWheel::linkNode(LinkList *link,TimeNode*node)
{

    link->tail->next = node;

    link->tail = node;

    node->next = nullptr;

}
