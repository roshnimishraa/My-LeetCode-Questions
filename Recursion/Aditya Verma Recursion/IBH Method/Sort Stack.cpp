#include <bits/stdc++.h>
void sortedInsert(stack<int> &st,int x){
	if(st.empty() ||(!st.empty() && st.top() < x )){
		st.push(x);
		return;
	}
	int num = st.top();
st.pop();

sortedInsert(st,x);

st.push(num);

} 
void sortStack(stack<int> &st)
{
 if(st.empty()){
	 return;
 }
 int num = st.top();
 st.pop();

 // recursive call 
 sortStack(st);

 sortedInsert(st,num);
}
