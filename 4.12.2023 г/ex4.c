#include <stdio.h>
#include <math.h>
#define SIZE 5
void fourth_power_function(long arr[], int size);
int main() 
{

    long arr[SIZE] = {2,3,4,5,6};
    fourth_power_function(arr, SIZE);
    for (int i= 0;i< SIZE;i++) 
    {
        printf("%ld ", arr[i]);
    }

    return 0;
}
void fourth_power_function(long arr[], int size) 
{
    for (int i=0;i< size;i++) 
    {
        arr[i] = pow(arr[i], 4);
    }
}