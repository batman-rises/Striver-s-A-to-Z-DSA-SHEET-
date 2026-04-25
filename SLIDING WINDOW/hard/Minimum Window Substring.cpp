class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";

        int n=s.size();
        int countRequired=t.size();

        unordered_map<char,int> mp;
        for(char ch:t){
            mp[ch]++;
        }

        int l=0,r=0;

        int minmWindowSize=1e8;
        int startIndex=0;

        while(r<n){
            char ch=s[r];
            if(mp[ch]>0){//it means its a required char
                countRequired--;
            }
            mp[ch]--;
            while(countRequired==0){
                //gotta shrink
                int curWindowSize=r-l+1;
                if(curWindowSize < minmWindowSize){
                    minmWindowSize=curWindowSize;
                    startIndex=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)
                    countRequired++;
                l++;
            }
            r++;
        }

        return minmWindowSize==1e8 ? "": s.substr(startIndex,minmWindowSize);
    }
};