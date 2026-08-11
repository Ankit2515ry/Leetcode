class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto it:s)mp[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            int n=it.second;
            char ch=it.first;
            pq.push({n,ch});
        }
        string res="";
        while(!pq.empty()){
            int n=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            for(int i=0;i<n;i++){
                res+=ch;
            }
        }
        return res;
    }
};