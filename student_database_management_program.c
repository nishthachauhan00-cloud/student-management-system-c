#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    int roll_no;
    char name[50];
    char course[50];
    float marks;
    long long phone_no;
};
 void addstudent()
 {
    FILE *fp;
    struct student s;

    fp = fopen("student.dat","ab");

    if (fp==NULL)
    {
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

    printf("Enter CGPA : ");
    scanf("%f", &s.marks);

    printf("Enter phone number : ");
    scanf("%lld", &s.phone_no);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("\n---STUDENT RECORD ADDED SUCCESSFULLY---\n");
 };
 void displaystudent(){
     FILE *fp;
     struct student s;
     fp = fopen("student.dat","rb");
     if(fp==NULL){
        printf("No record found\n");
        return;
     }
     printf("\n---STUNDENT RECORDS---\n");

     while(fread(&s, sizeof(s), 1, fp))
     {
        printf("\nRoll number : %d", s.roll_no);
        printf("\nStudent name : %s", s.name);
        printf("\nCourse : %s", s.course);
        printf("\nCGPA : %.2f", s.marks);
        printf("\nPhone number : %lld", s.phone_no);
        printf("\n------------------------------------\n");
     }
     fclose(fp);
 };
 void searchstudent(){
    FILE *fp;
    struct student s;
    int searchroll;
    int found=0;
    fp = fopen("student.dat","rb");

    if (fp==NULL)
    {
        printf("Record not found.\n");
        return;
    } 
   printf("Enter roll number : ");
   scanf("%d", &searchroll);
   while(fread(&s, sizeof(s), 1, fp)){
      if (s.roll_no==searchroll){
         printf("---STUDENT RECORD FOUND---");
         printf("\nRoll number : %d", s.roll_no);
         printf("\nStudent name : %s", s.name);
         printf("\nCourse : %s", s.course);
         printf("\nCGPA : %.2f", s.marks);
         printf("\nPhone number : %lld", s.phone_no);

         found= 1;
         break;
      }
   }
   fclose(fp);
   if(!found){
      printf("student with %d roll number not found.\n", searchroll);
   }

 };
 void updatestudent(){
   FILE *fp, *temp;
   struct student s;
   int searchroll;
   int found=0;
   
   fp= fopen("student.dat","rb");
   temp= fopen("temp.dat","wb");

   if (fp==NULL || temp==NULL){
      printf("file error!\n");
      return;
   }
   printf("Enter roll number : ");
   scanf("%d", &searchroll);

   while(fread(&s, sizeof(s), 1, fp)){
      if(s.roll_no == searchroll){
         printf("---UPDATE STUDENT DETAILS---\n");
         printf("Enter name : ");
         scanf(" %[^\n]", s.name);

         printf("Enter cousre name : ");
         scanf(" %[^\n]", s.course);

         printf("Enter CGPA : ");
         scanf("%f", &s.marks);

         printf("Enter phone number : ");
         scanf("%lld", &s.phone_no);

         fwrite(&s,sizeof(s), 1, temp);
         found=1;
      } else{
         fwrite(&s, sizeof(s), 1, temp);
      }
   }
   fclose(fp);
   fclose(temp);
   if (found){
      remove ("student.dat");
      rename("temp.dat","student.dat");
      printf("Student record updated successfully.\n");
   } else{
      remove("temp.dat");
      printf("student record not found!\n");
   }

 };
 void deletestudent(){
   FILE* fp, *temp;
   struct student s;
   int roo, found=0;
   fp = fopen("student.dat","rb");
   temp = fopen("temp.dat","wb");
   if(fp==NULL){
      printf("file error!\n");
      return;
   }
   printf("Enter roll number : ");
   scanf("%d", &roo);

   while(fread(&s, sizeof(s), 1, fp)){
      if(s.roll_no == roo){
         found=1;
      } else{
         fwrite(&s, sizeof(s), 1, temp);
      }
   }
   fclose(fp);
   fclose(temp);

   if(found){
      remove("student.dat");
      rename("temp.dat","student.dat");
      printf("Student record deleted successfully.\n");
   } else{
      remove("temp.dat");
      printf("student record not found dipshit!\n");
   }
 };
int main()
{
    int choice;
    while(1){
        printf("\n---STUDENT DATABASE MANAGEMENT SYSTEM---\n");
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
               printf("--enter valid choice--\n");
               break;     
        }
    }
    return 0;
}