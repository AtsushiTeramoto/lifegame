#include<stdio.h>
#include"Structures.h"
#include"Output.h"
void Output(struct lifegame_field *field)
{
    for (int i = 0; i < field->max_x; i++) {
        for (int j = 0; j < field->max_y; j++) {
            if (field->cells[i][j]){
                printf(" * ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}
