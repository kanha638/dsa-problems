class Robot {
public:
    int current_dir; 
    pair<int,int> current_pos;
    vector<pair<int,int>> directions;
    int gridWidth;
    int gridHeight;
    int gridParameter;

    Robot(int width, int height) {
        gridWidth = width;
        gridHeight = height;
        directions = {{0,1},{1,0},{0,-1},{-1,0}};
        current_dir = 1; // east direction at starting as per the problem statement
        current_pos = {0,0}; 
        gridParameter = 2 * width + 2*height - 4; 
    }
    
    void step(int num) {
        int effectiveStep = num%gridParameter;

        if(effectiveStep == 0){ // edge case handling
            if(current_pos.first == gridWidth-1 && current_pos.second == 0){
                current_dir = 1; // move it to east
            }else if (current_pos.first == 0 && current_pos.second == 0){
                current_dir = 2; // more to south
            }else if (current_pos.second == gridHeight-1 && current_pos.first == gridWidth-1){
                current_dir = 0; // move to north
            }else if (current_pos.second == gridHeight-1 && current_pos.first == 0){
                current_dir = 3; // move to west
            }
        }

        while(effectiveStep--){
            pair<int,int> dir = directions[current_dir];
            pair<int,int> newPos = {current_pos.first + dir.first,current_pos.second + dir.second};
            // cout<< newPos.first << " " << newPos.second << endl;
            if(newPos.first >= gridWidth){
                current_dir = 0; // move it to north
            }else if (newPos.first < 0){
                current_dir = 2; // more to south
            }else if (newPos.second >= gridHeight){
                current_dir = 3; // move to west
            }else if (newPos.second < 0){
                current_dir = 1; // move to east
            }
            dir = directions[current_dir];
            current_pos = {current_pos.first + dir.first,current_pos.second + dir.second};
        }
        
    }
    
    vector<int> getPos() {
        return {current_pos.first,current_pos.second}; 
    }
    
    string getDir() {       
        switch(current_dir){
            case 0:
                return "North";
            case 1: 
                return "East";
            case 2:
                return "South";
            case 3:
                return "West";
            default:
                return "";
        }
        return "";
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */