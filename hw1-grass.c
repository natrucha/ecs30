#include <stdio.h>
#define GRASS_CUT_RATE 2 // in ft^2/sec

int main(int argc, char const *argv[]) {
  int length_yard, width_yard, length_house, width_house;
  int yard_area, house_area, grass_area, time_sec, minutes, seconds;

  // obtain yard measurements
  printf("Please enter the length and width of the yard > ");
  scanf("%d %d", &length_yard, &width_yard );

  // obtain house measurements
  printf("Please enter the length and width of the house > ");
  scanf("%d %d", &length_house, &width_house );

  // calculate area of yard
  yard_area = length_yard * width_yard;
  // calculate area of house
  house_area = length_house * width_house;
  //calculate area of grass to cut
  grass_area = yard_area - house_area;
   // calculate time, in seconds, required to cut all the grass
  time_sec = grass_area / GRASS_CUT_RATE;
  // conver seconds to minutes
  minutes = time_sec / 60;
  // find the amount of left over seconds
  seconds = time_sec - (minutes * 60);

  printf("%d square feet will take %d minutes and %d seconds to cut.", grass_area, minutes, seconds);

  return 0;
}
