int* bfs(int n, int m, int edges_rows, int edges_columns, int** edges, int s, int* result_count) {
    int deg[n+1];
    memset(deg,0,sizeof(deg));

    for(int i=0;i<m;i++){
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
    }

    int* adj[n+1];
    int idx[n+1];
    for(int i=1;i<=n;i++){
        adj[i]=malloc(deg[i]*sizeof(int));
        idx[i]=0;
    }

    for(int i=0;i<m;i++){
        int u=edges[i][0], v=edges[i][1];
        adj[u][idx[u]++] = v;
        adj[v][idx[v]++] = u;
    }

    int dist[n+1];
    for(int i=1;i<=n;i++) dist[i]=-1;
    dist[s]=0;
    int q[n], f=0, b=0;
    q[b++]=s;

    while(f<b){
        int u = q[f++];
        for(int i=0;i<idx[u];i++){
            int v = adj[u][i];
            if(dist[v]==-1){
                dist[v]=dist[u]+6;
                q[b++]=v;
            }
        }
    }
    *result_count = n-1;
    int* out = malloc((n-1)*sizeof(int));
    int k=0;
    for(int i=1;i<=n;i++){
        if(i!=s) out[k++]=dist[i];
    }
    return out;
}
