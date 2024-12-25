#include "JSONlang.h"

PROGRAM_BEGIN

JSON(name) = STRING("Manolis")

JSON(oop) = OBJECT{
    KEY(title) : STRING("title"),
    KEY(year) : NUMBER(2011)
}

PROGRAM_END