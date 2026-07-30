#include <iostream>
#include <vector>

using namespace std;

const int MAXK = 5005;
const int MAX_NODES = 11005;
const int MAX_COLORS = 205;

struct Edge {
    int u, v, id;
};

int n, m, k, t;
int degU[MAX_NODES], degV[MAX_NODES];
Edge edges[MAXK];

int id_U[205][5005];
int id_V[205][5005];

int deg_U_cur[205];
int deg_V_cur[205];

int adj[MAX_NODES][MAX_COLORS];
int edg[MAX_NODES][MAX_COLORS];

int ansColor[MAXK];


void add_edge(int u, int v, int id) {
    int c1 = 1; while (adj[u][c1]) c1++;
    int c2 = 1; while (adj[v][c2]) c2++;

    if (c1 == c2) {
        adj[u][c1] = v; edg[u][c1] = id;
        adj[v][c1] = u; edg[v][c1] = id;
        ansColor[id] = c1;
        return;
    }

    vector<int> nodes;
    vector<int> path_edges;

    int curr = v;
    int cur_c = c1;
    while (curr) {
        nodes.push_back(curr);
        int nxt = adj[curr][cur_c];
        if (nxt) {
            path_edges.push_back(edg[curr][cur_c]);
        }
        curr = nxt;
        cur_c = (cur_c == c1) ? c2 : c1;
    }

    cur_c = c1;
    for (size_t i = 0; i + 1 < nodes.size(); ++i) {
        int x = nodes[i];
        int y = nodes[i + 1];
        adj[x][cur_c] = 0; edg[x][cur_c] = 0;
        adj[y][cur_c] = 0; edg[y][cur_c] = 0;
        cur_c = (cur_c == c1) ? c2 : c1;
    }

    cur_c = c2;
    for (size_t i = 0; i + 1 < nodes.size(); ++i) {
        int x = nodes[i];
        int y = nodes[i + 1];
        int e_id = path_edges[i];

        adj[x][cur_c] = y; edg[x][cur_c] = e_id;
        adj[y][cur_c] = x; edg[y][cur_c] = e_id;
        ansColor[e_id] = cur_c;

        cur_c = (cur_c == c1) ? c2 : c1;
    }

    adj[u][c1] = v; edg[u][c1] = id;
    adj[v][c1] = u; edg[v][c1] = id;
    ansColor[id] = c1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m >> k >> t)) return 0;

    for (int i = 1; i <= k; ++i) {
        cin >> edges[i].u >> edges[i].v;
        edges[i].id = i;
        degU[edges[i].u]++;
        degV[edges[i].v]++;
    }

    int totalUnevenness = 0;
    for (int i = 1; i <= n; ++i) {
        if (degU[i] % t != 0) totalUnevenness++;
    }
    for (int i = 1; i <= m; ++i) {
        if (degV[i] % t != 0) totalUnevenness++;
    }
    cout << totalUnevenness << "\n";

    int cnt_nodes = 0;
    for (int i = 1; i <= n; ++i) {
        int splits = (degU[i] + t - 1) / t;
        if (splits == 0) splits = 1;
        for (int j = 0; j < splits; ++j) {
            id_U[i][j] = ++cnt_nodes;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int splits = (degV[i] + t - 1) / t;
        if (splits == 0) splits = 1;
        for (int j = 0; j < splits; ++j) {
            id_V[i][j] = ++cnt_nodes;
        }
    }

    for (int i = 1; i <= k; ++i) {
        int u_orig = edges[i].u;
        int v_orig = edges[i].v;

        int u = id_U[u_orig][deg_U_cur[u_orig] / t];
        int v = id_V[v_orig][deg_V_cur[v_orig] / t];

        deg_U_cur[u_orig]++;
        deg_V_cur[v_orig]++;

        add_edge(u, v, edges[i].id);
    }

    for (int i = 1; i <= k; ++i) {
        cout << ansColor[i] << (i == k ? "" : " ");
    }
    cout << "\n";

    return 0;
}
