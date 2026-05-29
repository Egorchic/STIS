#ifndef POSSIBLEWORLD_H
#define POSSIBLEWORLD_H

#include "instance.h"

typedef struct {
    char name[40];
    Instance instences[64];
    int instance_count;
} PossibleWorld;

void initPossibleWorld(PossibleWorld* world, const char* name);
int addInstance(PossibleWorld* world, Instance instance);
int findInstanceIndex(const PossibleWorld* world, const char* instance_name);
int hasInstance(const PossibleWorld* world, const char* instance_name);
int instanceOf(
    const PossibleWorld* world,
    const Concept concepts[],
    int concept_count,
    const char* instance_name,
    int target_concept_index
);

#endif