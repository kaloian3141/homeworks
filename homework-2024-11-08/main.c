#include <stdio.h>
void radix_sort(int* arr, unsigned int n);
void print_arr(int * arr, int n);
void radix_sort_R(int * arr, unsigned int n, int maxdigit,int currentdigit);
void counting_sort(int * arr, unsigned int n, int digit);


int main()
{
    int arr[15] = {11,111,-1111,111111,22,33,5,-86,3,5,-38,9,53,-1,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, size);
    radix_sort(arr, size);
    print_arr(arr, size);
    return 0;

}

void print_arr(int * arr, int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void radix_sort(int* arr, unsigned int n)
{
 int negative_arr[n];
 int positive_arr[n];
 int j = 0, k = 0;

 for(int i = 0; i<n; i++)
 {
    if (arr[i]<0){
    negative_arr[j] = arr[i]*-1;
    j++;
    }
    else{
    positive_arr[k] = arr[i];
    k++;
    }
 }
 printf("Positive arr:\n");
 print_arr(positive_arr, k);
 printf("Negative arr:\n");
 print_arr(negative_arr, j);
 if(k>0)
 {
    int max = positive_arr[0];
    for(int i = 0; i<k; i++)
    {
        if(positive_arr[i]>max)
        max = positive_arr[i];
    }
    int digit = 1;
    while(max/digit > 10)
    {
        digit = digit * 10;
    }
    radix_sort_R(positive_arr,k,digit, 1);
 }

 if(j>0)
 {
    int max = negative_arr[0];
    for(int i = 0; i<j; i++)
    {
        if(negative_arr[i]>max)
        max = negative_arr[i];
    }
    int digit = 1;
    while(max/digit > 10)
    {
        digit = digit * 10;
    }
    radix_sort_R(negative_arr,j,digit, 1);
    for(int i = 0;i<j;i++)
    {
        negative_arr[i] = negative_arr[i] * -1;
    }
 }
 int size = 0;
 for(int i = j-1;i>=0;i--)
 {
  arr[size] = negative_arr[i];
  size++;
 }
 for (int i = 0; i < k; i++)
 {
    arr[size] = positive_arr[i];
    size++;
 }
 
}

void radix_sort_R(int * arr, unsigned int n, int maxdigit, int currentdigit)
{
    if (currentdigit > maxdigit)
    return;
    counting_sort(arr, n, currentdigit);
    printf("sorted for digit: %d\n",currentdigit);
    print_arr(arr, n);
    printf("\n");
    radix_sort_R(arr, n, maxdigit, currentdigit*10);
}

void counting_sort(int * arr, unsigned int n, int digit)
{ 
    int count[10] = {0}; 
    int output[n];

    for(int i = 0; i < n; i++) {
        int digitValue = (arr[i] / digit) % 10;
        count[digitValue]++;
    }

    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        int digitValue = (arr[i] / digit) % 10;
        output[count[digitValue] - 1] = arr[i];
        count[digitValue]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
}