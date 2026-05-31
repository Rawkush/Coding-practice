class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(auto x: asteroids) {
            if(mass > asteroids[asteroids.size()-1]) return true;
            if(mass >= x) mass+=x;
            else return false;
        }
        return true;
    }
};