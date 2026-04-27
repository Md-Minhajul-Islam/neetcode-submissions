public class Solution {
    public int Trap(int[] height) {
        int left = 0, right = height.Length-1;
        int water = 0, prevMx = 0;
        while(left < right)
        {
            int mn = Math.Min(height[left], height[right]);

            if(prevMx >= mn) water -= mn;
            else water += (mn-prevMx)*(right-left-1)-prevMx;

            prevMx = Math.Max(prevMx, mn);

            if(height[left] < height[right]) left++;
            else right--;
        }
        return water;
    }
}
