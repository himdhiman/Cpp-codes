// C++ implementation of the approach
#include <bits/stdc++.h>
#define MAX 10000002

using namespace std;
int prime[MAX];

// Array to store count of primes
int prime_count[MAX];

// Function to store smallest prime factor
// of every number till MAX
void sieve()
{
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i] == 0) {
            for (int j = i * 2; j < MAX; j += i) {
                if (prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
    for (int i = 2; i < MAX; i++) {

        // If the number is prime then it's
        // smallest prime factor is the number
        // itself
        if (prime[i] == 0)
            prime[i] = i;
    }
}

// Function to return the count of the divisors for
// the product of all the numbers from the array
long long numberOfDivisorsOfProduct(const int* arr,
                                           int n)
{
    memset(prime_count, 0, sizeof(prime_count));

    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        while (temp != 1) {

            // Increase the count of prime
            // encountered
            prime_count[prime[temp]]++;
            temp = temp / prime[temp];
        }
    }

    long long ans = 1;

    // Multiplying the count of primes
    // encountered
    for (int i = 2; i < MAX; i++) {
        ans = ans * (prime_count[i] + 1);
    }

    return ans;
}

// Driver code
int main()
{
    sieve();
//    int arr[] = {10, 5, 3, 1, 2, 6, 9};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    cout << numberOfDivisorsOfProduct(arr, n);
int temp = 9;
    while(temp != 1) {
        cout<<prime[temp]<<endl;
        temp = temp/prime[temp];
    }
    return 0;
}
