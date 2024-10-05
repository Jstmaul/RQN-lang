#ifndef TYPES

#define TYPES

typedef struct lexer_data_struct {
  char character;
  char *character_type;
} lexer_data_struct;

typedef struct parser_data_struct {
  char *string;
  char *string_type;
} parser_data_struct;

#endif // !TYPES
