//
//  main.c
//  water_container_leetcode
//
//  Created by Ege Kaya on 08/03/25.
//

#include <stdio.h>

int maxArea(int* height, int heightSize);

int main(void) {
    int n = 0;
    printf("enter line count: \n");
    scanf("%d" , &n);
    int line_arr[n];
    for (int i = 0; i < n ; i++) {
        printf("\nenter each line one by one:\n");
        scanf("%d" , &line_arr[i]);
    }
    printf("max area is %d\n", maxArea(line_arr, n));
    return 0;
}

int maxArea(int* height, int heightSize) {
    
    int left = 0, right = heightSize - 1;
    int max_area = 0;
    
    while (left < right) {
        int width = right - left;
        int min_height = (height[left] < height[right]) ? height[left] : height[right];
        int area = width * min_height;
        
        if (area > max_area)
            max_area = area;
        
        if (height[left] > height[right]) {
            right--;
        }
        else
            left++;
        
    }
    return max_area;
}
