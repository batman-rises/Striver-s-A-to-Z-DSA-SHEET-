class Solution
{
public:
    // Helper function to calculate total hours needed for a given speed
    long long func(vector<int> &piles, int hourly)
    {
        long long totalHrs = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            // Ceiling division: (a + b - 1) / b
            totalHrs += (piles[i] + (long long)hourly - 1) / hourly;
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int> &piles, int hr)
    {
        int l = 1;
        int h = *max_element(piles.begin(), piles.end());
        int ans = h;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            long long hrsNeeded = func(piles, mid);

            if (hrsNeeded <= (long long)hr)
            {
                // If Koko can finish within 'hr', try a slower speed
                ans = mid;
                h = mid - 1;
            }
            else
            {
                // Too slow! Koko needs to eat faster
                l = mid + 1;
            }
        }
        return ans; // You can also return 'l' here
    }
};