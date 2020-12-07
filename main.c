#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[30];
    unsigned int age;
    char job[30];
};

typedef struct Person Person;

Person addPerson(void);
void printPerson(const Person *person, size_t person_size);
void exitProgram(void);

int main() {

    int i;
    size_t person_size = 10;
    char choice;
    Person *person;
    person = (Person *)malloc(1* sizeof(Person));
    if(person == NULL) {
        printf("person not allocated!");
        return 0;
    }
    

    while(1) {
        printf("Add new person: a \tShow data: l\tDelete person: d\tExit: x\n\n");
        printf("Enter your choice:\n");
        scanf("%c", &choice);
        switch(choice) {
            case 'a':
                if (sizeof(person)/sizeof(person[0]) == person_size ) {
                    person_size += 5;       
                }
                for(i=sizeof(person)/sizeof(person[0]); i<person_size; i++) {
                    person[i] = addPerson();
                    break;
                }
                break;
            case 'l':
                printPerson(person, person_size);
                break;
            case 'd':
                printf("Delete");
                break;
            case 'x':
                exitProgram();
                break;
            default:
                printf("You have invalid choice\n\n\n\n");
                break;
        }
    }
    free(person);

    return 0;
}

Person addPerson(void) {
    Person person;
    printf("Please add the person name: ");
    scanf("%30s", person.name);
    printf("Please add the person age: ");
    scanf("%d", &person.age);
    printf("Please add the person job: ");
    scanf("%30s", person.job);

    printf("Person succesfully added\n");
    return person;
}

void printPerson(const Person *person, size_t person_size) {
    int i;
    for(i=0; i<person_size; ++i) {
        printf("Person { name: %s, age: %d, job: %s }\n", person->name, person->age, person->job);
    }
    return;
}

void exitProgram(void) {
    exit(0);
}