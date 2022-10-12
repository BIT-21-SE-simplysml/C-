#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
//int *p = new int(5);'
struct Student{
	int age;
	char grade;
};
Student s1 = {8,'A'};
Student *p = new Student;
int main(){
	p -> age = 308;
	cout << endl << (*p).age;
	for (int i = 0; i <= 5; ++i){
		int a;
		cin >> a;
		v.push_back(a);
		cout << v.size() << endl;//uint
	}
	sort(v.begin(),v.end());
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	return 0;
}
/*	int c;
	char v = 'c';
	n = 9;
//	cout << &n;
	int a,b;
//	cout << '\n';
//	cout << &a << '\n' << &b;
//	cout << '\n' << &c;
//	int *p = &a;
	cout << p << endl << &a << endl << &b << endl << p + 1; 

}*/
