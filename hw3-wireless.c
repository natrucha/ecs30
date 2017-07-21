#include<stdio.h>

#define GIVEN_MIN 600
#define FLAT_RATE 3999 // rate for 600 minutes in cents
#define AD_COST 40 // cost per minute over 600 minutes in cents
#define TAXES 0.0525 // taxes on all charges

int main(int argc, char const *argv[]) {
  int weekday; // number of weekday minutes used
  int night; // number of night minutes used
  int weekend; // number of weekend minutes used
  int extra_min; // number of extra minutes
  int extra_cost; // cost of extra minutes
  int cost; // before taxes bill in cents
  int tot_min; // total number of minutes used
  double avg_cost; // average cost of each minute
  double cost_dollars; // before taxes bill in dollars
  double tax; // taxes calculated for the bill
  double tot_cost; // bill after taxes

  // Obtain user input
  printf("Please enter the number of weekday minutes, night minutes: ");
  scanf("%d %d", &weekday, &night);
  printf("Please enter the number of weekend minutes: ");
  scanf("%d", &weekend);

  // Print the number of minutes
  printf("\nWeekday minues: %d, night minutes: %d, weekend minutes: %d\n", weekday, night, weekend);

  // check if minutes exceed 600
  if (weekday > GIVEN_MIN){
    // if so get the amount of extra minutes
    extra_min = weekday - GIVEN_MIN;
    extra_cost = extra_min * AD_COST; // multiply by cost of extra minutes to get additional costs
    cost = extra_cost + FLAT_RATE; // add costs together to get total
  } else {
    // if the number of minutes is below the amount paid for in the flat rate, there are no extra charges
    cost = FLAT_RATE;
  }

  // add up all the minutes to get the average minute cost
  tot_min = weekday + weekend + night;
  avg_cost = (double) cost / (tot_min * 100); // in dollars

  printf("Average minute cost: %.2lf\n", avg_cost);

  // get the cost in dollars and calculate taxes
  cost_dollars = (double) cost / 100; // in dollars
  tax = cost * TAXES / 100; // in dollars
  // Add cost and taxes to get the final bill
  tot_cost = cost_dollars + tax;

  printf("Pretax bill: $%.2lf\n", cost_dollars);
  printf("Taxes:       $%.2lf\n", tax);
  printf("Total bill:  $%.2lf\n", tot_cost);

  return 0;
}
