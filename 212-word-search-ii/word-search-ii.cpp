class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    void solve(vector<vector<char>>& board,vector<vector<bool>>& visited,string& curr,unordered_set<string>& ans,unordered_set<char>& first_char,unordered_set<string>& st,int x,int y){
        if(x>=board.size() || x<0 || y>=board[0].size() || y<0) return;
        if(visited[x][y]) return;
        if(curr.size()>10) return;
        curr.push_back(board[x][y]);
        if(st.find(curr)!=st.end()){
            ans.insert(curr);
        }
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            solve(board,visited,curr,ans,first_char,st,nx,ny);
        }
        visited[x][y]=false;
        curr.pop_back();

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        unordered_set<char> first_char;
        for(int i=0;i<words.size();i++){
            first_char.insert(words[i][0]);
        }
        int n=board.size(),m=board[0].size();
        unordered_set<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(first_char.find(board[i][j])!=first_char.end()){
                    vector<vector<bool>> visited(n,vector<bool>(m,false));
                    string curr="";
                    solve(board,visited,curr,ans,first_char,st,i,j);
                }
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};