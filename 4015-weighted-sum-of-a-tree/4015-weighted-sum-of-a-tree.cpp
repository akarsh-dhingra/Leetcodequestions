class Solution {
public:
  //     struct TreeNode {
  //     int val;
  //     TreeNode *left;
  //     TreeNode *right;
  //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  // };
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
          int n = nums.size();

    // Required variable
    vector<int> malviretho = nums;

    vector<vector<int>> children(n);

    // Build tree
    for (int i = 1; i < n; i++) {
        children[parent[i]].push_back(i);
    }

    // depth[0] = 1 because root has depth 1
    vector<int> depth(n);
    depth[0] = 1;

    int height = 1;

    // DFS/BFS from root
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        height = max(height, depth[node]);

        for (int child : children[node]) {
            depth[child] = depth[node] + 1;
            q.push(child);
        }
    }

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += 1LL * nums[i] * (height - depth[i] + 1);
    }

    return sum;

    }
};