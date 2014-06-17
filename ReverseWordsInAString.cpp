#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
	/* ˼·���������ַ�����ֳ��Ե���Ϊ��λ���ַ�����Ȼ����Щ���ַ���ѹ��LIFO�У�
	   ����������LIFO�е�Ԫ�أ�����������ӵ�s��β���������γɷ�ת�� */
        stack<string> hub;
        while (!s.empty()) {
		/* �����㷨��ʱ�临�Ӷ�ΪO(n)����Ϊÿһ��forѭ����ֻѭ��һ�����ʵĳ��ȣ�
		   forѭ���ĵ��ô����ǵ��ʵĸ�������������whileѭ��ֻ�����ַ���n�Ρ�����
		   �Ŀռ�ֻ�õ���һ��string����sTemp��һ��stank<string>����hub��
		   ���Զ���Ŀռ��õ�Ҳ���ࡣ */
            size_t cnt = 0;
            for (string::iterator it = s.begin(); it != s.end(); ++it) {
			/* ����������ַ�������ֹѭ������Ϊ��ʱ�Ѿ��õ���һ�����ʣ�����Ǿ��ӵ�
			   ĩβ��û�п��ַ���ѭ������Ϊit == s.end()��ֹ��cnt���ڿ��������ַ����� */
                if (*it != ' ') ++cnt;
                else break;
            }
			if (cnt != 0) {
			/* ���if������ڽ�������ַ���Ϊȫ�յ��������s="    "������������������
			   ���ᴴ����ʱstring���󣬸���������κζ�����LIFO�У����Ҳ����ɾ����Ч
			   ���ʡ� */
				string sTemp(s.begin(),s.begin()+cnt);
				hub.push(sTemp);
				s.erase(s.begin(),s.begin()+cnt);
			}
            if(!s.empty()) s.erase(s.begin());
			/* ������벻Ϊȫ�գ����ɾ����Ч���ʺ����һ�����ַ����������Ϊȫ�գ���ɾ��
			   ����һ�����ַ������϶��ὲ���п��ַ�ɾ�⣬���s�в�����Ԫ���ˣ��Ͳ�ɾ�ˡ� */
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
