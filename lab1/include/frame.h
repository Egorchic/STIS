#ifndef FRAME_H
#define FRAME_H

#include "concept.h"

typedef struct {
    char name [40];
    int concept_index;
} FrameRole;

typedef struct {
    char name[40];
    FrameRole roles[8];
    int role_count;
} Frame;

void initFrame(Frame* frame, const char* name);
int addRole(Frame* frame, const char* role_name, int concept_index);
void printFrame(const Frame* frame, const Concept concepts[]);

#endif