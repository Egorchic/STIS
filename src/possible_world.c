#include "possible_world.h"
#include <string.h>
#include <stdio.h>

void initPossibleWorld(PossibleWorld* world, const char* name) {
    strncpy(world->name, name, sizeof(world->name) - 1);
    world->name[sizeof(world->name) - 1] = '\0';
    world->instance_count = 0;
}

int addInstance(PossibleWorld* world, Instance instance) {
    if (world->instance_count == 64)
        return 0;
    world->instences[world->instance_count] = instance;
    world->instance_count++;

    return 1;
}

int findInstanceIndex(const PossibleWorld* world, const char* instance_name) {
    for (int i = 0; i < world->instance_count; i++) 
        if (strcmp(world->instences[i].name, instance_name) == 0)
            return i;

    return -1;
}

int hasInstance(const PossibleWorld* world, const char* instance_name) {
    if (findInstanceIndex(world, instance_name) != -1)
        return 1;

    return 0;
}

int instanceOf(
    const PossibleWorld* world,
    const Concept concepts[],
    int concept_count,
    const char* instance_name,
    int target_concept_index
) {
    if (!(hasInstance(world, instance_name)))
        return -1;

    if (target_concept_index < 0 || target_concept_index >= concept_count) {
        return -1;
    }

    int instance_ind = findInstanceIndex(world, instance_name);
    Instance instance = world->instences[instance_ind];
    int concept_ind = instance.concept_index;

    if (concept_ind < 0 || concept_ind >= concept_count) {
        return -1;
    }

    if (isIsa(concepts, concept_ind, target_concept_index))
        return 1;
    else
        return 0;
}