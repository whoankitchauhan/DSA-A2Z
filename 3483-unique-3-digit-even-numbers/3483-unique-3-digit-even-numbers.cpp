class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int frequency[10] = {};

        for (int digit : digits) {
            frequency[digit]++;
        }

        int count = 0;

        for (int num = 100; num <= 999; num += 2) {
            if (num % 2 != 0)
                continue;

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            int used[10] = {};
            used[a]++;
            used[b]++;
            used[c]++;

            bool possible = true;

            for (int digit = 0; digit <= 9; digit++) {
                if (used[digit] > frequency[digit]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                count++;
            }
        }

        return count;
    }
};