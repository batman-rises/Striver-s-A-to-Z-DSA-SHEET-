typedef struct
{
    int start;
    int end;
    int pos;
} Data;
// Function to find the maximum number of meetings that can
// be performed in a meeting room.

int maxMeetings(vector<int> &start, vector<int> &end)
{
    // Your code here
    int n = start.size();
    Data arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    }
    sort(arr, arr + n, [](Data a, Data b)
         { return a.end < b.end; });

    int cnt = 1;
    int freeTime = arr[0].end;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].start > freeTime)
        {
            cnt++;
            freeTime = arr[i].end;
        }
    }
    return cnt;
}