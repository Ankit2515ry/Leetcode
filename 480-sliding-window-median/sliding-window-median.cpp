class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // int n=nums.size();
        // vector<double>res;
        // multiset<int>st;
        // for(int i=0;i<k-1;i++)st.insert(nums[i]);
        // for(int i=k-1;i<n;i++){
        //     st.insert(nums[i]);
        //     if(k%2!=0){
        //         auto it=std::next(st.begin(),k/2);  // tree iterations linear in Worst case takes O(n) not random Access
        //         double sum=*it;
        //         res.push_back(sum);
        //     }else{
        //         auto it=std::next(st.begin(),k/2);
        //         double sum1=*it;
        //         sum1/=2;
        //         it=std::next(st.begin(),(k-1)/2);
        //         double sum2=*it;
        //         sum2/=2;
        //         res.push_back(sum1+sum2);
        //     }
        //     st.erase(st.find(nums[i-k+1]));
        // }
        // return res;

        int n=nums.size();
        vector<double>res;
        multiset<int>st;
        for(int i=0;i<k;i++)st.insert(nums[i]);
        auto it=next(st.begin(),k/2); 
        for(int i=k;i<n;i++){
            double temp=1.0*(*it)+*prev(it,1-k%2);
            temp/=2;
            res.push_back(temp);
            st.insert(nums[i]);
            if(nums[i]<*it)it--;
            if(nums[i-k]<=*it)it++;
            st.erase(st.find(nums[i-k]));
        }
        double temp=1.0*(*it)+*prev(it,1-k%2);
        temp/=2;
        res.push_back(temp);
        return res;
    }
};