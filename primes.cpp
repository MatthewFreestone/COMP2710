#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout << "Go up to what number? ";
    cin >> n;

    auto begin = chrono::steady_clock::now();
    int primes_count = 0;
    vector<bool> notPrime(n+1);
    // bool notPrime[n+1] = {false};
    for (int i = 2; i < n; i++)
    {
        if (!notPrime[i]){
            primes_count++;
            for (int j = 2; j <= (n/i); j++)
            {
                notPrime[i*j] = true;
            }
        }
    }
    auto end = chrono::steady_clock::now();
    auto diff = chrono::duration_cast<chrono::microseconds>(end-begin).count();
    printf("Found %d primes in %.4f seconds",primes_count, diff/1000000.0);
    // cout << "Found " << primes_count << " primes in " << diff << " ms."<< endl;
    return 0;
}
