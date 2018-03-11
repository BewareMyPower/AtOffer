/**
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
 * 请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
 * 那么对应的输出是第一个重复的数字2。
 */
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    // 空间复杂度O(1)的算法，利用数字范围0到n-1的性质可得a[i]肯定能作为下标
    // 比如a[7]={2,3,1,0,2,5,3}，算法如下:
    // 1.a[0]=2!=0，交换a[0]和a[2]，此时a[0]=1,a[2]=2;
    // 2.a[0]=1!=0，交换a[0]和a[1]，此时a[0]=3,a[1]=1;
    // 3.a[0]=3!=0，交换a[0]和a[3]，此时a[0]=0,a[3]=3;
    // 4.继续往前寻找，直到a[4]=2，而a[2]=2=a[4]，找到重复元素
    // 因为上述每一步都能使得有一个a[i]=i，所以交换次数不超过n
    // 而迭代次数是n，因此总的时间复杂度是O(n)	
	bool duplicate(int numbers[], int length, int* duplication) {
        if (!numbers || !duplication)
            return false;
        for (int i = 0; i < length; ++i) {
            if (numbers[i] < 0 || numbers[i] >= length)
                return false;
            while (numbers[i] != i) {
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
	
/*    bool duplicate(int numbers[], int length, int* duplication) {
        vector<int> v(length, 0);
        for (int i = 0; i < length; ++i) {
            if (numbers[i] < 0 || numbers[i] >= length)
                return false;
            v[numbers[i]]++;
            if (v[numbers[i]] > 1) {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;  // 没有重复元素
    }*/
};