#include<stdio.h>

int main(int argc, char const *argv[]) {
  float x, // x coordinate
        y; // y coordinate

  // get coordinate values from the user
  printf("Please enter the x and y coordinates: ");
  scanf("%lf%lf", &x, &y);
  printf("(%.1lf, %.1lf)\n", x, y);

  // determine if the coordinates are on the origin
  if (x == 0.0 && y == 0.0) {
    printf("(%.1lf, %.1lf) is on the origin\n", x, y);
  }
  // determine if the coordinate values are on the y-axis
  if (x == 0.0 && y != 0.0) {
    printf("(%.1lf, %.1lf) is on the y-axis\n", x, y);
  }
  // determine if the coordinates are on the x-axis
  if (x != 0.0 && y == 0.0) {
    printf("(%.1lf, %.1lf) is on the x-axis\n", x, y);
  }

  // detrmine on which quadrant lie teh coordinates
  if (x > 0.0 && y > 0.0) {
    printf("(%.1lf, %.1lf) is in quadrant I\n", x, y);
  } else if (x < 0.0 && y > 0.0) {
    printf("(%.1lf, %.1lf) is in quadrant II\n", x, y);
  } else if (x < 0.0 && y < 0.0) {
    printf("(%.1lf, %.1lf) is in quadrant III\n", x, y);
  } else if (x < 0.0 && y < 0.0) {
    printf("(%.1lf, %.1lf) is in quadrant III\n", x, y);
  }

  return 0;
}
