#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zoomrec.h"


/*
Program to generate a report ousing the students' zoom logs
*****************************************************************
* Aly Mohamed   Software Eng    Apr 9 2021      Created file and added conditions
* Aly Mohamed   Software Eng    Apr 10 2021     wrote code except writing to output file
* Aly Mohamed   Software Eng    Apr 9 2021      finalized code and tested
*/



//addZoomRecord
struct ZoomRecord* addZoomRecord(struct ZoomRecord* head,char* name, char* email,char *letter, char* duration){

struct ZoomRecord* s = malloc(sizeof(struct ZoomRecord));

int time=atoi(duration);
char labletter[1];
strcpy(labletter,letter);
char lab=labletter[0];

//adds node to the linkedlist
struct ZoomRecord* cur = head;

//we are creating a new linkedlist
if(head==NULL){

strcpy(s->name,name);
strcpy(s->email,email);
s->durations[lab-'A']=time;	


head=s;

}
else{

//new node has the highest cgpa
if(strcmp(email,head->email)<0){
strcpy(s->name,name);
strcpy(s->email,email);
s->durations[lab-'A']=time;

s->next=head;
head=s;
}
else{
//iterate on nodes
while(cur!=NULL){

//put the current node in between these 2 nodes
if(strcmp(cur->email,email)==0){
//set its next
//set it to be the next of the first node
cur->durations[lab-'A']=time;
return head;
}
else if(strcmp(email,cur->email)>0 && cur->next==NULL){
//add the new node to the end of the list
strcpy(s->name,name);
strcpy(s->email,email);
s->durations[lab-'A']=time;

cur->next=s;
return head;

}
else if(strcmp(email,cur->email)>0 &&strcmp(email,cur->next->email)<0){
//add the new node here
strcpy(s->name,name);
strcpy(s->email,email);
s->durations[lab-'A']=time;
s->next=cur->next;
cur->next=s;
return head;
} 
else{
//or go to next
cur=cur->next;

}

}
}
}
return head;

}


//generateAttendance
void generateAttendance(FILE* out, struct ZoomRecord *head){
  struct ZoomRecord *current_node = head;

        int count =0;
        //number of records we want is 5 maximum
        while (current_node != NULL) {
//       if(current_node->sid != 0)
	fprintf(out, "%s,%s,",current_node->email,current_node->name);
	
	int total =0;
	for(int i=0;i<9;i++){
	if(current_node->durations[i]>40) total++;
	fprintf(out, "%d,",current_node->durations[i]);
	}
       //prints the content of the sorted list to output file
	float percentage =(float) 100*total/9;
	fprintf(out, "%.2f\n",percentage);

        //go to next node
        current_node = current_node->next;
        count++;
         }

}

