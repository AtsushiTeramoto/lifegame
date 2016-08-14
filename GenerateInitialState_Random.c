#include<gsl/gsl_rng.h>
#include<stdbool.h>
#include"GenerateInitialState.h"
static gsl_rng *r;
void Preprocess_Initial_State(void)
{
    r = gsl_rng_alloc(gsl_rng_default);
}
void Postprocess_Initial_State(void)
{
    gsl_rng_free(r);
}
int get_max_x(void)
{
    return MAX_X;
}
int get_max_y(void)
{
    return MAX_Y;
}
int get_max_step(void)
{
    return MAX_STEP;
}
int get_max_index_of_history(void)
{
    return MAX_HISTORY;
}
bool get_init(const int i,const int j)
{
    return (gsl_rng_uniform(r) < 0.5) ? false : true;
}
