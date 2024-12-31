#include "JSONlang.h"

PROGRAM_BEGIN

JSON(name) = STRING("Manolis")

JSON(oop) = OBJECT{ 
    KEY(title) : STRING("title"),
    KEY(title) : STRING("title")
}
JSON(firstarray) = ARRAY
JSON(secondarray) = ARRAY[ STRING("Kalispera"), STRING("KALH")]

JSON(students) = ARRAY [
    OBJECT{
            KEY(name) : STRING("Nikos Nikolaou"),
            KEY(id) : STRING("HEYYY"),
            KEY(grades) : ARRAY[ OBJECT { KEY(hy100) : NUMBER(7.5) }, OBJECT { KEY(hy150) : NUMBER(8) } ] 
        },
        OBJECT{
        KEY(name) : STRING("Nikos Nikolaou"),
        KEY(id) : STRING("HEYYY"),
        KEY(grades) : ARRAY[ OBJECT { KEY(hy100) : NUMBER(7.5) }, OBJECT { KEY(hy150) : NUMBER(8) } ] 
    }
    ]
PRINT(students)
PROGRAM_END