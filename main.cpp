#include "JSONlang.cpp"

PROGRAM_BEGIN

JSON(name) = STRING("Manolis")

JSON(oop) = OBJECT{ 
    KEY(title) : STRING("title"),
    KEY(title) : STRING("title"),
}
JSON(firstarray) = ARRAY
JSON(secondarray) = ARRAY[ STRING("Kalispera"), STRING("KALH")]

PROGRAM_END