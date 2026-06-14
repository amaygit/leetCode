class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int tot_app=0,sum=0;
        for(auto p:apple){
            tot_app+=p;
        }
      sort(capacity.begin(), capacity.end(), greater<int>());
        int box=0;
        for(auto p:capacity){
            sum+=p;
            box++;
            if(sum>=tot_app)
        return box;
        }
        return box;
    }
};