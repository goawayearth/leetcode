#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class LRUCache {
public:
    vector<int> store;
    int capacity;
    int num=0;
    unordered_map<int,vector<int>> list;//vector 第一个是val,pos
    LRUCache(int capacity) {
        this->capacity = capacity;
        for(int i=0;i<capacity;i++){
            store.push_back(-1);
        }
    }

    int get(int key) {
        return list[key][0];
    }

    void put(int key, int value) {
        auto it = list.find(key);
        if(it == list.end()){
            //还不存在
            if(num<capacity){
                store.push_back()
            }
        }
        else{
            //已经存在
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
