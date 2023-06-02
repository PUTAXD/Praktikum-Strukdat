#include <bits/stdc++.h>
using namespace std;

int global_x, global_y;

vector<vector<pair<int,int>>> path;
vector<vector<bool>> visited;

int start_x, start_y, end_x, end_y;

vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};

//nyoba valid
bool isValid(int x, int y)
{
	if(x<0 || x >= global_x || y <0 || y>=global_y)
		return false;
	if(visited[x][y])
		return false;
	return true;
}

//bfs
void bfs()
{
	queue<pair<int,int>> queue;
	queue.push({start_x,start_y});
	while(!queue.empty())
	{
		int cx = queue.front().first;
		int cy = queue.front().second;
		queue.pop();
		for(auto mv: moves)
		{
			int mvx = mv.first;
			int mvy = mv.second;
			if(isValid(cx+mvx, cy+mvy))
			{
				queue.push({cx+mvx, cy+mvy});
				visited[cx+mvx][cy+mvy] = true;
				path[cx+mvx][cy+mvy] = {mvx,mvy};
			}
		}
	}
}

int main()
{
	cin >> global_y >> global_x;
	path.resize(global_x);//alokasi memori pada vector
	visited.resize(global_x);
    char maze[global_x][global_y];
	for(int i = 0; i < global_x; ++i)
	{
		path[i].resize(global_y);
		visited[i].resize(global_y);
	}
	for (int i = 0; i < global_x; ++i)
	{
		for (int j = 0; j < global_y; ++j)
		{
			path[i][j] = {-1,-1};
			char c; cin >> c;
            maze[i][j]=c;
			if(c == '#')
			{
				visited[i][j] = true;
			}
			if(c == 'A')
			{
				start_x = i; start_y = j;
			}
			if(c == 'B')
			{
				end_x = i; end_y = j;
			}
		}
	}
	bfs();
	vector<pair<int,int>> ans;
	pair<int,int> end = {end_x,end_y};
	
	while(end.first != start_x || end.second != start_y)
	{
		ans.push_back(path[end.first][end.second]);
		end.first -= ans.back().first;
		end.second -= ans.back().second;	
	}

	reverse(ans.begin(), ans.end());

	for(auto c: ans)
	{
        start_x+=c.first;
        start_y+=c.second;
        if(maze[start_x][start_y]!='B')
        maze[start_x][start_y]='x';
	}

    for (int i = 0; i < global_x; ++i)
	{
		for (int j = 0; j < global_y; ++j){
            cout<<maze[i][j];
        }
        cout<<endl;;
    }
    return 0;
}