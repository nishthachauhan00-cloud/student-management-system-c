#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    int roll_no;
    char name[50];
    char cousre{50};
    float marks;
    int phone_no;
};
 void addstudent();{
    FILE *fp;
    struct student s;

    fp = fopen("student.dat","ab");

    if (fp==null){
        printf("file not found.\n");
        return;
    }
    printf("---ENTER STUDENT DETAILS---");

    printf("\nEnter roll number : ");
    scanf("%d", &s.roll_no);

    printf("Enter name : ");
    scanf(" %[^\n]", s.name );

    printf("Enter course name : ");
    scanf(" %[^\n]", s.course);

    printf(" Enter CGPA : ");
    scanf("%f", &s.marks);

    printf("Enter phone number : ");
    scanf("%d", &s.phone_no);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("\n---STUDENT RECORD ADDED SUCCESSFULLY---\n");
 }
 void displaystudent();
 void searchstudent();
 void updatestudent();
 void deletestudent();
int main()
{
    int choice;
    while(1){
        printf(" ---student database management system---\n");
        printf("1. add student information\n");
        printf("2. display student information\n");
        printf("3. search student information\n");
        printf("4. update student information\n");
        printf("5. delete student information\n");
        printf("6. exit\n");

        printf("enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
               addstudent();
               break;
            case 2:
               displaystudent();
               break;   
            case 3:
               searchstudent();
               break;   
            case 4:
               updatestudent();
               break;   
            case 5:
               deletestudent();
               break;   
            case 6:
               exit(0);
            default:
               printf("--enter valid choice--\n")
               break;     
        }
    }
    return 0;
}