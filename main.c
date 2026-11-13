#include "stu_header.h"
int main(){
        char ch;
        sll *hptr;
        //hptr=malloc(sizeof(sll*));
        hptr=NULL;
        while(1){
                printf("a/A add new record,d/D delete a record,s/S show the lis,m/M modify a record ,v/V save records ,e/E exit,t/T sort the list ,l/L delete, r/R reverse the list:\n");
                scanf(" %c",&ch);
                if((ch>='A') && (ch<='Z'))
                        ch=ch+32;
                switch(ch){
                        case 'a':addrecord(&hptr);
                                 break;
                        case 'm':modify(hptr);break;
                        case 'v':saverecord(hptr);break;
                        case 'l':deleterecord(&hptr);break;
                        case 'r':reverse(&hptr);break;
                        case 't':sortrecord(&hptr);break;
                        case 's':showlist(hptr);break;
                        case 'e':exitrecord(hptr);break;
                        case 'd':delete(&hptr);break;
                }
                //if(ch=='e')
                //      break;
        }

}