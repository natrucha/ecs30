#include <stdio.h>
#define FPM 5280. // number of feet in a mile
#define FPK 3282. // number of feet in a kilometer

int main(int argc, char const *argv[]) {

  double minutes; // total scanned race time minutes; should input an integer but would have to conver to float
  double seconds; // total scanned race time seconds
  double total_seconds; // total time in seconds
  double fps; // feet per second achieved by runner
  double mps; // meters per second achieved by runner

  printf("This program will ask for the minutes and seconds for the time it\n");
  printf("took for a runner to run a mile.  The program will then calculate\n");
  printf("the feet per second and meters per second for that runner\n\n");\

  // obtain race time seconds and minutes
  printf("Minutes for the runner: ");
  scanf("%lf", &minutes);
  printf("Seconds for the runner: ");
  scanf("%lf", &seconds);

  // convert minutes to seconds and add to seconds to get total time in seconds
   total_seconds = (minutes * 60.) + seconds;
   printf("seconds %lf\n", total_seconds);

   // calculate fps
   fps = FPM / total_seconds;
   // calculate mps
   mps = fps * 1000. / FPK;

   printf("That is %.1lf feet per second, and %.2lf meters per second for that runner.", fps, mps);

  return 0;
}
