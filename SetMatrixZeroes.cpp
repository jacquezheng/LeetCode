void setZeroes(vector<vector<int> > &matrix) {
    int m = matrix.size(), n = 0;
    if(m>0)
        n = matrix[0].size();
    else
        return;
        
    class my_pair{
        public:
            int my_x, my_y;
            my_pair(){
                my_x = -1;
                my_y = -1;
            }
            my_pair(int x,int y){
                my_x = x;
                my_y = y;
            }
    };
    vector<my_pair> to_change;
            
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                to_change.push_back(my_pair(i,j));
            }
        }
    }
        
    for(int i = 0; i < to_change.size(); i++){
        for(int k = 0; k<m; k++)
            matrix[k][to_change[i].my_y] = 0;
        for(int l = 0; l<n; l++)
            matrix[to_change[i].my_x][l] = 0;
    }
}
