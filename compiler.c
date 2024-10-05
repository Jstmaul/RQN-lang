#include "lexer.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

int lexer_token_count;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("give some input bro\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("no file with that name detected bro\n");
    return 1;
  }

  lexer_data_struct *lexer_data = maulLexer(fp,&lexer_token_count);

  fclose(fp);



  for (int i = 0; i < lexer_token_count; i++) {
    printf("character : %c , type : %s\n",lexer_data[i].character,lexer_data[i].character_type);

  }

  free(lexer_data);

  return EXIT_SUCCESS;
}
