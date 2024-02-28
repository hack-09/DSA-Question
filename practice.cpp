#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> edge;

int dfs(int node, vector<bool>& visited, vector<bool>& on_stack) {
    cout << "Visiting node: " << node << endl; // Debugging print statement
    if (visited[node]) {
        if (on_stack[node]) {
            // Cycle detected, calculate sum
            int sum = node;
            int current = edge[node];
            while (current != node) {
                sum += current;
                current = edge[current];
            }
            return sum;
        } else {
            return -1; // Already visited but not part of a cycle
        }
    }

    visited[node] = true;
    on_stack[node] = true;

    int result = dfs(edge[node], visited, on_stack);

    on_stack[node] = false;

    return result;
}

int solution_function(int N) {
    edge.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> edge[i];
    }

    int max_cycle_sum = -1;

    vector<bool> visited(N, false);
    vector<bool> on_stack(N, false);

    for (int i = 0; i < N; ++i) {
        int cycle_sum = dfs(i, visited, on_stack);
        if (cycle_sum != -1) {
            max_cycle_sum = max(max_cycle_sum, cycle_sum);
        }
    }
    cout<<max_cycle_sum<<endl;

    return max_cycle_sum;
}

int main() {
    int n;
    cin >> n;

    int result = solution_function(n);

    cout << result << endl;

    return 0;
}
