//
//  main.c
//  expression_matching
//
//  Created by Ege Kaya on 19/03/25.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int s_index = 0, p_index = 0;

    while (p_index < p_len) {
        if (p_index + 1 < p_len && p[p_index + 1] == '*') {
            char prev_char = p[p_index];
            while (s_index < s_len && (s[s_index] == prev_char || prev_char == '.')) {
                if (isMatch(s + s_index, p + p_index + 2)) {
                    return true;
                }
                s_index++;
            }
            p_index += 2;
        } else if (s_index < s_len && (s[s_index] == p[p_index] || p[p_index] == '.')) {
            s_index++;
            p_index++;
        } else {
            return false;
        }
    }
    
    return s_index == s_len;
}
