#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
	/* 思路：讲整个字符串拆分成以单词为单位的字符串，然后将这些子字符串压入LIFO中，
	   这样，弹出LIFO中的元素，将其依次添加到s的尾部，就能形成反转。 */
        stack<string> hub;
        while (!s.empty()) {
		/* 整个算法的时间复杂度为O(n)，因为每一个for循环都只循环一个单词的长度，
		   for循环的调用次数是单词的个数，所以整个while循环只访问字符串n次。额外
		   的空间只用到了一个string对象sTemp和一个stank<string>对象hub，
		   所以额外的空间用的也不多。 */
            size_t cnt = 0;
            for (string::iterator it = s.begin(); it != s.end(); ++it) {
			/* 如果碰到空字符，则终止循环，因为此时已经得到了一个单词，如果是句子的
			   末尾，没有空字符，循环会因为it == s.end()终止。cnt用于拷贝单词字符串。 */
                if (*it != ' ') ++cnt;
                else break;
            }
			if (cnt != 0) {
			/* 这个if语句用于解决输入字符串为全空的情况，即s="    "的情况。在这种情况下
			   不会创建临时string对象，更不会加入任何东西到LIFO中，因此也不会删除有效
			   单词。 */
				string sTemp(s.begin(),s.begin()+cnt);
				hub.push(sTemp);
				s.erase(s.begin(),s.begin()+cnt);
			}
            if(!s.empty()) s.erase(s.begin());
			/* 如果输入不为全空，则会删除有效单词后面的一个空字符，如果输入为全空，则删除
			   的是一个空字符，最后肯定会讲所有空字符删光，如果s中不再有元素了，就不删了。 */
        }
        while (!hub.empty()) {
            string sTemp = hub.top();
            s.append(sTemp);
            hub.pop();
            if (!hub.empty()) s.append(" ");
        }
	}
};

int main(int argc, char* argv[])
{
	string s1("     ");
	string s2("the sky is blue");

	Solution test;
	test.reverseWords(s1);
	test.reverseWords(s2);

	cout << s1 << endl;
	cout << s2 << endl;

	return 0;
}
