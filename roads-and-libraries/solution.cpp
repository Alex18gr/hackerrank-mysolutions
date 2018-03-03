#include <bits/stdc++.h>

using namespace std;

int road = 0;

void dfs (int s, vector<int> adj[], vector<int> &visited){
    
    visited[s] = 1;
    for(int i = 0;i < adj[s].size();++i)    {
     if(visited[adj[s][i]] == 0)
        //road++;
        dfs(adj[s][i], adj, visited);
    }
    
}


int roadsAndLibraries(int n, int c_lib, int c_road, vector < vector<int> > cities) {
    // Complete this function
    vector <int> adj[n+1];
    for(int cities_i = 0;cities_i < n;cities_i++){
           for(int cities_j = 0;cities_j < 2;cities_j++){
              cout << cities[cities_i][cities_j] << " ";
              
           }
        adj[cities[cities_i][0]].push_back(cities[cities_i][1]);
        adj[cities[cities_i][1]].push_back(cities[cities_i][0]);
        cout << endl;
    }
    
    
    for(int i = 1;i <= n;++i)
{   
        cout << "Adjacency list of node " << i << ": ";
    for(int j = 0;j < adj[i].size();++j)
        {
        if(j == adj[i].size() - 1)
                cout << adj[i][j] << endl;
        else
            cout << adj[i][j] << " --> ";
    }
}   
    
    vector<int> visited (n,0);
    int roads = 0;
    int lib = 0;
    
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            lib++;
            dfs( i, adj, visited);
        }
    }
    
    return (road*c_road) + (lib*c_lib);
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int c_lib;
        int c_road;
        road = 0;
        cin >> n >> m >> c_lib >> c_road;
        vector< vector<int> > cities(m,vector<int>(2));
        for(int cities_i = 0;cities_i < m;cities_i++){
           for(int cities_j = 0;cities_j < 2;cities_j++){
              cin >> cities[cities_i][cities_j];
           }
        }
        int result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout << result << endl;
    }
    return 0;
}
