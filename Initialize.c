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
static bool ** Alloc_Cells(const int max_x, const int max_y)
{
    bool **cells;
    cells = (bool **)malloc_and_check(sizeof(bool*)*max_x);
    for (int i = 0; i < max_x; i++) {
        cells[i] = (bool *)malloc_and_check(sizeof(bool)*max_y);
    }
    return cells;
}
static bool ***Alloc_Cells_History(const int max_index_of_history, const int max_x, const int max_y)
{
    bool ***cells_history;
    cells_history = (bool ***)malloc_and_check(sizeof(bool**)*max_index_of_history);
    for (int i = 0; i < max_index_of_history; i++) {
        cells_history[i] = Alloc_Cells(max_x,max_y);
    }
    return cells_history;
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
void set_pointers(struct lifegame_field *field, const int new_index)
{
    field->cells = field->cells_history[new_index];
    field->index_of_history = new_index;
}
struct lifegame_field* Initialize(void)
{
    struct lifegame_field *field;
    field = malloc_and_check(sizeof(struct lifegame_field));
    field->max_x = get_max_x();
    field->max_y = get_max_y();
    field->max_step = get_max_step();
    field->max_index_of_history = get_max_index_of_history();
    field->cells_history = Alloc_Cells_History(field->max_index_of_history,field->max_x,field->max_y);
    set_pointers(field,0);
    Preset_Cells(field);
    field->step = 0;
    return field;
}
