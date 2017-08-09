#include<stdio.h>
#include<ctype.h>
// works fine on baseball.txt, but doen't on baseball2.txt
// looks like it overwrites over the previous string
// but if the previous string is longer, those slots don't get overwritten


int main(int argc, char const *argv[]) {
  // need to fscanf whatever txt file
  FILE *score_card;
  int input_status;
  int player_number;
  char record[27]; // record given in hits, outs, walks, sacrifices, and hits by pitch
  int counter_bats; // counts the total at-bats
  int counter_hits; // counts number of hits
  int counter_outs; // counts number of outs
  double average; // player's batting average

  if (argc == 2) {
    score_card = fopen(argv[1], "r");
    // read the information from the text document
    // ()%s with a non-determined length is a really bad idea safety-wise)
    input_status = fscanf(score_card, "%d %s", &player_number, &record);

    printf("player number: %d, record: %s\n", player_number, record);

    while (input_status == 2){
      // add up all the at-bat
      counter_bats = 0;
      counter_hits = 0;
      counter_outs = 0;
      for (int i = 0; i < sizeof(record); i++) {
        char letter = record[i];
        // checks if the particular array element is filled
        if (isalpha(letter)) {
          // if filled, add to the counter for batting
          counter_bats++;
          printf("%d\n", counter_bats);
          printf("letter of record at loop: %c\n", letter);
          if (letter == 'H') {
            // add up all the hits
            counter_hits++;
            printf("Hit added\n");
          } else if (letter == 'O') {
            // subtract any at-bat that was an out
            counter_outs++;
            printf("Out added\n");
          }
        }

      }
      // divide the number of hits
      average = (double) counter_hits / (counter_hits + counter_outs);
      printf("Player %d's record: %s\n", player_number, record);
      printf("Player %d's batting average: %.3lf\n\n", player_number, average);
      input_status = fscanf(score_card, "%d %s", &player_number, &record);
    }
  }

  fclose(score_card);
  return 0;
}
