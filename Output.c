#include<stdio.h>
#include"Structures.h"
#include"Output.h"
void Output(const struct lifegame_field *field)
{
    printf("step = %d\n",field->step);
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
