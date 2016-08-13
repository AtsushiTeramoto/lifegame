#include <stdlib.h>
#include"Structures.h"
#include"Initialize.h"

bool ** Alloc_Cells(int max_x, int max_y)
{
    bool **cells;
    cells = (bool **)malloc(sizeof(bool*)*max_x);
    for (int i = 0; i < max_x; i++) {
        cells[i] = (bool *)malloc(sizeof(bool)*max_y);
    }
    return cells;
}
void Assign_Cells(struct lifegame_field *field ,bool **new_cells)
{
    field->cells = new_cells;
}
static void Preset_Cells(struct lifegame_field *field)
{
    for (int i = 0; i < field->max_x; i++) {
        for (int j = 0; j < field->max_y; j++) {
            field->cells[i][j] = (((i+j)*(i)*(j-i))%7 != 0);
        }
    }
}
struct lifegame_field* Initialize(int max_x,int max_y)
{
    struct lifegame_field *field;
    field = malloc(sizeof(struct lifegame_field));
    field->max_x = max_x;
    field->max_y = max_y;
    field->cells = Alloc_Cells(field->max_x,field->max_y);
    Preset_Cells(field);
    field->step = 0;
    return field;
}
