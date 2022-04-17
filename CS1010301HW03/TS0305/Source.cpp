#include <iostream>
#include <vector>

using namespace std;

typedef struct graph {
	vector<vector<bool>> data;
	int m, n;
	bool error;
}Graph;


void drawSquare(Graph& graph, int x, int y, int w) {
	if (x + w >= graph.m || y + w >= graph.n || x < 0 || y < 0) {
		graph.error = true;
	}
	else {
		for (int i = x; i <= x + w; i++)
			for (int j = y; j <= y + w; j++)
				graph.data[j][i] = true;
	}
	
}

void drawTriangle(Graph& graph, int x, int y, int w, string dir) {
	int xwidth = w, ywidth = w;
	if (x >= graph.m || y >= graph.n || x < 0 || y < 0) {
		graph.error = true;
	}
	else {
		if (dir == "LU") {
			if (y - w < 0 || x - w < 0)
				graph.error = true;
			else
			{
				for (int i = x; i >= x - xwidth; i--)
				{
					for (int j = y; j >= y - ywidth; j--)
						graph.data[j][i] = true;
					ywidth--;
				}
			}
		}
		else if (dir == "LD") {
			if (y + w >= graph.n || x - w < 0)
				graph.error = true;
			else
			{
				for (int i = x; i >= x - xwidth; i--)
				{
					for (int j = y; j <= y + ywidth; j++)
						graph.data[j][i] = true;
					ywidth--;
				}
			}
		}
		else if (dir == "RU") {
			if (y - w < 0 || x + w >= graph.m)
				graph.error = true;
			else
			{
				for (int i = x; i <= x + xwidth; i++)
				{
					for (int j = y; j >= y - ywidth; j--)
						graph.data[j][i] = true;
					ywidth--;
				}
			}
		}
		else if (dir == "RD") {
			if (y + w >= graph.n || x + w >= graph.m)
				graph.error = true;
			else
			{
				for (int i = x; i <= x + xwidth; i++)
				{
					for (int j = y; j <= y + ywidth; j++)
						graph.data[j][i] = true;
					ywidth--;
				}
			}
		}
	}
}

void drawLine(Graph& graph, int x1, int y1, int x2, int y2) {
	if (x1 >= graph.m || x1 < 0 || x2 >= graph.m || x2 < 0 || y1 >= graph.n || y1 < 0 || y2 >= graph.n || y2 < 0) {
		graph.error = true;
	}
	else {
		int xmove, ymove;
		if (x1 < x2) {
			xmove = 1;
		}
		else if (x1 > x2) {
			xmove = -1;
		}
		else {
			xmove = 0;
		}
		if (y1 < y2) {
			ymove = 1;
		}
		else if (y1 > y2) {
			ymove = -1;
		}
		else {
			ymove = 0;
		}
		for (int x = x1, y = y1; x != x2 || y != y2; x += xmove, y += ymove) {
			graph.data[y][x] = true;
		}
		graph.data[y2][x2] = true;
	}
}

void print(Graph& graph) {
	if (graph.error) {
		cout << "Out of range." << endl;
	}
	else {
		for (int i = 0; i < graph.n; i++)
		{
			for (int j = 0; j < graph.m; j++)
			{
				if (graph.data[i][j])
					cout << "X";
				else
					cout << "*";
			}
			cout << endl;
		}
	}
	cout << endl;
}

int main() {
	int m, n, x, y, x1, y1, x2, y2, w;
	string action, Dir;
	Graph graph;

	cin >> m >> n;

	graph.data.resize(n);
	for (int i = 0; i < n; i++) {
		graph.data[i].resize(m);
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			graph.data[i][j] = false;
		}
	}

	graph.m = m;
	graph.n = n;
	graph.error = false;

	while (true) {
		graph.error = false;
		cin >> action;
		if (action == "EXIT") {
			break;
		}
		switch (action[0])
		{
		case 'S':
			cin >> w;
			cin >> x >> y;
			w--;
			drawSquare(graph, x, y, w);
			break;
		case 'L':
			cin >> x1 >> y1 >> x2 >> y2;
			drawLine(graph, x1, y1, x2, y2);
			break;
		case 'T':
			cin >> w;
			w--;
			cin >> x >> y;
			cin >> Dir;
			drawTriangle(graph, x, y, w, Dir);
			break;
		}
		print(graph);
	}
	
			
}