#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
       stack<int> hub;
	   string sAdd("+");
	   string sMinus("-");
	   string sMultiply("*");
	   string sDivide("/");
	   for (vector<string>::iterator it = tokens.begin();
		    it != tokens.end(); ++ it) {
				if (*it == sAdd) {
					int rhs = hub.top();
					hub.pop();
					int lhs = hub.top();
					hub.pop();
					hub.push(lhs + rhs);
				}
				else if (*it == sMinus) {
					int rhs = hub.top();
					hub.pop();
					int lhs = hub.top();
					hub.pop();
					hub.push(lhs - rhs);
				}
				else if (*it == sMultiply) {
					int rhs = hub.top();
					hub.pop();
					int lhs = hub.top();
					hub.pop();
					hub.push(lhs * rhs);
				}
				else if (*it == sDivide) {
					int rhs = hub.top();
					hub.pop();
					int lhs = hub.top();
					hub.pop();
					hub.push(lhs / rhs);
				}
				else hub.push(stringToInt(*it));
	   }
	   if (hub.size() == 1) return hub.top();
	   else throw new exception("Somting is Wrong!");
    }
private:
	int stringToInt(string &s) {
		int result = 0;
		int weight = 1;
		for (string::reverse_iterator rit = s.rbegin();
			rit != s.rend(); ++rit) {
				if (*rit == '-') result = -result;//若输入为负数
				else {
				 result += weight * (int)(*rit - '0');
				 weight *= 10;
				}
		}
		return result;
	}
};

int main(int argc, char* argv[])
{
	vector<string> token1;
	token1.push_back("2");
	token1.push_back("1");
	token1.push_back("+");
	token1.push_back("3");
	token1.push_back("*");
	
	vector<string> token2;
	token2.push_back("4");
	token2.push_back("13");
	token2.push_back("5");
	token2.push_back("/");
	token2.push_back("+");

	vector<string> token3;
	token3.push_back("4");
	token3.push_back("-3");
	token3.push_back("+");

	Solution test;

	try {
		cout << test.evalRPN(token1) << endl;
		cout << test.evalRPN(token2) << endl;
		cout << test.evalRPN(token3) << endl;
	}
	catch (exception* e) {
		cerr << e->what() << endl;
	}

	return 0;
}