#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj; // Список смежности для представления графа
vector<pair<int, int>> edges; // Список всех рёбер

// Функция для проверки связности между двумя вершинами
bool isConnected(int src, int dest, int n) {
  vector<bool> visited(n, false);
  vector<int> stack;
  stack.push_back(src);
  visited[src] = true;

  while (!stack.empty()) {
	  int node = stack.back();
	  stack.pop_back();
	  for (int neighbor : adj[node]) {
		  if (!visited[neighbor]) {
			  if (neighbor == dest) return true;
			  visited[neighbor] = true;
			  stack.push_back(neighbor);
			}
		}
	}
  return false;
}

// Функция для удаления ребра
void removeEdge(int u, int v) {
  adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
  adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
}

// Функция для добавления ребра
void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  int n, m; // количество вершин и рёбер
  cin >> n >> m;
  adj.resize(n);
  int a, b; // города А и Б

  // Чтение рёбер
  for (int i = 0; i < m; i++) {
	  int u, v;
	  cin >> u >> v;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
	  edges.push_back({u, v});
	}

  cin >> a >> b;

  // Перебор комбинаций из трех рёбер
  bool possible = false;
  for (int i = 0; i < edges.size(); i++) {
	  for (int j = i + 1; j < edges.size(); j++) {
		  for (int k = j + 1; k < edges.size(); k++) {
			  // Удаление трех рёбер
			  removeEdge(edges[i].first, edges[i].second);
			  removeEdge(edges[j].first, edges[j].second);
			  removeEdge(edges[k].first, edges[k].second);

			  // Проверка связности
			  if (!isConnected(a, b, n)) {
				  possible = true;
				}

			  // Восстановление рёбер
			  addEdge(edges[i].first, edges[i].second);
			  addEdge(edges[j].first, edges[j].second);
			  addEdge(edges[k].first, edges[k].second);

			  if (possible) break;
			}
		  if (possible) break;
		}
	  if (possible) break;
	}

  cout << (possible ? "Yes" : "No") << endl;
  return 0;
}
