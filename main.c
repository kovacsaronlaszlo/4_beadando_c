#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[30];
    unsigned int age;
    char job[30];
};

typedef struct Person Person;

void addPerson(Person** personArr, int person_size, int n);
void printPerson(const Person** personArr, int n);
void exitProgram(void);

int main() {

    int n=0;
    int person_size = 10;
    char choice;
    Person** personArr = (Person**)malloc(person_size * sizeof(Person*));    

    while(1) {
        printf("Add new person: a \tShow data: l\tDelete person: d\tExit: x\n\n");
        printf("Enter your choice:\n");
        scanf("%c", &choice);
        switch(choice) {
            case 'a':
                addPerson(personArr, person_size, n);
                n++;
                break;
            case 'l':
                printPerson(personArr, n);
                break;
            case 'd':
                printf("Delete\n");
                break;
            case 'x':
                free(personArr);
                exitProgram();
                break;
            default:
                printf("You have invalid choice\n\n\n\n");
                break;
        }
    }

    return 0;
}

void addPerson(Person** personArr, int person_size, int n) {

    Person *person;
    person = (Person*)malloc(sizeof(Person));
    
    if (n == person_size ) {
        person_size += 5;       
    }
    printf("Please add the person name: ");
    scanf("%30s", person->name);
    printf("Please add the person age: ");
    scanf("%d", &person->age);
    printf("Please add the person job: ");
    scanf("%30s", person->job);
    printf("%d", n);
    if(n < person_size) {
        personArr[n] = person;
    }

    printf("Person successfully added\n");
    return;
}

void printPerson(const Person** personArr, int n) {
    int i;
    printf("\n\n");
    printf("Id\tName\tAge\tJob\n");
    for(i=0; i<n; ++i) {
        printf("%d\t%s\t%d\t%s\n", i+1, personArr[i]->name, personArr[i]->age, personArr[i]->job);
    }
    printf("\n\n");
    return;
}

void exitProgram(void) {
    exit(0);
}