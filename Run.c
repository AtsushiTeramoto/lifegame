#include"Structures.h"
#include"Run.h"
#include"Step.h"
#include"Output.h"

void Run(struct lifegame_field *field)
{
    Output(field);
    while (field->step < field->max_step) {
        Step(field);
        Output(field);
    }
}
