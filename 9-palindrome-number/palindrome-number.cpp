class Solution {
public:
    bool isPalindrome(int x) {
        long long digit=0,ele=1,orginal=x;
        vector<int>vec1;
        vector<int>vec2;

        if(x<0)
        return false;
        while(x!=0){
            ele=x%10;
            vec1.push_back(ele);
           x=x/10;
        }
        vec2=vec1;
        reverse(vec1.begin(),vec1.end());
        
        
        return vec1==vec2;
    }
};