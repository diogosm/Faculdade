/******************************* Net Flow ************************************/

int v_num;
int parent[MAX]; // it has the father of all nodes in the DFS tree
// build the path
int bfs (int G[][MAX], int src, int dest, int F[][MAX]) {

	int i, j, flag = 0;
	int queue[MAX], st, end, v;

	for (i = 0; i < v_num; i++)
		parent[i] = -1;

	parent[src] = -2;
	st = end = 0;
	queue[end++] = src;
	
	while (st < end) {
	
		v = queue[st++];
		for (j = 0; j < v_num; j++)
			if (G[v][j] && parent[j] == -1 && G[v][j] - F[v][j] > 0) {
				parent[j] = v;
				if (j == dest) // the destiny is reachable
					flag = 1;
				queue[end++] = j;
			}
	}
	
	return flag;
}


int ed_karp (int G[][MAX], int src, int dest) {

	int i, j, cap_residual;
	int F[MAX][MAX], v, u, max_flow = 0;

	for (i = 0; i < v_num; i++)
		for (j = 0; j < v_num; j++)
			F[i][j] = 0;

	// build the path
	while ( bfs (G, src, dest, F) ) {

		// define residual capacity
		v = dest;
		cap_residual = 0;
		while (v != src) {
			u = parent[v];
			if (G[u][v] - F[u][v] < cap_residual || cap_residual == 0)
				cap_residual = G[u][v] - F[u][v];
			v = u;
		}

		// update the flow
		max_flow += cap_residual;
		v = dest;
		while (v != src) {
			u = parent[v];
			F[u][v] += cap_residual;
			F[v][u] -= cap_residual;
			v = u;
		}
	}
	
	return max_flow;
}
