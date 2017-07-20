#include<stdio.h>

#define so_many_miles 50000 // cutoff for to determine lots of miles

int main(int argc, char const *argv[]) {
  int p_number; // pollutant number
  double gr_mi; // grams per mile
  int odo; // odometer reading

  // obtain information from user
  printf("(1) Carbon monoxide\n(2) Hydrocarbons\n(3) Nitrogen oxides\n(4) Nonmethane hydrocarbons\n");
  printf("Enter pollutant number>> ");
  scanf("%d", &p_number);
  printf("Enter number of grams emitted per mile>> ");
  scanf("%lf", &gr_mi);
  printf("Enter the odometer reading>> ");
  scanf("%d", &odo);

  // begin by checking the odometer to see if the milage is above 50,000 miles
  if(odo <= so_many_miles){
    // check what emission type was chosen and check if the emissio amount of that type exceeds permitted amount
    switch (p_number) {
      case 1:
        if(gr_mi <= 3.4){
          printf("Emissions do not exceed permitted level of 3.40 grams/mile.\n");
        } else {
          printf("Emissions exceed permitted level of 3.40 grams/mile.\n");
        }
        break;
      case 2:
        if(gr_mi <= 0.31){
          printf("Emissions do not exceed permitted level of 0.31 grams/mile.\n");
        } else {
          printf("Emissions exceed permitted level of 0.31 grams/mile.\n");
        }
        break;
      case 3:
        if(gr_mi <= 0.4){
          printf("Emissions do not exceed permitted level of 0.40 grams/mile.\n");
        } else {
          printf("Emissions exceed permitted level of 0.40 grams/mile.\n");
        }
        break;
      case 4:
        if(gr_mi <= 0.25){
          printf("Emissions do not exceed permitted level of 0.25 grams/mile.\n");
        } else {
          printf("Emissions exceed permitted level of 0.25 grams/mile.\n");
        }
        break;
      default:
        printf("Error: Not a valid option. Please restart and enter a valid emission type number.\n");
    }
  } else if(odo > so_many_miles){
    // check odometer is above 50,000 miles... probably could be as else
    // check what emission type was chosen and check if the emissio amount of that type exceeds permitted amount
    switch (p_number) {
      case 1:
        if(gr_mi <= 4.2){
          printf("Emissions do not exceed permitted level of 4.20 grams/mile.\n");
        } else {
          printf("Emissions exceed permitted level of 4.20 grams/mile.\n");
        }
        break;
      case 2:
        if(gr_mi <= 0.39){
          printf("Emissions do not exceed permitted level of 0.39 grams/mile.\n");
        } else {
          printf("Emissions exceed permitted level of 0.39 grams/mile.\n");
        }
        break;
      case 3:
        if(gr_mi <= 0.5){
          printf("Emissions do not exceed permitted level of 0.50 grams/mile.\n");
        } else {
          printf("Emissions exceed permitted level of 0.50 grams/mile.\n");
        }
        break;
      case 4:
        if(gr_mi <= 0.31){
          printf("Emissions do not exceed permitted level of 0.31 grams/mile.\n");
        } else {
          printf("Emissions exceed permitted level of 0.31 grams/mile.\n");
        }
        break;
      default:
        printf("Error: Not a valid option. Please restart and enter a valid emission type number.\n");
    }
  }
  return 0;
}
