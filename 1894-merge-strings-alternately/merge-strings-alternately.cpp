class Solution {
public:
    string mergeAlternately(string word1, string word2) {
     int p=word1.length(),q=word2.length();
     int i=0,j=0;
     string op;
     while(i<p && j<q){
        op.push_back(word1[i]);
        i++;
        op.push_back(word2[j]);
        j++;

     }   

     while(i<p){
        op.push_back(word1[i]);
        i++;
     }
     
     while(j<q){
        op.push_back(word2[j]);
        j++;
     }
     return op;
    }
};