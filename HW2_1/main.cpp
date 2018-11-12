#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct mydata
{
    priority_queue<int, vector<int>, greater<int> > right;
    priority_queue<int> left;
    int count;

    void __init__()
    {
        count = 0;
        while(!right.empty())
            right.pop();
        while(!left.empty())
            left.pop();
    }

    void __push__(int n)
    {
        if (!count){
            left.push(n);
        }else{
            if (n > left.top()){
                right.push(n);
                if ( !(count & 1) ){
                    left.push(right.top());
                    right.pop();
                }
            }else{
                left.push(n);
                if (count & 1){
                    right.push(left.top());
                    left.pop();
                }
            }
        }
        count++;
    }

    void __del__()
    {
        left.pop();
        if (!(count&1)){
            left.push(right.top());
            right.pop();
        }
        count--;
    }

    int __query__()
    {
        return left.top();
    }
};

int main() {
    int t, n;
    char op;
    int num;

    scanf("%d", &t);
    while(t--) {
        mydata here;
        here.__init__();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            getchar();
            scanf("%c", &op);

            switch(op)
            {
                case 'I':
                    scanf("%d", &num);
                    here.__push__(num);
                    break;
                case 'D':
                    here.__del__();
                    break;
                case 'Q':
                    printf("%d\n", here.__query__());
                    break;
            }
        }
    }
    return 0;
}
