class Solution
{
public:
    int f(int day, int last, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxPoints = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxPoints = max(maxPoints, matrix[0][task]);
                }
            }
            return maxPoints;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxPoints = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int point = matrix[day][task] + f(day - 1, task, matrix, dp);
                maxPoints = max(maxPoints, point);
            }
        }

        return dp[day][last] = maxPoints;
    }

    int ninjaTraining(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n - 1, 3, matrix, dp); // 3 means no last task
    }
};