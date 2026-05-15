class Solution {
public:

    double getMedian(vector<int>&v1, vector<int>& v2, int needSmaller, int n, int m)
    {
        int l = 0, r = n-1;
        while(l <= r)
        {
            int mid = l+(r-l)/2;
            
            double range1 = lower_bound(v2.begin(), v2.end(), v1[mid])-v2.begin();
            double range2 = upper_bound(v2.begin(), v2.end(), v1[mid])-v2.begin();

            if(needSmaller >= mid+range1 && needSmaller <= mid+range2)
            {
                return v1[mid];
            }
            else if(needSmaller < mid+range1) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        int needSmaller = (n+m)/2;
        
        double median = getMedian(nums1, nums2, needSmaller, n, m);
        if(median == -1) median = getMedian(nums2, nums1, needSmaller, m, n);

        if((n+m)%2 == 0)
        {
            needSmaller--;
            double  median2 = getMedian(nums1, nums2, needSmaller, n, m);
            if(median2 == -1) median2 = getMedian(nums2, nums1, needSmaller, m, n);

            median = (median+median2)/2;
        }
        return median;
    }
};
