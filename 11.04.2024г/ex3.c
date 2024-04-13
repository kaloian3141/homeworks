#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[16];
    int number;
    double average_grade;
} Student;
void addstudent(Student *students, int num) 
{
  students = (Student*)realloc(students,num*sizeof(Student));
  if(students == NULL) {
        printf("\nError allocating memory");
        exit(1);
    }
    printf("\nEnter student[%d] name: ",num);
    scanf("%s", students[num-1].name);
    printf("\nEnter student[%d] number: ",num);
    scanf("%d", &students[num-1].number);
    do{
    printf("\nEnter student[%d] average grade: ",num);
    scanf("%lf", &students[num-1].average_grade);
    } while(students[num-1].average_grade > 6 || students[num-1].average_grade < 2);
}
void printstudents(Student *students, int count) {
    if (count == 0) {
        printf("There is no students.\n");
        return;
    }

    printf("LIst with students:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, number: %d, average grade: %.2lf\n",
               students[i].name, students[i].number, students[i].average_grade);
    }
}
int main(void)
{
    int students_num;
    printf("\nEnter number of students: ");
    scanf("%d",&students_num);
    Student *students = (Student *)malloc(students_num * sizeof(Student));
      if (students == NULL) {
        printf("\nError allocating memory");
        return 1;
    }
    for(int i=0;i<students_num;i++)
    {
    printf("\nEnter student[%d] name: ",i+1);
    scanf("%s", students[i].name);
    printf("\nEnter student[%d] number: ",i+1);
    scanf("%d", &students[i].number);
    do{
    printf("\nEnter student[%d] average grade: ",i+1);
    scanf("%lf", &students[i].average_grade);
    }while(students[i].average_grade > 6 || students[i].average_grade < 2);
    
    }
    int choice;

    while(1){
        printf("\nMenu:\n");
        printf("1.Add student\n");
        printf("2.Print all students\n");
        printf("3.Exit\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            students_num++;
            addstudent(students,students_num);
        }
        else if(choice == 2)
        {
            printstudents(students,students_num);
        }
        else if(choice == 3)
        {
           break; 
        }
        else 
        {
            printf("\nInvalid choice");
        }
    }
    free(students);
}