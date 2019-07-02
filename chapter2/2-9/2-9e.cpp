#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int N, K, T, U, V, L;
    cin >> N >> K >> T >> U >> V >> L;
    vector<int> D(N + 1);
    D[0] = 0;
    for(int i = 1; i <= N; ++i){ cin >> D[i]; }
    sort(D.begin(), D.end());
    D.push_back(L);
    int stock = 0;
    double answer = 0.0, remains = 0.0;
    for(int i = 1; i < D.size(); ++i){
//cerr << i << " : " << answer << ", " << remains << ", " << stock << endl;
        double len = D[i] - D[i - 1];
        if(stock == 0){
            answer += remains / V;
            answer += (len - remains) / U;
            ++stock;
        }else{
            double d = remains;
            answer += remains / V;
            while(stock > 0 && d < len){
                d += V * T;
                answer += T;
                --stock;
            }
            if(d < len){
                remains = 0.0;
                answer += (len - d) / U;
                ++stock;
            }else{
                remains = d - len;
                answer -= remains / V;
                if(stock == K){
                    remains = V * T;
                }else{
                    ++stock;
                }
            }
        }
    }
    cout << setprecision(9) << setiosflags(ios::fixed) << answer << endl;
    return 0;
}