#include <stdio.h>
#include "include/concept.h"
#include "include/instance.h"
#include "include/possible_world.h"
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


    Instance instances[3];

    initInstance(&instances[0], "Иван", findConceptByName(concepts, 6, "ПОЛЬЗОВАТЕЛЬ"));
    initInstance(&instances[1], "Датасет_v1", findConceptByName(concepts, 6, "ДАТАСЕТ"));
    initInstance(&instances[2], "Experiment_87", findConceptByName(concepts, 6, "ЭКСПЕРИМЕНТ"));

    for (int i = 0; i < 3; i++) {
        printInstance(&instances[i], concepts);
        printf("\n");
    }    
    printf("\n");


    PossibleWorld world;
    initPossibleWorld(&world, "Мир_1");
    addInstance(&world, instances[0]);
    addInstance(&world, instances[1]);
    addInstance(&world, instances[2]);
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 6; i++) {
            int result = instanceOf(&world, concepts, 6, world.instences[j].name, i);
            if (result == -1)
                printf("%s не является экземпляром в мире %s\n", world.instences[j].name, world.name);
            else {
                if (result == 1)
                    printf("%s instance-of %s\n", world.instences[j].name, concepts[i].name);
                else
                    printf("%s not instance-of %s\n", world.instences[j].name, concepts[i].name);
            }
        }
        printf("\n");
    }

    return 0;
}