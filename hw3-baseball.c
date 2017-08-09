#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char const *argv[]) {
  // need to fscanf whatever txt file
  FILE *score_card; // text file useed to get data
  int input_status; // number of inputs obtained from the TXT file
  int player_number;
  char record[27]; // record given in hits, outs, walks, sacrifices, and hits by pitch
  int counter_hits; // counts number of hits
  int counter_outs; // counts number of outs
  double average; // player's batting average

  if (argc == 2) {
    score_card = fopen(argv[1], "r");
    // read the information from the text document
    // ()%s with a non-determined length is a really bad idea safety-wise)
    input_status = fscanf(score_card, "%d %s", &player_number, &record);

    while (input_status == 2){
      // set up counters for hits and outs to get the final average
      counter_hits = 0;
      counter_outs = 0;
      for (int i = 0; i < sizeof(record); i++) {
        char letter = record[i];
        // checks if the particular array element is filled with a letter
        if (isalpha(letter)) {
          // if filled, determined if it is one of the two important results
          if (letter == 'H') {
            // add up all the hits
            counter_hits++;
          } else if (letter == 'O') {
            // add up all the outs together
            counter_outs++;
          }
        }

      }
      // divide the number of hits by the number of hits + bats (at-bats)
      average = (double) counter_hits / (counter_hits + counter_outs);
      printf("Player %d's record: %s\n", player_number, record);
      printf("Player %d's batting average: %.3lf\n\n", player_number, average);
      // clear the string for the next player's records
      memset(record, '0', 27);
      // obtain next player's information from the TXT file
      input_status = fscanf(score_card, "%d %s", &player_number, &record);
    }
  }

  fclose(score_card);
  return 0;
}
