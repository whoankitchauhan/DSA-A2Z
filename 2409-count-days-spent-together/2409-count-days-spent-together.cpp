
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }
            return day;
        };

        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        int startDay = convert(start);
        int endDay = convert(end);

        return max(0, endDay - startDay + 1);
    }
};
