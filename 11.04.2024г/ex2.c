#include <stdio.h>
enum Weekdays
{
    MONDAY = 1,
    TUESDAY,
    WENDESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
int main(void)
{
while (1)
{
    int choice =0;
    printf("\n");
    scanf("%d",&choice);
    enum Weekdays day;
    day = choice;
    switch (day)
    {
    case MONDAY:printf("\nMonday");break;
    case TUESDAY:printf("\nTuesday");break;
    case WENDESDAY:printf("\nWendesday");break;
    case THURSDAY:printf("\nThursday");break;
    case FRIDAY:printf("\nFriday");break;
    case SATURDAY:printf("\nSaturday");break;
    case SUNDAY:printf("\nSunday");break;

    default:
        printf("\nInvalid choice");
        break;
    }
}

}