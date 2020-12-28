class MedianFinder {
priority_queue<int>pq_lo; //max_hp
    priority_queue<int,vector<int>,greater<int>>pq_hi;
    public:
    /** initialize your data structure here. */
    MedianFinder() {
       //min_hp 
    }
    
    void addNum(int num) {
        pq_lo.push(num);
        pq_hi.push(pq_lo.top());
        pq_lo.pop();
        if(pq_lo.size()<pq_hi.size())
        {
            pq_lo.push(pq_hi.top());
            pq_hi.pop();
        }
    }
    
    double findMedian() {
        double res=0;
        if(pq_lo.size()>pq_hi.size())
        {
            res=pq_lo.top();
        }
        else
        {
            res=(double(pq_lo.top())+pq_hi.top())/2;
        }
        return res;
    }
};

// The max-heap lo is allowed to store, at worst, one more element more than the min-heap hi. Hence if we have processed kk elements:

// If k = 2*n + 1 \quad (\forall \, n \in \mathbb{Z})k=2∗n+1(∀n∈Z), then lo is allowed to hold n+1n+1 elements, while hi can hold nn elements.
// If k = 2*n \quad (\forall \, n \in \mathbb{Z})k=2∗n(∀n∈Z), then both heaps are balanced and hold nn elements each.
// This gives us the nice property that when the heaps are perfectly balanced, the median can be derived from the tops of both heaps. Otherwise, the top of the max-heap lo holds the legitimate median.
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */