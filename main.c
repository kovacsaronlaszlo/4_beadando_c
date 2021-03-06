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
void printPerson(Person** personArr, int n);
void exitProgram(void);
void stringValidation(char *input);
void deletePerson(Person** personArr, int n);

int main() {

    int n=0;
    int person_size = 10;
    char choice;
    Person** personArr = (Person**)malloc(person_size * sizeof(Person*));    

    while(1) {
        printf("Add new person: a \tShow data: l\tDelete person: d\tExit: x\n\n");
        printf("Enter your choice: ");
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
                deletePerson(personArr, n);
                n--;
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

void stringValidation(char *input) {
    int flag = 0;
    do {
        scanf("%s", input);
        if(strlen(input)<=30) {
            flag = 1;
        } else {
            printf("Long input, please add shorter: ");
        }

    } while(flag == 0);
    return;
}

void addPerson(Person** personArr, int person_size, int n) {

    Person *person;
    person = (Person*)malloc(sizeof(Person));
    
    if (n == person_size ) {
        person_size += 5;       
    }
    printf("Please add the person name: ");
    stringValidation(person->name);
    printf("Please add the person age: ");
    scanf("%d", &person->age);
    printf("Please add the person job: ");
    stringValidation(person->job);
    if(n < person_size) {
        personArr[n] = person;
    }

    printf("Person successfully added\n");
    return;
}

void printPerson(Person** personArr, int n) {
    int i;
    printf("\n\n");
    printf("Id\tName\tAge\tJob\n");
    for(i=0; i<n; ++i) {
        printf("%d\t%s\t%d\t%s\n", i+1, personArr[i]->name, personArr[i]->age, personArr[i]->job);
    }
    printf("\n\n");
    return;
}

void deletePerson(Person** personArr, int n) {
    int i, index = -1;
    char del_person[30];

    printf("Please add the deleteable Person name: ");
    stringValidation(del_person);
    for(i=0; i<n; i++) {
        if(strcmp(del_person,personArr[i]->name) == 0) {
            index = i;
            break;
        }
    }

    if(index != -1) {
        for(i=index; i<n-1; i++) {
            personArr[i] = personArr[i+1];
        }
    } else {
        printf("\n");
        printf("No such as person in database!\n");
    }
}

void exitProgram(void) {
    exit(0);
}