class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count the frequency of each digit available to us
        int freq[10] = {0};
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;

        // Loop 'a' (hundreds place): Cannot be 0 for a 3-digit number
        for (int a = 1; a <= 9; a++) {
            if (freq[a] == 0)
                continue;
            freq[a]--; // Use one copy of digit 'a'

            // Loop 'b' (tens place)
            for (int b = 0; b <= 9; b++) {
                if (freq[b] == 0)
                    continue;
                freq[b]--; // Use one copy of digit 'b'

                // Loop 'c' (ones place): Step by 2 to guarantee the number is
                // even
                for (int c = 0; c <= 8; c += 2) {
                    if (freq[c] > 0) {
                        count++; // A unique valid 3-digit even number is formed
                    }
                }

                freq[b]++; // Backtrack: restore digit 'b'
            }

            freq[a]++; // Backtrack: restore digit 'a'
        }

        return count;
    }
};
