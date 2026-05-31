#include "frame.h"
#include <string.h>
#include <stdio.h>

void initFrame(Frame* frame, const char* name) {
    strncpy(frame->name, name, sizeof(frame->name) - 1);
    frame->name[sizeof(frame->name) - 1] = '\0';
    frame->role_count = 0;
}

int addRole(Frame* frame, const char* role_name, int concept_index) {
    if (frame->role_count == 8)
        return 0;

    if (concept_index < 0)
        return 0;

    FrameRole role;             
    strncpy(role.name, role_name, sizeof(role.name) - 1);
    role.name[sizeof(role.name) - 1] = '\0';
    role.concept_index = concept_index;
    
    frame->roles[frame->role_count] = role;
    frame->role_count++;

    return 1;
}

void printFrame(const Frame* frame, const Concept concepts[]) {
    printf("[%s\n", frame->name);

    for (int i = 0; i < frame->role_count; i++) {
        printf("    %s -> x%d : %s\n", frame->roles[i].name, i + 1, concepts[frame->roles[i].concept_index].name);
    }
    
    printf("]\n");
}