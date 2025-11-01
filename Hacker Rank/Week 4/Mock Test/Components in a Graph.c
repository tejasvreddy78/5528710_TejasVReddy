int find(int* p, int x){
    return p[x]==x? x : (p[x]=find(p,p[x]));
}

void join(int* p, int* sz, int a, int b){
    a=find(p,a); b=find(p,b);
    if(a!=b){
        p[b]=a;
        sz[a]+=sz[b];
    }
}

int* componentsInGraph(int rows, int cols, int** gb, int* result_count){

    int maxv=0;
    for(int i=0;i<rows;i++){
        if(gb[i][0]>maxv) maxv=gb[i][0];
        if(gb[i][1]>maxv) maxv=gb[i][1];
    }

    int p[maxv+1], sz[maxv+1];
    for(int i=1;i<=maxv;i++){
        p[i]=i;
        sz[i]=1;
    }

    for(int i=0;i<rows;i++){
        join(p,sz, gb[i][0], gb[i][1]);
    }

    int mn=1e9, mx=0;
    for(int i=1;i<=maxv;i++){
        if(p[i]==i && sz[i]>=2){
            if(sz[i]<mn) mn=sz[i];
            if(sz[i]>mx) mx=sz[i];
        }
    }

    int* out = malloc(2*sizeof(int));
    *result_count=2;
    out[0]=mn;
    out[1]=mx;
    return out;
}
