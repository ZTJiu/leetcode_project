#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
 public:
  LRUCache(int capacity) { capacity_ = capacity; }

  int get(int key) {
    auto it = index_.find(key);
    if (it == index_.end()) return -1;
    int val = it->second->second;
    index_[key] = Access(key, val, it->second);
    return val;
  }

  void put(int key, int value) {
    auto it = index_.find(key);
    if (it != index_.end()) {
      index_[key] = Access(key, value, it->second);
      return;
    }
    if (cache_.size() >= capacity_) {
      int key = cache_.back().first;
      index_.erase(key);
      cache_.pop_back();
    }
    index_[key] = Access(key, value, cache_.end());
  }

 private:
  std::list<std::pair<int, int>>::iterator Access(
      int key, int value, const std::list<std::pair<int, int>>::iterator& it) {
    if (it != cache_.end()) {
      cache_.erase(it);
    }
    cache_.push_front(std::pair<int, int>(key, value));
    return cache_.begin();
  }

  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> index_;
  std::list<std::pair<int, int>> cache_;
  int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char* argv[]) { return 0; }