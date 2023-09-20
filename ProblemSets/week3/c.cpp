#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, k, q;
    cin >> num;

    for(int i=0; i<num; i++) {
        int h, n, m;
        cin >> h >> n >> m;

        string result = "YES";

        while(h > 20 && n > 0) {
            h = h/2 + 10;
            n--;
        }

        if(h <= 0) {
            cout << result << endl;
            continue;
        } else if(h > 10*m) {
            result = "NO";
            cout << result << endl;
            continue;
        }

        
        cout << result << endl;
    }
    
    return 0;
}
