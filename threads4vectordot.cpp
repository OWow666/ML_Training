#include<iostream>
#include<thread>
#include<vector>
#include<numeric>

using namespace std;

void partial_dot_product(const vector<int>& v1, const vector<int>& v2, int begin, int end, int& result)
{
    // 通过引用传递（&）来避免复制整个向量，减少内存使用和提高效率，
    // const用于保证函数不会修改向量
    int partial_sum = 0;
    for(int i=begin;i<end;i++)
        partial_sum += v1[i]*v2[i];
    result = partial_sum;
}

int main()
{
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2 = {10,20,30,40,50,60,70,80,90,100};

    const int thread_num =4;
    const int n = v1.size();
    int results[thread_num] = {0};
    // create thread 
    vector<thread> threads(thread_num);

    int len = n/thread_num;
    for(int i=0;i<thread_num;i++)
    {
        int start = i*len;
        int end = (i!=thread_num-1) ? (start+len) : n;

        /*
        功能和用途?
            std::ref 生成一个 std::reference_wrapper 类型的对象，这是一个轻量级的包装器，它包含了对原始对象的引用。
            这个包装器的行为在很多方面模仿了引用的特性，但与真正的引用不同的是，它可以被赋值和复制。
            这使得std::reference_wrapper可以用在通常不允许使用普通引用的地方，如作为容器元素、通过值传递到函数中等。

        为什么需要 std::ref?
            在多线程编程中，尤其是使用 std::thread 时，如果需要传递引用到线程的构造函数中，直接传递引用是不允许的。
            这是因为 std::thread 的构造函数通过值传递其参数，这意味着它会尝试复制其参数。
            由于引用不能直接被复制，所以必须使用 std::ref 来传递引用。
        */

        threads[i] = thread(partial_dot_product, ref(v1), ref(v2), start, end, ref(results[i]));
    }

    // std::thread对象不能被复制，只能被移动。只能通过引用直接操作thread容器内的原始线程对象
    for(auto& t : threads)
    {
        t.join();
    }

    int result = accumulate(results, results+thread_num, 0);

    cout<<"Dot product: "<<result<<endl;

/*
    test:
    int temp=0;
    for(int i=0;i<10;i++) temp+=v1[i]*v2[i];
    cout<<temp<<endl;
*/

    return 0;
}