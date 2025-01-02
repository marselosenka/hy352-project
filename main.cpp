#include "JSONlang.h"
JSON(hello)
PROGRAM_BEGIN

JSON(name) = STRING("Manolis")

JSON(oop) = OBJECT{ 
    KEY(title) : STRING("title"),
    KEY(title2) : STRING("title5")
}+OBJECT{ 
    KEY(title3) : STRING("title"),
    KEY(title2) : STRING("title")
}

JSON(firstarray) = ARRAY
JSON(secondarray) = ARRAY[ STRING("Kalispera"), STRING("KALH")]

/** 
JSON(UOC) = OBJECT {
    KEY(MATHIMATIKO) : OBJECT {
        KEY(MEM341) : STRING("Oikonomia or sumn"),
        KEY(MEM555) : STRING("Kati me arithmous"),
        KEY(MEM666) : STRING("Arithmoi 2")
    },
    KEY(CSD) : OBJECT {
        KEY(HY100) : STRING("Eisagwgh"),
        KEY(HY352) : STRING("software engineering"),
        KEY(HY469) : STRING("HCI")
    },
    KEY(Iatriki) : OBJECT {
        KEY(MED1000) : STRING("Eisagwgh sto depon"),
        KEY(MED252) : STRING("Antikeimenostrafhs farmakologia"),
        KEY(MED352) : STRING("Mixanikos Swmatos"),
        KEY(MED240) : STRING("Domes tis kardias"),
        KEY(MED359) : STRING("Web tis anw koilias"),
        KEY(MED340) : STRING("")
    },
    KEY(HELL) : OBJECT {}
    
}
SET UOC["Iatriki"]["MED340"] ASSIGN STRING("GLWSSES KAI VOCAL CORDS")
*/
SET secondarray APPEND STRING("HEYYY"),STRING("MISO LEPTO") 
PRINT secondarray 




PROGRAM_END