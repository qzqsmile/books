#include<iostream>
#include<string>
#include<stdexcept>
#include<cstdlib>

using std::domain_error;
using std::cout;
using std::endl;
using std::cin;

int nrand(int n);
long int lnrand(long int n);
int bit_long_int(long int n);
int four_bit_rand(int n);

int main()
{
    long int n = 0;

    cout << "Please input" << endl;;
    cin >> n;
    n = lnrand(n);
    cout << "The result is " << n << endl;

    return 0;
}

int nrand(int n)
{
    if (n <= 0 || n >  RAND_MAX)
        throw domain_error("Argument to nrand is out of rantge");

    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}

long int lnrand(long int n)
{
    int temp = 0;
    long int result = 0;

    if (n < 32767){
        nrand(n);
    }else{
        if (bit_long_int(n) > 8){
            temp = n % 10000 + 1; 
            result = four_bit_rand(temp);
            n = n / 10000;
            temp = n % 10000 + 1;
            result += four_bit_rand(temp) * 10000;
            n = n / 10000;
            temp = n % 10000 + 1;
            result += four_bit_rand(temp) * 100000000;
        }else{
            temp = n % 10000 + 1;
            result = four_bit_rand(temp);
            temp = n / 10000 + 1;   
            result = result + four_bit_rand (temp) * 10000;
        }
    }
    return result;
}

int bit_long_int(long int n)
{
    int bit = 1;

    while (n = n / 10){
        bit++;
    }
    
    return bit;
}

int four_bit_rand(int n)
{
    if (1 == n)
        return nrand(10000);
    else 
        return nrand(n);
}

