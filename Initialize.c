#include <stdlib.h>
#include"Structures.h"
#include"Initialize.h"
#include"GenerateInitialState.h"

static void* malloc_and_check(const size_t size)
{
    void *p = malloc(size);
    if (p == NULL) {
        abort();
    }
    return p;
}
bool ** Alloc_Cells(const int max_x, const int max_y)
{
    bool **cells;
    cells = (bool **)malloc_and_check(sizeof(bool*)*max_x);
    for (int i = 0; i < max_x; i++) {
        cells[i] = (bool *)malloc_and_check(sizeof(bool)*max_y);
    }
    return cells;
}
void Assign_Cells(struct lifegame_field *field ,bool **new_cells)
{
    field->cells = new_cells;
}
static void Preset_Cells(struct lifegame_field *field)
{
    Preprocess_Initial_State();
    for (int i = 0; i < field->max_x; i++) {
        for (int j = 0; j < field->max_y; j++) {
            field->cells[i][j] = get_init(i,j);
        }
    }
    Postprocess_Initial_State();
}
struct lifegame_field* Initialize(void)
{
    struct lifegame_field *field;
    field = malloc_and_check(sizeof(struct lifegame_field));
    field->max_x = get_max_x();
    field->max_y = get_max_y();
    field->cells = Alloc_Cells(field->max_x,field->max_y);
    Preset_Cells(field);
    field->step = 0;
    return field;
}
