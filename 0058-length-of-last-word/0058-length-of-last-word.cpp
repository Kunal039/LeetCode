class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size()-1;
        int size = 0;

        while (length>=0 && s[length] == ' ') length--;

        for(int i=length; i>-1; i--) {
            if(s[i] == ' ') break;
            else size++;
        }
        return size;
    }
};