class Solution {
public:
    int trap(vector<int>& height) {
//         Solution 1: TC-O(N), SC-O(N)
//         vector<int> pre(height.size()),suf(height.size());
//         int water=0;

//         pre[0]=height[0];
//         for(int i=1;i<height.size();i++) {
//             if(height[i]>pre[i-1]) {
//                 pre[i]=height[i];
//             }
//             else {
//                 pre[i]=pre[i-1];
//             }
//         }

//         suf[height.size()-1]=height[height.size()-1];
//         for(int i=height.size()-2;i>=0;i--) {
//             if(height[i]>suf[i+1]) {
//                 suf[i]=height[i];
//             }
//             else {
//                 suf[i]=suf[i+1];
//             }
//         }

//         for(int i=0;i<height.size();i++) {
//             water+=min(pre[i],suf[i])-height[i];
//         }
//         return water;

//         Solution 2: TC-O(N), SC-O(1)

        int water = 0, leftmax = 0, rightmax = 0, left = 0, right = height.size() - 1;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] > leftmax) {
                    leftmax = height[left];
                }
                else {
                    water += leftmax - height[left];
                }
                left++;
            }
            else {
                if (height[right] > rightmax) {
                    rightmax = height[right];
                }
                else {
                    water += rightmax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};