#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_BUFFER_SIZE 1024
#define LINE_BUFFER_SIZE 10000
char word_buffer[WORD_BUFFER_SIZE], line_buffer[LINE_BUFFER_SIZE];

void wc(FILE *ofile, FILE *infile, char *inname) {
  int char_count = 0;
  int word_count = 0;
  int line_count = 0;
  while(fgets(line_buffer, LINE_BUFFER_SIZE, infile) != NULL){
    line_count++;
    char_count += strlen(line_buffer); 
    int offset;
    char * current_position = line_buffer;
    while(sscanf(current_position, "%s%n", word_buffer, &offset) == 1){
      word_count++;
      current_position += offset;
    }
  }
  fprintf(ofile, "%d %d %d %s\n", line_count, word_count, char_count, inname);
}

int main (int argc, char *argv[]) {
   if(argc != 3){
    printf("The program need two arguments: input file path and output file path.\n");
    return -1;
   }
  char *inname = argv[1];
  FILE *infile = fopen(inname, "r");
  FILE *ofile = fopen(argv[2], "w");
  
  wc(ofile, infile, inname);  
  return 0;
}
