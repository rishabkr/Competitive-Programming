class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        if(n <= 1)return 0;
        
        
        //array to store frequencies
        vector<int> hash(26, 0);
        //count frequency of each character
        for(char c: s) hash[c-'a']++;
        
        
        //number of character to delete
        int res = 0;
        //set to check whether more than one characters are of same frequency or not
        unordered_set<int> stt;
        
        //check for each character
        for(int i=0; i<26; ++i) {
            //while current frequency in the set
            while(stt.find(hash[i]) != stt.end()) {
                hash[i]--;
                res++;
            }
            if(hash[i]!=0) stt.insert(hash[i]);
        }
		//PLEASE UPVOTE
        return res;
    }
};

// class Solution {
// public:
//     /*Count frequency of each letter
// Sort the frequencies
// From the letter with highest frequency, for each letter we keep no more than previous letter
// Total number - number we kept = number we want to delete*/
    
//     int minDeletions(string s) {
//         vector<int>freq(26,0);
//         for(char c : s)
//         {
//             freq[c-'a']++;
//         }
        
//         sort(freq.begin(),freq.end(),greater<int>());
//         int keep=0;
//         int prev=INT_MAX;
        
//         for(int current_freq :  freq)
//         {
//             if(current_freq == 0 or prev == 0)
//             {
//                 break;
//             }
//             cout<<prev<<" "<<keep<<"\n";
//             prev=min(current_freq, prev - 1);
//             keep+=prev;
//         }
//         return s.size()-keep;
        
//     }
// };

// class Solution {
// public:
//     /*Count frequency of each letter
// Sort the frequencies
// From the letter with highest frequency, for each letter we keep no more than previous letter
// Total number - number we kept = number we want to delete*/
    
//     int minDeletions(string s) {
//         vector<int>freq(26,0);
//         for(char c : s)
//         {
//             freq[c-'a']++;
//         }
        
//         sort(freq.begin(),freq.end(),greater<int>());
//         int keep=0;
//         int prev=INT_MAX;
        
//         for(int current_freq :  freq)
//         {
//             if(current_freq == 0 or prev == 0)
//             {
//                 break;
//             }
//             cout<<prev<<" "<<keep<<"\n";
//             prev=min(current_freq, prev - 1);
//             keep+=prev;
//         }
//         return s.size()-keep;
        
//     }
// };