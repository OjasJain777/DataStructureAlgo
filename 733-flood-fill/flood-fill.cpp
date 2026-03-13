void infect(vector<vector<int>> &image, int i, int j, int c){
    int k = image[i][j];
    image[i][j] = -1;
    if(i+1<image.size() && image[i+1][j] == k){
        infect(image, i+1, j, c);
    }
    if(i-1>=0 && image[i-1][j] == k){
        infect(image, i-1, j, c);
    }
    if(j+1<image[0].size() && image[i][j+1] == k){
        infect(image, i, j+1, c);
    }
    if(j-1>=0 && image[i][j-1] == k){
        infect( image, i, j-1, c);
    }
}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        infect(image, sr, sc, color);
        for(int i =0;i<image.size();i++){
            for(int j =0;j<image[0].size();j++){
                if(image[i][j]==-1){
                    image[i][j] = color;
                }
            }
        }
        return image;
    }
};