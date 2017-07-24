#include <stdio.h>
#define KM_M 1000. // meters in a km
#define HR_SEC 3600. // seconds in an hour

int main(int argc, char const *argv[]) {
  double takeoff_v, catapult_s, v, t, a;

  // obtaine takeoff speed and catapult distance
  printf("Please enter the takeoff speed of the jet in km/hr > ");
  scanf("%lf", &takeoff_v);
  printf("Please enter the catapult distance in meters > ");
  scanf("%lf", &catapult_s);

  // convert takeoff_v to m/s
  v = takeoff_v * (KM_M / HR_SEC);
  // calculate time
  t = 2 * catapult_s / v;
  // calculate acceleration
  a = v / t;

  printf("The jet would accelerate at %.2lf m/s^2 for %.2lf seconds.", a, t);


  return 0;
}
