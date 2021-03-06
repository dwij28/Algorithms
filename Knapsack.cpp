/*input
4 5
1 8
2 4
3 0
2 5
2 3
*/

/*~~~~~~~~~~~~~~~~~~~~dwij28 == Abhinav Jha~~~~~~~~~~~~~~~~~~~~*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define set_bit(n, x, i) (n ^ ((-x ^ n) & (1 << i)))
#define get_bit(n, i) ((n >> i) & 1) 
using namespace std;

template<typename T>void scan(T&x){bool n=false;register T c=getchar();x=0;if(c=='-'){n=true;c=getchar();}for(;(c>47&&c<58);c=getchar()){x=(x<<1)+(x<<3)+c-48;}if(n){x*=-1;}}
template<typename T>void allocate(T **x,T n){*x=(T*)malloc(sizeof(T)*n);}

int main() {
	int s, n, size[2500], value[2500], dp[200][200]; // s = total max size, n = no. of elements, size, value arrays for size and value of element, dp matrix for knapsack calculation
	scanf("%d%d", &s, &n);
	for (int i = 1; i < n+1; i++) { // 1 indexed arrays
		scanf("%d%d", &size[i], &value[i]);
	}
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < s+1; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (j < size[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = MAX(value[i] + dp[i-1][j-size[i]], dp[i-1][j]);
		}
	}
	printf("%d\n", dp[n][s]);
	return 0;
}