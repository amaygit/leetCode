class Solution {
public:
bool check(int frq1[], int frq2[]){
        for(int i=0;i<26;i++){
            if(frq1[i]!=frq2[i])
            return false;
        }
        return true;
}
    bool checkInclusion(string s1, string s2) {
       int freqofS1[26]={0};
        for(int i=0;i<s1.length();i++)
        freqofS1[s1[i]-'a']++;

        for(int i=0;i<s2.length();i++){
            int index=i,windowSize=0;
        int freqofS2[26]={0};
            // freqofS2[i]=0;
            while(windowSize<s1.length() && index<s2.length()){
                freqofS2[s2[index]-'a']++;
                windowSize++; index++;
            }
            if(check(freqofS2,freqofS1))
            return true;
            
        }
            return false;

    }
};