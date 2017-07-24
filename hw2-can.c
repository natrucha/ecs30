#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[]) {
  // uses can.tx which has the information as:
  // radius ** height ** cost per square centimeter ** quantity
  FILE *cans; // pointer to input file
  int input_status;
  double radius, height, cost, quantity; // variables from text file. Measurements in cm.
  double surface_area, run_cost; // calculated variables
  int counter;

  // prepare file for input
  cans = fopen("cans.txt", "r");

  printf("This program calculates the cost of material for three open-top cylindrical\n");
  printf("containers.  It reads the radius, height, cost per square centimeter, and\n");
  printf("quantity for each container from the file cans.txt. Each line in cans.txt has\n");
  printf("the format: radius height cost_per_sq_cm quantity.\n\n");

  // read four lines of information from text document, calculate the surface_area and run_cost
  input_status = fscanf(cans, "%lf %lf %lf %lf", &radius, &height, &cost, &quantity);
  // check what number should be used to run the while loop
  //printf("input status: %d\n", input_status);
  counter = 0;
  while (input_status == 4) {
    counter++;
    surface_area = (M_PI * radius * radius) + (M_PI * 2. * radius * height); // cm^2
    run_cost = (surface_area * cost) * quantity; // $
    printf("Each can #%d has surface area %.3lf, and the run will cost $%.2lf.\n", counter, surface_area, run_cost);
    input_status = fscanf(cans, "%lf %lf %lf %lf", &radius, &height, &cost, &quantity);
  }


  fclose(cans);
  return 0;
}
