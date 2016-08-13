#include<Structures.h>
#include"Initialize.h"
#include"Run.h"
#include"Finalize.h"

int main(void)
{
    struct lifegame_field *field;
    field = Initialize(MAX_X,MAX_Y);
    Run(field);
    Finalize(field);
    return 0;
}

