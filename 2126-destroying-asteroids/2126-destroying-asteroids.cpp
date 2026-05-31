class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long lm = mass;
        for(int i = 0; i < asteroids.size(); i++){
            if(lm < asteroids[i])
                return false;
            lm += asteroids[i];
        }
        return true;
    }
};