#include<stdio.h>
#define BMI_CONST 703

int main(int argc, char const *argv[]) {
  int wt_lb, // user inputted weight in pounds
      ht_in; // user inputted height in inches
  double bmi; // resulting body mass index (BMI)

  // obtain user input
  printf("Please enter your weight in whole pounds: ");
  scanf("%d", &wt_lb);
  printf("Please enter your height in whole inches: ");
  scanf("%d", &ht_in);

  //calculate BMI
  bmi = (double)( BMI_CONST * wt_lb) / ( ht_in * ht_in );

  // determine if user is underweight, normal, overweight, or obese
  if (bmi < 18.5) {
    printf("You have a BMI of %.1lf, and your weight status as underweight.\n", bmi);
  } else if (bmi > 18.5 && bmi < 24.9 ){
    printf("You have a BMI of %.1lf, and your weight status as normal.\n", bmi);
  } else if ( bmi > 25.0 && bmi < 29.9){
    printf("You have a BMI of %.1lf, and your weight status as overweight.\n", bmi);
  } else {
    printf("You have a BMI of %.1lf, and your weight status as obese.\n", bmi);
  }

  return 0;
}
