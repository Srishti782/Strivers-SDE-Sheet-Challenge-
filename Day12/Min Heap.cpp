#include <bits/stdc++.h>
using namespace std; 
class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        if(pq.size() == 0){
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int PI = 0;
        int LCI = 2*PI + 1;
        int RCI = 2*PI + 2;
        while(LCI < pq.size()){
            int minIndex = PI;
            if(pq[minIndex] > pq[LCI]){
                minIndex = LCI;
            }
            if(RCI < pq.size() and pq[minIndex] > pq[RCI]){
                minIndex = RCI;
            }
            if(minIndex == PI){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[PI];
            pq[PI] = temp;

            PI = minIndex;
            LCI = 2*PI + 1;
            RCI = 2*PI + 2;

        }
        return ans;
    }
   
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    PriorityQueue pq;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(q[i][0] == 0){
            for(int j = 1; j < q[i].size(); j++){
                pq.insert(q[i][j]);
            }
        }
        else{
            ans.push_back(pq.removeMin());
        }
    }
    return ans;
}
