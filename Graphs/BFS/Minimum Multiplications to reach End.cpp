class Solution {
  public:
    const int mod = 100000;
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> vis(mod, 0);
        vis[start] = 1;
        while (!q.empty())
        {
            auto tp = q.front();
            q.pop();
            int curr = tp.first;
            int step = tp.second;
            if (curr == end)
            {
                return step;
            }
            for (int x : arr)
            {
                int imd = (1LL * x * curr) % mod;
                if (!vis[imd])
                {
                    vis[imd] = 1;
                    q.push({imd, step + 1});
                }
            }
        }
        return -1;
    }
};
