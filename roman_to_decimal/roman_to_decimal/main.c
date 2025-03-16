//
//  main.c
//  roman_to_decimal
//
//  Created by Ege Kaya on 16/03/25.
//

#include <string.h>
#include <stdio.h>

int getValue(char ch) {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}


int romanToInt(char* s) {
    int length = strlen(s);
    int total = 0;
    for(int i = 0; i < length ;i++) {
        int current = getValue(s[i]);
        int next = (i + 1 < length) ? getValue(s[i + 1]) : 0;
         if (current < next) {
            total -= current;
        } else {
            total += current;
        }
    }
    return total;
}

