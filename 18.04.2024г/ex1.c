#include <stdio.h>

typedef enum
{
    False = 0,
    True
} bool;

typedef struct {
    char first_name[50];
    char middle_name[50];
    char last_name[50];
    char email[100];
    char phone_number[20];
} Participant;

typedef struct {
    Participant participant;
    bool will_participate;
} Answer;



typedef struct {
    char title[100];
    char description[500];
    struct {
        int day;
        int month;
        int year;
        struct {
            int hour;
            int minute;
        } time;
    } Date;
    Answer List_of_answers[100];
} Event;

void print_Answers(Answer answer) {
    printf("Participant:\n");
    printf("Name: %s %s %s\n", answer.participant.first_name, answer.participant.middle_name, answer.participant.last_name);
    printf("Email: %s\n", answer.participant.email);
    printf("Phone: %s\n", answer.participant.phone_number);
    switch (answer.will_participate) {
        case True:
            printf("Will participate\n");
            break;
        case False:
            printf("Will not participate\n");
            break;
    }
}

void print_date(Event event_date) {
    printf("\n%d/%d/%d at %d:%d\n", event_date.Date.day, event_date.Date.month, event_date.Date.year, event_date.Date.time.hour, event_date.Date.time.minute);
}

void print_event(Event event, int num_of_participant) {
    printf("Title: %s\n", event.title);
    printf("Description: %s\n", event.description);
    printf("Date: ");
    print_date(event);
    for (int i = 0; i < num_of_participant; ++i) {
        printf("Answer %d:\n", i + 1);
        print_Answers(event.List_of_answers[i]);
        
    }
}

int main(void) {
    Event event1 = {
        .title = "Event1",
        .description = "event1",
        .Date = {.day = 18, .time = {.hour = 13, .minute = 0}, .month = 4, .year = 2024},
        .List_of_answers = {
            {
                .participant = {.first_name = "Kaloyan",
                                .middle_name = "Borislavov",
                                .last_name = "Vlahov",
                                .email = "kaloyanv@gmail.com",
                                .phone_number = "0123 456 5413"},
                .will_participate = False
            },
            {
                .participant = {.first_name = "Yordan",
                                .middle_name = "Yordanov",
                                .last_name = "Tsonev",
                                .email = "YordanTs@gmail.com",
                                .phone_number = "534 185 6242"},
                .will_participate = True
            }
        }
    };
    Event event2 = { .title = "Event2",
        .description = "event2",
        .Date = {.day = 20, .time = {.hour = 9, .minute = 30}, .month = 2, .year = 2024},
        .List_of_answers = {
            {
                .participant = {.first_name = "Daniel",
                                .middle_name = "Atanasov",
                                .last_name = "Velev",
                                .email = "Danielv@gmail.com",
                                .phone_number = "244 452 9996"},
                .will_participate = True
            },
            {
                .participant = {.first_name = "Maria",
                                .middle_name = "Stefanova",
                                .last_name = "Ivanova",
                                .email = "MariaI@gmail.com",
                                .phone_number = "509 520 0989"},
                .will_participate = False
            }
        }
    };


    int num_of_participant = 2;
    print_event(event1, num_of_participant);
    print_event(event2, num_of_participant);

    return 0;
}