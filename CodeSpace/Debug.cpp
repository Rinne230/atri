#include <iostream>
using namespace std;
int fun(int *num1, int *num2 ){
    int c;
    for (c = *num1; c >= 1; --c)
        if (*num1 % c == 0 && *num2 % c == 0) break;
    return c;
}
int main(){		
	int a, num1,num2;
	cin >> num1 >> num2;
	cout << num1 << "和" << num2 <<"的最大公约数是："; 
	a = fun(&num1, &num2);  
	cout << a << endl; 
	return 0;
}