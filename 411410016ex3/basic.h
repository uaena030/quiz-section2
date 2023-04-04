#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SAME 0
#define LOWER 1
#define HIGHER 2

#define MAXBUF 4096

#define Nor 0

#define TooMany 4
#define TooLess 5
#define Unknown 3
#define Duplicate 47

#define INFIX 0
#define PREFIX 1
#define POSTFIX 2

#define TRUE 1
#define FALSE 0

#define Rev 1
#define isAddOrMinus(oper) ((*oper) == '+') || ((*oper) == '-')? TRUE : FALSE