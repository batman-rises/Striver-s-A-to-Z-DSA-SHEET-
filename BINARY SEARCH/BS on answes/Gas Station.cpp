class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totGas = 0, totCost = 0, start = 0, current = 0;
        for (int i = 0; i < gas.size(); i++)
        {

            totGas += gas[i];
            totCost += cost[i];

            current += (gas[i] - cost[i]);
            if (current < 0)
            {
                start = i + 1;
                current = 0;
            }
        }
        return (totGas >= totCost) ? start : -1;
    }
};