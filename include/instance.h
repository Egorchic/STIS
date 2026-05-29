#ifndef INSTANCE_H
#define INSTANCE_H

#include "concept.h"

typedef struct  {
    char name[40];
    int concept_index;
} Instance;

void initInstance(Instance* instance, const char* name, int concept_index);
void setName(Instance* instance, const char* name);
void printInstance(const Instance* instance, const Concept concepts[]);

#endif