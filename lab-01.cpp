#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
int value = 8;
ll fork(ll id)//pa
{
    if(id<=0 ) return 1;
    return fork(id-1);
}
int main()
{

    ll pid = fork(1);//ch
    if (pid == 0)   /* child process */
    {
        value +=1;

        return 0;
    }
    else if (pid > 0)   /* parent process */
    {
        printf("PARENT: value = %d",value); /* LINE A */
        return 0;
    }
}
