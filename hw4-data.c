#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[]) {
  FILE *numbers;
  int input_status;
  int num_num; // number of numbers in file
  double sml_num = 1000; // smallest number
  double lrg_num = 0; // largest number
  double average; // average of all the numbers
  double std_dev; // standard deviation
  double sum_squares = 0; // sum of the squares of the numbers
  double sum_num = 0; // total after adding all numbers
  double get_num;

  if (argc == 2) {
    numbers = fopen(argv[1], "r");
    // get the number of numbers in the TXT file
    input_status = fscanf(numbers, "%d", &num_num);

    for (int i = 0; i < num_num; i++) {
      // get new number in list
      input_status = fscanf(numbers, "%lf", &get_num);
      printf("newest number on list: %lf\n", get_num);
      // add it to the other numbers from the list
      sum_num = sum_num + get_num;
      // get the square and add it into sum of squares
      sum_squares = sum_squares + (get_num * get_num);

      // check if number is bigger than the last one
      if (get_num > lrg_num) {
        lrg_num = get_num;
      }

      // check if number is smaller than the last one
      if (get_num < sml_num) {
        sml_num = get_num;
      }
    }
  }

  // calculate the average
  average = sum_num / num_num;
  // calculate the standard deviation
  std_dev = sqrt((sum_squares / num_num) - (average * average));

  printf("Smallest: %.2lf\n", sml_num);
  printf("Largest:  %.2lf\n", lrg_num);
  printf("Average:  %.2lf\n", average);
  printf("Standard deviation: %.2lf\n", std_dev);

  fclose(numbers);
  return 0;
}
