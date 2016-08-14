#include<stdbool.h>
struct lifegame_field
{
    int max_x;
    int max_y;
    bool **cells;
    bool ***cells_history;
    int index_of_history;
    int max_index_of_history;
    int step;
    int max_step;
};
