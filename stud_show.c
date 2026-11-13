#include "stu_header.h"
void showlist(sll *hptr){
        while(hptr){
                printf("%d %s %f\n",hptr->roll,hptr->name,hptr->percen);
                hptr=hptr->next;
        }

}