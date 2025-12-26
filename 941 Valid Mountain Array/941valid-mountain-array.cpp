class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return false;
        int c=0;
        if(arr[0]>arr[1]||arr[n-1]>arr[n-2])return false;
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1])return false;
            if(c==0&&arr[i]>arr[i+1])c++;
            if(c==1){
                if(arr[i]<arr[i+1])return false;
            } 
        }
        return true;
    }
};