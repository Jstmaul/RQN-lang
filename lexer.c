#include "lexer.h"
#include "type.h"
#include <ctype.h>
#include <stdio.h>


int lexer_token_count;
lexer_data_struct *maulLexer(FILE *fp,int* lexer_token_count) {
  int ch;
  int i = 0;
  int data_capacity = 1;

  char *character;

  lexer_data_struct *lexer_data =
      (lexer_data_struct *)malloc(data_capacity * sizeof(lexer_data_struct));

  if (lexer_data == NULL) {
    printf("FAILED ALLOC DATA\n");
    exit(EXIT_FAILURE);
  }

  while ((ch = (int)fgetc(fp)) != EOF) {
    printf("lexer : %c\n", ch);

    if (i >= data_capacity) {
      data_capacity++;

      lexer_data = realloc(lexer_data, data_capacity * sizeof(lexer_data_struct));

      if (lexer_data == NULL) {
        printf("FAILED ALLOC DATA\n");

        exit(EXIT_FAILURE);
      }
    }
    if (isalpha(ch)) {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "name";
    } else if (isdigit(ch)) {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "digit";
    } else if (ch == '\n') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "new_line";
    } else if (ch == ' ') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "space";
    } else if (ch == '{') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "left_bracket";
    } else if (ch == '}') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "right_bracket";
    } else if (ch == '(') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "left_parent";
    } else if (ch == ')') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "right_parent";
    } else if (ch == '*') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "asteric";
    } else if (ch == '^') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "xor";
    } else if (ch == '/') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "backslash";
    } else if (ch == '\\') {
      lexer_data[i].character = ch;
      lexer_data[i].character_type = "frontslash";
    } else {
      printf("unworked character :  %d\n", ch);
      continue;
    }
    if (lexer_data[i].character)
      printf("[SUCCES]\n");
    i++;
  }
  *lexer_token_count = i;

  return lexer_data;
}
