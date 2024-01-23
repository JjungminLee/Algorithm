#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m, max = -1;
    long long start, end, mid, sum;
    cin >> n >> m;

    int arr[n];

    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    sort(arr, arr+n);

    start = 0;
    end = arr[n - 1];

    while(start <= end){
        sum = 0;
        mid = (start + end) / 2;

        for(int i = 0 ; i < n ; i++){
            if(arr[i] - mid > 0) sum += arr[i] - mid; //자른 나무 길이
        }

        if(sum >= m){
            start = mid + 1;
            if(mid > max) max = mid;
        }
        else end = mid - 1;
    }

    cout << max;
    
    return 0;
}