class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].length();
            int last = index + 1;

            while (last < n) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length();
                last++;
            }

            string line = "";
            int numWords = last - index;

            if (last == n || numWords == 1) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } else {
                int sumWordLengths = 0;
                for (int i = index; i < last; i++) {
                    sumWordLengths += words[i].length();
                }

                int totalSpaces = maxWidth - sumWordLengths;
                int baseSpaces = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        int spacesToApply = baseSpaces + (i - index < extraSpaces ? 1 : 0);
                        line.append(spacesToApply, ' ');
                    }
                }
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};