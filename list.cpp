#include <iostream>
#include <list>
using namespace std;
void josephus(int num, int next){
	list<int> survivors;
	survivors.insert(survivors.begin(), 1);
	for (int i = 1; i < num; i++)
	{
		survivors.insert(survivors.end(), i+1);
	}
	list<int>::iterator kill = survivors.begin();
	list<int>::iterator temp;
	while (survivors.size() > 2)
	{
		temp = kill;
		for (int k = 0; k < next; k++)
		{
			if (*kill == survivors.back()){
				kill = survivors.begin();
			}
			else{
				kill++;
			}
		}
		survivors.remove(*temp);
	}
	cout << survivors.front() << survivors.back() << endl;
}
int main(){
	int testCase;
	cin >> testCase;
	int n, k;
	for (int i = 0; i < testCase; i++)
	{
		cin >> n >> k;
		josephus(n, k);
	}
}