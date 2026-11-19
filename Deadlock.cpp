
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;

    cout << "n=processnumbers, m=itemNum : ";
    cin >> n >> m;

    int total[m], process[n];
    int allo[n][m], maX[n][m], need[n][m];
    int available[n+1][m], rem[m], done[n];

    cout << "\nTotal values enter:\n";

    for(int i = 0; i < m; i++) {
        cin >> total[i];
    }

    // Allocation Matrix
    cout << "\nAllocation Matrix:\n";

    for(int i = 0; i < n; i++) {

        process[i] = i + 1;

        cout << "P" << process[i] << ": ";

        for(int j = 0; j < m; j++) {
            cin >> allo[i][j];
        }
    }

    // Max Matrix
    cout << "\nMax Matrix:\n";

    for(int i = 0; i < n; i++) {

        cout << "P" << process[i] << ": ";

        for(int j = 0; j < m; j++) {

            cin >> maX[i][j];

            need[i][j] = maX[i][j] - allo[i][j];
        }
    }

    // Calculate Total Allocation
    int tt[m] = {0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tt[j] += allo[i][j];
        }
    }

    cout << "\nTotal Allocation:\n";

    for(int j = 0; j < m; j++) {
        cout << "Resource " << j+1 << " = " << tt[j] << endl;
    }

    // Calculate Initial Available
    for(int j = 0; j < m; j++) {

        rem[j] = total[j] - tt[j];

        available[0][j] = rem[j];
    }

    cout << "\nInitial Available:\n";

    for(int j = 0; j < m; j++) {
        cout << rem[j] << "\t";
    }

    cout << endl;

    // Initialize done
    for(int i = 0; i < n; i++) {
        done[i] = 0;
    }

    // Banker's Algorithm
    int safe[n];
    int count = 0;

    while(count < n) {

        bool found = false;

        for(int i = 0; i < n; i++) {

            if(done[i] == 0) {

                bool check = true;

                // Check Need <= Available
                for(int j = 0; j < m; j++) {

                    if(need[i][j] > rem[j]) {
                        check = false;
                        break;
                    }
                }

                if(check == true) {

                    // Save process
                    safe[count] = process[i];

                    // Update Available
                    for(int j = 0; j < m; j++) {

                        rem[j] = rem[j] + allo[i][j];

                        available[count+1][j] = rem[j];
                    }

                    // Mark process completed
                    done[i] = 1;

                    count++;
                    found = true;
                }
            }
        }

        if(found == false) {
            break;
        }
    }

    // Print Banker's Table
    cout << "\n\n========== BANKER'S ALGORITHM ==========\n";

    cout << "\nProcess\tAllocation\tMax\t\tNeed\n";

    for(int i = 0; i < count; i++) {

        int p = safe[i] - 1;

        cout << "P" << safe[i] << "\t";

        // Allocation
        for(int j = 0; j < m; j++) {
            cout << allo[p][j] << " ";
        }

        cout << "\t\t";

        // Max
        for(int j = 0; j < m; j++) {
            cout << maX[p][j] << " ";
        }

        cout << "\t";

        // Need
        for(int j = 0; j < m; j++) {
            cout << need[p][j] << " ";
        }

        cout << "\t";

        // Available BEFORE process execution
        for(int j = 0; j < m; j++) {
            cout << available[i][j] << " ";
        }

        cout << endl;
    }

    // Print Safe Sequence
    if(count == n) {

        cout << "\nSystem is in SAFE state!";

        cout << "\nSafe Sequence: ";

        for(int i = 0; i < n; i++) {

            cout << "P" << safe[i];

            if(i != n-1) {
                cout << " -> ";
            }
        }
    }
    else {

        cout << "\nSystem is in UNSAFE state!";

        cout << "\nNo safe sequence exists.";
    }

    // Print Complete Available Matrix
    cout << "\n\nAvailable Matrix History:\n";

    for(int i = 0; i <= count; i++) {

        cout << "Step " << i << ": ";

        for(int j = 0; j < m; j++) {
            cout << available[i][j] << "\t";
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}
