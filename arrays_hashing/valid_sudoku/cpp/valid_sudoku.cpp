#include<iostream>
#include<vector>

using std::cout;
using std::vector;

// Time O(n) where n is number of cells
// Space O(n)

class Solution {
public:
    static bool isValidSudoku(const vector<vector<char>>& board) {
        // initialize row, column and square bool arrays to store
        // a value everytime we encounter it
        const int x = 9;
        bool row[x][x] = { false };
        bool col[x][x] = { false };
        bool sqr[x][x] = { false };

        for(int r = 0; r < x; r++) {
            for(int c = 0; c < x; c++) {
                if(board[r][c] == '.') continue;

                // create an index from board char
                int i = board[r][c] - '0' -1;
                // a gets the 0-8 sqares as index
                int a = (r/3) * 3 + (c/3);

                // if encountered in row col or sqr -> false
                if(row[r][i] || col[c][i] || sqr[a][i])
                    return false;

                // indicate a number i has been seen
                row[r][i]= 1; col[c][i]= 1; sqr[a][i]= 1;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board =
        {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};

    bool answer = Solution::isValidSudoku(board);

    cout << std::boolalpha << answer << '\n';
}
