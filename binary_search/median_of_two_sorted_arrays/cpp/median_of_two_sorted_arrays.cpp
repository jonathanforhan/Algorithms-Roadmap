#include<iostream>
#include<vector>
#include<limits>

using std::vector;
using int_limit = std::numeric_limits<int>;

class Solution {
public:
    static double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        int a = nums1.size(), b = nums2.size();
        if(a > b) return findMedianSortedArrays(nums2, nums1); // nums2 must always be bigger
        
        int total = a + b;

        int l = 0;
        int r = a;

        double answer = 0.0;

        /* we calculation the partition size to include the small array
         * next we apply that partition on the big array
         * if the next value of either array is greater than the edge of the partition
         * we expand the one that must be expanded and shrink the other
         * until we have isolated the median(s) and then divide if necessary
         */
        while(l <= r) {
            int i = (l + r) >> 1;        // nums1
            int j = (total + 1) / 2 - i; // nums2

            int left1 =  i > 0 ? nums1[i - 1] : int_limit::min();
            int right1 = i < a ? nums1[i] : int_limit::max();
            int left2 =  j > 0 ? nums2[j - 1] : int_limit::min();
            int right2 = j < b ? nums2[j] : int_limit::max();

            if(left1 <= right2 && left2 <= right1) {
                if(total % 2 == 0) {
                    answer = (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
                } else {
                    answer = std::max(left1, left2);
                }
                break;
            } else if(left1 > right2) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return answer;
    }
};

int main() {
    std::vector<int> nums1 = { 1, 3, 7, 8, 12 };
    std::vector<int> nums2 = { 2, 3, 6, 9, 14 };

    double answer = Solution::findMedianSortedArrays(nums1, nums2);

    std::cout << answer << '\n';

    return 0;
}
