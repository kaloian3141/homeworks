#include <stdio.h>
#include <stdlib.h>

char *create_name() 
{
    char c='\0';
    char *name=NULL;
    int len= 0;
    do 
    {
        c=getchar();
        len++;
        name=(char*)realloc(name,len*sizeof(char));
        if(name==NULL) 
        {
            printf("\nError allocating memory");
            free(name);
            exit(1);
        }
        name[len-1] = c;
    }
    while (c!='\n');
    name[len-1] = '\0';
    return name;
}

float *create_grades(int subject_num)
{
    float *grades =(float *)malloc(subject_num*sizeof(float));
    if(grades==NULL) 
    {
        printf("\nError allocating memory");
        free(grades);
        exit(1);
    }
    for(int j=0;j<subject_num;j++)
    {
        float grade = 0;
        do 
        {
            printf("\nEnter grade [%d]: ", j+1);
            scanf("%f", &grade);
        } 
        while (grade<2||grade>6);
        grades[j]=grade;
    }
    return grades;
}

void print_grades(char **subject_names,char **student_names,float **grades,int subject_num,int student_num) 
{
    printf("%-15s", " ");
    for(int i=0;i<subject_num;i++) 
    {
        printf("%-15s",subject_names[i]);
    }
    printf("\n");
    for(int i=0;i<student_num;i++) 
    {
        printf("%-15s", student_names[i]);

        for (int j=0;j<subject_num;j++) 
        {
            printf("%-15.2f", grades[i][j]);
        }
        printf("\n");
    }
}

int main(void) 
{
    int subject_num, student_num, choice;
    printf("\nEnter number of subjects: ");
    do 
    {
        scanf("%d", &subject_num);
    } 
    while(subject_num <= 0);
    getchar();
    char **subject_names = (char**)malloc(subject_num*sizeof(char*));
    if(subject_names==NULL) 
    {
        printf("\nError allocating memory");
        for (int i = 0; i < subject_num; i++)
            free(subject_names[i]);
        free(subject_names);
        return 1;
    }
    for(int i = 0; i < subject_num; i++) 
    {
        printf("Enter name of subject [%d]: ", i+1);
        subject_names[i] = create_name();
    }

    printf("\nEnter number of students: ");
    do 
    {
        scanf("%d", &student_num);
    } 
    while(student_num<=0);
    getchar();
    char **student_names = (char**)malloc(student_num *sizeof(char*));
    if(student_names ==NULL) 
    {
        printf("\nError allocating memory");
        for (int i = 0; i < student_num; i++)
            free(student_names[i]);
        free(student_names);
        for (int i = 0; i < subject_num; i++)
            free(subject_names[i]);
        free(subject_names);
        return 1;
    }
    float **grades = (float**)malloc(student_num * sizeof(float*));
    if(grades == NULL) 
    {
        printf("\nError allocating memory");
        for (int i = 0; i < student_num; i++)
            free(student_names[i]);
        free(student_names);
        for (int i = 0; i < subject_num; i++)
            free(subject_names[i]);
        free(subject_names);
        for (int i = 0; i < student_num; i++)
            free(grades[i]);
        free(grades);
        return 1;
    }
    for(int i =0;i < student_num;i++) 
    {
       
        printf("\nEnter name of student [%d]: ", i+1);
        student_names[i] = create_name();
        printf("\nEnter student [%d] grades: ", i+1);
        grades[i] = create_grades(subject_num);
        getchar();
    }
    while(1) 
    {
        printf("\nMenu:");
        printf("\n1.Print students grades table");
        printf("\n2.Create new student");
        printf("\n3.Exit\n");
        scanf("%d", &choice);

        if(choice == 1) 
        {
            print_grades(subject_names, student_names, grades, subject_num, student_num);
        } 
        else if(choice == 2) 
        {
            student_num++;
            student_names = (char**)realloc(student_names, student_num*sizeof(char*));
            if(student_names == NULL) 
            {
                printf("\nError allocating memory");
                for (int i = 0; i < student_num; i++)
                    free(student_names[i]);
                free(student_names);
                for (int i = 0; i < subject_num; i++)
                    free(subject_names[i]);
                free(subject_names);
                for (int i = 0; i < student_num; i++)
                    free(grades[i]);
                free(grades);
                return 1;
            }
            printf("\nEnter new student name: ");
            getchar();
            student_names[student_num-1] = create_name();
            grades = (float**)realloc(grades, student_num*sizeof(float*));
            if (grades == NULL) 
            {
                printf("\nError allocating memory");
                for (int i = 0; i < student_num; i++)
                     free(student_names[i]);
                free(student_names);
                for (int i = 0; i < subject_num; i++)
                     free(subject_names[i]);
                free(subject_names);
                for (int i = 0; i < student_num; i++)
                    free(grades[i]);
                free(grades);
                return 1;
            }
            printf("\nEnter student [%d] grades: ", student_num);
            grades[student_num-1] = create_grades(subject_num);
        } 
        else if (choice == 3) 
        {
            break;
        } 
        else 
        {
            printf("\nInvalid choice");
        }
    }
    for (int i = 0; i < student_num; i++)
        free(student_names[i]);
    free(student_names);
    for (int i = 0; i < subject_num; i++)
        free(subject_names[i]);
    free(subject_names);
    for (int i = 0; i < student_num; i++)
        free(grades[i]);
    free(grades);

    return 0;
}