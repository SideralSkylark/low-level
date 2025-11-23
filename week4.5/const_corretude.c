#include <stddef.h>
#include <stdio.h>

// changed from (char *name) -> (const char *name) because we just read name and dont modify it
void print_user(const char *name);

//from int *b, and int *b to const because we dont modify its values 
int compare(const int *a, const int *b);

// return literal, because we want to receive literal, and receive literal
// becuase we dont want to allow changes to filename
const char *find_extension(const char *filename);

//dosent use const because returns void and no const on parameter because buff is modifiable
void fill_buffer(char *buff, size_t size);


