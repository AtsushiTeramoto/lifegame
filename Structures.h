#include<stdbool.h>
struct lifegame_field
{
    int max_x;
    int max_y;
    bool **cells;
    int step;
    int max_step;
};
