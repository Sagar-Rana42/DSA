int find(int x , vector<int>&parent){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x],parent);
}

void union(int x , int y,vector<int>&parent , vector<int>&size){
    int x_parent = find(x);
    int y_parent = find(y);

    if(x_parent == y_parent){
        return;
    }
    else if(size[x_parent] > size[y_parent] ){
        parent[y_parent] = x_parent;
        size[x_parent] += size[y_parent];

    }
    else if(size[x_parent] < size[y_parent] ){
        parent[x_parent] = y_parent;
        size[y_parent] += size[x_parent];

    }
    else{
        parent[x_parent] = parent[y_parent];
        size[y_parent] += size[x_parent];
    }
}
