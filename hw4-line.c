#include<stdio.h>

int get_problem();

void get2_pt(int *x1, int *y1, // first point coordinates
             int *x2, int *y2 // second point coordinates
           );

void get_pt_slope( double *m, // slope
                  int *x, int *y // point coordinates
                );


int main(int argc, char const *argv[]) {
  // this is a pain in the butt....
  int conv_form;
  int x_coor, y_coor;
  int x_coor_1, y_coor_1;
  double slope;
  double b;

  // set up the menu by having the user choose one of the two options
  conv_form = get_problem();
  /*printf("Select the form that you would like to convert to slope-intercept form:\n");
  printf("1) Two-point form (you know two points on the line)\n");
  printf("2) Point-slope form (you know the line's slope and one point)\n");
  printf("=> ");
  scanf("%d", &conv_form);
  printf("choice %d\n", conv_form);*/

  // depending on the user's choice, the options will change the menu to reflect
  // which variables get filled and passed to the main program
  if (conv_form == 1) {
    get2_pt(&x_coor, &y_coor, &x_coor_1, &y_coor_1);
    /*printf("Enter the x-y coordinates of the first point separted by a space=> ");
    scanf("%d %d", &x_coor, &y_coor);
    printf("Enter the x-y coordinates of the second point separated by a space=> ");
    scanf("%d %d", &x_coor_1, &y_coor_1);
    */
  } else if (conv_form == 2) {
    get_pt_slope(&slope, &x_coor, &y_coor);
    /*printf("Enter the slope=> ");
    scanf("%lf", &slope);
    printf("Enter the x-y coordinates of the point separated by a space=> ");
    scanf("%d %d", &x_coor, &y_coor);
    */
  }

  if (conv_form == 1) {
    slope = (double) (y_coor_1 - y_coor) / (x_coor_1 - x_coor);
    b = (double) (-x_coor * slope) + y_coor;

    printf("\nTwo-point form\n");
    printf("      (%.2lf- %.2lf)\n", (double) y_coor_1, (double) y_coor);
    printf("  m = -------------\n");
    printf("      (%.2lf - %.2lf)\n\n", (double) x_coor_1, (double) x_coor);
    printf("Slope-intercept form\n");
    printf("  y = %.2lfx + %.2lf\n", slope, b);

  } else if (conv_form == 2) {
    b = (double) (-x_coor * slope) + y_coor;

    printf("\nPoint-slope form\n");
    printf("  y - %.2lf = %.2lf(x - %.2lf)\n\n", (double) y_coor, slope, (double) x_coor);
    printf("Slope-intercept form\n");
    printf("  y = %.2lfx + %.2lf\n", slope, b);

  }

  return 0;
}


int get_problem(){
  int conv_option;

  // displays the user menu and returns the problem number selected to main
  printf("Select the form that you would like to convert to slope-intercept form:\n");
  printf("1) Two-point form (you know two points on the line)\n");
  printf("2) Point-slope form (you know the line's slope and one point)\n");
  printf("=> ");
  scanf("%d", &conv_option);

  return conv_option;
}

void get2_pt(int *x1, int *y1, // first point coordinates
             int *x2, int *y2 // second point coordinates
            ){
  printf("Enter the x-y coordinates of the first point separted by a space=> ");
  scanf("%d %d", x1, y1); // gets the coordinate for the first point
  printf("Enter the x-y coordinates of the second point separated by a space=> ");
  scanf("%d %d", x2, y2); // gets the coordinates for the second point
}

void get_pt_slope( double *m, // slope
                   int *x, int *y // point coordinates
                 ){
  printf("Enter the slope=> ");
  scanf("%lf", m);
  printf("Enter the x-y coordinates of the point separated by a space=> ");
  scanf("%d %d", x, y);
}
