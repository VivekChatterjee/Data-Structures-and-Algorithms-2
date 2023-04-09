class Solution {
 private:
  /* State */
  enum VisitedKind {
    GREEN = 0,  /* Visited but not an ancestor. */
    YELLOW = 1, /* Visited ancestor. Means a cycle. */
    RED = 2     /* Not visited. */
  };
  vector<vector<int>> al;
  vector<array<int, 26>> cv_cache;
  vector<VisitedKind> visited;
  string colors;

  int dfs(int nv) {
    visited[nv] = YELLOW;
    for (int cnv : al[nv]) {
      switch (visited[cnv]) {
        case GREEN: {
          if (dfs(cnv) == -1) return -1; /* Cycle. */
          update(cv_cache[nv], cv_cache[cnv]);
          continue;
        }
        case YELLOW:
          return -1; /* Cycle. */
        case RED:
          update(cv_cache[nv], cv_cache[cnv]);
      }
    }
    visited[nv] = RED;
    ++cv_cache[nv][colors[nv] - 'a'];
    return *max_element(cv_cache[nv].begin(), cv_cache[nv].end());
  }

  void update(array<int, 26> &pcv, const array<int, 26> &ccv) {
    for (int i = 0; i < 26; ++i) {
      pcv[i] = max(pcv[i], ccv[i]);
    }
  }

 public:
  int largestPathValue(string &colors, vector<vector<int>> &edges) {
    this->colors = colors;
    int n = colors.size();
    int lcv = INT_MIN;
    int cv;

    /* State Initialization. */
    al = vector<vector<int>>(n);
    cv_cache = vector<array<int, 26>>(n);
    visited = vector<VisitedKind>(n);

    for (auto &e : edges) {
      al[e[0]].push_back(e[1]);
    }

    for (int i = 0; i < n; ++i) {
      if (visited[i] == GREEN) {
        cv = dfs(i);
        // printf("cv=%d for dfs(i=%d).\n", cv, i);
        if (cv == -1) return -1; /* Cycle. */
        lcv = max(lcv, cv);
      }
    }

    return lcv;
  }
};