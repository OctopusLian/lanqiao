#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq; //构造从小到大的优先队列 
int main() {
  int n;
  cin >> n;
  while (!pq.empty())
    pq.pop();
  int x, s;
  for (int i = 0; i < n; i++) {
    cin >> x;
    pq.push(x); 
  } 
  int sum = 0;
  while (pq.size() > 1) {
    s = pq.top();
    pq.pop();
    s += pq.top();
    pq.pop();
    sum += s;
    pq.push(s);
  }
  cout << sum << endl;
}