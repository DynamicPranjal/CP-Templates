struct UnionFind{
	int n;
	vector<int>rank;
	vector<int>parent;

	UnionFind(int n){
		rank.resize(n);
		fill(rank.begin(),rank.end(),0);	// initializing all rank to be equal i.e., 0
		parent.resize(n);
		for(int i=0;i<n;i++){				// initially all element in itself a union
			parent[i]=i;
		}
	}

	int get(int a){
		return parent[a]=(parent[a]==a ? a : get(parent[a]));	//recursive to find parent of union
	}

	void merge(int a,int b){
		a=get(a);				
		b=get(b);						// Comparision is done by parent elements of a union
		if(a!=b){						
			if(rank[a]<rank[b]){		// UNION BY RANK
				swap(a,b);				// Suppose A has more rank
			}							
			parent[b]=a;				// UNION is done with element having more rank 
			if(rank[a]==rank[b])
				rank[a]++;
		}
	}
} 