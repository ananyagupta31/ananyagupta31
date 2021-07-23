#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
    int marks1;
    int marks2;
    int marks3;
    int marks4;
    int marks5;
    int marks6;
    int marks7;
    int marks8;
    int marks9;
    int marks10;
};
int main()
{
    gotoxy(15,8);
    printf("<--:Student Record Management System:-->");
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter Name : ");
//        gets(std.name);///???
        gets(std.name);
        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter Roll No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Course : ");
//        gets(std.course);///???
        gets(std.course);
        gotoxy(10,11);
        printf("Enter Branch : ");
        gets(std.branch);
        gotoxy(10,12);
        printf("Enter marks1 : ");
        scanf("%d",&std.marks1);
        gotoxy(10,13);
        printf("Enter marks2 : ");
        scanf("%d",&std.marks2);
        gotoxy(10,14);
        printf("Enter marks3 : ");
        scanf("%d",&std.marks3);
        gotoxy(10,15);
        printf("Enter marks4 : ");
        scanf("%d",&std.marks4);
        gotoxy(10,16);
        printf("Enter marks5 : ");
        scanf("%d",&std.marks5);
        gotoxy(10,17);
        printf("Enter marks6 : ");
        scanf("%d",&std.marks6);
        gotoxy(10,18);
        printf("Enter marks7 : ");
        scanf("%d",&std.marks7);
        gotoxy(10,19);
        printf("Enter marks8 : ");
        scanf("%d",&std.marks8);
        gotoxy(10,20);
        printf("Enter marks9 : ");
        scanf("%d",&std.marks9);
        gotoxy(10,21);
        printf("Enter marks10 : ");
        scanf("%d",&std.marks10);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,22);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
//        another = getch();///???
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   Name of Student       Mobile No   Roll No  Course      Branch    marks1       marks2    marks3     marks4       marks5    marks6     marks7       marks8      marks9    marks10     ");
    gotoxy(10,6);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-12s%-9d%-12s%-12s%-12d%-12d%-12d%-12d%-12d%-12d%-12d%-12d%-12d%-12d",i,std.name,std.mobile,std.rollno,std.course,std.branch,std.marks1,std.marks2,std.marks3,std.marks4,std.marks5,std.marks6,std.marks7,std.marks8,std.marks9,std.marks10);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
           /* gotoxy(10,8);
            printf("Name : %s",std.name);
            gotoxy(10,9);
            printf("Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("Roll No : %d",std.rollno);
            gotoxy(10,11);
            printf("Course : %s",std.course);
            gotoxy(10,12);
            printf("Branch : %s",std.branch);
            */
            printf("           Name of Student       Mobile No   Roll No  Course      Branch    marks1       marks2    marks3     marks4       marks5    marks6     marks7       marks8      marks9    marks10     ");
    gotoxy(10,10);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
           gotoxy(10,11);
            printf("%-22s%-12s%-9d%-12s%-12s%-12d%-12d%-12d%-12d%-12d%-12d%-12d%-12d%-12d%-12d",std.name,std.mobile,std.rollno,std.course,std.branch,std.marks1,std.marks2,std.marks3,std.marks4,std.marks5,std.marks6,std.marks7,std.marks8,std.marks9,std.marks10);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,7);
            printf("Enter name: ");
            gets(std.name);
            gotoxy(10,8);
            printf("Enter mobile number : ");
            gets(std.mobile);
            gotoxy(10,9);
            printf("Enter roll no : ");
            scanf("%d",&std.rollno);
            gotoxy(10,10);
            printf("Enter Course : ");
            fflush(stdin);
            gets(std.course);
            gotoxy(10,11);
            printf("Enter Branch : ");
            fflush(stdin);
            gets(std.branch);
            gotoxy(10,12);
            printf("Enter marks1 : ");
        scanf("%d",&std.marks1);
        gotoxy(10,13);
        printf("Enter marks2 : ");
        scanf("%d",&std.marks2);
        gotoxy(10,14);
        printf("Enter marks3 : ");
        scanf("%d",&std.marks3);
        gotoxy(10,15);
        printf("Enter marks4 : ");
        scanf("%d",&std.marks4);
        gotoxy(10,16);
        printf("Enter marks5 : ");
        scanf("%d",&std.marks5);
        gotoxy(10,17);
        printf("Enter marks6 : ");
        scanf("%d",&std.marks6);
        gotoxy(10,18);
        printf("Enter marks7 : ");
        scanf("%d",&std.marks7);
        gotoxy(10,19);
        printf("Enter marks8 : ");
        scanf("%d",&std.marks8);
        gotoxy(10,20);
        printf("Enter marks9 : ");
        scanf("%d",&std.marks9);
        gotoxy(10,21);
        printf("Enter marks10 : ");
        scanf("%d",&std.marks10);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,22);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
