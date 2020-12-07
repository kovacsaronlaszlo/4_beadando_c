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
void printPerson(const Person *person, int n);
void exitProgram(void);

int main() {

    int n=0;
    size_t person_size = 10;
    char choice;
    Person *person;
    person = malloc(sizeof(Person) + person_size* sizeof(Person));
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
                if (n == person_size ) {
                    person_size += 5;       
                }
                if(n < person_size) {
                    person[n] = addPerson();
                }
                n++;
                printf("%d\n", n);
                break;
            case 'l':
                printPerson(person, n);
                break;
            case 'd':
                printf("Delete\n");
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

void printPerson(const Person *person, int n) {
    int i;
    printf("\n\n");
    printf("Id\tName\tAge\tJob\n");
    for(i=0; i<n; ++i) {
        printf("%d\t%s\t%d\t%s\n", i+1, person->name, person->age, person->job);
    }
    printf("\n\n");
    return;
}

void exitProgram(void) {
    exit(0);
}