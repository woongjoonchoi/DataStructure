
// st: segment Tree

// 지정된 범위의 합을 구하는 쿼리
// qs,qe : 쿼리의 시작 과 끝
// l,r : 현재 노드가 포함하는 index의 시작과 끝
// i: segemntTree의 현재 index
#include <math.h>
int getMid(int s, int e) { return s + (e -s)/2; }

int constructSegUtil(int arr[], int ss ,int se , int st[],int i)
{
    if(ss==se) {
        st[i] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss,se);
    st[i] = constructSegUtil(arr,ss,mid,st,2*i) + constructSegUtil(arr,mid+1,se,st,2*i + 1);
    return st[i];
}
int *constructSegTree(int n ,int arr[])
{
    int height= (int)(ceil(log2(n)));

    int max_size = pow(height,2) + 1;

    int *st = new int[max_size];
    constructSegUtil(arr,0,n-1,st,0);
    return st;
}


int getsumUtil(int *st,int l , int r ,int i,int qs,int qe)
{
    // if(l<= node[0] && r>=node[1])
    if((l>=qs && r <=qe)) return st[i];
    if(l>qe || r<qs) return 0;
    
    int mid = (l+r)/2;
    return getsumUtil(st,l,mid,i,qs,qe) + getsumUtil(st,mid+1,r,i,qs,qe) ;
    
}
int getsum(int *st,int n , int qs , int qe,int arr)
{
    return getsumUtil(st,0,n-1,0,qs,qe);
}
int main()
{
    return 0;
}