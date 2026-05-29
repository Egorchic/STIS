#include <stdio.h>
#include "include/concept.h"
#include <windows.h> 

/*
concepts[0] = ОБЪЕКТ.ПЛАТФОРМЫ
concepts[1] = УЧАСТНИК.ПЛАТФОРМЫ
concepts[2] = АРТЕФАКТ
concepts[3] = ПОЛЬЗОВАТЕЛЬ
concepts[4] = ДАТАСЕТ
concepts[5] = ЭКСПЕРИМЕНТ
*/

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    Concept concepts[6];
    
    initConcept(&concepts[0], "ОБЪЕКТ.ПЛАТФОРМЫ", NO_PARENT);
    initConcept(&concepts[1], "УЧАСТНИК.ПЛАТФОРМЫ", 0);
    initConcept(&concepts[2], "АРТЕФАКТ", 0);
    initConcept(&concepts[3], "ПОЛЬЗОВАТЕЛЬ", 1);
    initConcept(&concepts[4], "ДАТАСЕТ", 2);
    initConcept(&concepts[5], "ЭКСПЕРИМЕНТ", 2);

    const char* name = "АРТЕФАКТ";
    printf("%d\n\n", findConceptByName(concepts, 6, name));

    int child = 3;
    for (int i = 0; i < 6; i++)
        if (i != 3) {
            if (isIsa(concepts, child, i)) {
                printConcept(concepts, child);
                printf(" ISA "); 
                printConcept(concepts, i);
                printf("\n");
            }
            else {
                printConcept(concepts, child);
                printf(" ISNOTA "); 
                printConcept(concepts, i);
                printf("\n");
            } 
        }
    printf("\n");
    
    


    return 0;
}