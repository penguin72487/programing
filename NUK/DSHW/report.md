# report hw3
在這次作業中我特別不使用STL與algorithm，但是稍微使用了string，而且刻意使用不這麼像STL的部分。  
在其中我學到最重要的東西是While迭代型的stack要怎麼做，其中一個很關鍵的因素是要使用goto  
這是我第二個發現可以合理使用goto的地方，上次發現還是上次寫尾遞迴的時候。  
這是最核心的程式
```cpp
while (!s.empty()) {
        next:
        Node cur = s.top();
        if (cur.x == ed_X && cur.y == ed_Y) {

            return true;
        }
        for (int i = 0; i < 8; i++) {
            int new_X = cur.x + dx[i];
            int new_Y = cur.y + dy[i];
            if (maze[new_X][new_Y] == '0') {
                s.push(Node(new_X, new_Y));
                maze[new_X][new_Y] = vec[i];
                goto next;
            }
            
        }
        maze[cur.x][cur.y] = 'b';
        s.pop();
    }
```