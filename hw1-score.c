#include <stdio.h>

int main(int argc, char const *argv[]) {
  char desired_grade;
  double min_average, curr_average, curr_grade, needed_points;
  double final_weight; // in percent, how much does the final test count to the final grade


  // get desired letter grade
  printf("Enter desired grade> ");
  scanf("%s", &desired_grade);

  // obtain minimum average required to get desired letter grade
  printf("Enter minimum average required> ");
  scanf("%lf", &min_average );

  // obtain current average
  printf("Enter current average in the course> ");
  scanf("%lf", &curr_average );

  // obtain final test weight on final grade
  printf("Enter how much the final counts\nas a percentage of the course grade> ");
  scanf("%lf", &final_weight);

  // calculate current class grade
  curr_grade = curr_average * (1 - final_weight / 100);

  // calculate test grade needed to get desired grade
  needed_points = 100 * ( (min_average - curr_grade) / final_weight );

  printf("\nYou need a score of %.2lf on the final to get a %c.", needed_points, desired_grade);

  return 0;
}
