class Solution {
public:
    bool isPowerOfTwo(int n) {
        //can done by n&(n-1);
        //if n is pow of two means it set one msb from n-1
        //1->0...0001
        //2->0...0010 here msb from position 1 to 2 and if we do and of both result to zero;  
        for(int i=0;i<31;i++){
            //here loop till 31 bit because of negative 
            if(n==1<<i)return true;
        }
        return false;
    }
};