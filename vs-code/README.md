# vs-code
用vscode編譯器的時候都在這裡寫
## 起源
想要使用debugger，可是devC++有BUG會閃退，code::blacks不喜歡，就使用VScode。

## 值得看的東西

### g271 g277 APCS2021九月第三題
 g277的各種解
* [`g271前綴合`](github.com/penguin72487/zero-judge-practice/blob/master/vs-code/g271前綴合.cpp)TLE爆時間O(n^2)
* [`g277陣列線段`](https://github.com/penguin72487/zero-judge-practice/blob/master/vs-code/g277%E9%99%A3%E5%88%97%E7%B7%9A%E6%AE%B5.cpp)以陣列模擬fake segment tree O(nlongn)
* [`g277笛卡兒樹`](github.com/penguin72487/zero-judge-practice/blob/master/vs-code/g277笛卡爾樹.cpp)使用笛卡兒樹解 O(n)
* [`g277DCtree`](https://github.com/penguin72487/zero-judge-practice/blob/master/vs-code/g277DCtree.cpp)使用堆疊優化建樹流程，去除父節點O(n)
  
### 圖論
* [`無向圖最短距離`](https://github.com/penguin72487/zero-judge-practice/blob/master/vs-code/%E7%84%A1%E5%90%91%E5%9C%96%E6%9C%80%E7%9F%AD%E8%B7%9D%E9%9B%A2.cpp) 無向圖有加權最短距離
* [`f678最小生成樹`](https://github.com/penguin72487/zero-judge-practice/blob/master/vs-code/f678%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A8%B9.cpp) 無向圖有加權->樹 可試試[`最小生成樹測資`](https://github.com/penguin72487/zero-judge-practice/blob/master/vs-code/%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A8%B9%E6%B8%AC%E8%B3%87)所提供之測資。
* [`BipartiteGraph`](https://github.com/penguin72487/zero-judge-practice/blob/master/vs-code/BipartiteGraph.cpp) 二分圖檢測
  
## 還沒寫完 2021/11/10
* 矩陣計算機，矩陣快速冪
* skip list
* 把skip list嵌入笛卡兒樹的建樹中
* `g598BipartiteGraph` 二分圖解APCS2021十一月第四題
  
