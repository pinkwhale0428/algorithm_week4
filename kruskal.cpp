#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

// ������ ���ڿ� ���ڷ� �����մϴ�.
std::map<char, int> vertex_map = {
    {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}
};
std::vector<char> vertex_names = { 'a', 'b', 'c', 'd', 'e', 'f' };

// ������ ��Ÿ���� ����ü
struct Edge {
    int u, v, weight;
};

// ������ ����ġ�� ���� �����ϱ� ���� �� �Լ�
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Union-Find �ڷᱸ��
class DisjointSet {
public:
    std::vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void kruskal(const std::vector<Edge>& all_edges) {
    std::vector<Edge> sorted_edges = all_edges;
    std::sort(sorted_edges.begin(), sorted_edges.end(), compareEdges);

    DisjointSet ds(vertex_names.size());
    std::vector<Edge> mst;
    int mst_weight = 0;

    std::cout << "--- ũ�罺Į �˰��� ���� ���� ---" << std::endl;
    for (const auto& edge : sorted_edges) {
        std::cout << "  Ȯ�� ����: (" << vertex_names[edge.u] << "-" << vertex_names[edge.v] << ", ����ġ: " << edge.weight << ")";
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.unite(edge.u, edge.v);
            mst.push_back(edge);
            mst_weight += edge.weight;
            std::cout << " -> MST�� �߰�" << std::endl;
        }
        else {
            std::cout << " -> ����Ŭ �������� �ǳʶ�" << std::endl;
        }
    }

    std::cout << "\n--- ���� MST ��� �� �� ����ġ ---" << std::endl;
    for (const auto& edge : mst) {
        std::cout << "  " << vertex_names[edge.u] << " -- " << vertex_names[edge.v] << " (����ġ: " << edge.weight << ")" << std::endl;
    }

    std::cout << "�� ����ġ: " << mst_weight << std::endl;
}

int main() {
    std::vector<Edge> edges;

    // �־��� ���� ����
    auto add_edge = [&](char u_char, char v_char, int weight) {
        edges.push_back({ vertex_map[u_char], vertex_map[v_char], weight });
        };

    add_edge('a', 'b', 8);
    add_edge('b', 'c', 1);
    add_edge('c', 'f', 1);
    add_edge('f', 'b', 2);
    add_edge('a', 'd', 2);
    add_edge('a', 'e', 4);
    add_edge('d', 'e', 3);
    add_edge('b', 'd', 4);
    add_edge('f', 'd', 7);
    add_edge('e', 'f', 9);

    kruskal(edges);

    return 0;
}