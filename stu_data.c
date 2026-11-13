#include "stu_header.h"
int main(){
        char ch;
        sll *hptr;
        //hptr=malloc(sizeof(sll*));
        hptr=NULL;
        while(1){
                printf("a/A add new record,d/D delete a record,s/S show the lis,m/M modify a record ,v/V save records ,e/E exit,t/T sort the list ,l/L delete, r/R reverse the list\n");
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
void exitrecord(sll *hptr){
        char ch;
        printf("S/s save and exit\n E/e exit without saving\n");
        scanf(" %c",&ch);
        if(ch>='A' && ch<='Z')
                ch=ch+32;
        switch(ch){
                case 's':saverecord(hptr);exit(0);
                case 'e':exit(0);
                default:printf("enter correct option\n");
        }


}

void namesort(sll **hptr){
        sll *p1=*hptr,*p2,t;
        int i,c=0,j;
        sll *node;
        node=*hptr;
        while(node){
                node=node->next;
                c++;
        }
        for(i=0;i<c-1;i++){
                p2=p1->next;
                for(j=0;j<c-1-i;j++){
                        if(strcmp(p1->name,p2->name)>0){
                                t.roll=p1->roll;
                                strcpy(t.name,p1->name);
                                t.percen=p1->percen;

                                p1->roll=p2->roll;
                                strcpy(p1->name,p2->name);
                                p1->percen=p2->percen;

                                p2->roll=t.roll;
                                strcpy(p2->name,t.name);
                                p2->percen=t.percen;
                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }
}
void percensort(sll **hptr){
        sll *p1=*hptr,*p2,t;
        int i,c=0,j;
        sll *node;
        node=*hptr;
        while(node){
                node=node->next;
                c++;
        }
        for(i=0;i<c-1;i++){
                p2=p1->next;
                for(j=0;j<c-1-i;j++){
                        if(p1->percen>p2->percen){
                                t.roll=p1->roll;
                                strcpy(t.name,p1->name);
                                t.percen=p1->percen;

                                p1->roll=p2->roll;
                                strcpy(p1->name,p2->name);
                                p1->percen=p2->percen;

                                p2->roll=t.roll;
                                strcpy(p2->name,t.name);
                                p2->percen=t.percen;
                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }
}

void sortrecord(sll **hptr){
        char ch;
        printf("N/n sort with names\n P/p sort with percentage\n");
        scanf(" %c",&ch);
        if(ch>='A' && ch<='Z')
                ch=ch+32;
        switch(ch){
                case 'n':namesort(hptr);break;
                case 'p':percensort(hptr);break;
                default:printf("entyer correct option\n");
        }
}

void reverse(sll **hptr){
        sll *node,*start,*prev;
        node=*hptr;
        int n=0,i,j;
        while(node){
                n++;
                if(node->next==NULL)
                        start=node;
                node=node->next;
        }
        for(i=0;i<n-1;i++){
                node=*hptr;
                for(j=0;j<n-1-i;j++){
                        prev=node;
                        node=node->next;
                }
                node->next=prev;
        }
        node=*hptr;
        node->next=NULL;
        *hptr=start;
        //showlist(*hptr);
}

void deleterecord(sll **hptr){
        sll *node,*next;
        node=*hptr;
        while(node){ next=node->next;
                free(node);
                node=next;
        }
        //free(*hptr);
        *hptr=NULL;
        printf("deleted succefully\n");
}

void saverecord(sll *hptr){
        sll *node;
        node=hptr;
        FILE *fs=fopen("studen.dat","w");
        while(node){
                fprintf(fs,"%d %s %f\n",node->roll,node->name,node->percen);
                node=node->next;

        }

}

void modify(sll *hptr){
        char ch;
        printf("R/r for search by roll number\n N/n search by name\n P/p for persentage\n");
        scanf(" %c",&ch);
        if(ch>='A' && ch<='B')
                ch=ch+32;
        switch(ch){
                case 'r':rmodify(hptr);break;
                case 'p':pmodify(hptr);break;
                case 'n':nmodify(hptr);break;
                default:printf("enter correct option\n");
        }
}

void nmodify(sll *hptr){
        sll *node;
        node=hptr;
        char n[20];
        printf("name to modify=");
        scanf("%s",n);
        while(node){
                if(strcmp(node->name,n)==0){
                        printf("name=%s\n",node->name);
                        printf("perc=%f\n",node->percen);
                        printf("modifiefd name=");
                        scanf("%s",node->name);
                        printf("modified persen=");

                        scanf("%f",&node->percen);
                        break;
                }
                else
                        node=node->next;
        }
        if(node==NULL)
                printf("not founded\n");
}
void pmodify(sll *hptr){
        sll *node;
        node=hptr;
        float n;
        printf("percentage to modifyi=");
        scanf("%f",&n);
        while(node){
                if(node->percen==n){
                        printf("name=%s\n",node->name);
                        printf("perc=%f\n",node->percen);
                        printf("modifiefd name=");
                        scanf("%s",node->name);
                        printf("modified persen=");
                        scanf("%f",&node->percen);
                        break;
                }
                else
                        node=node->next;
        }
        if(node==NULL)
                printf("not founded\n");
}
void rmodify(sll *hptr){
        sll *node;
        node=hptr;
        int n;
        printf("number to modifyi=");
        scanf("%d",&n);
        while(node){
                if(node->roll==n){
                        printf("name=%s\n",node->name);
                        printf("perc=%f\n",node->percen);
                        printf("modifiefd name=");
                        scanf("%s",node->name);
                        printf("modified persen=");
                        scanf("%f",&node->percen);
                        break;
                }
                else
                        node=node->next;
        }
        if(node==NULL)
                printf("not founded\n");
}
void delete(sll **hptr){
        char ch;
:set number
        printf("R/r enter roll number to delete\nN/n enter name to delete");

        scanf(" %c",&ch);
        if((ch>='A') && (ch<='Z'))
                ch=ch+32;
        switch(ch){
                case 'r':roldelete(hptr);break;
                case 'n':namedelete(hptr);break;
                default:printf("enter correct option");
                        break;
        }

}

void namedelete(sll **hptr){
        sll *node,*prev;
        node=*hptr;
        char n[20];
        printf("enter name=");
        scanf("%s",n);
        if((node->next==NULL) && (strcmp(node->name,n)==0)){
                free(node);
                *hptr=NULL;
        }
        else{
                if(strcmp(node->name,n)==0){
                        *hptr=node->next;
                        free(node);
                }
                else{
                        node=node->next;
                        prev=*hptr;
                        while(node){
                                if(strcmp(node->name,n)!=0){
                                        node=node->next;
                                        prev=prev->next;
                                }
                                else{
                                        prev->next=node->next;
                                        free(node);
                                        printf("deleted\n");
                                        break;
                                }
                        }
                        if(node==NULL)
                                printf("not detected\n");
                }
        }
}
void roldelete(sll **hptr){
        sll *node,*prev;
        node=*hptr;
        int n;
        printf("enter roll number=");
        scanf("%d",&n);
        if((node->next==NULL) && (node->roll==n)){
                free(node);
                *hptr=NULL;
        }
        else{
                if(node->roll==n){
                        *hptr=node->next;
                        free(node);
                }
                else{
                        node=node->next;
                        prev=*hptr;
                        while(node){
                                if(node->roll!=n){
                                        node=node->next;
                                        prev=prev->next;
                                }
                                else{
                                        prev->next=node->next;
                                        free(node);
                                        printf("deleted");
                                        break;
                                }
                        }
                        if(node==NULL)
                                printf("not detected");
                }
        }


}




void showlist(sll *hptr){
        while(hptr){
                printf("%d %s %f\n",hptr->roll,hptr->name,hptr->percen);
                hptr=hptr->next;
        }

}

void addrecord(sll **hptr){
        static int i=1,min=1,max;
        int j;
        sll *new,*node,*prev;
        node=*hptr;
        new=malloc(sizeof(sll));
        printf("enter name and value ");
        scanf("%s%f",new->name,&new->percen);
        if(*hptr==NULL){
                i=1;
                new->roll=i++;
                *hptr=new;
                new->next=NULL;

                node=*hptr;
        }
        else{
                node=*hptr;

                for(j=1;j<i;j++){

                        node=*hptr;
                        while(node){
                                if(node->roll==j){
                                        break;
                                }
                                else
                                        node=node->next;
                        }
                        if(node==NULL){
                                break;

                        }
                }
                if(j==i)
                        i++;
                new->roll=j;
                node=*hptr;
                while(node->next)
                        node=node->next;
                node->next=new;
                new->next=NULL;
        }
}