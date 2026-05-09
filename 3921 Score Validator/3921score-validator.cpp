class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int s=0;
        int c=0;
        for(auto it:events){
            if(c==10)break;
            if(it=="0"||it=="1"||it=="2"||it=="3"||it=="4"||it=="6"){
                int temp=stoi(it);
                s+=temp;
            }else if(it=="W"){
                c++;
            }else if(it=="WD"||it=="NB"){
                s++;
            }
        }
        return {s,c};
    }
};