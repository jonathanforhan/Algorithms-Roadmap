#include<iostream>
#include<vector>

using std::vector;

// Time O(log(n) + log(m))
// Space O(1)

class Solution {
public:
    static bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        int low = 0;
        int x = matrix.size(), y = matrix[0].size();
        int high = x * y;
        
        while(low <= high) {
            int mid = (low + high) >> 1;
            // get the i and j iters from the mid by 
            // dividing by y and then modding by y
            int i = mid / y;
            int j = mid % y;
            if(i >= x || j >= y) return false; // bounds check
            
            if(matrix[i][j] < target) {
                low = mid+1;
            } else if(matrix[i][j] > target) {
                high = mid-1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 5;

    bool answer = Solution::searchMatrix(matrix, target);
    std::cout << std::boolalpha << answer << '\n';
}
