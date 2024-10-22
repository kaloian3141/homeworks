#include <stdio.h>
#include "vector.h"

int sum_numbers(int n);
float power_recurtion(float n, int power);
float power(float n, int power);
int is_palindron_recurtion(vector *v,int i,int j);
int is_palindron(vector * v);
void print_pascal_triangle(int rows);
int get_pascal_triangle_element(int r, int c);

int main()
{
    int a = 22;
    printf("\n%d - %d" ,a , sum_numbers(a));
    float b = 2; 
    int p = -4;
    printf("\n%2f**%d = %2f\n", b, p, power(b, p));
    vector * v = init_vector(6);
    push(v, 1);
    push(v, 2);
    push(v, 3);
    push(v, 2);
    push(v, 1);
    print_vector(v);
    if(is_palindron(v))
      printf("it is palindron\n");
    else
      printf("it is not palindron\n");
    int rows = 5;
    print_pascal_triangle(rows);
    int r = 4, c = 3;
    printf("\nrow %d, col %d - %d", r, c, get_pascal_triangle_element(r, c));
    return 0;
}


int sum_numbers(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sum_numbers(n-1);

}

float power_recurtion(float n, int power)
{
    if(power == 1)
      return n;
    else
      return n * power_recurtion(n, power-1);
}

float power(float n, int power)
{
    if(power == 0)
      return 1;
    else if(power > 0)
      return power_recurtion(n, power);
    else if(power < 0)
      return power_recurtion(1/n, power * -1);
}

int is_palindron_recurtion(vector *v,int i,int j)
{
    if(i >= j)
        return 1;
    if(getAt(v, i) != getAt(v, j))
        return 0;
    else if(getAt(v, i) == getAt(v, j))
        return is_palindron_recurtion(v, i+1, j-1);
}

int is_palindron(vector * v)
{
  int i = 0, j = v->size-1, is_pallindron = 1;
  return is_palindron_recurtion(v, i, j);
}

void print_pascal_triangle(int rows)
{
  for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", get_pascal_triangle_element(i, j));
        }
        printf("\n");
    }
}

int get_pascal_triangle_element(int r, int c)
{
  if (c == 0 || c == r) {
        return 1;
    }
    return get_pascal_triangle_element(r - 1, c - 1) + get_pascal_triangle_element(r - 1, c);
}