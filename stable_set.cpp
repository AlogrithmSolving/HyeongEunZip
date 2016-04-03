#include <iostream>
using namespace std;

int main(){

	int subject, nSubject, semester, maxClass;
	cin >> subject >> nSubject >> semester >> maxClass;
	int set[12];
	int openClass[10];
	int init = 0;
	int R = 0, temp;
	for (int i = 0; i < subject; i++)
	{
		cin >> R;		
		set[i] = 0;
		for (int j = 0; j < R; j++)
		{
			cin >> temp;
			set[i] |= (1 << temp);
		}
		init |= (1 << i);
	}
	for (int i = 0; i < semester; i++)
	{
		cin >> R;
		openClass[i] = 0;
		for (int j = 0; j < R; j++)
		{
			cin >> temp;
			openClass[i] |= (1 << temp);
		}
	}
	int count = 0;
	for (int i = 0; i < semester; i++)
	{
		int takenSubject = 0;
		for (int j = 0; j < subject; j++)
		{
			if ((openClass[i] & (1 << j)) != 0 && ( init &  (1 << j)) != 0 ){
				if ((set[j] & init) == 0){
					//cout << "i = " << i << "//// j = " << j << endl;
					//cout << init << "dddd";
					//init -= (1 << j);
					//cout << init << endl;
					takenSubject |= (1 << j);
				}
			}
		}		
		if (takenSubject > 0){
			count++;
		}
		init = init ^ takenSubject;
		//cout << init << endl;
	}
	if (init == 0){
		cout << count << endl;
	}
	else
		cout << "fail" << endl;
	return 0;
}