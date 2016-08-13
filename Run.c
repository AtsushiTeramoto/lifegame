#include"Structures.h"
#include"Run.h"
#include"Step.h"
#include"Output.h"

void Run(struct lifegame_field *field)
{
    Output(field);
    while (field->step < STEP_MAX) {
        Step(field);
        Output(field);
    }
}
