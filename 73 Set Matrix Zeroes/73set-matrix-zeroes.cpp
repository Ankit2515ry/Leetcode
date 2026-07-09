class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        //O(n*m) space complexity and O(m*n*max(m,n)) time complexity 

        // vector<vector<int>>temp=matrix;
        // int n=matrix.size();
        // int m=matrix[0].size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==0){
        //             for(int k=0;k<n;k++){
        //                 temp[k][j]=0;
        //             }
        //             for(int k=0;k<m;k++){
        //                 temp[i][k]=0;
        //             }
        //         }
        //     }
        // }
        // matrix=temp;

        //O(max(m,n)) space and O(n*m) time complexity

        // int n=matrix.size();
        // int m=matrix[0].size();
        // vector<int>row;
        // vector<int>col;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==0){
        //             row.push_back(i);
        //             break;
        //         }
        //     }
        // }
        // for(int j=0;j<m;j++){
        //     for(int i=0;i<n;i++){
        //         if(matrix[i][j]==0){
        //             col.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // for(auto &it:row){
        //     for(int j=0;j<m;j++){
        //         matrix[it][j]=0;
        //     }
        // }
        // for(auto &it:col){
        //     for(int i=0;i<n;i++){
        //         matrix[i][it]=0;
        //     }
        // }

        //In place solution
        
        int n=matrix.size();
        int m=matrix[0].size();
        bool row0=false;
        bool col0=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(i==0)row0=true;
                    if(j==0)col0=true;
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<m;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<n;i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(row0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(col0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};