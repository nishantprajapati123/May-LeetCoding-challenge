class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int n = A.size();
        if(n == 0)  return 0;
        int sum = accumulate(A.begin(), A.end(), 0);
        
        //use variation of kadane's algorithm
        //1.find use simple kadanes, k
        //2.reverse sign of each element then use kadanes
        //3.add sum = sum + step2
        //4.if sum > k && sum!=0 (sum!=0 to handle if all element are -ve)
        
        int s = A[0];
        int k = s;
        for(int i=1;i<n;i++)
        {
            s = max(s + A[i], A[i]);
            k = max(k, s);
        }
        

        for(int &x:A)
            x = -x;
        
        int rev_s = A[0];
        int rev_k = rev_s;
        for(int i=1;i<n;i++)
        {
            rev_s = max(rev_s + A[i], A[i]);
            rev_k = max(rev_s, rev_k);
        }
        // cout<<"rev_k = "<<rev_k<<endl;
        sum += rev_k;
        if(sum > k && sum!=0)
            return sum;
        else
            return k;
    }
};