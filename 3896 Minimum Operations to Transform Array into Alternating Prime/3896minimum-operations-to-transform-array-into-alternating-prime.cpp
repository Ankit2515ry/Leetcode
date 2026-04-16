class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<bool>s(1e5+10,true);
        s[0]=s[1]=false;
        for(int i=2;i<1e5+10;i++){
            if(s[i]){
                for(long long j=1LL*i*i;j<1e5+10;j+=i){
                    s[j]=false;
                }
            }
        }
        int n=nums.size();
        //vector<int>pre(1e5+10);->condition if we also allow to decerement by 1.
        int temp=-1;
        // for(int i=0;i<1e5+10;i++){
        //     pre[i]=temp;
        //     if(s[i])temp=i;
        // }
        vector<int>pos(1e5+10);
        temp=-1;
        for(int i=1e5+10-1;i>=0;i--){
            pos[i]=temp;
            if(s[i])temp=i;
        }
        int res=0;
        for(int i=0;i<n;i+=2){
            if(!s[nums[i]]){
                //int a=(pre[nums[i]]!=-1)?pre[nums[i]]:INT_MAX;
                int b=(pos[nums[i]]!=-1)?pos[nums[i]]:INT_MAX;
                //res+=min(abs(a-nums[i]),abs(b-nums[i]));
                res+=b-nums[i];
                //cout<<res<<" "<<"p"<<" "<<i<<endl;
            }
        }
        vector<int>nnp(1e5+10);
        temp=-1;
        for(int i=1e5+10-1;i>=0;i--){
            nnp[i]=temp;
            if(!s[i])temp=i;
        }
        for(int i=1;i<n;i+=2){
            if(s[nums[i]]){
                //int a=nums[i];
                int b=nnp[nums[i]];
                //while(s[a])a--;
                //while(s[b])b++;
                //res+=min(abs(a-nums[i]),abs(b-nums[i]));
                res+=b-nums[i];
                //cout<<res<<" "<<"np"<<" "<<i<<endl;
            }
        }
        return res;
    }
};