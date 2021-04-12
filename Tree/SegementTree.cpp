

// st: segment Tree

// 지정된 범위의 합을 구하는 쿼리
// qs,qe : 쿼리의 시작 과 끝
// l,r : 현재 노드가 포함하는 index의 시작과 끝
// i: segemntTree의 현재 index
int getMid(int s, int e) { return s + (e -s)/2; }

int getsumUtil(int l , int r ,int i,int qs,int qe)
{
    // if(l<= node[0] && r>=node[1])
    if((l>=qs && r <=qe)) return st[i];
    if(l>qe || r<qs) return 0;
    
    int mid = (l+r)/2;
    return getsumUtil(l,mid,i,qs,qe) + getsumUtil(mid+1,r,i,qs,qe) ;
    
}
int main()
{
    return 0;
}