//
//  main.c
//  tree_preorder
//
//  Created by Ege Kaya on 11/03/25.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidSerialization(char* preorder) {
    int valid_counter = 1;
    int i = 0;

    while (preorder[i]) {
        if (valid_counter < 0)
            return false;

        if (preorder[i] == ',') {
            i++;
            continue;
        }

    
        if (preorder[i] == '#') {
            valid_counter--;
            i++;
        }
        else {
            valid_counter++;
            while (preorder[i] && preorder[i] != ',')
                i++;
        }
    }
    
    return valid_counter == 0;
}

int main(void) {
    char preorder[] = "#,7,6,9,#,#,#";
    printf("%s\n", isValidSerialization(preorder) ? "Valid" : "Invalid");
    return 0;
}
