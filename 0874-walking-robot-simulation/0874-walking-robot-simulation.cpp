class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        vector<pair<int,int>> directions(4);
        directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int current_direction_idx = 0;
        pair<int,int> current_pos = {0,0};
        set<pair<int,int>> obstacles_set;
        for(int i = 0 ; i < obstacles.size();i++){
            obstacles_set.insert({obstacles[i][0],obstacles[i][1]});
        }
        int ans = 0;
        for(int i = 0 ; i < commands.size();i++){
            int cmd = commands[i];
            if(cmd == -1){
                current_direction_idx = (current_direction_idx+1)%4;
            }
            else if ( cmd == -2){
                current_direction_idx = (current_direction_idx+3)%4;
            }
            else
            {
                for(int i = 1;  i <= cmd ; i++){
                    pair<int,int> newPosition = {current_pos.first + directions[current_direction_idx].first,current_pos.second + directions[current_direction_idx].second};
                    if(obstacles_set.find(newPosition) == obstacles_set.end()){
                        current_pos = newPosition;
                    }else{
                        break;
                    }
                    int newDistance =  pow(current_pos.first,2) + pow(current_pos.second,2);
                    ans = max(ans,newDistance);
                }
            }
        }
        int newDistance =  pow(current_pos.first,2) + pow(current_pos.second,2);
        ans = max(ans, newDistance);
        return ans;
        
    }
};