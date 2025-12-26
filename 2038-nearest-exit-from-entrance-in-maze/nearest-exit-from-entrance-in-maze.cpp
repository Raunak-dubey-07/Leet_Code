class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int step=0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
               
                if ((r != entrance[0] || c != entrance[1]) &&
                    ((r == 0 || r == maze.size() - 1) ||c == 0 || c == maze[0].size() - 1)) {
                    return step;
                }
                if(r+1<maze.size() && maze[r+1][c]!='+'){
                    q.push({r+1,c});
                    maze[r+1][c]='+';
                }
                if(r-1>=0 && maze[r-1][c]!='+'){
                    q.push({r-1,c});
                    maze[r-1][c]='+';
                }
                if(c+1<maze[0].size() && maze[r][c+1]!='+'){
                    q.push({r,c+1});
                    maze[r][c+1]='+';
                }
                if(c-1>=0 && maze[r][c-1]!='+'){
                    q.push({r,c-1});
                    maze[r][c-1]='+';
                }

            }
            step++;
        }
        return -1;
    }
};