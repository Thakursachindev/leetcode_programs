class Solution {
public:
    int numTrees(int n) {
        vector<int> T(n+1, 0);
        
        T[0] = T[1] = 1;
        
        for(int r = 2; r <= n; r++){
            for(int mid = 1; mid <= r; mid++){
                
                T[r] += T[mid-1] * T[r-mid];
            }
        }
        return T[n];
    }
};




-------------------

    
class Solution {
public:
    int numTrees(int n) {
 if(n==0 || n == 1)
        return 1;
    int ans=0;
    for(int i = 1; i<=n; i++){
        ans += numTrees(i-1) * numTrees(n-i);
    }    
    return ans;
    }
};
