#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[30];
    unsigned int age;
    char job[30];
};

typedef struct Person Person;

void addPerson(Person *person);
void printPerson(const Person *person, size_t person_size);

int main() {

    int i;
    size_t person_size = 1;
    char choice;
    Person *person;
    person = calloc(person_size, sizeof(Person));
    if(person == NULL) {
        printf("person not allocated!");
        return 0;
    }
    

    while(1) {
        printf("Add new person: a \tShow data: l\tDelete person: d\tExit: x\n\n");
        printf("Enter your choice:\n");
        scanf("%c", &choice);
        person = realloc(person, person_size * sizeof(Person));
        if(person == NULL) {
            printf("person not allocated!");
            return 0;
        }
        switch(choice) {
            case 'a':
                addPerson(person);
                break;
            case 'l':
                printPerson(person, person_size);
                break;
            case 'd':
                printf("Delete");
                break;
            case 'x':
                free(person);
                exit(0);
                break;
            default:
                printf("You have invalid choice\n\n\n\n");
                break;
        }
    }

}

void addPerson(Person *person) {
    printf("Please add the person name: ");
    scanf("%s", person->name);
    if(strlen(person->name) > 30) {
        printf("Long name, max character length must be 30!");
        return;
    }
    printf("Please add the person age: ");
    scanf("%d", &person->age);
    printf("Please add the person job: ");
    scanf("%s", person->job);
    if(strlen(person->job) > 30) {
        printf("Long name, max character length must be 30!");
        return;
    }

    printf("Person succesfully added\n");
}

void printPerson(const Person *person, size_t person_size) {
    int i;
    for(i=0; i<person_size; ++i) {
        printf("Person { name: %s, age: %d, job: %s }\n", person->name, person->age, person->job);
    }
    return;
}