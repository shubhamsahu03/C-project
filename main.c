#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SUBJECT_NAME 50


typedef struct student{
    int rno;
    char name[20];
    struct subject
    {
        int scode ;
        char sname[20];
        int mark;
    }sub[10];
    int total;
    float per;
    
}student;

void create(){
    student  *s;
    int n,i,j;
    printf("Enter how many students you want : ");
    scanf("%d",&n);

    s=(student*)calloc(n,sizeof(student));
    for (i=0;i<n;i++){
        printf("Enter marks of %s")
    }






}
void display(){}
void append(){}



int main() {
    FILE *fp;
    char subjects_string[MAX_SUBJECT_NAME * 10];
    char *subject;
    char subjects[10][MAX_SUBJECT_NAME];
    int i = 0;

    fp = fopen("subjects.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fgets(subjects_string, MAX_SUBJECT_NAME * 10, fp);
    fclose(fp);

    subject = strtok(subjects_string, ", ");
    while (subject != NULL && i < 10) {
        strcpy(subjects[i], subject);
        subject = strtok(NULL, ", ");
        i++;
    }
    int ch;
    do{
        printf("\n1.CREATE");
        printf("\nDISPLAY");
        printf("\n3.APPEND");
        printf("\n0.Exit");
        printf("\nEnter your Choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        create();
        break;
        case 2:
            display();
         break;
        case 3:
            append();
        break;        
        }
    }while (ch!=0);

    return 0;
    
    
}