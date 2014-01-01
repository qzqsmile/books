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
    if (n <= 0 || n > RAND_MAX)
	throw domain_error("Argument to nrand is out of rantge");

    const int bucket_size = RAND_MAX / n;
    int r;
    do
	r = rand() / bucket_size;
    while (r >= n);

    return r;
}

long int lnrand(long int n)
{
    int temp_rand = 0;
    int four_bit_low = 0, four_bit_middle = 0, four_bit_high = 0;
    long int result = 0;

    if (n < 32767) {
        nrand(n);
    } else {
        if (bit_long_int(n) > 8) {

            four_bit_high = n / 100000000;
            four_bit_low = n % 10000;
            four_bit_middle = (n / 10000) % 10000;

            temp_rand = nrand((four_bit_high) + 1);
            if (temp_rand < four_bit_high) {
                result +=
                    10000 * 10000 * temp_rand + nrand(10000) +
                    nrand(10000);
            } else if( temp_rand == four_bit_high ){
                temp_rand = nrand((four_bit_middle + 1));
                if (temp_rand < four_bit_middle) {
                    result += four_bit_high * 10000 * 10000 + temp_rand * 10000 + nrand(10000);
                } else if(four_bit_middle == temp_rand){
                    temp_rand = nrand((four_bit_low + 1)); 
                    if (temp_rand <= four_bit_low) {
                        result += four_bit_high * 10000 * 10000 + four_bit_middle * 10000 + temp_rand;
                    }else{
                        result = lnrand(n);
                    }
                }else{
                    result = lnrand(n);
                }
            }else {
                result = lnrand(n);
            }
        } else {
            four_bit_low = n % 10000;
            four_bit_middle = n / 10000;
            temp_rand = nrand((four_bit_high)+1);
            if(temp_rand < four_bit_high){
                result += temp_rand * 10000 * 10000 + nrand(10000);
            }else if(temp_rand == four_bit_high){
                temp_rand = nrand((four_bit_low + 1));
                if (temp_rand <= four_bit_low){
                    result += four_bit_middle * 10000 + nrand(10000);
                }else{
                    result += lnrand(n);
                }
            }else{
                result = lnrand(n);
            }
        }
    }
    return result;
}

int bit_long_int(long int n)
{
    int bit = 1;

    while (n = n / 10) {
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
