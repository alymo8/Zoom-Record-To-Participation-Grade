#include<stdio.h>
#include<stdlib.h>
#include "zoomrec.h"
#include<string.h>
//#include "zoomrecs.c"

int main(int argc, char* argv[]){

//wrong input
if(argc!=3) {
printf("Usage ./labapp <sourcecsv> <outputcsv>\n");

return 1;
}


struct ZoomRecord *head=NULL;

char line[1024];

FILE *file = fopen(argv[1], "rt");

fgets(line,1024,file);
//get lines from the file
while(fgets(line,1024,file)){

char string[100];
for(int i=0;i<strlen(line);i++){
string[i]=line[i];
}

//ex first field is id, 2nd field is email..

char* email=strtok(string,",");
char* name=strtok(NULL,",");

//create a new student and call addzoomrec
//divide the input line to match the zoomrecord
char* lab=strtok(NULL,",");
char* duration=strtok(NULL,",");

int time=atoi(duration);


//printf("%s,%s,%s,%d\n",email,name,lab,time);
head=addZoomRecord(head, name, email, lab, duration); 

}
if(head!=NULL){
FILE *out;
//open the output file
char* filename = argv[2];

out = fopen(filename,"w+");
//print header line
fprintf(out, "User Email,(Original Name),A,B,C,D,E,F,G,H,I,Attendance(Percentage)\n");

generateAttendance(out,head);

}
}

