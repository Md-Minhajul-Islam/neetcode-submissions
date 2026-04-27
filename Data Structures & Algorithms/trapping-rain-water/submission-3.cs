public class Solution {
    public int Trap(int[] height) {
        int left = 0, right = height.Length-1;
        int leftMx = 0, rightMx = 0, water = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                leftMx = Math.Max(leftMx, height[left]);
                water += leftMx-height[left++];
            }
            else
            {
                rightMx = Math.Max(rightMx, height[right]);
                water += rightMx-height[right--];
            }
        }
        return water;
    }
}
