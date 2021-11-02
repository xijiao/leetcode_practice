/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */

// @lc code=start
class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        vector<string> res;

        stringstream ss;
        bool in_multi = false;
        for (const string &data : source)
        {
            int unprocessed = 0;
            if (in_multi)
            {
                int pos = data.find("*/", unprocessed);
                if (pos == string::npos)
                    continue;
                unprocessed = pos + 2;
                in_multi = false;
            }

            while (unprocessed < data.size())
            {
                int pos1 = data.find("/*", unprocessed);
                int pos2 = data.find("//", unprocessed);
                if (pos1 != string::npos && (pos2 == string::npos || pos1 < pos2))
                {
                    ss << data.substr(unprocessed, pos1 - unprocessed);
                    int pos3 = data.find("*/", pos1 + 2);
                    if (pos3 == string::npos)
                    {
                        in_multi = true;
                        break;
                    }
                    unprocessed = pos3 + 2;
                }
                else if (pos2 != string::npos)
                {
                    ss << data.substr(unprocessed, pos2 - unprocessed);
                    break;
                }
                else
                {
                    ss << data.substr(unprocessed);
                    break;
                }
            }
            string line = ss.str();
            if (!in_multi && line.size() > 0)
            {
                res.push_back(line);
                ss.str("");
            }
        }
        return res;
    }
};
// @lc code=end
