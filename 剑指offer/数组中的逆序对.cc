/**
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
 */
class Solution {
public:
	/*
	运行时间：135ms
	占用内存：4520k
	*/
    // 归并排序思想: 逆序数即稳定排序过程中数据交换的次数
    // 注意前>后才称为逆序数，因此排序时必须前>后才进行交换
    // 比如已经归并的有序数组L=[4,5,7]和R=[4,6]进行归并时
    // 1. 插入R的4时[5,7]均未插入，cnt+=2;
    // 2. 插入R的6时[7]均未插入，cnt+=1
    int Merge(int a[], int k, int n) {
        int cnt = 0;
        vector<int> v(a, a + n);
        int i1 = 0;
        int i2 = k;
        int i = 0;
        while (i1 < k && i2 < n) {
            if (v[i1] <= v[i2]) {
                a[i++] = v[i1++];
            } else {
                a[i++] = v[i2++];
                cnt = (cnt + k - i1) % 1000000007;  // 关键部分
            }
        }
        if (i1 == k) {
            while (i2 < n)
                a[i++] = v[i2++];
        } else {
            while (i1 < k)
                a[i++] = v[i1++];
        }
        return cnt;
    }
    
    int InversePairs(int a[], int n) {
        if (n <= 1)
            return 0;
        int mid = n / 2;
        int res1 = InversePairs(a, mid);
        int res2 = InversePairs(a + mid, n - mid);
        int cnt = Merge(a, mid, n);
        cnt = (cnt + res1) % 1000000007;
        cnt = (cnt + res2) % 1000000007;
        return cnt;
    }
    
    int InversePairs(vector<int> data) {
        return InversePairs(&data[0], data.size());
    }
	
	/* 基于分割操作的思想 */
	// 从左到右依次遍历a[1]~a[n-1]，若小于a[0]则放到左边(序列L)，否则放到右边(序列R)
    // 每次把较小的数放到左边时，原本大于它又在它左边的数有a[0]和已经放到右边的数
    // 所以此时cnt += (1 + R.size())，其中R是右边的数序列
	/*
	运行时间：150ms
	占用内存：4252k
	*/
/*	int InversePairs(int a[], int n) {
        if (n <= 1)
            return 0;
        int nLeft = 0;  // 小于a[0]的数量
        for (int i = 1; i < n; i++) {
            if (a[i] < a[0])
                nLeft++;
        }
        int nRight = n - 1 - nLeft;
        int cnt = nLeft % 1000000007;
        // Partition操作
        int* p = new int[n - 1];
        for (int i = 0; i < n - 1; i++)
            p[i] = a[i + 1];
        a[nLeft] = a[0];
        int iLeft = 0;
        int iRight = nLeft + 1;
        for (int i = 0; i < n - 1; i++) {
            if (p[i] < a[nLeft]) {
                cnt = (cnt + iRight - nLeft - 1) % 1000000007;
                a[iLeft++] = p[i];
            } else {
                a[iRight++] = p[i];
            }
        }
        delete[] p;
        cnt += InversePairs(a, nLeft);
        cnt %= 1000000007;
        cnt += InversePairs(a + nLeft + 1, nRight);
        cnt %= 1000000007;
        return cnt;
    }

    int InversePairs(vector<int> data) {
        return InversePairs(&data[0], data.size());
    }*/
};