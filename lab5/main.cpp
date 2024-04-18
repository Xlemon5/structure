#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Функция для проверки существования пути из u в v
bool isPathExists(int u, int v, const vector<vector<int>>& graph, vector<bool>& visited) {
  queue<int> q;
  q.push(u);
  visited[u] = true;

  while (!q.empty()) {
	  int current = q.front();
	  q.pop();
	  for (int neighbor : graph[current]) {
		  if (!visited[neighbor]) {
			  if (neighbor == v) {
				  return true;
				}
			  visited[neighbor] = true;
			  q.push(neighbor);
			}
		}
	}
  return false;
}

// Главная функция для решения задачи
bool canDisconnect(int A, int B, vector<pair<int, int>>& edges, int n) {
  vector<vector<int>> graph(n);
  for (auto& edge : edges) {
	  graph[edge.first].push_back(edge.second);
	  graph[edge.second].push_back(edge.first);
	}

  // Перебор всех комбинаций из 3 ребер
  int m = edges.size();
  for (int i = 0; i < m; ++i) {
	  for (int j = i + 1; j < m; ++j) {
		  for (int k = j + 1; k < m; ++k) {
			  // Удаляем 3 ребра
			  vector<bool> visited(n, false);
			  vector<vector<int>> tempGraph = graph;
			  tempGraph[edges[i].first].erase(remove(tempGraph[edges[i].first].begin(), tempGraph[edges[i].first].end(), edges[i].second), tempGraph[edges[i].first].end());
			  tempGraph[edges[i].second].erase(remove(tempGraph[edges[i].second].begin(), tempGraph[edges[i].second].end(), edges[i].first), tempGraph[edges[i].second].end());
			  tempGraph[edges[j].first].erase(remove(tempGraph[edges[j].first].begin(), tempGraph[edges[j].first].end(), edges[j].second), tempGraph[edges[j].first].end());
			  tempGraph[edges[j].second].erase(remove(tempGraph[edges[j].second].begin(), tempGraph[edges[j].second].end(), edges[j].first), tempGraph[edges[j].second].end());
			  tempGraph[edges[k].first].erase(remove(tempGraph[edges[k].first].begin(), tempGraph[edges[k].first].end(), edges[k].second), tempGraph[edges[k].first].end());
			  tempGraph[edges[k].second].erase(remove(tempGraph[edges[k].second].begin(), tempGraph[edges[k].second].end(), edges[k].first), tempGraph[edges[k].second].end());

			  // Проверяем, есть ли путь из A в B
			  fill(visited.begin(), visited.end(), false);
			  if (!isPathExists(A, B, tempGraph, visited)) {
				  return true;
				}
			}
		}
	}
  return false;
}

int main() {
  int n = 6; // количество вершин
  vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}, {4, 5}};
  int A = 0, B = 5;

  if (canDisconnect(A, B, edges, n))
	cout << "Yes, can disconnect A and B by removing exactly three roads." << endl;
  else
	cout << "No, cannot disconnect A and B by removing exactly three roads." << endl;

  return 0;
}
