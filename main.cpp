#include "Graph.h"

int main(){
    Graph travelPlanner;
    int n;
    cout << "Enter number of locations : ";
    cin >> n;
    cout << "Enter the location names : \n";
    //Adding all locations to the graph
    for(int i = 0; i < n; i++){
        string loc;
        cin >> loc;
        travelPlanner.addLocation(loc);
    }
    int m;
    cout << "Enter the number of travel routes : ";
    cin >> m;
    cout << "Enter routes (Source Destination Cost Time) : \n";
    //Adding all the routes to the graph
    for(int i = 0; i < m; i++){
        string src, dest;
        int cost, time;
        cin >> src >> dest >> cost >> time;
        travelPlanner.addRoute(src, dest, cost, time); 
    }
    //User input the source & destination
    string source, destination;
    cout << "Enter the source : ";
    cin >> source;
    cout << "Enter the destination : ";
    cin >> destination;
    //User input the travel choice
    int choice;
    cout << "Choose travel Preference : \n1. Cheapest Route.\n2. Fastest Route.\nEnter your choice : ";
    cin >> choice;
    travelPlanner.dijkstra(source, destination, choice);

    return 0;
}