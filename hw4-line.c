#include<stdio.h>

int get_problem();

void get2_pt(int *x1, int *y1, // first point coordinates
             int *x2, int *y2 // second point coordinates
           );

void get_pt_slope( double *m, // slope
                  int *x, int *y // point coordinates
                );

void slope_intcpt_from2_pt(int x1, int y1, // first point coordinates
                           int x2, int y2, // second point coordinates
                           double *m, // slope
                           double *b // y-intercept
                         );

double intcpt_from_pt_slope(int x, int y, double m);

void display2_pt(int x1, int y1, int x2, int y2);

void display_pt_slope(int x, int y, double m);

void display_slope_intcpt (double m, double y_int);


int main(int argc, char const *argv[]) {
  // this is a pain in the butt....
  int conv_form; // choice to use either two points or a point and a slope for the calculations
  int x_coor, y_coor; // first point's coordiantes
  int x_coor_1, y_coor_1; // second point's coordinates
  double slope; // slope of the line
  double b; // y-intercept of the line

  // set up the menu by having the user choose one of the two options
  conv_form = get_problem();

  // depending on the user's choice, the options will change the menu to reflect
  // which variables get filled and passed to the main program
  if (conv_form == 1) { // if two point form
    // ask the user for the four coordiantes that make up the points
    get2_pt(&x_coor, &y_coor, &x_coor_1, &y_coor_1);

  } else if (conv_form == 2) { // if slope and point
    // ask the user for the slope and the point
    get_pt_slope(&slope, &x_coor, &y_coor);

  }

  // depending on the user's choice, different calculations and different display messages come up
  if (conv_form == 1) {
    // calculate the slope and y-intercept using the two points
    slope_intcpt_from2_pt(x_coor, y_coor, x_coor_1, y_coor_1, &slope, &b);
    // displays the equation used to calculate the slope
    display2_pt(x_coor, y_coor, x_coor_1, y_coor_1);
    // displays the final slope-intercept equation
    display_slope_intcpt (slope, b);
  } else if (conv_form == 2) {
    // if slope is given, the y-intercept, or b, is calculated using the point and slope 
    b = intcpt_from_pt_slope(x_coor, y_coor, slope);
    // the equation used to calculate the y-intercept is displayed
    display_pt_slope(x_coor, y_coor, slope);
    // displayes the final slope-intercept equation
    display_slope_intcpt (slope, b);

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

void slope_intcpt_from2_pt(int x1, int y1, // first point coordinates
                           int x2, int y2, // second point coordinates
                           double *m, // slope
                           double *y_int // y-intercept
                           ){
  // calculates the slope using the coordinates of the two points
  *m = (double) (y2 - y1) / (x2 - x1);
  // calculates the y-intercept using the calculated slope and the first point
  *y_int = (double) (-x1 * *m) + y1;

}

double intcpt_from_pt_slope(int x, int y, double m){
  double y_int;
  // calculate the y-intercept from a slope and the coordinates of a point
  y_int = (double) (-x * m) + y;

  return y_int;
}

void display2_pt(int x1, int y1, int x2, int y2){
   // takes the four coordinates of submitted two points
   // displayes a two-point line equation with a heading
   printf("\nTwo-point form\n");
   printf("      (%.2lf- %.2lf)\n", (double) y2, (double) y1);
   printf("  m = -------------\n");
   printf("      (%.2lf - %.2lf)\n\n", (double) x2, (double) x1);
 }

void display_pt_slope(int x, int y, double m){
   printf("\nPoint-slope form\n");
   printf("  y - %.2lf = %.2lf(x - %.2lf)\n\n", (double) y, m, (double) x);
 }

void display_slope_intcpt (double m, double y_int){
  if (y_int < 0){
    // if the y-intercept is negative, the slope-intercept form has to change
    // because the sign is presented separately. This could be done for other display cases
    // if so desired (especially for display2_pt)
    y_int = -y_int;
    printf("Slope-intercept form\n");
    printf("  y = %.2lfx - %.2lf\n", m, y_int);
  } else { // if not negative (including zero) the equation should remain positive
    printf("Slope-intercept form\n");
    printf("  y = %.2lfx + %.2lf\n", m, y_int);
  }
}
