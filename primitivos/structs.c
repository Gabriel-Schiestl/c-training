#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define class struct

class Person {
    int age;

    char *name;

    void (*greet)(class Person *);
};

class Person * newPerson(int age, const char *name, void (*greet)(class Person *)) {
    class Person *person = malloc(sizeof(class Person));

    person->age = age;
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);

    person->greet = greet;

    return person;
}

void present_person(class Person *person) {
    printf("%s, %d years old say hi!\n", person->name, person->age);
}

int main() {
    class Person *person = newPerson(20, "Gabriel", &present_person);

    person->greet(person);
}