#include <stdio.h>
#define REINB_RATE .35

int main(int argc, char const *argv[]) {
  double beg_odo, end_odo, total_mileage, reinbursement;

  printf("MILEAGE REINBURSEMENT CALCULATOR\n");

  // get odometer readings
  printf("Enter beginning odometer reading=> ");
  scanf("%lf", &beg_odo );
  //get ending mileage
  printf("Enter ending odometer reading=> ");
  scanf("%lf", &end_odo);

  //calculate total mileage
  total_mileage = end_odo - beg_odo;
  //calculate reinbursement using given rate
  reinbursement = total_mileage * REINB_RATE;
  printf("You traveled %.1f miles. At $.35 per mile, \nyour reinbursement is $%.2f.", total_mileage, reinbursement);
  return 0;
}
