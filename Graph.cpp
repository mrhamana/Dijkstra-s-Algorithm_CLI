#include <iostream>
#include <queue>
#include <set>
#include <functional>
#include <unordered_map>
#include <vector>
#include <tuple>

#define INF 999999999999
using namespace std;

template <typename T>
class Graph
{
    vector<vector<int>> adj_matrix;
    vector<T> NODES;
    unordered_map<T, int> node_to_index;

public:
    void addNodes(vector<T> myvec)
    {
        int n = myvec.size();
        this->NODES = myvec;
        vector<int> temp(n, 0);
        for (int i = 0; i < n; i++)
        {
            this->adj_matrix.push_back(temp);
            this->node_to_index[myvec[i]] = i;
        }
    }

    void traverse()
    {
        cout << "  ";
        for (T c : NODES)
        {
            cout << c << " ";
        }
        cout << endl;
        int n = 0;
        for (vector<int> temp : adj_matrix)
        {
            cout << this->NODES[n] << "|";
            n++;
            for (int i : temp)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    void addEdge(T a, T b, int dist)
    {
        int x = -1;
        int y = -1;
        int n = this->NODES.size();

        if (node_to_index.find(a) != node_to_index.end())
        {
            x = node_to_index[a];
        }
        if (node_to_index.find(b) != node_to_index.end())
        {
            y = node_to_index[b];
        }

        if (x == -1 || y == -1)
        {
            cout << "The value not found in the graph" << endl;
            return;
        }

        this->adj_matrix[x][y] = dist;
    }

    void djastra(T a)
    {
        unordered_map<T, int> distances;
        for (T node : this->NODES)
        {
            distances[node] = (node == a) ? 0 : INF;
        }

        priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
        pq.push({0, a});

        while (!pq.empty())
        {
            int current_dist;
            T current_node;

            tie(current_dist, current_node) = pq.top();
            pq.pop();

            if (current_dist > distances[current_node])
            {
                continue;
            }

            int index = node_to_index[current_node];

            for (int i = 0; i < this->NODES.size(); ++i)
            {
                int weight = this->adj_matrix[index][i];
                if (weight != 0)
                {
                    T neighbor_node = this->NODES[i];
                    if (current_dist + weight < distances[neighbor_node])
                    {
                        distances[neighbor_node] = current_dist + weight;
                        pq.push({distances[neighbor_node], neighbor_node});
                    }
                }
            }
        }
        for (const auto &node : distances)
        {
            cout << node.first << " : " << node.second << endl;
        }
    }
};

int main()
{
    Graph<char> g;
    vector<char> nodes = {'a', 'b', 'c', 'd', 'e'};
    g.addNodes(nodes);
    g.addEdge('a', 'c', 4);
    g.addEdge('a', 'b', 1);
    g.addEdge('b', 'e', 2);
    g.addEdge('b', 'd', 2);
    g.addEdge('d', 'e', 3);
    g.djastra('a');
    return 0;
}