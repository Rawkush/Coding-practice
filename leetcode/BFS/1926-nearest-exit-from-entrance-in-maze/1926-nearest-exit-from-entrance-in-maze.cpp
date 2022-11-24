/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> pq;
        maze[entrance[0]][entrance[1]] = 0;
        pq.push(make_pair(entrance[0], entrance[1]));
        int currentLvl=0;

        while(!pq.empty()){
            const int lvlLength = pq.size();
            for(int i = 0; i < lvlLength; i++){
                pair<int, int> currentPos = pq.front();
                pq.pop();
                int row = currentPos.first;
                int col = currentPos.second;
                if((row ==0 || row==maze.size()-1 || col==0 || col==maze[0].size()-1) && currentLvl!=0 ){
                    return currentLvl;
                }
                // go left
                if(row-1>=0 && maze[row-1][col] =='.'){
                    maze[row-1][col] = '+';
                    pq.push(make_pair(row-1, col));
                }
                // go right
                if(row+1<maze.size() && maze[row+1][col]=='.'){
                    maze[row+1][col] = '+';
                    pq.push(make_pair(row+1, col));
                }
                // go up
                if(col-1>=0 && maze[row][col-1]=='.'){
                    maze[row][col-1] = '+';
                    pq.push(make_pair(row, col-1));
                }

                // go down
                if(col+1<maze[0].size() && maze[row][col+1]=='.'){
                    maze[row][col+1] =  '+';
                    pq.push(make_pair(row, col+1));
                }
            }
            currentLvl++;
        
        }
        return -1;
    }
};
// @lc code=end
