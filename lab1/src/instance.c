#include "instance.h"
#include <string.h>
#include <stdio.h>

void initInstance(Instance* instance, const char* name, int concept_index) {
    setInstanceName(instance, name);
    instance->concept_index = concept_index;
}

void setInstanceName(Instance* instance, const char* new_name) {
    strncpy(instance->name, new_name, sizeof(instance->name) - 1);
    instance->name[sizeof(instance->name) - 1] = '\0';
}

void printInstance(const Instance* instance, const Concept concepts[]) {
    printf("%s ", instance->name);
    printConcept(concepts, instance->concept_index);
}