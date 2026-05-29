#ifndef CONCEPT_H
#define CONCEPT_H

#define NO_PARENT -1

typedef struct {
    char name[40];
    int parent_index;
} Concept;

void setName(Concept* concept, const char* new_name);
void initConcept(Concept* concept, const char* name, int parent_index);
int isIsa(const Concept concepts[], int child_index, int parent_index);
int findConceptByName(const Concept concepts[], int concept_count, const char* name);
void printConcept(const Concept concepts[], int concept_index);

#endif