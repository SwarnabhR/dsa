#include<iostream>
using namespace std;

int main(){
    int msg[7], recmsg[7];

    cout << "Enter the message: " << endl;
    for (int i = 1; i <= 7; i++){
        if (i == 1 || i == 2 || i == 4)
        {
            continue;
        }
        cin >> msg[i];
    }
    msg[1] = msg[3] ^ msg[5] ^ msg[7];
    msg[2] = msg[3] ^ msg[6] ^ msg[7];
    msg[4] = msg[5] ^ msg[6] ^ msg[7];

    cout << "Enter the data recieved by reciever: " << endl;
    for (int i = 1; i <= 7; i++){
        cin >> recmsg[i];
    }
    int C, C1, C2, C4;
    C1 = recmsg[1] ^ recmsg[3] ^ recmsg[5] ^ recmsg[7];
    C2 = recmsg[2] ^ recmsg[3] ^ recmsg[6] ^ recmsg[7];
    C4 = recmsg[4] ^ recmsg[5] ^ recmsg[5] ^ recmsg[7];

    C = C4 * 4 + C2 * 2 + C1 * 1;

    if (C4 == 0 && C2 == 0 && C1 == 0){
        cout << "No error";
    } else {
        cout << "Error at position: " << C << endl;
        if (recmsg[C] == 0){
            recmsg[C] = 1;
        } else{
            recmsg[C] = 0;
        }
        cout << "Message after fixing the error: " << endl;
        for (int j = 1; j <= 7; j++){
            cout << recmsg[j];
        }
    }
    
    return 0;
}