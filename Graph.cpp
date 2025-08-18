#include <iostream>
#include <queue>
#include <set>
#include <functional>
#include <unordered_map>
#include <vector>
#include <tuple>

#define INF 9999
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
    Graph<string> g;
    std::vector<std::string> places = {
        "Thimi", "Dulikhel", "RingRoad", "Pokhara", "Thamel",
        "Kathmandu", "Lumbini", "Chitwan", "Janakpur", "Biratnagar",
        "Illam", "Birgunj", "Hetauda", "Narayanghat", "Jomsom",
        "Muktinath", "Nagarkot", "Bhaktapur", "Patan", "Dhulikhel",
        "Bhadrapur", "Kakarbhitta", "Bandipur", "Gorkha", "Sarangkot",
        "BegnasLake", "PhewaLake", "Gosaikunda", "Langtang", "NamcheBazaar",
        "Lukla", "EverestBaseCamp", "Manang", "ThorongLaPass", "Beni",
        "Ghorepani", "PoonHill", "Kanyam", "Tansen", "Palpa",
        "Butwal", "SiddhababaTemple", "Dharan", "Bhedetar", "Barahachhetra",
        "Okhaldhunga", "Solukhumbu", "Ramechhap", "Jiri", "Phaplu",
        "Salleri", "Khandbari", "Tumlingtar"};

    g.addNodes(places);
    g.addEdge("Kathmandu", "Pokhara", 200);

    g.addEdge("Pokhara", "Lumbini", 150);

    g.addEdge("Kathmandu", "Lumbini", 250);

    g.addEdge("Kathmandu", "Chitwan", 160);

    g.addEdge("Chitwan", "Lumbini", 100);

    g.addEdge("Kathmandu", "Janakpur", 225);

    g.addEdge("Janakpur", "Biratnagar", 150);

    g.addEdge("Biratnagar", "Illam", 120);

    g.addEdge("Kathmandu", "Birgunj", 180);

    g.addEdge("Birgunj", "Hetauda", 50);

    g.addEdge("Hetauda", "Narayanghat", 80);

    g.addEdge("Narayanghat", "Pokhara", 120);

    g.addEdge("Pokhara", "Jomsom", 160);

    g.addEdge("Jomsom", "Muktinath", 20);

    g.addEdge("Kathmandu", "Nagarkot", 32);

    g.addEdge("Nagarkot", "Bhaktapur", 15);

    g.addEdge("Bhaktapur", "Patan", 18);

    g.addEdge("Patan", "Kathmandu", 5);

    g.addEdge("Kathmandu", "Dhulikhel", 30);

    g.addEdge("Dhulikhel", "Bhadrapur", 400);

    g.addEdge("Bhadrapur", "Kakarbhitta", 25);

    g.addEdge("Kathmandu", "Bandipur", 140);

    g.addEdge("Bandipur", "Gorkha", 60);

    g.addEdge("Gorkha", "Pokhara", 90);

    g.addEdge("Pokhara", "Sarangkot", 10);

    g.addEdge("Pokhara", "BegnasLake", 15);

    g.addEdge("Pokhara", "PhewaLake", 5);

    g.addEdge("Kathmandu", "Gosaikunda", 100);

    g.addEdge("Gosaikunda", "Langtang", 40);

    g.addEdge("Kathmandu", "NamcheBazaar", 250);

    g.addEdge("NamcheBazaar", "Lukla", 30);

    g.addEdge("Lukla", "EverestBaseCamp", 130);

    g.addEdge("Kathmandu", "Manang", 300);

    g.addEdge("Manang", "ThorongLaPass", 40);

    g.addEdge("Kathmandu", "Pokhara", 200);

    g.addEdge("Pokhara", "Beni", 80);

    g.addEdge("Beni", "Ghorepani", 50);

    g.addEdge("Ghorepani", "PoonHill", 5);

    g.addEdge("Kathmandu", "Ilam", 600);

    g.addEdge("Ilam", "Kanyam", 20);

    g.addEdge("Kathmandu", "Tansen", 300);

    g.addEdge("Tansen", "Palpa", 10);

    g.addEdge("Palpa", "Butwal", 40);

    g.addEdge("Butwal", "SiddhababaTemple", 15);

    g.addEdge("Kathmandu", "Dharan", 450);

    g.addEdge("Dharan", "Bhedetar", 20);

    g.addEdge("Dharan", "Barahachhetra", 35);

    g.addEdge("Kathmandu", "Okhaldhunga", 350);

    g.addEdge("Okhaldhunga", "Solukhumbu", 100);

    g.addEdge("Kathmandu", "Ramechhap", 150);

    g.addEdge("Ramechhap", "Jiri", 50);

    g.addEdge("Jiri", "Phaplu", 60);

    g.addEdge("Phaplu", "Salleri", 10);

    g.addEdge("Salleri", "Khandbari", 150);

    g.addEdge("Khandbari", "Tumlingtar", 30);
    g.djastra("Kathmandu");
}