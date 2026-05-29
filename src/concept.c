#include "concept.h"
#include <stdio.h>
#include <string.h>

void setName(Concept* concept, const char* new_name) {
    strncpy(concept->name, new_name, sizeof(concept->name) - 1);
    concept->name[sizeof(concept->name) - 1] = '\0';
}

void initConcept(Concept* concept, const char* name, int parent_index) {
    setName(concept, name);
    concept->parent_index = parent_index;
}

int isIsa(const Concept concepts[], int child_index, int parent_index) {
    if (child_index == -1)
        return 0;

    if (concepts[child_index].parent_index == parent_index)
        return 1;
    else 
        return isIsa(concepts, concepts[child_index].parent_index, parent_index);
}

int findConceptByName(const Concept concepts[], int concept_count, const char* name) {
    for (int i = 0; i < concept_count; i++)
        if (strcmp(concepts[i].name, name) == 0)
            return i;

    return -1;
}

void printConcept(const Concept concepts[], int concept_index) {
    printf("%s", concepts[concept_index].name);
}