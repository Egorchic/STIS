#ifndef KRIPKESCALE_H
#define KRIPKESCALE_H

#include "possible_world.h"

typedef struct {
    PossibleWorld worlds[8];
    int world_count;
    int accessibility[8][8];
} KripkeScale;

void initKripkeScale(KripkeScale* scale);
int addWorld(KripkeScale* scale, PossibleWorld world);
int findWorldIndex(const KripkeScale* scale, const char* world_name);
void setAccessible(KripkeScale* scale, int from_world_index, int to_world_index, int value);
int isAccessible(const KripkeScale* scale, int from_world_index, int to_world_index);
PossibleWorld* getWorld(KripkeScale* scale, int world_index);

#endif