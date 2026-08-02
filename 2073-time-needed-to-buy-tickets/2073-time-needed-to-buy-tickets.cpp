class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timeTaken = 0;
        queue<pair<int, int>> line;

        for (int i = 0; i < tickets.size(); i++) {
            line.push({tickets[i], i});
        }

        while (!line.empty()) {
            auto person = line.front();
            line.pop();

            int ticketLeft = person.first;
            int idx = person.second;

            ticketLeft--;
            timeTaken++;

            if (ticketLeft == 0) {
                if (idx == k) {
                    return timeTaken;
                }
            }

            else {
                line.push({ticketLeft, idx});
            }
        }
        return timeTaken;
    }
};