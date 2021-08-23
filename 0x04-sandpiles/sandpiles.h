#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void loop_and_overflow(int grid1[3][3], int grid2[3][3]);
void grid_overflow(int grid1[3][3], int grid2[3][3]);
int check_overflow(int num, int *over);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
