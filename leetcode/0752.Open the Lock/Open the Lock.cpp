class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        dead.insert(deadends.begin(), deadends.end());
        if(dead.count("0000"))
            return -1;
        int steps = 0;
        queue<string> q;
        q.push("0000");
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; ++i){
                string curr = q.front();
                q.pop();
                if(curr == target)return steps;
                for(int j = 0; j < 4; ++j){
                    for(int t = -1; t < 2; t += 2){
                        char y = (curr[j] -'0' + 10 + t) % 10 + '0';
                        string x = curr;
                        x[j] = y;
                        if(!dead.count(x)){
                            q.push(x);
                            dead.emplace(x);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
