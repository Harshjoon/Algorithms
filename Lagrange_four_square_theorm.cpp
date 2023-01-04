#include <cmath>

class Solution {
public:
    // Checks weather the number is a perfect square or not.
    bool isSquare(int n){
        int s=(int)sqrt(n);
        return (s*s==n);
    }

    int numSquares(int n){
        // return 1 if perfect square.
        if (isSquare(n)) return 1; 
        // check for legendre's 3 square sum theorm.
        // number has 4 square sum if num = 4*a(8*b + 7)
        // for non negative integers a,b. 
        int m=n;
        while(m%4==0) m/=4;
        if(m%8==7) return 4;
        for( int i=1;i<sqrt(n);i++ )
            // subtract num with each square.
            // if residual is square return 2.
            if( isSquare(n - i*i) ) return 2;
        // otherwise return 3.
        return 3;
    }
};