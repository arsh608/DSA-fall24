#include<iostream>
using namespace std;

int recursive_factorial(int n){
	if(n==0 || n==1){
        return 1;
    }

    else{
        return  n * recursive_factorial(n-1);
    }
}

int main(){
    cout << "Enter Number for Factorial: ";
    int num;
    cin >> num;
    if(num<0){
		cout<<"No Factorial for negative numbers";
	}
    else{
    cout << "Factorial of " << num << " is " << recursive_factorial(num);}
    
    return 0;
}
