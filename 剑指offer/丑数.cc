/**
 * 把只包含因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含因子7。
 * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 */

class Solution {
public:
	struct Record {
        vector<int>& _v;
        int _mult;
        int id = 0;
        Record(vector<int>& v, int mult) : _v(v), _mult(mult) {}
        
        int next() const { return _v[id] * _mult; }
        
        bool operator < (const Record& rhs) const {
            return next() < rhs.next();
        }
    };
    // 设第k个丑数为a[n]，记录3个位置i,j,k，分别有
    // a[n]>a[i]*2  a[n]>a[j]*3 a[n]>a[k]*5以及
    // a[n]<a[i+1]*2 a[n]<a[j+1]*3 a[n]<a[k+1]*5
    // 那么每次只需要在a[i+1]*2 a[j+1]*3 a[k+1]*5中找到
    // 一个最小的数作为a[n+1]，然后更新相应的i,j,k即可
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        vector<int> v = { 1 };
        v.reserve(index);
        
        vector<Record> records;
        records.emplace_back(v, 2);
        records.emplace_back(v, 3);
        records.emplace_back(v, 5);
        
        for (int i = 1; i < index; ++i) {
            auto it = std::min_element(records.begin(), records.end());
            v.push_back(it->next());
            // 更新下标
            for (auto& rec : records)
                while (rec.next() <= v.back())
                    rec.id++;
        }
        return v.back();
    }
	
/*    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        vector<int> v = { 1 };
        v.reserve(index);
        int id[3] = { 0, 0, 0 };
        int mult[3] = { 2, 3, 5 };
        int val[3];
        for (int i = 0; i < 3; ++i)
            val[i] = v[id[i]] * mult[i];
        for (int i = 1; i < index; ++i) {
            int k = std::min_element(val, val + 3) - val;
            v.push_back(v[id[k]] * mult[k]);
            id[k]++;
            // 更新2，3，5对应的元素下标
            for (int j = 0; j < 3; j++) {
                while ( (val[j] = v[id[j]] * mult[j]) <= v.back() )
                    id[j]++;
            }
        }
        return v.back();
    }*/
};