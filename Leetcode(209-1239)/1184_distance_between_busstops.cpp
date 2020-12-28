class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start>destination)
        {
            swap(start,destination);
        }
    int total_distance=accumulate(distance.begin(),distance.end(),0);
    int inter_distance=accumulate(distance.begin()+start,distance.begin()+destination,0);
    
        return min(inter_distance,total_distance-inter_distance);    
    
    }
};
