// Problem: C++ Variadics
// Link: https://www.hackerrank.com/challenges/cpp-variadics/problem
// Language: C++
// Difficulty: Hard


template <bool... Args>
int reversed_binary_value(){
    bool arr[] = {Args...};
    int sum = 0;
    int a = 0;
    
    for(bool i : arr){
        sum = sum | ((1&i) << a++);
    }
    return sum;
}


