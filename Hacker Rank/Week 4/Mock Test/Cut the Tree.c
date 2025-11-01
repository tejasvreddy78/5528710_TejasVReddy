int best;

int dfs(int u,int p,int* val,int** adj,int* deg,int tot){
    int sum=val[u];
    for(int i=0;i<deg[u];i++){
        int v=adj[u][i];
        if(v!=p){
            int r = dfs(v,u,val,adj,deg,tot);
            int diff = abs(tot - 2*r);
            if(diff<best) best=diff;
            sum+=r;
        }
    }
    return sum;
}

int cutTheTree(int data_count,int* data,int edges_rows,int edges_cols,int** edges){
    int n=data_count;
    int deg[n+1];
    memset(deg,0,sizeof(deg));

    for(int i=0;i<edges_rows;i++){
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
    }

    int* adj[n+1];
    int idx[n+1];
    for(int i=1;i<=n;i++){
        adj[i]=malloc(deg[i]*sizeof(int));
        idx[i]=0;
    }
    for(int i=0;i<edges_rows;i++){
        int a=edges[i][0],b=edges[i][1];
        adj[a][idx[a]++]=b;
        adj[b][idx[b]++]=a;
    }

    int tot=0;
    for(int i=0;i<n;i++) tot+=data[i];
    best=1e9;

    dfs(1,0,data-1,adj,deg,tot);

    return best;
}

