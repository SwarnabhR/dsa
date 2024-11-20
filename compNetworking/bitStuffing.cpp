#include<iostream>
#include<string>
using namespace std;

int main(){
    int a[20], b[30], i, j, k, count, n, c[30], l, p;
    cout << "Enter size of data: " << endl;
    cin >> n;
    cout << "Enter the data in the form of 0 and 1: " << endl;
    for (i = 0; i < n; i++){
        cin >> a[i];
    }
    i = 0;
    count = 1;
    j = 0;
    l = 0;
    while(i<n){
        count = 1;
        if (a[i] == 1){
            b[j] = a[i];
            for (k = i + 1; a[k] == 1 && k < n && count < 5; k++){
                b[j] = a[k];
                count++;
                if (count == 5){
                    j++;
                    b[j] = 0;
                    c[l] = j;
                    l++;
                }
                i = k;
            }
        }
        else{
            b[j] = a[i];
        }
        i++;
        j++;
    }
    cout << "After bit stuffing the sending frame is: " << endl;
    cout << "011111110 HEADER" << endl;
    for (i = 0; i < j; i++){
        cout << b[i];
    }
    cout << "  TRAILER 011111110" << endl;
    cout<<"After bit de-stuffing the actual data is: "<<endl;
    for (i = 0, p = 0; i < j; i++){
        if(i==c[p]){
            p++;
            continue;
        }
        cout<<b[i];
    }
    return 0;
}