#include "Graph.h"
//Adds the location to the graph
void Graph::addLocation(string& location){
    if(graph.find(location) == graph.end())
        graph[location] = {};
}
//Adds the route 
void Graph::addRoute(string& source, string& destination, int cost, int time){
    //Un-directed Graph (bi-directional)
    graph[source].push_back({destination, cost, time});
    graph[destination].push_back({source, cost, time});
}
//Gives the optimal path (cheapest / fastest) according to the choice 
void Graph::dijkstra(const string& source, const string& destination, int choice){
    unordered_map<string, int> distance;
    unordered_map<string, string> parent;

    for(auto x : graph)//initialises the distance to maximum value
        distance[x.first] = INT_MAX;
    
    distance[source] = 0;//distances of source is set to zero
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq; //initializing min priority queue
    pq.push({0, source});

    while(!pq.empty()){
        int d = pq.top().first;
        string loc = pq.top().second;
        pq.pop();
        if(d > distance[loc])   continue;

        for(auto x : graph[loc]){
            int weight = (choice == 1) ? x.cost : x.time;
            if(distance[loc] + weight < distance[x.destination]){
                distance[x.destination] = distance[loc] + weight;
                parent[x.destination] = loc;
                pq.push({distance[x.destination], x.destination});
            }
        }
    }
    if(distance[destination] == INT_MAX){
        cout << "\nNo Path is Found.!\n";
        return;
    }

    vector<string> path;
    for(string node = destination; node != source; node = parent[node]){
        path.push_back(node);
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    
    cout << "OPTIMAL PATH : \n";
    for(int i = 0; i < path.size(); i++){
        if(i == 0)
            cout << path[0];
        else
            cout << " -> " << path[i] ;
    }
    cout << endl;
    if(choice == 1)
        cout << "Total Cost [Cheapest] = " << distance[destination] << " Rupees";
    else
        cout << "Total Time [Fastest] = " << distance[destination] << " Hours";
}