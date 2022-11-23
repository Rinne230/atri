#include <iostream>
using namespace std;
int fun(int *num1, int *num2 ){
    if(*num2 == 0) return *num1;
    *num1 = *num1 % *num2;
    return fun(num2, num1);
}
int main(){		
	int a, num1,num2;
	cin >> num1 >> num2;
	cout << num1 << "和" << num2 <<"的最大公约数是："; 
	a = fun(&num1, &num2);  
	cout << a << endl; 
	return 0;
}