#include "kripke_scale.h"
#include <string.h>

void initKripkeScale(KripkeScale* scale) {
    scale->world_count = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            scale->accessibility[i][j] = 0;
}

int addWorld(KripkeScale* scale, PossibleWorld world) {
    if (scale->world_count == 8)
        return 0;

    scale->worlds[scale->world_count] = world;
    scale->world_count++;

    return 1;
}

int findWorldIndex(const KripkeScale* scale, const char* world_name) {
    for (int i = 0; i < scale->world_count; i++)
        if (strcmp(scale->worlds[i].name, world_name) == 0)
            return i;

    return -1;
}

void setAccessible(KripkeScale* scale, int from_world_index, int to_world_index, int value) {
    if (from_world_index < 0 || from_world_index >= scale->world_count)
        return;
    if (to_world_index < 0 || to_world_index >= scale->world_count)
        return;
    if (value != 0 && value != 1)
        return;

    scale->accessibility[from_world_index][to_world_index] = value;
}

int isAccessible(const KripkeScale* scale, int from_world_index, int to_world_index) {
    if (from_world_index < 0 || from_world_index >= scale->world_count)
        return;
    if (to_world_index < 0 || to_world_index >= scale->world_count)
        return;
    
    return scale->accessibility[from_world_index][to_world_index];
}

PossibleWorld* getWorld(KripkeScale* scale, int world_index) {
    if (world_index < 0 || world_index >= scale->world_count)
        return NULL;

    return &scale->worlds[world_index];
}