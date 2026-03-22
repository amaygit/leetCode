class Solution {
public:
set<vector<int>>s;
    void comb(vector<int>& candidates,int i, vector<int>& temp,vector<vector<int>>&ans,int target){
        int n=candidates.size();
        //base case
        if(i==n || target<0)
        return ;
        if(target==0){
            if(s.find(temp)==s.end()){
            ans.push_back(temp);
            s.insert(temp);
            }
        }
        temp.push_back(candidates[i]);
        //single inclusion
        comb(candidates,i+1,temp,ans,target-candidates[i]);
        //mutliple inclusion
        comb(candidates,i,temp,ans,target-candidates[i]);
        //Exclusion backtrack
        temp.pop_back();
        comb(candidates,i+1,temp,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();

        vector<vector<int>>ans;
        vector<int>temp;
        comb(candidates,0,temp,ans,target);
        return ans;
    }
};