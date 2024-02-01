#include<stdio.h>
#include<string.h>

struct studentcourses{
    char course_name[20];
    char grade[10];
};

struct student{
    char full_name[50];
    char department[10];
    char index_no[10];
    int count;
    struct studentcourses cou[10];
};

struct coursedetails{
    char course_Id[10];
    char course_name[20];
    float credit;
};

char menu(){
    char select_option;

        printf("\t\t\t\t\t 1. Add Student Details\n");
        printf("\t\t\t\t\t 2. View Student Details\n");
        printf("\t\t\t\t\t 3. Add Course Details\n");
        printf("\t\t\t\t\t 4. View Course Details\n");
        printf("\t\t\t\t\t 5. Exit\n");
        printf("\t\t\t\t\t ________________________\n");

        printf("\nSelect Your Option: ");
        scanf(" %c",&select_option);

while(select_option!='1' && select_option!='2' && select_option!='3' && select_option!='4' && select_option!='5'){
    printf("\n\aWrong Selection, Please Select (1,2,3,4,5) :  ");
    scanf(" %c",&select_option);
    }
return select_option;
}

void createsaveFile(){
    FILE *studentDetails;
    FILE *coursedetails;

if(studentDetails=fopen("information.txt","r+")==NULL){
    studentDetails=fopen("information.txt","w");
    fclose(studentDetails);
}
if(coursedetails=fopen("coursedetails.txt","r+")==NULL){
    coursedetails=fopen("coursedetails.txt","w");
    fclose(coursedetails);
}
}
void enterStudentDetails(){
    system("cls");
    printf("\t\t\t\t\t***********************\n");
    printf("\t\t\t\t\t ADD STUDENT DETAILS.\n");
    printf("\t\t\t\t\t***********************\n\n\n");
    FILE *studentDetails;

struct student student;
char command;
int Subject_count;
    printf("\t\t\t\tEnter student full_name : ");
    scanf(" %[^\n]s",student.full_name);
    printf("\t\t\t\tEnter student Department: ");
    scanf(" %[^\n]s",student.department);
    printf("\t\t\t\tEnter student Index NO  : ");
    scanf(" %[^\n]s",student.index_no);
    studentDetails=fopen("information.txt","a");
    printf("\n\t\t\t\tNumber of courses     : ");
    scanf("%d",&Subject_count);
    student.count=Subject_count;
    printf("\n");

for(int m=0;m<Subject_count;m++){
    printf("\t\t\t\tEnter NO %d Course Name : ",m+1);
    scanf(" %[^\n]s",student.cou[m].course_name);
    printf("\t\t\t\tEnter The grade ('A', 'B', 'C', 'D', 'E' Or if absent 'AB'): ");
    scanf("%s",student.cou[m].grade);
    printf("\n");
}
    fwrite(&student,sizeof(struct student),1,studentDetails);
    fclose(studentDetails);
    printf("Detail has been saved!!");
    printf("\n\nDo you want to enter a new student(y/n) ");
    scanf(" %c",&command);

if(command=='y'||command=='Y')
    enterStudentDetails();
else
    main();
}

