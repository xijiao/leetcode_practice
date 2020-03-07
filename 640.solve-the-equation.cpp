/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        int la = 0, lb = 0, ra = 0, rb = 0;
        int end = fillFormula(equation, la, lb, 0);
        fillFormula(equation, ra, rb, end + 1);
        cout << la << " " << lb << " " << ra << " " << rb << endl;
        if (lb == rb) {
            if (la == ra) {
                return "Infinite solutions";
            } else {
                return "x=0";
            }
        } else if (la == ra) {
            return "No solution";
        } else {
            return "x=" + to_string((rb - lb) / (la - ra));
        }
    }

    int fillFormula(const string& equation, int& a, int& b, int start) {
        int cursor = start, last_cursor = start;
        for (; cursor < equation.size();) {
            char c = equation[cursor];
            if (c == '=') {
                break;
            } else if (c == 'x') {
                int v = 1;
                if (cursor - last_cursor == 1 &&
                        (equation[last_cursor] == '-' || equation[last_cursor] == '+')) {
                    if (equation[last_cursor] == '-') {
                        v = -1;
                    }
                }
                else if (last_cursor != cursor) {
                    v = stoi(equation.substr(last_cursor, cursor - last_cursor));
                }
                a += v;
                last_cursor = ++cursor;
            } else if (last_cursor != cursor && (c == '-' || c == '+')) {
                int v = stoi(equation.substr(last_cursor, cursor - last_cursor));
                b += v;
                last_cursor = cursor;
            } else {
                cursor++;
            }
        }
        if (last_cursor != cursor) {
            int v = stoi(equation.substr(last_cursor, cursor - last_cursor));
            b += v;
        }
        return cursor;
    }
};
// @lc code=end

