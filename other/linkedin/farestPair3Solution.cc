//Problem :
//Given a sequence of integers A[n], find a pair of integers A[x]<A[y], such that y-x >= j-i and A[i]<A[j]

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution1
{
public:
    std::vector<int> findLongestAscendingPair(std::vector<int>& v)
    {
        std::vector<int> ret(2,0);
        int n = v.size();
        if(n==0) return ret;
        int len=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(v[i]<v[j])
                {
                    if( j-i > len)
                    {
                        len = j-i;
                        ret[0] = i;
                        ret[1] = j;
                    }
                }
            }
        }
        return ret;        
    }

};


class Solution2
{
public:
    std::vector<int> findLongestAscendingPair(std::vector<int>& v)
    {
        std::vector<int> ret(2,0);
        int n = v.size();
        if(n==0) return ret;

        std::vector<int> store;
        store.push_back(0);
        std::vector<int> p(n,0);
        int len=0, low, high, mid;
        for(int i=1; i<n; i++)
        {
            if(v[i]>v[store.back()])
            {
                p[i] = store.back();
                store.push_back(i);
                continue;
            }
            bool flag = false; // indicating same value
            for(low=0, high=store.size()-1; low<high;)
            {
                mid = low + (high-low)/2;
                if(v[store[mid]]<v[i])
                    low = mid+1;
                else
                    high = mid;
            }
            if(v[i] < v[store[low]])
            {
                if(low>0)
                    p[i] = store[low-1];
                store[low]=i;
            }
            int j=i;
            while(v[p[j]] < v[j]) j = p[j];
            if(v[j] < v[i] && i-j>len)
            {
                len = std::max(len, i-j);
                ret[0] = j;
                ret[1] = i;
            }
        }
        return ret;        
    }
};

class Solution3
{
public:
    std::vector<int> findLongestAscendingPair(const std::vector<int> &height) {
        std::vector<int> ret(2,0);
        int n = height.size();
        std::vector<int> left;
        int start = -1;
        int end = -1;
        left.push_back(0);
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            int low = 0;
            int high = left.size();
            if(height[i] < height[left[left.size() - 1]]) {
                left.push_back(i);
            } else {
                while(low < high) {
                    int mid = low + (high - low) / 2;
                    if(height[left[mid]] >= height[i]) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }
                if((i - left[low]) > ans) {
                    start = left[low];
                    end = i;
                }
                ans = std::max(ans, i - left[low]);
            }
        }
        ret[0] = start;
        ret[1] = end;
        return ret;
        //printf("%d, %d\n",start, end);
    }
};

int main()
{
    std::vector<int> result1;
    std::vector<int> result2;
    int a[] = {2,1,1,5,2,3,2,4,3};
    std::vector<int> v(a, a+9);
    Solution1 s1;
    Solution3 s2;
    for(int i=0; i<1000; i++)
    {
        v.clear();
        for(int j=0; j<10; j++)
            v.push_back(rand()%10);
        result1 = s1.findLongestAscendingPair(v);
        result2 = s2.findLongestAscendingPair(v);
        if(result1[0]!=result2[0] || result1[1]!=result2[1])
        {
            std::cout << "\n";
            for(int j=0; j<10; j++) {
                std::cout << v[j] << " ";
            }
            std::cout << "\n";
            std::cout << result1[0] << " " << result1[1] << "\n";
            std::cout << result2[0] << " " << result2[1] << "\n";
                                 
        }
    }


    return 0;
}
