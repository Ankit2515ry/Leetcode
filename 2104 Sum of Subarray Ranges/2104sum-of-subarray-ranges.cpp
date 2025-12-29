class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res=0;
        for(int i=0;i<nums.size();i++){
            int mi=INT_MAX;
            int ma=INT_MIN;
            for(int j=i;j<nums.size();j++){
                mi=min(mi,nums[j]);
                ma=max(ma,nums[j]);
                res+=ma-mi;
            }
        }
        return res;
        // int n = nums.size();
        // vector<int> left(n), right(n);
        // stack<int> st;
        // long long minSum = 0, maxSum = 0;
        // while (!st.empty()) st.pop();
        // for (int i = 0; i < n; i++) {
        //     while (!st.empty() && nums[st.top()] > nums[i])
        //         st.pop();
        //     left[i] = st.empty() ? i + 1 : i - st.top();
        //     st.push(i);
        // }
        // while (!st.empty()) st.pop();
        // for (int i = n - 1; i >= 0; i--) {
        //     while (!st.empty() && nums[st.top()] >= nums[i])
        //         st.pop();
        //     right[i] = st.empty() ? n - i : st.top() - i;
        //     st.push(i);
        // }
        // for (int i = 0; i < n; i++)
        //     minSum += (long long) nums[i] * left[i] * right[i];
        // while (!st.empty()) st.pop();
        // for (int i = 0; i < n; i++) {
        //     while (!st.empty() && nums[st.top()] < nums[i])
        //         st.pop();
        //     left[i] = st.empty() ? i + 1 : i - st.top();
        //     st.push(i);
        // }
        // while (!st.empty()) st.pop();
        // for (int i = n - 1; i >= 0; i--) {
        //     while (!st.empty() && nums[st.top()] <= nums[i])
        //         st.pop();
        //     right[i] = st.empty() ? n - i : st.top() - i;
        //     st.push(i);
        // }
        // for (int i = 0; i < n; i++)
        //     maxSum += (long long) nums[i] * left[i] * right[i];
        // return maxSum - minSum;
    }
};