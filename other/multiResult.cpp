public int [ ] multi (int [ ] a){
if (null==a)
return null;
int left=1;
int right=1;
int [] ans= new int[a.length];
for (int k=0;k<ans.length;++k)
    ans[k]=1;
for (int i=0;i<a.length;i++){
    ans[i]=ans[i]*left;
    ans[a.length-i-1]=ans[a.length-i-1]*right;
    left=left*a[i];
    right=right*a[a.length-1-i];
    }
    return ans;

}

