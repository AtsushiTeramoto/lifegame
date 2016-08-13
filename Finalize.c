#include<stdlib.h>
#include"Structures.h"
#include"Finalize.h"
void Free_Cells(struct lifegame_field *field)
{
    for (int i = 0; i < field->max_x; i++){
        free(field->cells[i]);
    }
    free(field->cells);
}

void Finalize(struct lifegame_field *field)
{
    Free_Cells(field);
}
