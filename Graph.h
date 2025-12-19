#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>
using namespace std;

struct Route{
    string destination;
    int cost;
    int time;
};

class Graph{
    private:
        unordered_map<string, vector<Route>> graph;
    public:
        void addLocation(string& location);
        void addRoute(string& source, string& destination, int cost, int time);
        void dijkstra(const string& source, const string& destination, int choice);
};

#endif