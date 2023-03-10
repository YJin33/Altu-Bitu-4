#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 소수 구하기
vector<bool> getPrime(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            is_prime[j] = false;
        }
    }
    return is_prime;
}
// 상근 수 구하기
// 각 자리수의 합을 받아오기
int getSum(int n)
{
    int total = 0;
    int tmp;
    while (n)
    {
        tmp = n % 10;
        total += tmp;
        n /= 10;
    }
    return total;
}

bool isValid(int n)
{
    set<int> visited;
    visited.insert(n);
    while (1)
    {
        // n자리 제곱의 함
        n = getSum(n);
        if (n == 1)
        {
            return true;
        }
        if (visited.find(n) != visited.end())
        {
            return false;
        }
        visited.insert(n);
    }
}
vector<int> solution(int n)
{
    vector<int> result;
    vector<bool> is_prime = getPrime(n);
    for (int i = 0; i <= n; i++)
    {
        if (is_prime[i] && isValid(i))
        {
            result.push_back(i);
        }
    }

    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    // 입력
    cin >> n;
    // 연산
    vector<int> result = solution(n);

    // 출력
    for (int i : result)
    {
        cout << i << "\n";
    }
    return 0;
}