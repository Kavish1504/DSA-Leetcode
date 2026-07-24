class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp;
        char ch='a';
        for(int i=0;i<key.size();i++){
            if(key[i] == ' ')
                continue;

            if(!mp.count(key[i])){

                mp[key[i]] = ch;
                ch++;
            }
        }
        for(int i=0;i<message.size();i++){
            if(mp.count(message[i])){
                message[i]=mp[message[i]];
            }
        }
        return message;
    }
};