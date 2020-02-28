/*
PAT (Basic Level) Practice （中文） / 1007 素数对猜想 (20分)
https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744

总时间限制: 200ms 内存限制: 64MB

描述
让我们定义 dn 为：dn = pn+1 – pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入
输入在一行给出正整数N

输出
在一行中输出不超过N的满足猜想的素数对的个数。

样例输入
20

样例输出
4
*/

#include <iostream>
using namespace std;
bool IsPrimeNum(int num){
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int n,result = 0;
    cin >> n;
    for(int i = 5; i <= n; i++){
        if(IsPrimeNum(i - 2) && IsPrimeNum(i)) result++;
    }
    cout << result;
    return 0;
}
