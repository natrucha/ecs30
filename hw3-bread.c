#include<stdio.h>

/*********************** REQUIREMENTS ***********************/

// have to create a calc_bake_time function and a display_instructions function
// trying to minimize the amount of if statments in the calc_baking_time function to below four

/*********************** PROGRESS ***********************/

// First user choice does change between white and sweet bread
// for some reason scanf is reading the [return] key stroke as one of the choices

/*********************** PRINT ***********************/

void display_instructions(char manual, int bake_sec, int p_kneading, int p_rising, int s_kneading, int s_rising, int loaf_shaping, int f_rising, int baking, int cooling, int baking_time_min, int baking_time_sec){

  // print the stuff that gets printed no matter what
  printf("Primary kneading: %d minutes\n", p_kneading);
  printf("Primary rising: %d minutes\n", p_rising);
  printf("Secondary kneading: %d minutes\n", s_kneading);
  printf("Secondary rising: %d minutes\n", s_rising);
  printf("Loaf shaping: %d seconds\n", loaf_shaping);

  if (manual == 'y' || manual == 'Y') {
    // if manual, stop there, add instructions to take it out
    printf("You should remove the dough for manual baking.\n\n");
  } else {
    // if the user did not choose manual, print everything else
    printf("Final rising: %d minutes\n", f_rising);
    printf("Baking: %d minutes %d seconds\n", baking, bake_sec);
    printf("Cooling: %d minutes\n\n", cooling);
  }
  // print total baking time
  printf("For a total baking time of %d minutes and %d seconds.\n", baking_time_min, baking_time_sec);
}

/*********************** CALCULATE ***********************/

void calc_baking_time(char bread_type, char loaf_type, char manual) {
  // set basic values for the time of each process
  int p_kneading = 15; // time for Primary kneading in minutes
  int p_rising = 60; // time for primary rising in minutes
  int s_kneading = 18; // time for secondary kneading in minutes
  int s_rising = 20; // time for secondary rising in minutes
  int loaf_shaping = 2; // time fo loaf shaping in seconds
  int f_rising = 75; // time for final rising in minutes
  int baking = 45; // time to bake in minutes
  int cooling = 30; // time to cool in minutes

  int baking_time_min; // total baking time minutes
  int bake_sec = 0; // baking time in seconds
  int baking_time_sec = 0; // total baking time seconds

  // if sweet bread desired
  if (bread_type == 's' || bread_type == 'S') {
    // change the necessary time values for sweet bread
    p_kneading = 20;
    s_kneading = 33;
    s_rising = 30;
    baking = 35;
  }

  // if the loaf type desired is double
  if (loaf_type == 'd' || loaf_type == 'D') {
    // increase the baking time by 50%
    baking = baking * 1.5;
    bake_sec = 30; // because I'm keeping everything as an int and the seconds go poof
  }

  baking_time_min = p_kneading + p_rising + s_kneading + s_rising;
  // if the user chooses not to make it manual, add f_rising, baking, and cooling
  if (manual == 'n' || manual == 'N') {
    baking_time_min = baking_time_min + f_rising + baking + cooling;
  }

  // finish adding in the loaf shaping seconds to the total seconds
  baking_time_sec = bake_sec + loaf_shaping;

  // call the display instructions function
  display_instructions(manual, bake_sec, p_kneading, p_rising, s_kneading, s_rising, loaf_shaping, f_rising, baking, cooling, baking_time_min, baking_time_sec);
  //return 0;
}

/*********************** MAIN ***********************/

int main(int argc, char const *argv[]) {
  char bread_type; // set white bread or sweet bread
  char loaf_type; // single or double loaf
  char manual; // set if the baking will be manual

  // obtain user input
  printf("Are you making white or sweet bread (w or s)? ");
  scanf("%c", &bread_type);
  printf("Is this a single or double loaf (s or d)? ");
  scanf(" %c", &loaf_type);
  printf("Are you going to bake manually (y or n)? ");
  scanf(" %c", &manual);

  // debugging
  //printf("%c %c %c\n", bread_type, loaf_type, manual);

  calc_baking_time(bread_type, loaf_type, manual);

  return 0;
}
