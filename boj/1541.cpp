// 백준 1541-잃어버린 괄호
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findAnswer(string s)
{
	int answer = 0;
	string temp = "";
	bool minus = false;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\n') {
			if (minus)
				answer -= stoi(temp);
			else
				answer += stoi(temp);
			temp = "";
			if (s[i] == '-')
				minus = true;
		}
		else
			temp += s[i];
	}
	return  answer;
}

int main()
{
	string s; cin >> s;
	s += '\n';
	int answer = findAnswer(s);
	cout << answer << "\n";
	return 0;
}