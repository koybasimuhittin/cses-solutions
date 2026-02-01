for (int i = 0; i < n; i++) {
        res += grid[curr.f1][curr.s2];
        curr = parent[curr.f1][curr.s2];
    }