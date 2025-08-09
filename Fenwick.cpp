// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Fenwick
{
    vector<int> bit;
    int n;

    public:

    Fenwick(int sz)
    {
        n = sz;
        bit.assign(n+1, 0);
    }
    
    void update(int idx, int val)
    {
        idx++;
        for( ; idx <=n ; idx += idx&-idx) {
            bit[idx] += val;
        }
    }
    
    int query(int idx)
    {
        idx++;
        int res = 0;
        for( ; idx > 0 ; idx -= idx&-idx) {
            res += bit[idx];
        }
        return res;
    }
};

int main() {
    Fenwick f(9);
    
    for(int i=0;i<9;i++) {
        f.update(i, i+1);
    }
    
    cout<<f.query(5);
}
