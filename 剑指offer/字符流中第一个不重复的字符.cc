/**
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。
 * 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 * 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 */
// 对比习题《第一次只出现一次的字符》,注意这里由于是字符流所以无法直接用下标查找字符
class Solution
{
public:
    unordered_map<char, pair<int, int>> us;  // 字符=>(出现次数, 首次出现的位置)
    int cnt = 0;  // 字符流数量
    
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if (us.count(ch) == 0)
            us[ch] = make_pair(1, cnt);
        else
            us[ch].first++;
        cnt++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        int pos = INT_MAX;
        for (auto& x : us) {
            if (x.second.first == 1 && x.second.second < pos) {
                pos = x.second.second;
                ch = x.first;
            }
        }
        return ch;
    }

};