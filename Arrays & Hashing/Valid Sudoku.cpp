// https://neetcode.io/problems/valid-sudoku

class Solution {
public:

    int max(unordered_map<char,int>& num_map) {
        int max_value = -1;
        for(auto& [key,value] : num_map) {
            if (max_value<value) {max_value = value;}
        }
        return max_value;
    }

    int max(vector<unordered_map<char,int>>& num_maps) {
        int max_value = -1;
        for(auto& num_map : num_maps) {
            int value = max(num_map);
            if (max_value<value) {max_value = value;}
        }
        return max_value;
    }

    bool isValidSudoku(const vector<vector<char>>& board) {
        unordered_map<char,int> row;
        vector<unordered_map<char,int>> columns(9);
        vector<unordered_map<char,int>> sub_boxes(9);

        for(int i =0;i<9;++i) {
            row = unordered_map<char,int>();
            
            for(int j=0;j<9;++j) {
                if (board[i][j] == '.') {continue;}
                

                // row
                ++row[board[i][j]];

                // columns
                ++columns[j][board[i][j]];

                // sub-boxes
                ++sub_boxes[3*(i/3)+(j/3)][board[i][j]];
            }
            if (max(row)>=2) {return false;}

        }

        if (max(columns)>=2 || max(sub_boxes)>=2) {return false;}

        return true;
    }
};
