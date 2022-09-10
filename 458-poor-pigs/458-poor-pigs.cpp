class Solution {
    using ld = long double;
public:
    int poorPigs(ld buckets, ld md, ld mt) {
        return ceil(log(buckets)/log(mt/md+1));
    }
};