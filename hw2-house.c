#include <stdio.h>

int main(int argc, char const *argv[]) {
  int initial_cost; // initial one time house cost in whole dollars
  int annual_cost; // annual fuel cost in whole dollars
  double tax_rate; // tax rate in real numbers
  double total_cost;

  printf("This program determines the total cost of owning a home for five years.\n");
  printf("The user will enter inital cost in whole dollars, annual fuel costs in\n");
  printf("whole dollars, and the annual tax rate as a real number\n\n");

  // Obtain the initial cost, annual cost, and tax rate
  printf("Please enter the initial cost, fuel cost, and tax rate: ");
  scanf("%d %d %lf", &initial_cost, &annual_cost, &tax_rate);

  // calculate total cost
  total_cost = (double) initial_cost + 5 * ( (initial_cost * tax_rate) + annual_cost );
  printf("The total cost is $%.2lf\n", total_cost);

  return 0;
}
