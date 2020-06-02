#include <iostream>
#include <list>
#include <unordered_map>

class LFUCache {
  struct FreqNode;
  struct FreqSubNode {
    int key;
    std::list<FreqNode>::iterator root;
    FreqSubNode(int new_key, std::list<FreqNode>::iterator new_root)
        : key(new_key), root(new_root) {}
  };
  struct FreqNode {
    int freq;
    std::list<FreqSubNode> sub_nodes;
    FreqNode(int new_freq) : freq(new_freq) {}
  };
  struct Node {
    int val;
    int key;
    std::list<FreqSubNode>::iterator freq_subnode_it;
    Node(int new_key, int new_val) : val(new_val), key(new_key) {}
    Node(const Node& node) = default;
  };

 public:
  LFUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto it = cache_.find(key);
    if (it == cache_.end()) return -1;
    auto sub_node_it = it->second.freq_subnode_it;
    it->second.freq_subnode_it = Access(key, sub_node_it);
    return it->second.val;
  }

  void put(int key, int value) {
    if (capacity_ <= 0) return;
    auto it = cache_.find(key);
    if (it != cache_.end()) {
      it->second.val = value;
      it->second.freq_subnode_it = Access(key, it->second.freq_subnode_it);
    } else {
      if (cache_.size() >= capacity_) Evict();
      cache_.emplace(key, Node(key, value));
      if (freq_.empty() || freq_.front().freq != 1) {
        freq_.push_front(FreqNode(1));
      }
      freq_.front().sub_nodes.push_front(FreqSubNode(key, freq_.begin()));
      cache_.at(key).freq_subnode_it = freq_.front().sub_nodes.begin();
    }
  }

 private:
  std::list<FreqSubNode>::iterator Access(
      int key, std::list<FreqSubNode>::iterator subnode_it) {
    int new_freq = subnode_it->root->freq + 1;
    auto new_freq_node_it = subnode_it->root;
    new_freq_node_it->sub_nodes.erase(subnode_it);
    if (!new_freq_node_it->sub_nodes.empty()) {
      ++new_freq_node_it;
    } else {
      freq_.erase(new_freq_node_it++);
    }
    if (new_freq_node_it == freq_.end() || new_freq_node_it->freq != new_freq) {
      new_freq_node_it = freq_.insert(new_freq_node_it, FreqNode(new_freq));
    }
    new_freq_node_it->sub_nodes.push_front(FreqSubNode(key, new_freq_node_it));
    return new_freq_node_it->sub_nodes.begin();
  }

  void Evict() {
    if (freq_.empty()) return;
    int key = freq_.front().sub_nodes.back().key;
    cache_.erase(key);
    freq_.front().sub_nodes.pop_back();
    if (freq_.front().sub_nodes.empty()) {
      freq_.pop_front();
    }
  }

  int capacity_;
  std::unordered_map<int, Node> cache_;
  std::list<FreqNode> freq_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char* argv[]) {
  int capacity = 2;
  LFUCache cache(capacity);
  cache.put(1, 1);
  cache.put(2, 2);
  std::cout << cache.get(1) << std::endl;
  cache.put(3, 3);
  std::cout << cache.get(2) << std::endl;
  cache.get(3);
  cache.put(4, 4);
  std::cout << cache.get(1) << std::endl;
  std::cout << cache.get(3) << std::endl;
  std::cout << cache.get(4) << std::endl;
  return 0;
}