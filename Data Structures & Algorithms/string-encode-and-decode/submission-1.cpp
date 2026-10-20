class Solution {
public:

    int static cast_to_num(string nums){
        int ans =0;
        for(int i = 0; i <nums.size(); i++){
            ans *=10; 
            ans += (nums[i]-'0');
        }
        return ans;
    }

    static string cast_to_str(int num){
        vector<char> tmp; 

        while(num){
            tmp.push_back('0' + (num%10)); 
            num/=10; 
        }
        string sol(tmp.rbegin(), tmp.rend());
        return sol;
    }

    static string encode(vector<string>& strs) {
        string code; 

        for(auto str: strs){
            code += cast_to_str(str.size());
            code += '_'; 
            code += str;
        }
        return code;
    }

    static vector<string> decode(string s) {
        vector<string> ans; 
        int si = 0; 
        while(si < s.size()){
            string num; 
            int m= 0;
            while(si < s.size()){
                if (s[si] == '_'){
                    si++;
                    break;
                }
                num+= s[si];
                si++;

            }
            string new_str;
            m = cast_to_num(num);
            for(int i = 0; i < m; i++, si++){
                new_str+= s[si];
            }
            ans.push_back(new_str);
            
        }
        return ans;

    }
};
