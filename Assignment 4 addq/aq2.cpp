# include<iostream>
using namespace std;

int minimumIdx(queue<int>& q, int k){
    int min_val = INT_MAX;
    int minIdx = -1;
    
    for(int i = 0; i < q.size(); i++){
        int curr = q.front();
        q.pop();
        q.push(curr);

        if(i < k && curr < min_val){
            min_val = curr;
            minIdx = i;
        } 
    }

    return minIdx;
}

void moveMinToRear(queue<int>& q, int minIdx, int k){
    int n = q.size();
    int minVal;

    for(int i = 0; i < n; i++){
        int curr = q.front();
        q.pop();
        if(i < k && i == minIdx){
            minVal = curr;
        }
        else{
            q.push(curr);
        }
    }
    q.push(minVal);
}

void SortQueue(queue<int>& q){
    int n = q.size();

    for(int i = 0; i < n; i++){
        int minIdx = minimumIdx(q, n - i);

        moveMinToRear(q, minIdx, n - i);
    }
}

int main(){
    queue<int> q;
    int x;
    int size;
    cout << "Enter size of Queue :";
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> x;
        q.push(x);
    }

    SortQueue(q);
    for(int i = 0; i < q.size(); i++){
        int val = q.front();
        cout << val << " ";
        q.pop();
        q.push(val);
    }

    return 0;
}
