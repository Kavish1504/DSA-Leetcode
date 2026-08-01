class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        queue<pair<string,int>> q;
        q.push({startGene,0});
        st.erase(startGene);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front.first==endGene) return front.second;
            for(int i=0;i<front.first.size();i++){
                char original=front.first[i];
                for(char ch:{'A','C','G','T'}){
                    front.first[i]=ch;
                    if(st.find(front.first)!=st.end()){
                        q.push({front.first,front.second+1});
                        st.erase(front.first);
                    }
                }
                front.first[i]=original;
            }
        }
        return -1;
    }
};