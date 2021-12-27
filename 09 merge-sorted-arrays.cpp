class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*for(int i=0;i<m;i++) {
            if(nums1[i]>nums2[0]) {
                swap(nums1[i],nums2[0]);
                sort(nums2.begin(),nums2.end());
            }
        }
        for(int i=m;i<m+n;i++) {
            nums1[i]=nums2[i-m];
        }*/

        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }

        int gap, count = 0;
        if ((m + n) % 2) {
            gap = (m + n) / 2 + 1;
        }
        else {
            gap = (m + n) / 2;
        }

        while (gap > 1) {
            for (int i = 0, j = i + gap; j < m + n; i++, j++) {
                if (nums1[i] > nums1[j]) {
                    swap(nums1[i], nums1[j]);
                }
            }
            if (gap % 2) {
                gap = gap / 2 + 1;
            }
            else {
                gap = gap / 2;
            }
        }

        for (int i = 0, j = i + gap; j < m + n; i++, j++) {
            if (nums1[i] > nums1[j]) {
                swap(nums1[i], nums1[j]);
            }
        }
    }
};