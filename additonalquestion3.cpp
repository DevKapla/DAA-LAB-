#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;

    while (T--) {
        long long N, H, W;
        cin >> N >> H >> W;

        long long low = 0, high = 1e18;
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            long long fitW = mid / W;
            long long fitH = mid / H;

            if (fitW > 0 && fitH > 0 && fitW * fitH >= N) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
