#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> result(n, -1);

        vector<tuple<int, int, char, int>> robots;

        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }

        sort(robots.begin(), robots.end());

        stack<tuple<int, int, char, int>> activeRobots;

        for (auto& robot : robots) {
            int pos = get<0>(robot);
            int health = get<1>(robot);
            char direction = get<2>(robot);
            int index = get<3>(robot);

            if (direction == 'R') {
                activeRobots.push(robot);
            } else {
                while (!activeRobots.empty() &&
                       get<2>(activeRobots.top()) == 'R') {
                    auto rightRobot = activeRobots.top();
                    int rightHealth = get<1>(rightRobot);

                    if (rightHealth > health) {
                        get<1>(rightRobot) -= 1;
                        activeRobots.top() = rightRobot;
                        health = 0;
                        break;
                    } else if (rightHealth < health) {
                        health -= 1;
                        activeRobots.pop();
                    } else {
                        health = 0;
                        activeRobots.pop();
                        break;
                    }
                }

                if (health > 0) {
                    activeRobots.push(
                        make_tuple(pos, health, direction, index));
                }
            }
        }

        while (!activeRobots.empty()) {
            auto robot = activeRobots.top();
            activeRobots.pop();
            result[get<3>(robot)] = get<1>(robot);
        }

        vector<int> survivors;
        for (int health : result) {
            if (health != -1) {
                survivors.push_back(health);
            }
        }

        return survivors;
    }
};
