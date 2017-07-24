#include<stdio.h>

int main(int argc, char const *argv[]) {
  double x; // x-coordinate
  double y; // y-coordinate

  printf("Please enter the x and y coordinates: ");
  scanf("%lf %lf", &x, &y);

  if (x == 0 && y == 0) {
    printf("(%.1lf, %.1lf) is the origin\n", x, y);
  } else if (x == 0 && y != 0) {
    printf("(%.1lf, %.1lf) is on the y axis\n", x, y);
  } else if (x != 0 && y == 0) {
    printf("(%.1lf, %.1lf) is on the x axis\n", x, y);
  }

  if (x > 0 && y > 0) {
    printf("(%.1lf, %.1lf) is in quadrant I\n", x, y);
  } else if (x < 0 && y > 0) {
    printf("(%.1lf, %.1lf) is in quadrant II\n", x, y);
  } else if (x < 0 && y < 0) {
    printf("(%.1lf, %.1lf) is in quadrant III\n", x, y);
  } else if (x > 0 && y < 0 ) {
    printf("(%.1lf, %.1lf) is in quadrant IV\n", x, y);
  }
  return 0;
}
