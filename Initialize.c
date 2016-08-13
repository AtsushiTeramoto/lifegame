#include <stdlib.h>
#include"Structures.h"
#include"Initialize.h"

#ifdef USE_INIT_ARRAY
#define INIT_ARRAY_MAX_X 10
#define INIT_ARRAY_MAX_Y 10
static bool init[INIT_ARRAY_MAX_X][INIT_ARRAY_MAX_Y] = 
{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};
#endif

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
    for (int i = 0; i < field->max_x; i++) {
        for (int j = 0; j < field->max_y; j++) {
#ifdef USE_INIT_ARRAY
            field->cells[i][j] = init[i][j];
#else
            field->cells[i][j] = 0;
#endif
        }
    }
}
struct lifegame_field* Initialize(const int max_x,const int max_y)
{
    struct lifegame_field *field;
    field = malloc_and_check(sizeof(struct lifegame_field));
#ifdef USE_INIT_ARRAY
    field->max_x = INIT_ARRAY_MAX_X;
    field->max_y = INIT_ARRAY_MAX_Y;
#else
    field->max_x = max_x;
    field->max_y = max_y;
#endif
    field->cells = Alloc_Cells(field->max_x,field->max_y);
    Preset_Cells(field);
    field->step = 0;
    return field;
}
