/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate 
 * (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and 
 * (i, 0). Find two lines, which together with x-axis forms a container, such that the container 
 * contains the most water.
 * Note: You may not slant the container and n is at least 2.
 */
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
  int maxArea = 0;
  int left = 0;
  int right = height.size() - 1;
    
  while (left < right) {
    maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
    
    if (height[left] > height[right]) {
        right--;
    }
    else {
        left++;
    }            
  }
  return maxArea;  
}

int main(int argc, const char** argv) {

  return 0;
}

