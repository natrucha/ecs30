#include<stdio.h>

// switch these around because we are using those numers to know the type of beer
// not the name of the beer
#define PIELS 1
#define COORS 2
#define BUD 3
#define IRON 4

int main(int argc, char const *argv[]) {
  FILE *inventory;
  int input_status;
  int p_num; // inventory piels
  int c_num; // inventory coors
  int b_num; // inventory bud
  int i_num; // inventory iron city
  int id_num; // ID number of the beer in the transaction line
  int change; // how many beers were sold in that transaction line

  if (argc == 2) {
    inventory = fopen(argv[1], "r");
    // get the inventory of each type of beer
    input_status = fscanf(inventory, "%d %d %d %d", &p_num, &c_num, &b_num, &i_num);
    // obtaine the first transaction
    input_status = fscanf(inventory, "%d %d", &id_num, &change);

    while (input_status == 2) {
      // figure out what beer brand inventory changes and add the change
      switch (id_num) {
        case PIELS :
          p_num = p_num + change;
          break;
        case COORS :
          c_num = c_num + change;
          break;
        case BUD :
          b_num = b_num + change;
          break;
        case IRON :
          i_num = i_num + change;
          break;
      }
      // get the next transaction line
      input_status = fscanf(inventory, "%d %d", &id_num, &change);
    }
  }
  // print out the results for each
  printf("Piels: %10d\n", p_num);
  printf("Coors: %10d\n", c_num);
  printf("Bud: %12d\n", b_num);
  printf("Iron City: %6d\n", i_num);

  fclose(inventory);
  return 0;
}
