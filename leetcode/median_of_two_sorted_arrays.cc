#include "common.h"

class Solution {
public:
    // 参考: https://blog.csdn.net/hk2291976/article/details/51107778
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);   
        int lo = 0, hi = nums1.size() * 2;  // 比如{1,2}被扩展为{#,1,#,2,#}
        int L1, R1, L2, R2;  // Li和Ri为割ci的左右两个数
        while (lo <= hi) {  // 注意是<=而非<，当nums1=[]时，lo==hi，此时L1,L2,R1,R2均未计算
            // 割c1和c2左边有(c1+c2)=(n1+n2)个数，两个数组扩展后有2*(n1+n2+1)个数，因此
            // 割c1和c2右边有2*(n1+n2+1)-(n1+n2)-2=(n1+n2)个数
            int c1 = (lo + hi) / 2;
            int c2 = (nums1.size() + nums2.size()) - c1;
            // 判断边界条件，最左边的可以看作最小值，最右边的可以看成最大值
            // 若不在边界，则割c的左边下标是(c-1)/2，右边下标是c/2
            L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            R1 = (c1 == 2 * nums1.size()) ? INT_MAX : nums1[c1 / 2];
            L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            R2 = (c2 == 2 * nums2.size()) ? INT_MAX : nums2[c2 / 2];
            // 理想情况是{L1,L2}<={R1,R2}
            if (L1 > R2) {  // L2<=R2<=L1<=R1，需要增大R2减小L1，因此割c1向左移动
                hi = c1 - 1;
            } else if (L2 > R1) {  // L1<=R1<=L2<=R2，需要增大R1减小L2，因此割c1向右移动
                lo = c1 + 1;
            } else {  // 理想情况: {L1,L2}<={R1,R2}
                break;
            }
        }  // lo == hi
        return (max(L1, L2) + min(R1, R2)) / 2.0;
    }
};