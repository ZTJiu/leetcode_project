/******************************************
* File  : regular_expresion_matching.cc
* Date  : 2017-12-17
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <iostream>
#include <vector>

class Solution {
public:
    bool isMatch(string s, string p) {
        int pos = p.size() - 1;
        int len = p.size();
        for (; pos >= 0; --pos) {
            if (p[pos] == '.') {
                if (pos - 1 >= 0 && p[pos-1] == '*') {
                    init_stack.push(new Node(ANY_ZERO_OR_MORE, 0);
                    pos -= 2;
                } else {
                    init_stack_.push(new Node(ANY, 0));
                    --pos;
                }
            } else {
                if (pos >= 0 && p[pos] == '*') {
                    init_stack_.push(new Node(ZERO_OR_MORE, 0));
                    pos -= 2;
                } else {
                    init_stack_.push(new Node(CHAR, p[pos]));
                    --pos;
                }
            }
        }

        pos = 0;
        p_pos = 0;

        while (pos < s.size() && p_pos < init_stack_.size()) {
            Node * node = init_stack_.top();
            bool back_trace = false;
            switch (node->type) {
                case CHAR:
                    if (node->value == s[pos]) {
                        ++pos;
                        init_stack_.pop();
                        end_stack_.push(node);
                    } else {
                        if (end_stack_.empty() || any_num_ == 0) {
                            return false;;
                        } else {
                            // back trace
                            --pos;
                            node = end_stack_.top();
                            if (node->)
                            end_stack_.pop();
                        }
                    }
            }

            if (back_trace) {
                while (not end_stack_.empty()) {
                    Node * node = end_stack_.top();
                    end_stack_.pop();

                    if (node->type != ANY) {
                        init_stack_.push(node);
                    } else {
                        if (node->match_end > node->match_end) {
                            --node->match_end
                        }
                    }
                }
            }
        }

        if (pos == s.size() && init_stack_.size() == 0) {
            return true;
        }

        return false;
    }

    Solution(): any_num_(0) {
    }

    ~Solution() {
        while (not init_stack_.empty()) {
            delete init_stack_.pop();
        }
        while (not end_stack_.empty()) {
            delete end_stack_.pop();
        }
    }

private:
    typedef {
        CHAR = 0,
        ANY = 1,
        ZERO_OR_MORE = 2,
        ANY_ZERO_OR_MORE
    } NodeType;
    struct Node {
        Node(NodeType type_, char value_) {
            type = type_;
            value = value_;
            match_begin = -1;
            match_end = -1;
        }
        NodeType type;
        char value;
        int match_begin;
        int metch_end;
    };
    std::stack<Node *> init_stack_;
    std::stack<Node *> end_stack_;
    size_t any_num_;
};
