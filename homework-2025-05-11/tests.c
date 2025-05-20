#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
    printf("line\n");
    for(char a = 'a'; a < 'z'; a++)
    {
        printf("%c", a);
        Sleep(20);
        system("cls");
    }
    printf("line2\n");
    int arr[6][5] = {{1,2,3,4,5}, 
                     {1,2,3,4,5}, 
                     {1,2,3,4,5}, 
                     {1,2,3,4,5},
                     {1,2,3,4,5}, 
                     {1,2,3,4,5}};
    int colsize = sizeof(arr) / sizeof(arr[0]);
    int rowsize = sizeof(arr[0]) / sizeof(arr[0][0]);
    for(int i = 0; i < colsize; i++)
    {
        for(int j = 0; j < rowsize; j++)
        {
            printf("i - %d; j - %d; ", i, j);
            printf("number - %d; ", arr[i][j]);
        }
        printf("\n");
    }

}