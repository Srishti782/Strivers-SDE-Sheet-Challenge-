#include <bits/stdc++.h>
using namespace std; 
void sortStack(stack<int> &s)
{
	// Write your code here
	if(s.empty()){
		return;
	}

	int x = s.top();
	s.pop();

	sortStack(s);
	stack<int> temp;

	while(!s.empty() && s.top() > x){
		temp.push(s.top());
		s.pop();
	}
	s.push(x);

	while(!temp.empty()){
		s.push(temp.top());
		temp.pop();
	}
}