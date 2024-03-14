#include <stdio.h>
#include <stdlib.h>

void print_grades(float * grades, int arrlen)
{
    float sum = 0;
    for(int i = 0; i<arrlen; i++)
    {
        sum = sum + grades[i];
    }
    sum = sum/arrlen;
    printf("\n Average success: %f\n", sum);
}
int main(void)
{
    int n = 0;
    printf("Enter number of grades: ");
    scanf("%d",&n);
    float * grades = (float*)malloc(sizeof(float)*n);
    if (grades == NULL)
    {
        printf("Error allocating memory\n");
        free(grades);
        return 1;
    }
    for(int i=0; i<n; i++)
    {
        do
        {
            printf("\nEnter grade %d: ",i+1);
            scanf("%f",&grades[i]);
        } 
        while (grades[i]<2 || grades[i]>6);
    }
    while (1)
    {
        printf("\nMenu:\n");
        printf("1.Print average success\n");
        printf("2.Add new grade\n");
        printf("3.Remove last grade\n");
        printf("4.Exit\n");
        int choice;
        scanf("%d",&choice);
        if(choice == 1)
        {
            print_grades(grades,n);
        }
        else if(choice == 2)
        {
            grades = (float*)realloc(grades,(n+1)*(sizeof(float)));
            if (grades == NULL)
            {
              printf("Error allocating memory\n");
              free(grades);
              return 1;
            }
            do
            {
               printf("\nEnter new grade: ");
               scanf("%f",&grades[n]);
            }
            while (grades[n]<2 || grades[n]>6);
        
            n++;
            
        }
        else if(choice == 3)
        {
               grades = (float*)realloc(grades,(n-1)*(sizeof(float)));
               if (grades == NULL)
               {
                printf("Error allocating memory\n");
                free(grades);
                return 1;
               }
                printf("Last grade was removed\n");
                n--; 
        }
        else if(choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        } 
    }
    free(grades);
    return 0;
}