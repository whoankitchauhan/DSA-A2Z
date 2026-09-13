class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLength = haystack.length();
        int needleLength = needle.length();
        int needleIndex = 0;

        for (int i = 0; i < haystackLength; i++) {

            // If characters match, move to the next character of needle
            if (haystack[i] == needle[needleIndex]) {
                needleIndex++;
            } else {
                // Restart from the next possible starting position
                i = i - needleIndex;

                // Start matching needle again from index 0
                needleIndex = 0;
            }

            // Entire needle has been matched
            if (needleIndex == needleLength) {
                return i - needleLength + 1;
            }
        }

        return -1;
    }
};
