#include <bits/stdc++.h>
using namespace std;

// we know what it is doing!
// TRUST the function!
void say_hello(int n){
    if(n==0){
        return;
    }
    say_hello(n-1);// prints n-1 hellos
    cout<<"hello "<<n<<"\n";
}

int sum_n(int n){
    if(n==0){
        return 0; //base case!!! #IMP
    }
    return sum_n(n-1)+n;//sum of n-1 elements + n
}

int fact(int n){
    if(n==0){
        return 1;
    }
    return fact(n-1)*n;
}

/*
    1034 -> (103) + 4
    103 -> (10) + 3
    10 -> (1) + 0 // not this! this is not the base case! u can assume like that though
    1 -> (0) + 1 //base case!!
*/

int sum_digits(int n){
    if(n==0){
        return 0;
    }
    return sum_digits(n/10)+(n%10);
}

/*

.. -> prints nothing for n=0!
{1
 12
 123} // (n-1) block
 12..n
*/

void pattern_print_1(int n){
    if(n==0){
        return;//base case!
    }
    pattern_print_1(n-1);
    for(int i=1;i<=n;i++)cout<<i;
    cout<<'\n';
}

/*
123..n
{1234
 123
 12
 1} // (n-1) block
 .. -> prints nothing for n=0! base case!
*/

void pattern_print_2(int n){
    if(n==0){
        return;
    }
    for(int i=1;i<=n;i++)cout<<i;
    cout<<'\n';
    pattern_print_2(n-1);
}

/*
 123..n
{123 n-1 block!
 12
{1} --> base case ! spl case! --> ending case!
 12
 123} n-1 block
 123..n

{123
 12
 1
 12
 123} n-1 block

*/

void pattern_print_3(int n){
    if(n==1){
        cout<<"1\n";
        return;
    }
    for(int i=1;i<=n;i++)cout<<i;cout<<'\n';  
    pattern_print_3(n-1);
    for(int i=1;i<=n;i++)cout<<i;cout<<'\n';
}

/*
* * * * *   * * * * * 
* * * *       * * * * 
* * *           * * * 
* *               * * 
*                   * 
* *               * * 
* * *           * * * 
* * * *       * * * * 
* * * * *   * * * * * 
*/
// TO-DO!! hallow diamond patten
/*
*                   * 
* *               * * 
* * *           * * * 
* * * *       * * * * 
* * * * *   * * * * * 
* * * *       * * * * 
* * *           * * * 
* *               * * 
*                   * 
*/ 
//TO-DO!! this one also

void pattern_print_4(int n){
    
    for(int i=1;i<=n;i++){
        cout<<"* ";
    }
    for(int i=1;i<n;i++)
    {
    }
        
}
// 1,2,3,4,5,6,7,8,...
// 0,1,1,2,3,5,8,13,...
// f6 = f5+f4
// u need prev. 2 values! 
// f(n) = f(n-1) + f(n-2) -> reccurence relation! 
// above recurrence relation fails for base cases!!

int fib(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

/*
nCr = (n-1)Cr + (n-1)C(r-1);
1c1 -> 1
2c2 -> 1
nCn -> 1 OR 1c(0/1) -> 1 #3rd base!
1c2 -> nope # first base!
nc0 -> 1 #2nd base!
*/
// 3c1 = 2c1 + 2c0
// 2c1 = 1c1 + 1c0
int nCr(int n, int r){
    if(n<r){
        return 0;
    }
    if(r==0){
        return 1;
    }
    if(n==r){
        return 1;
    }
    return nCr(n-1,r)+nCr(n-1,r-1);
}

/*
racecar
r_(acecar)_r
*/

bool palindrome_check(string str){
    int n=str.length();
    if(n==1){
        return true;
    }
    if(n==0){
        return true;
    }
    string new_str = str.substr(1,n-2);
    return palindrome_check(new_str)&&(str[0]==str[n-1]);
}

int main(){
        
    //say_hello(10);
    //cout<<sum_n(4);
    //cout<<fact(7);
    //cout<<sum_digits(1034);
    //pattern_print_1(5);
    //pattern_print_2(6);
    //pattern_print_3(5);
    
    //pattern_print_4(5); TO-DO!!

    //cout<<fib(8);
    //cout<<nCr(5,4);
    //(palindrome_check("racecar"))?cout<<"Its a palindrome":cout<<"No its not!";
    
}