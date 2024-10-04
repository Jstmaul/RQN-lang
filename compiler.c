#include "lexer.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

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

  int token_count;
  data_struct *data = maulLexer(fp,&token_count);

  fclose(fp);

  for (int i = 0; i < token_count; i++) {
    printf("character : %c , type : %s\n",data[i].character,data[i].character_type);

  }

  free(data);

  return EXIT_SUCCESS;
}
