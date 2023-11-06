#include <iostream>
#include <vector>
#include <string>
using namespace std;

// initialize global variables

vector<vector<int>> graph;
vector<string> cities;
vector<bool> visited;
vector<string> path;
int min_distance = 2147483647;
vector<string> shortestPath;


// depth first search function
void dfs(int current, int end, int distance) {
    // mark current as visited, add current to path
    visited[current] = true;
    path.push_back(cities[current]);
    // if we have reached the end, print the path and its length
    if (current == end) {
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl << "Length of Path: " << distance << endl;

        // if our current path is the shortest, redefine the shortest path
        if (distance < min_distance) {
            min_distance = distance;
            shortestPath = path;
        }
    }
    // recursively call dfs function for every city
    for (int n = 0; n < cities.size(); n++) {
        int temp = graph[current][n];
        if (!visited[n] && temp > 0) {
            dfs(n, end, distance + temp);
        }
    }
    // go backwards
    visited[current] = false;
    path.pop_back();
}
// function that determines the index of a string in a vector
int findIndex(vector<string> haystack, string needle) {
    for (int i = 0; i < haystack.size(); i++) {
        if (haystack[i] == needle) {
            return i;
        }
    }
    return -1;
}

int main() {
    // determine how many cities the user wants
    int numCities;
    cout << "How many cities? ";
    cin >> numCities;

    // use a for loop to name cities based on user input
    for (int i = 0; i < numCities; i++) {
        cout << "Name of city " << i + 1 << ": ";
        string cityName;
        cin >> cityName;
        cities.push_back(cityName);
        visited.push_back(false);
    }
    // use a for loop to create an empty graph
    for (int i = 0; i < numCities; i++) {
        vector<int> row(numCities, 0);
        graph.push_back(row);
    }
    // for loop to fill the graph with distances based on user input
    for (int i = 0; i < numCities; i++) {
        for (int j = i + 1; j < numCities; j++) {
            cout << "Distance between " << cities[i] << " and " << cities[j] << ": ";
            int distance;
            cin >> distance;
            graph[i][j] = graph[j][i] = distance;
        }
    }

    // determine which cities to find the paths between
    cout << "Please decide which two cities you would like to find the possible paths between:" << endl;
    cout << "First city: ";
    string first;
    cin >> first;
    cout << "Second city: ";
    string second;
    cin >> second;

    int firstIndex = findIndex(cities, first);
    int secondIndex = findIndex(cities, second);

    // call dfs using cities

    dfs(firstIndex, secondIndex, 0);

    // print shortest path

    if (min_distance == 2147483647) {
        cout << "No path found." << endl;
    } else {
        cout << "Shortest Path: ";
        // for loop to print the path
        for (int i = 0; i < shortestPath.size(); i++) {
            cout << shortestPath[i];
            if (i != shortestPath.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl << "Length of Path: " << min_distance << endl;
    }

    return 0;
}