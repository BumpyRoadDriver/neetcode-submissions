class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0; int j = s.size()-1; 
        while(i < j){
            while((not isalnum(s[i]))and i < j){
                i++;
            }
            while((not isalnum(s[j])) and i < j){
                j--;
            }
            char a = tolower(s[i]);
            char b = tolower(s[j]);
            if (a != b) {return false;} 
            i++;
            j--;

        }
        return true;
    }
};
