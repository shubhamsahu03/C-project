#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct student{
    int rno;
    char name[20];
    struct subject
    {
        int scode ;
        char sname[20];
        int mark;
    }sub[5];
    int total;
    char grade;
    float per;
    
}student;
// unique roll no checker

void create(){
    student  *s;
    FILE *fp;
    int n,i,j;
    printf("Enter how many students you want : ");
    scanf("%d",&n);

    s=(student*)calloc(n,sizeof(student));
    fp=fopen("mystudents.txt","a+");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<n;i++) {
        s[i].total=0;
        s[i].per=0;
        printf("Enter Rollno:");
        scanf("%d",&s[i].rno);
        fflush(stdin);
      
        printf("Enter name: ");
        scanf(" %[^\n]s",s[i].name);
        for (j=0;j<5;j++){
            printf("Enter marks of subject%d:",j+1);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total+=s[i].sub[j].mark;
        };
        s[i].per=s[i].total/5.0;
        s[i].grade = (s[i].total / 5) >= 90 ? 'A' :
              (s[i].total / 5) >= 80 ? 'B' :
              (s[i].total / 5) >= 70 ? 'C' :
              (s[i].total / 5) >= 60 ? 'D' : 'F';
        fwrite(&s[i],sizeof(student),1,fp);
    };
    fclose(fp);
}
void display(){
    student sl;
    FILE *fp;
    fp=fopen("mystudents.txt","r");
     
    while(fread(&sl,sizeof(student),1,fp)){
        printf("\n%-5d%-20s",sl.rno,sl.name);
        for(int j=0 ;j<5;j++){
            printf("%4d",sl.sub[j].mark);
        }
        printf("%5d%7.2f%5.2c",sl.total,sl.per,sl.grade);
        
    }
    fclose(fp);
    printf("\n\n");


}
void append(){
    student  *s;
    FILE *fp;
    int n,i,j;
    printf("Enter how many students you want to append : ");
    scanf("%d",&n);

    s=(student*)calloc(n,sizeof(student));
    fp=fopen("mystudents.txt","a");
    for(i=0;i<n;i++) {
        s[i].total=0;
        s[i].per=0;
        printf("Enter Rollno:");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s",s[i].name);
        for (j=0;j<5;j++){
            printf("Enter marks of subject%d:",j+1);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total+=s[i].sub[j].mark;
        };
        s[i].per=s[i].total/5.0;
        s[i].grade = (s[i].total / 5) >= 90 ? 'A' :
              (s[i].total / 5) >= 80 ? 'B' :
              (s[i].total / 5) >= 70 ? 'C' :
              (s[i].total / 5) >= 60 ? 'D' : 'F';
        fwrite(&s[i],sizeof(student),1,fp);
    };
    fclose(fp);
}
void noofrec(){
    student sl;
    FILE *fp;
    fp=fopen("mystudents.txt","r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(student);
    printf("\n\nNO OF RECORDS= %d\n\n",n);
    fclose(fp);
};
void search(){
    student sl;
    FILE *fp;
    int j,rno,found=0;

    fp=fopen("mystudents.txt","r");
    printf("Enter rollno to search:");
    scanf("%d",&rno);
    while(fread(&sl,sizeof(student),1,fp)){
        if (sl.rno==rno){
            found=1;
            printf("\n%-5d%-20s",sl.rno,sl.name);
        for(int j=0 ;j<5;j++){
            printf("%4d",sl.sub[j].mark);
        }
        printf("%5d%7.2f",sl.total,sl.per);
        }
        
    }
    if (!found){
        printf("\nRecord not Found.\n");
    }
    fclose(fp);


}
void update(){
    student sl;
    FILE *fp,*fp1;
    int j,rno,found=0;

    fp=fopen("mystudents.txt","r");
    fp1=fopen("temp.txt","w");

    printf("Enter rollno to update:");
    scanf("%d",&rno);
    while(fread(&sl,sizeof(student),1,fp)){
        if (sl.rno==rno){
            sl.total=0;
            sl.per=0;
            found=1;
            fflush(stdin);
            printf("Enter new name: ");
            scanf("%[^\n]s",sl.name);
            for (j=0;j<5;j++){
                printf("Enter new marks of subject%d:",j+1);
                scanf("%d",&sl.sub[j].mark);
                sl.total+=sl.sub[j].mark;
            }
            sl.per=sl.total/5.0;
            sl.grade = (sl.total / 5) >= 90 ? 'A' :
              (sl.total / 5) >= 80 ? 'B' :
              (sl.total / 5) >= 70 ? 'C' :
              (sl.total / 5) >= 60 ? 'D' : 'F';
        }
            fwrite(&sl,sizeof(student),1,fp1);

        
    }
    fclose(fp);
    fclose(fp1);
    if (found){
        fp1=fopen("temp.txt","r");
        fp=fopen("mystudents.txt","w");
        while(fread(&sl,sizeof(student),1,fp1)){
            fwrite(&sl,sizeof(student),1,fp);
        }
        fclose(fp);
        fclose(fp1);

    }
    else{
        printf("\nRecord not found\n");
    }
}

void delete_rec(){
    student sl;
    FILE *fp,*fp1;
    int j,rno,found=0;

    fp=fopen("mystudents.txt","r");
    fp1=fopen("temp.txt","w");

    printf("Enter rollno to delete:");
    scanf("%d",&rno);
    while(fread(&sl,sizeof(student),1,fp)){
        if (sl.rno==rno){
           
            found=1;
            
            
        }
        else{    fwrite(&sl,sizeof(student),1,fp1);}

        
    }
    fclose(fp);
    fclose(fp1);
    if (found){
        fp1=fopen("temp.txt","r");
        fp=fopen("mystudents.txt","w");
        while(fread(&sl,sizeof(student),1,fp1)){
            fwrite(&sl,sizeof(student),1,fp);
        }
        fclose(fp);
        fclose(fp1);

    }
    else{
        printf("\nRecord not found\n");
    }
}


void sort_name_on_screen(){
      student *s,sl;
    FILE *fp;
    fp=fopen("mystudents.txt","r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(student);
    s=(student*)calloc(n,sizeof(student));
    rewind(fp);
    for(int i=0;i<n;i++){
        fread(&s[i],sizeof(student),1,fp);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;i<n;j++){
            if(strcmp(s[i].name,s[j].name)>0){
                sl=s[i];
                s[i]=s[j];
                s[j]=sl;
            }
        }
    
    }
    for (int i=0;i<n;i++){
        printf("\n%-5d%-20s",s[i].rno,s[i].name);
        for(int j=0 ;j<5;j++){
            printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].per);
    }
    fclose(fp);

}

int main() {
   

    int ch;
    do{
        printf("\n1.CREATE");
        printf("\n2.DISPLAY");
        printf("\n3.APPEND");
        printf("\n4.No.OF RECORDS:");
        printf("\n5.SEARCH");
        printf("\n6.UPDATE");
        printf("\n7.DELETE RECORD");
       
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
        case 4:
            noofrec();
        break;
        case 5:
            search();
        break;
        case 6:
            update();
        break;
        case 7:
            delete_rec();
        break;
        

        }

    }while (ch!=0);

    return 0;
    
    
}