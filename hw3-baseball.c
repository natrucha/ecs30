#include<stdio.h>
#include<string.h>
// wrong thing to use because it has to be a constant string
// mine's not a constant string...

int main(int argc, char const *argv[]) {
  // need to fscanf whatever txt file
  FILE *score_card;
  int input_status;
  int player_number;
  char record[30]; // record given in hits, outs, walks, sacrifices, and hits by pitch
  int counter_bats; // counts the total at-bats
  int counter_hits; // counts number of hits
  double average; // player's batting average

  if (argc == 2) {
    score_card = fopen(argv[1], "r");
    // read the information from the text document
    // ()%s with a non-determined length is a really bad idea safety-wise)
    input_status = fscanf(score_card, "%d %s", &player_number, &record);

    while (input_status == 2){
      // add up all the at-bat
      counter_bats = 0;
      counter_hits = 0;
      for (int i = 0; i < sizeof(record); i++) {
        counter_bats++;
        if (strcmp(record[i], "H") == 0) {
          // add up all the hits
          counter_hits++;
        } else if (strcmp(record[i], "O") == 0) {
          // subtract any at-bat that was an out
          counter_bats--;
        }
      }
      // divide the number of hits
      average = (double) counter_hits / counter_bats;
      printf("Player %d's record: %s\n", player_number, record);
      printf("Player %d's batting average: %.3lf\n\n", player_number, average);
    }
  }

  fclose(score_card);
  return 0;
}
