#include "lexer.h"
#include "type.h"
#include <ctype.h>
#include <stdio.h>

data_struct *maulLexer(FILE *fp, int *token_count) {
  int ch;
  int i = 0;
  int data_capacity = 1;

  char *character;

  data_struct *data =
      (data_struct *)malloc(data_capacity * sizeof(data_struct));
  if (data == NULL) {
    printf("FAILED ALLOC DATA\n");
    exit(EXIT_FAILURE);
  }

  while ((ch = (int)fgetc(fp)) != EOF) {
    printf("lexer : %c\n", ch);

    if (i >= data_capacity) {
      data_capacity++;
      data = realloc(data, data_capacity * sizeof(data_struct));
      if (data == NULL) {
        printf("FAILED ALLOC DATA\n");
        exit(EXIT_FAILURE);
      }
    }
    if (isalpha(ch)) {
      data[i].character = ch;
      data[i].character_type = "name";
    } else if (isdigit(ch)) {
      data[i].character = ch;
      data[i].character_type = "digit";
    } else if (ch == '\n') {
      data[i].character = ch;
      data[i].character_type = "new_line";
    } else if (ch == ' ') {
      data[i].character = ch;
      data[i].character_type = "space";
    } else if (ch == '{') {
      data[i].character = ch;
      data[i].character_type = "left_bracket";
    } else if (ch == '}') {
      data[i].character = ch;
      data[i].character_type = "right_bracket";
    } else if (ch == '(') {
      data[i].character = ch;
      data[i].character_type = "left_parent";
    } else if (ch == ')') {
      data[i].character = ch;
      data[i].character_type = "right_parent";
    } else {
      printf("unworked character :  %d\n", ch);
      continue;
    }
    if (data[i].character)
      printf("[SUCCES]\n");
    i++;
  }
  *token_count = i;

  return data;
}
