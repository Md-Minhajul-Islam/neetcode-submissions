public class Solution {
    public int MaxArea(int[] heights) {
        
        int mx = 0;
        int left = 0, right = heights.Length-1;

        while(left < right)
        {
            mx = Math.Max((right-left)*Math.Min(heights[left], heights[right]), mx);

            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return mx;
    }
}
