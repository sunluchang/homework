#include <stdio.h>
#include <algorithm>
#include <string.h>

struct edge{
	int a, b;
	int cost;

	bool operator < ( edge e) const {
		return cost < e.cost;
	}
}es[10005];

int n, eg_num, costs;
int papa[105];

int find(int x) {
	if (x != papa[x]) {
		papa[x] = find(papa[x]);
	}
	return papa[x];
}

void init() {
	memset(papa, 0, sizeof(papa));
	eg_num = costs = 0;
}

void kruscal(){
    int tmp;
    for (int i = 0; i < n; i++) {
        papa[i] = i;
        for (int j = 0; j < n; j++) {
            scanf("%d", &tmp);
            if (tmp)
                es[eg_num++] = { i, j, tmp };
        }
    }
    std::sort(es, es + eg_num);
    int now = 0;
    for (int i = 0; i < eg_num; i++) {
        int af = find(es[i].a);
        int bf = find(es[i].b);
        if (af != bf){
            papa[af] = bf;
            now++;
            costs += es[i].cost;
        }
        if(now == n -1) break;
    }
    printf("%d\n", costs);
}

int main(){
    while(~scanf("%d", &n)) {
        init();
        kruscal();
    }
}
