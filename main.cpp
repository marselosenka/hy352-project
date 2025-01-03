#include "JSONlang.h"
JSON(hello)
PROGRAM_BEGIN

JSON(name) = OBJECT{};

JSON(oop) = OBJECT{ 
    KEY(title) : STRING("title"),
    KEY(title2) : STRING("title5")
}+OBJECT{ 
    KEY(title3) : STRING("title"),
    KEY(title2) : STRING("title")
}

JSON(firstarray) = ARRAY[ STRING("Kalispera"), STRING("KALH")]
JSON(secondarray) = ARRAY[ STRING("Kalispera"), STRING("KALH")]

JSON(UOC) = ARRAY [ OBJECT {
    KEY(MATHIMATIKO) : OBJECT {
        KEY(MEM341) : STRING("Oikonomia or sumn"),
        KEY(MEM555) : STRING("Kati me arithmous"),
        KEY(MEM666) : NUMBER(2) > NUMBER(3)
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
        KEY(MED359) : STRING("Web tis anw koilias")
    }

    
}]
JSON(UOC2) = ARRAY [ OBJECT {
    KEY(MATHIMATIKO) : OBJECT {
        KEY(MEM341) : STRING("Oikonomia or sumn"),
        KEY(MEM555) : STRING("Kati me arithmous"),
        KEY(MEM666) : NUMBER(2) > NUMBER(3)
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
        KEY(MED359) : STRING("Web tis anw koilias")
    }

    
}]
//SET UOC[0] ASSIGN STRING("GLWSSES KAI VOCAL CORDS")

//SET secondarray APPEND STRING("HEYYY"),STRING("MISO LEPTO") 
SET name APPEND OBJECT {
        KEY(MEM341) : STRING("Oikonomia or sumn"),
        KEY(MEM555) : STRING("Kati me arithmous"),
        KEY(MEM666) : STRING("Arithmoi 2")
    }

JSON(lol) = OBJECT {
        KEY(MEM341) : firstarray != secondarray,
        KEY(MEM555) : TRUE,
        KEY(MEM666) : FALSE
    }
PRINT lol
//PRINT name

PROGRAM_END