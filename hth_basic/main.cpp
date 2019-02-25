    #include<bits/stdc++.h>
    #define gc getchar_unlocked
    using namespace std;


    void sc(int &x)
    {
        register int c = gc();
        x = 0;
        for(;(c<48 || c>57);c = gc());
        for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    }

    int main(){

        //ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n,q,tmp;
        //cin>>n>>q;
        sc(n);
        sc(q);

        int a[n][2];
        int b[n];

        //memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        for(int i=0;i<n;i++)
        { //cin>>a[i][0];
          sc(tmp);
          a[i][0]=tmp;
          a[i][1]=i;
        }


        int k;
        for(int i=1;i<n;i*=2){
            k=0;
            while(i+k<n){
                if(a[k][0]<a[i+k][0]){
                    int temp;
                    temp=a[k][0];
                    a[k][0]=a[i+k][0];
                    a[i+k][0]=temp;

                    temp=a[k][1];
                    a[k][1]=a[i+k][1];
                    a[i+k][1]=temp;

                }
                b[a[k][1]]++;
                b[a[i+k][1]]++;
                k+=2*i;
            }
        }

        while(q--){
            sc(k);
            //cin>>k;
           // cout<<b[--k]<<"\n";
            printf("%d\n",b[--k]);
        }
        return 0;
    }
