class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0)
            {
                ans.push_back(asteroids[i]);
            }
            else
            {
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i]))
                {
                    ans.pop_back();
                }

                if (!ans.empty() && ans.back() == abs(asteroids[i]))
                {
                    // Both are equal -> destroy both
                    ans.pop_back();
                }
                else if (ans.empty() || ans.back() < 0)
                {
                    // Push current asteroid if no collision
                    ans.push_back(asteroids[i]);
                }
            }
        }
        return ans;
    }
};
