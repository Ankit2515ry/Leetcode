class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        priority_queue<int>pq;
        int s=0;
        for(int i=0;i<n;i++){
            if(s+courses[i][0]<=courses[i][1]){
                s+=courses[i][0];
                pq.push(courses[i][0]);
            }else if(!pq.empty() && pq.top() > courses[i][0]){
                s+=courses[i][0]-(int)pq.top();
                pq.pop();
                pq.push(courses[i][0]);
            }
        }
        return (int)pq.size();
    }
};