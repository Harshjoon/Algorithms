class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<bool> v(n,true);
        
        v[0] = v[1] = false;
        
        // for( int i=2;i*i<n;i++ ){
        //     for( int j=i*i;j<n;j+=i){
        //         v[j] = false;
        //     }
        // }

        int p = 2;
        int it,t=0;
        auto itr = v.begin();
        while(p <= v.size()/2){
            it = 2*p;
            while(it < n){
                v[it] = false;
                it+=p;
            }
            while( !(*(itr + t)==true) ){
                t++;
            }
            p = t;
            if( itr+t==v.end()) break;
            t++;
        }
        int ans = 0;
        for(auto i:v) if(i) ans++;
        return ans;
        //return count(v.begin(),v.end(),true);
    }
};