void updatestudentDetails(){

int found=0;
char command;
    FILE *studentDetails,*tempFile;
struct student student;
char index_no[20];
    studentDetails=fopen("information.txt","r");
    tempFile=fopen("tempdata.txt","w");
    printf("\nEnter student Index NO :- ");
    scanf("%s",index_no);
while(fread(&student,sizeof(struct student),1,studentDetails)){
    if(strcmp(index_no,student.index_no)==0){
        found=1;
        int totalcredit=0;
        float creditGrade=0.0,totalGPA=0.0;
        int Subject_count;
        printf("\t\t\t\tUpdate student full_name      : ");
        scanf(" %[^\n]s",student.full_name);
        printf("\t\t\t\tUpdate student Department: ");
        scanf(" %[^\n]s",student.department);
        printf("\t\t\t\tUpdate student Index NO  : ");
        scanf(" %[^\n]s",student.index_no);
        studentDetails=fopen("information.txt","a");
        printf("\n\t\t\t\tUpdate Number of courses     : ");
        scanf("%d",&Subject_count);
        student.count=Subject_count;
        printf("\n");

        for(int m=0;m<Subject_count;m++){
            printf("\t\t\t\tEnter NO %d Course Name : ",m+1);
            scanf(" %[^\n]s",student.cou[m].course_name);
            printf("\t\t\t\tEnter The grade ('A', 'B', 'C', 'D', 'E' Or if absent 'AB'): ");
            scanf("%s",student.cou[m].grade);
            printf("\n");
        }
    }
    fwrite(&student,sizeof(struct student),1,tempFile);
    }
    fclose(studentDetails);
    fclose(tempFile);

    if(found==1){
        tempFile=fopen("tempdata.txt","r");
        studentDetails=fopen("information.txt","w");
        while(fread(&student,sizeof(struct student),1,tempFile)){
            fwrite(&student,sizeof(struct student),1,studentDetails);
        }
        fclose(studentDetails);
        fclose(tempFile);
    }else{
        printf("\n\t\t\t\tIndex No not found!!!\n\n");
        fclose(studentDetails);
    }
        printf("Exit press(Y), View another student detail press(V), Want to edit above detail press(E) ");
        scanf(" %c",&command);
        if(command=='y'||command=='Y')
            main();
        else if(command=='v'||command=='V')
            viewStudentDetails();
        else if(command=='e'||command=='E')
            updatestudentDetails();

}

void viewStudentDetails(){
    system("cls");
    printf("\t\t\t\t\t**********************************\n");
    printf("\t\t\t\t\t\tSTUDENT DETAILS & GPA\n");
    printf("\t\t\t\t\t**********************************\n\n\n");

char command;
int found=0;
    FILE *studentDetails,*coursedetails;
struct student student;
struct coursedetails cde;
char index_no[20];
    studentDetails=fopen("information.txt","r");
    coursedetails=fopen("coursedetails.txt","r");
    printf("\nEnter student Index NO :- ");
    scanf("%s",index_no);
while(fread(&student,sizeof(struct student),1,studentDetails)){
if(strcmp(index_no,student.index_no)==0){
    found=1;
int totalcredit=0;
float creditGrade=0.0,totalGPA=0.0;
    printf("\t\t\t\tfull_name : %s\n\n",student.full_name);
    printf("\t\t\t\tIndex NO  :%s\n\n",student.index_no);
    printf("\t\t\t\tDepartment: %s\n\n",student.department);
    printf("\t\t\t\tCourses & Grades \n");
for(int c=0;c<student.count;c++){
    while(fread(&cde,sizeof(struct coursedetails),1,coursedetails)){
        if(strcmp(student.cou[c].course_name,cde.course_name)==0){
            totalcredit+=cde.credit;
            if(strcmp("A",student.cou[c].grade)==0)
                creditGrade+=cde.credit*4.0;
            else if(strcmp("B",student.cou[c].grade)==0)
                creditGrade+=cde.credit*3.0;
            else if(strcmp("C",student.cou[c].grade)==0)
                creditGrade+=cde.credit*2.5;
            else if(strcmp("D",student.cou[c].grade)==0)
                creditGrade+=cde.credit*1.5;
            else if(strcmp("E",student.cou[c].grade)==0)
                creditGrade+=cde.credit*0.0;
            else if(strcmp("AB",student.cou[c].grade)==0)
                creditGrade+=cde.credit*0.0;
        }
        break;
    }
    printf("\n");
    printf("\t\t\t\t%s :\t",student.cou[c].course_name);
    printf("%s\n",student.cou[c].grade);
}
    printf("\n");
    totalGPA=creditGrade/totalcredit;
    printf("\t\t\t\tCurrent GPA  : %.2f\n",totalGPA);
    printf("\n");
    }
}
if(found==0)
    printf("\n\t\t\t\tIndex No not found!!!\n\n");
    fclose(studentDetails);
    printf("Exit press(Y), View another student detail press(V), Want to edit above detail press(E) ");
    scanf(" %c",&command);
if(command=='y'||command=='Y')
    main();
if (command=='E'||command=='e');
    updatestudentDetails();
if (command=='v'||command=='V')
    viewStudentDetails();
}
void entercourseDetails(){
    system("cls");
    printf("\t\t\t\t\t*********************\n");
    printf("\t\t\t\t\t ADD COURSE DETAILS\n");
    printf("\t\t\t\t\t*********************\n\n\n");
    FILE *coursedetails;
struct coursedetails cde;
char command;
    printf("\t\t\t\tEnter course ID    : ");
    scanf(" %[^\n]s",cde.course_Id);
    printf("\t\t\t\tEnter Course Name  : ");
    scanf(" %[^\n]s",cde.course_name);
    printf("\t\t\t\tEnter Credit Value : ");
    scanf("%f",&cde.credit);
    coursedetails=fopen("coursedetails.txt","a");
    printf("\n");
    fwrite(&cde,sizeof(struct coursedetails),1,coursedetails);
    fclose(coursedetails);
    printf("Detail has been saved!");
    printf("\n\nDo you want to enter a new course(y/n) ");
    scanf(" %c",&command);
if(command=='y'||command=='Y')
    entercourseDetails();
else
    main();
}
void viewcourseDetails(){
    system("cls");
    printf("\t\t\t\t\t\t*****************\n");
    printf("\t\t\t\t\t\t COURSE DETAILS\n");
    printf("\t\t\t\t\t\t*****************\n\n\n");
char command;
    FILE *coursedetails;
struct coursedetails cde;
    coursedetails=fopen("coursedetails.txt","r");
while(fread(&cde,sizeof(struct coursedetails),1,coursedetails)){
    printf("\t\t\t\tCourse ID           : %s\n",cde.course_Id);
    printf("\t\t\t\tCourse Name         : %s\n",cde.course_name);
    printf("\t\t\t\tCourse Credit Value : %.1f\n",cde.credit);
    printf("\n");
}
    printf("\n");
    printf("Exit press(Y), Want to edit above detail press(E) ");
    scanf(" %c",&command);
if(command=='y'||command=='Y'){
    main();
}
else if(command=='E'||command=='e'){
    updatecourseDetails();
}
else
    main();
}


