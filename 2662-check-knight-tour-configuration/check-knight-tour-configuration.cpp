bool c(vector<vector<int>> &arr, int i, int j, int mi, int mj){
    if(arr[i][j]==arr[mi][mj]){
        return 1;
    }
    int h = 0;
    int a = arr[i][j];
    if(i>1){
        if(j>0){
            if(arr[i-2][j-1] == a+1){
                h=1;
                return c(arr, i-2, j-1, mi, mj);
            }
        }
        if(j<arr[0].size()-1){
            if(arr[i-2][j+1] == a+1){
                h=1;
                return c(arr,i-2,j+1, mi,mj);
            }
        }
    }
    if(i+2<arr.size()){
        if(j>0){
            if(arr[i+2][j-1]==a+1){
                h=1;
                return c(arr,i+2,j-1,mi,mj);
            }
        }
        if(j<arr[0].size()-1){
            if(arr[i+2][j+1]==a+1){
                h=1;
                return c(arr,i+2,j+1,mi,mj);
            }
        }
    }
    if(j>1){
        if(i>0){
            if(arr[i-1][j-2]==a+1){
                h=1;
                return c(arr,i-1,j-2,mi,mj);
            }        
        }
        if(i+1<arr.size()){
            if(arr[i+1][j-2] == a+1){
                h=1;
                return c(arr, i+1,j-2,mi,mj);
            }
        }
    }
    if(j+2<arr[0].size()){
        if(i>0){
            if(arr[i-1][j+2]==a+1){
                h=1;
                return c(arr, i-1,j+2,mi,mj);
            }
        }
        if(i+1<arr.size()){
            if(arr[i+1][j+2] == a+1){
                h=1;
                return c(arr,i+1,j+2,mi,mj);
            }
        }
    }
    if(h==0){
        return 0;
    }
    return 0;
};
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int si = 0;
        int sj = 0;
        if(grid[0][0] !=0){
            return false;
        }
        int mi;
        int mj;
        int m=INT_MIN;
        for(int i =0; i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] > m){
                    m=grid[i][j];
                    mi=i;
                    mj = j;
                }
            }
        }
        return c(grid, si,sj, mi,mj);
    }
};