#include <bits/stdc++.h>
using namespace std;
double c, pref, maxd, ans = 2147483647;
int n, geted = 0;
double d[10], qd[10], p[10];
void dfs(int depth, double cost, double oils){
    // printf("%d %f\n",depth,cost);
    if (depth == n + 1){
        ans = min(ans, cost);
        geted = 1;
        return;
    }
    double nx = 0;
    for (int i = depth; i <= n; i++){ //从站点depth到站点i
        nx += qd[i];
        if (nx > pref * c)
            break;
        dfs(i + 1, cost + p[depth] * (c - oils), c - nx / pref);                      // Full fill
        dfs(i + 1, cost + max((double)0, p[depth] * nx / pref - p[depth] * oils), 0); // Enough fill
    }
}
int main(){
    scanf("%lf%lf%lf%lf%d", &maxd, &c, &pref, &p[0], &n);
    d[0] = 0;
    for (int i = 1; i <= n; ++i){
        scanf("%lf%lf", &d[i], &p[i]);
        qd[i - 1] = d[i] - d[i - 1];
    }
    qd[n] = maxd - d[n];
    p[n + 1] = 0;
    dfs(0, 0, 0);
    if (geted)
        printf("%.2f\n", ans);
    else
        printf("No Solution\n");
    // printf("Done.\n");
    return 0;
}