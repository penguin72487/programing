#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#ifdef ENABLE_TIMING
    #include <chrono>
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto durat = duration_cast<nanoseconds>(stop - start);
#endif

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    
    auto it_left = left.begin();
    auto it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left <= *it_right) {
            result.push_back(*it_left);
            ++it_left;
        } else {
            result.push_back(*it_right);
            ++it_right;
        }
    }
    result.insert(result.end(), it_left, left.end());
    result.insert(result.end(), it_right, right.end());

    return result;
}
vector<int> merge_parallel(const vector<int>& left, const vector<int>& right) {
    // if (left.size() + right.size() < 1000) {
    //     // 小資料直接單線程合併
    //     return merge(left, right);
    // }

    auto mid_left = left.size() / 2;

    auto future_left = async(launch::async, [&]() {
        return merge(vector<int>(left.begin(), left.begin() + mid_left),
                     vector<int>(right.begin(), right.begin() + right.size() / 2));
    });

    auto future_right = async(launch::async, [&]() {
        return merge(vector<int>(left.begin() + mid_left, left.end()),
                     vector<int>(right.begin() + right.size() / 2, right.end()));
    });

    vector<int> merged_left = future_left.get();
    vector<int> merged_right = future_right.get();

    // 最後再單線程合併兩邊的結果
    return merge(merged_left, merged_right);
}
vector<int> parallel_merge_sort(vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    auto mid = arr.begin() + (arr.size() >> 1);
    vector<int> left(arr.begin(), mid);
    vector<int> right(mid, arr.end());

    auto future_left = async(launch::async, parallel_merge_sort, ref(left));
    auto future_right = async(launch::async, parallel_merge_sort, ref(right));

    vector<int> sorted_left = future_left.get();
    vector<int> sorted_right = future_right.get();

    return merge_parallel(sorted_left, sorted_right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);


    vector<int> arr={7,12,19,3,18,4,2,6,15,8};
    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif

    vector<int> sorted_arr = parallel_merge_sort(arr);

    #ifdef ENABLE_TIMING
    stop = high_resolution_clock::now();
    durat = duration_cast<nanoseconds>(stop - start);
    cout << "\nTotal time taken: " << double(durat.count()) / 1000000.0 << " ms.\n";
    #endif

    // 印前幾個確認一下
    for(auto& i : sorted_arr) {
        cout << i << " ";
    }
    cout << endl;

 

    return 0;
}
