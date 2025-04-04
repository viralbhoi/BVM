// #include <iostream>
// #include <thread>
// int main() {
// unsigned int cores = std::thread::hardware_concurrency();
// std::cout << "Available CPU cores: " << cores << std::endl;
// return 0;
// }

#include <iostream>
#include <vector>
#include <thread>
// #include <algorithm> // For std::min_element
// #include <random>    // For generating random numbers
#include <chrono>    // For measuring execution time
// // Function to find the minimum value in a subarray
// void find_min(const std::vector<int> &arr, int start, int end, int &min_val)
// {
//     min_val = *std::min_element(arr.begin() + start, arr.begin() + end);
// }
// int main()
// {
//     const int SIZE = 10000000; // Large array size
//     const int NUM_THREADS = 4; // Number of threads to use
//     // Generate random numbers for the array
//     std::vector<int> arr(SIZE);
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<int> dis(-1000, 1000);

//     for (int &num : arr)
//     {
//         num = dis(gen);
//     }
//     // **1. Single-threaded approach**
//     auto start_time = std::chrono::high_resolution_clock::now();

//     int min_single = *std::min_element(arr.begin(), arr.end());
//     auto end_time = std::chrono::high_resolution_clock::now();
//     auto single_time = std::chrono::duration<double>(end_time -
//                                                      start_time)
//                            .count();
//     std::cout << "Single-threaded Min: " << min_single << "\n";
//     std::cout << "Time taken (Single-threaded): " << single_time << "seconds\n\n ";
//         // **2. Multi-threaded approach**
//         start_time = std::chrono::high_resolution_clock::now();

//     std::vector<std::thread> threads(NUM_THREADS);
//     std::vector<int> min_vals(NUM_THREADS, std::numeric_limits<int>::max());
//     int chunk_size = SIZE / NUM_THREADS;
//     // Create threads to find local minimums
//     for (int i = 0; i < NUM_THREADS; ++i)
//     {
//         int start = i * chunk_size;
//         int end = (i == NUM_THREADS - 1) ? SIZE : (start + chunk_size);
//         threads[i] = std::thread(find_min, std::cref(arr), start, end,
//                                  std::ref(min_vals[i]));
//     }
//     // Join threads
//     for (auto &t : threads)
//     {
//         t.join();
//     }
//     // Find the global minimum from the results of each thread
//     int min_multi = *std::min_element(min_vals.begin(), min_vals.end());
//     end_time = std::chrono::high_resolution_clock::now();
//     auto multi_time = std::chrono::duration<double>(end_time -
//                                                     start_time)
//                           .count();
//     std::cout << "Multi-threaded Min: " << min_multi << "\n";
//     std::cout << "Time taken (Multi-threaded): " << multi_time << " seconds\n";
//     // **Performance comparison**
//     std::cout << "\nSpeedup Factor: " << single_time / multi_time << "x\n";
//     return 0;
// }

int sum = 0;
int mini = INT_MAX;

using namespace std;
void foo(int start, int end,vector<int> arr)
{
    for (int it = start; it < end; ++it)
    {
       sum += arr[it];
       mini = min(mini,arr[it]);
    }

    
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,-1,0,0,0,-5};
    auto start_time = std::chrono::high_resolution_clock::now();

    vector<thread> threads(5);

    for (int i = 0; i < 5; ++i) {
        int chunk_size = nums.size() / threads.size();

        int start =  i*chunk_size;
        int end =  i*chunk_size + chunk_size;

        threads[i] = thread(foo,start,end,nums);
    }
    for (auto& t : threads) {
        t.join();
    }

    // for(auto t : threads){
    //     t.join();
    // }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto multi_time = std::chrono::duration<double>(end_time - start_time).count();
     std::cout << "Time taken (Multi-threaded): " << multi_time << " seconds\n";
    cout<<sum<<endl;
    cout<<mini<<endl;
    return 0;
}