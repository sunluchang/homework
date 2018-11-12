#include <stdio.h>
#include <string.h>

struct point {
    int x, y;

    bool operator == (const point a) const {
        return (x == a.x && y == a.y);
    }

    bool operator != (const point a) const {
        return (x != a.x || y != a.y);
    }
};

int t, n, m;
int a, b;
int f;

int isopen[1005][1005];
point papa[1005][1005];

int dir[][2] = {
        {0,     -1  },
        {1,     0   },
        {0,     1   },
        {-1,    0   },
};

point getpapa(point x) {
    return papa[x.x][x.y];
}

point find(point x) {
    if (x != getpapa(x)) {
        papa[x.x][x.y] = find(getpapa(x));
    }
    return papa[x.x][x.y];
}

void unionp(point x, point y) {
    point xf = find(x);
    point yf = find(y);
    if (xf == yf)
        return;
    papa[xf.x][xf.y].x = yf.x;
    papa[xf.x][xf.y].y = yf.y;

}

void make() {
    isopen[a][b] = 1;

    papa[a][b].x = a;
    papa[a][b].y = b;

    if (a == 1){
        isopen[0][0] = 1;
        papa[0][0] = {0, 0};
        unionp({a, b}, {0, 0});
    }

    if (a == n){
        isopen[n+1][0] = 1;
        papa[n+1][0] = {n+1, 0};
        unionp({a, b}, {n+1, 0});
    }

    for (int i = 0; i < 4; i++) {
        int x = a + dir[i][0];
        int y = b + dir[i][1];
        if (x >= 1 && y >= 1 && x <= n && y <= n)
            if (isopen[x][y])
                unionp({a, b}, {x, y});

    }
}

void init() {
    f = -1;
    memset(isopen, 0, sizeof(isopen));
    papa[n+1][0] = {n+1, 0};
}

int ok() {
    if (isopen[0][0] && isopen[n+1][0] && find({0,0}) == find({n+1,0}))
        return  1;
    return 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        init();
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &a, &b);
            if (f == -1) {
                make();
                if (ok()) {
                    f = i;
                }
            }
        }
        printf("%d\n", f);
    }
    return 0;
}