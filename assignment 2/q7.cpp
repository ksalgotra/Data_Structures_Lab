# include<iostream>
using namespace std;

int arr[50];
int max_size = 50;
int n = 0;
void createArr(){
    cout<<"Enter size of array :";
    cin>>n;
    if(n > max_size){
        cout<<"Invalid Input"<<endl;
        return;
    }
    cout<<"Enter elements :";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
}

int mergeANDcount(int l, int m, int r){
    int temp[100];
    int i = l;
    int j = m + 1;
    int idx = 0;
    int inv_count = 0;
    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            temp[idx++] = arr[i++];
        }
        else{
            temp[idx++] = arr[j++];
            inv_count += m - i + 1;
        }
    }
    while(i <= m){
        temp[idx++] = arr[i++];
    }
    while(j <= r){
        temp[idx++] = arr[j++];
    }

    for(int k = 0; k <= idx - 1; k++){
        arr[l + k] = temp[k];
    }

    return inv_count;
}

int CountInv(int l, int r){
    if(l >= r){
        return 0;
    }
    int mid = l + (r - l)/2;
    int leftCount = CountInv(l, mid);
    int rightCount = CountInv(mid + 1, r);

    return leftCount + rightCount + mergeANDcount(l, mid, r);

}

int main(){
    createArr();
    cout << "The number of inversions for the given array are :" << CountInv(0, n - 1);

    return 0;
}
