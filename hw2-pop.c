#include<stdio.h>

#define INIT_POP 52.966 // Gotham population in 1990
#define GROWTH_CONS 2.184 // population growth constant
#define INIT_YEAR 1990 // Initial year

int main(int argc, char const *argv[]) {
  FILE *pop; // pointer to input file
  int year; // year at which final population will be calculated
  double t; // amount of years since 1990 during which there was population growth
  double P; // final population

  pop = fopen("pop.txt", "w");
  // obtain desired year for which population is calculated
  printf("Enter a year after 1990> ");
  scanf("%d", &year);

  t = (double) year - INIT_YEAR;
  P = INIT_POP + GROWTH_CONS * t;

  fprintf(pop, "Predicted Gotham City population for %d (in thousands): ", year);
  fprintf(pop, "%.3lf", P);

  fclose(pop);
  return 0;
}
