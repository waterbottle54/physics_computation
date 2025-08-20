
#include <stdio.h>
#include <math.h>

void calc_tag_position(
    double* x, double* y, double *z,
    double dist0, double distx, double disty, 
    double x_anchorx, double y_anchory)
{
    double d0 = dist0;
    double dx = distx;
    double dy = disty;
    double xa = x_anchorx;
    double ya = y_anchory;
    double d02 = pow(d0, 2);
    double dx2 = pow(dx, 2);
    double dy2 = pow(dy, 2);
    *x = (d02 - dx2)/(2*xa) + (xa/2);
    *y = (d02 - dy2)/(2*ya) + (ya/2);
    *z = sqrt(d02 - pow(*x, 2) - pow(*y, 2));
}

int main()
{
    double x_anchorx = 1.0;
    double y_anchory = 1.0;
    double dist0 = 1.4142;
    double distx = 1.0;
    double disty = 1.0;
    double x, y, z;
    
    calc_tag_position(&x, &y, &z, dist0, distx, disty, x_anchorx, y_anchory);
    printf("coord = (%.2lf, %.2lf, %.2lf) \n", x, y, z);

    return 0;
}
