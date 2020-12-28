class Solution {
public:
    
    struct Car
    {
      int position;
       double time;
    };
    
    static bool comp(Car a, Car b)
    {
        return a.position < b.position;
    }
    
    
    int carFleet(int target, vector<int>& positions, vector<int>& speed) {
        
        int n=positions.size();
        vector<Car>cars(n);
        
        for(int i=0;i<n;i++)
        {
            Car car;
            double t=(double(target-positions[i])/speed[i]); //time=distance/speed
            car.position=positions[i];
            car.time=t;
            cars[i]=car;
            
        }
        
        sort(cars.begin(),cars.end(),comp);
        
        int ans=0;
        int t=n;
    
        while(--t > 0)
        {
           
            if(cars[t].time <  cars[t-1].time)
            {
                ans++;//if cars[t] arrives sooner, it can't be caught
            }
            else
            {
                cars[t-1]=cars[t];//else, cars[t-1] arrives at same time as cars[t]
            }
        }
        return ans+ (t==0 ? 1 : 0);//lone car is fleet (if it exists)
    }
};
    /*Call the "lead fleet" the fleet furthest in position.

If the car S (Second) behind the lead car F (First) would arrive earlier, then S forms a fleet with the lead car F. Otherwise, fleet F is final as no car can catch up to it - cars behind S would form fleets with S, never F.
A car is a (position, speed) which implies some arrival time (target - position) / speed. Sort the cars by position.

Now apply the above reasoning - if the lead fleet drives away, then count it and continue. Otherwise, merge the fleets and continue.*/