void updatecourseDetails(){

FILE *coursedetails, *tempcde;
struct coursedetails cde;
int found=0;
char command;
char cid[10];

    coursedetails=fopen("coursedetails.txt","r");
    tempcde=fopen("tempcoursedetails.txt","w");
    printf("\nEnter Course ID :- ");
    scanf("%s",cid);

    while(fread(&cde,sizeof(struct coursedetails),1,coursedetails)){
        if(strcmp(cid,cde.course_Id)==0){
            found=1;
            printf("\t\t\t\tUpdate course ID    : ");
            scanf(" %[^\n]s",cde.course_Id);
            printf("\t\t\t\tUpdate Course Name  : ");
            scanf(" %[^\n]s",cde.course_name);
            printf("\t\t\t\tUpdate Credit Value : ");
            scanf("%f",&cde.credit);
            coursedetails=fopen("coursedetails.txt","a");
            printf("\n");
        }
        fwrite(&cde,sizeof(struct coursedetails),1,tempcde);
    }
    fclose(coursedetails);
    fclose(tempcde);

    if(found==1){
        tempcde=fopen("tempcoursedetails.txt","r");
        coursedetails=fopen("coursedetails.txt","w");
        while(fread(&cde,sizeof(struct coursedetails),1,tempcde)){
            fwrite(&cde,sizeof(struct coursedetails),1,coursedetails);
        }
        fclose(coursedetails);
        fclose(tempcde);
    }else{
        printf("\n\t\t\t\tIndex No not found!!!\n\n");
        fclose(coursedetails);
    }
       printf("Exit press(Y), Want to edit above detail press(E) ");
    scanf(" %c",&command);
    if(command=='y'||command=='Y'){
        main();
    }
    else if(command=='E'||command=='e'){
        updatecourseDetails();
    }
    else
        main();

}
void main(){
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t***************************************\n");
    printf("\t\t\t\t  STUDENT DATABASE MANAGEMENT SYSTEM\n");
    printf("\t\t\t\t***************************************\n\n");
int menue_selection=menu();
    createsaveFile();

if(menue_selection=='1'){
    enterStudentDetails();
}
else if(menue_selection=='2'){
    viewStudentDetails();
}
else if(menue_selection=='3'){
    entercourseDetails();
}
else if(menue_selection=='4'){
    viewcourseDetails();
}
else if(menue_selection=='5'){
    exit(0);
}
}
