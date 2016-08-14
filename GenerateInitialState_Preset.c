#include<stdbool.h>
#define INIT_X_SIZE 10
#define INIT_Y_SIZE 10
static bool InitArray[INIT_X_SIZE][INIT_Y_SIZE] = 
{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};
void Preprocess_Initial_State(void)
{
    return;
}
void Postprocess_Initial_State(void)
{
    return;
}
bool get_init(const int i, const int j)
{
    return InitArray[i][j];
}
int get_max_x(void)
{
    return INIT_X_SIZE;
}
int get_max_y(void)
{
    return INIT_Y_SIZE;
}
    
