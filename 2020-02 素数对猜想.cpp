/*
PAT (Basic Level) Practice �����ģ� / 1007 �����Բ��� (20��)
https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744

��ʱ������: 200ms �ڴ�����: 64MB

����
�����Ƕ��� dn Ϊ��dn = pn+1 �C pn������ pi �ǵ�i����������Ȼ�� d1=1 �Ҷ���n>1�� dn ��ż����
�������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������
�ָ�������������N (< 105)������㲻����N���������������Եĸ�����

����
������һ�и���������N

���
��һ�������������N���������������Եĸ�����

��������
20

�������
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
