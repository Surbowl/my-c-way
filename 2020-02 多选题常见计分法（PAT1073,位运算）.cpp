/*
PAT (Basic Level) Practice �����ģ� / 1073 ��ѡ�ⳣ���Ʒַ� (20��)
https://pintia.cn/problem-sets/994805260223102976/problems/994805263624683520

��ʱ������: 400ms �ڴ�����: 64MB

����
���Ķ�ѡ���ǱȽ��鷳�����飬�кܶ಻ͬ�ļƷַ�����
��һ������ļƷַ����ǣ��������ѡ���˲�����ȷѡ�����û��ѡ���κδ���ѡ���õ� 50% ������
�������ѡ�����κ�һ�������ѡ����ܵ÷֡�
���������д�����������ʦ���Ķ�ѡ�⣬����ָ���ĵ�����ĸ�ѡ��������ࡣ

����
�����ڵ�һ�и������������� N����1000���� M����100�����ֱ���ѧ�������Ͷ�ѡ��ĸ�����
��� M �У�ÿ��˳�θ���һ���������ֵ�������� 5 ������������ѡ������������� 2 �Ҳ����� 5 ������������
��ȷѡ�������������ѡ�����������������������ȷѡ�ע��ÿ���ѡ���СдӢ����ĸ a ��ʼ˳�����С�
������� 1 ���ո�ָ���
��� N �У�ÿ�и���һ��ѧ���Ĵ����������ÿ��𰸸�ʽΪ (ѡ�е�ѡ����� ѡ��1 ����)������Ŀ˳�������
ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ���������ѡ�е�ѡ��������ʵ��ѡ�����������

���
���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�У����С����� 1 λ��
���������������Ŀѡ�����Ϣ����ʽΪ��������� ��Ŀ��ţ���Ŀ���������˳���1��ʼ��ţ�-ѡ��š�
����в��У���ÿ��һ��ѡ�����Ŀ��ŵ���˳��������ٲ�����ѡ��ŵ���˳�����������β�����ж���ո�
���������Ŀ��û���˴��������һ����� Too simple��

�������� 1 
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)

������� 1 
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b

�������� 2
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)

������� 2
5.0
5.0
Too simple

��ʾ
����λ���� 
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n, m, optnum, truenum, temp, maxcnt = 0;
    int hash[] = {1, 2, 4, 8, 16}, opt[1010][110] = {0};
    char c;
    scanf("%d %d", &n, &m);
    vector<int> fullscore(m), trueopt(m);
    vector<vector<int>> cnt(m, vector<int>(5));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &fullscore[i], &optnum, &truenum);
        for (int j = 0; j < truenum; j++) {
            scanf(" %c", &c);
            trueopt[i] += hash[c-'a'];
        }
    }
    for (int i = 0; i < n; i++) {
        double grade = 0;
        for (int j = 0; j < m; j++) {
            getchar();
            scanf("(%d", &temp);
            for (int k = 0; k < temp; k++) {
                scanf(" %c)", &c);
                opt[i][j] += hash[c-'a'];
            }
            int el = opt[i][j] ^ trueopt[j];
            if (el) {
                if ((opt[i][j] | trueopt[j]) == trueopt[j]) {
                    grade += fullscore[j] * 1.0 / 2;
                }
                for (int k = 0; k < 5; k++)
                    if (el & hash[k]) cnt[j][k]++;
            } else {
                grade += fullscore[j];
            }
        }
        printf("%.1f\n", grade);
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 5; j++)
            maxcnt = maxcnt > cnt[i][j] ? maxcnt : cnt[i][j];
    
    if (maxcnt == 0) {
        printf("Too simple\n");
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < cnt[i].size(); j++) {
                if (maxcnt == cnt[i][j])
                    printf("%d %d-%c\n", maxcnt, i+1, 'a'+j);
            }
        }
    }
    return 0;
}
