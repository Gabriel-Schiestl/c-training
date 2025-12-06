#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person { // Person 2x in order to self-reference(in method greet)
    int age;

    char *name;

    void (*greet)(struct Person *);
} Person;

Person * newPerson(int age, const char *name, void (*greet)(Person *)) {
    Person *person = malloc(sizeof *person);

    person->age = age;
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);

    person->greet = greet;

    return person;
}

void present_person(Person *person) {
    printf("%s, %d years old say hi!\n", person->name, person->age);
}

int main() {
    Person *person = newPerson(20, "Gabriel", &present_person);

    person->greet(person);
}