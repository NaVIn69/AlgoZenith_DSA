void dfs(int curr, int parent, bool passInPath, int *resPointer, unordered_map<int, vector<int> > &adjmap, int passengers[])
{
    bool leaf = true;
    bool passenger = false;
    if (passInPath || passengers[curr])
    {
        passenger = true;
    }
    for (auto neigh : adjmap[curr])
    {
        if (neigh != parent && neigh != 1)
        {
            dfs(neigh, curr, passenger, resPointer, adjmap, passengers);
            leaf = false;
        }
    }
    if (leaf && passenger)
    {
        *resPointer = *resPointer + 1;
    }
   
}

int minBuses(int N, int passengers[], int edges[][2])
{

    // first make adjacency list
    unordered_map<int, vector<int> > adjmap;
    for (int i = 0; i < N-1; i++)
    {
        int e1 = edges[i][0];
        int e2 = edges[i][1];
        adjmap[e1].push_back(e2);
        adjmap[e2].push_back(e1);
    }

    // result pointer
    int res = 0;
    int *resP = &res;

    // start from node 1 and iterate through all its neighbouts and launch dfs
    for (auto neigh : adjmap[1])
    {
        dfs(neigh, 1, false, resP, adjmap, passengers);
    }

    return res;
}

