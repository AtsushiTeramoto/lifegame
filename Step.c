#include"Structures.h"
#include"Step.h"
#include"Initialize.h"
#include"Finalize.h"

enum State {DEATH, BIRTH, KEEP, INVERSE};
static const enum State dead_alive_array[] = {
    DEATH,
    DEATH,
    KEEP,
    BIRTH,
    DEATH,
    DEATH,
    DEATH,
    DEATH,
    DEATH
};
static bool get_Dead_or_Alive(const int count_neighbor,const bool dead_alive)
{
    switch(dead_alive_array[count_neighbor]){
        case DEATH:
            return false;
        case BIRTH:
            return true;
        case KEEP:
            return dead_alive;
        case INVERSE:
            return !dead_alive;
    }
}
static int Periodic_Index(const int i,const int max_i)
{
    if (i < 0) {
        return max_i-1;
    } else if (i >= max_i) {
        return 0;
    } else {
        return i;
    }
}

static int Count_Neighbor(const struct lifegame_field *field,const int x, const int y){
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                const int px = Periodic_Index(x+i,field->max_x);
                const int py = Periodic_Index(y+j,field->max_y);
                if (field->cells[px][py]) count++;
            }
        }
    }
    return count;
}
static bool get_new_value(const struct lifegame_field *field, const int x, const int y)
{
    const int count_neighbor = Count_Neighbor(field,x,y);    
    return get_Dead_or_Alive(count_neighbor,field->cells[x][y]);
}
static int get_next_index_of_history(const struct lifegame_field *field)
{
    return (field->index_of_history + 1 < field->max_index_of_history) ? field->index_of_history + 1 : 0;
}
void Step(struct lifegame_field *field)
{
    const int next_index_of_history = get_next_index_of_history(field);
    for (int i = 0; i < field->max_x; i++) {
        for (int j = 0; j < field->max_y; j++) {
            field->cells_history[next_index_of_history][i][j] = get_new_value(field,i,j);
        }
    }
    set_pointers(field, next_index_of_history);
    field->step++;
}
