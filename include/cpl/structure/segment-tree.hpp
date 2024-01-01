#ifndef CPL_STRUCTURES_SEGMENT_TREE_H_
#define CPL_STRUCTURES_SEGMENT_TREE_H_

#include <functional>
#include <vector>

template <typename T, T empty = T()>
class SegmentTree {
    struct Node {
        T val;
        T lazy;
        bool is_lazy;

        Node(T val_, T lazy_ = empty, bool is_lazy_ = false)
            : val(val_), lazy(lazy_), is_lazy(is_lazy_) {}
    };

    using Merge = std::function<T(const T&, const T&)>;
    using Apply = std::function<void(T&, const T&)>;

    int n;
    std::vector<Node> t;
    Merge merge;
    Apply apply;

    inline int left(int i) { return i << 1; }
    inline int right(int i) { return (i << 1) + 1; }

    void build(std::vector<T>& a) {
        n = 1;
        while (n < (int)a.size()) n <<= 1;
        t.resize(n << 1, Node(empty));
        for (int i = 0; i < (int)a.size(); i++) {
            t[n + i].val = a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            t[i].val = merge(t[left(i)].val, t[right(i)].val);
        }
    }

    void pushDown(int node) {
        if (t[node].is_lazy) {
            apply(t[left(node)].val, t[node].lazy);
            apply(t[left(node)].lazy, t[node].lazy);
            apply(t[right(node)].val, t[node].lazy);
            apply(t[right(node)].lazy, t[node].lazy);
            t[node].lazy = 0;
            t[node].is_lazy = false;
            t[left(node)].is_lazy = t[right(node)].is_lazy = true;
        }
    }

    T query(int low, int high, int node, int node_low, int node_high) {
        if (low <= node_low && node_high <= high) {
            return t[node].val;
        }
        if (high < node_low || node_high < low) {
            return 0;
        }
        pushDown(node);
        int mid = (node_low + node_high) / 2;
        return query(low, high, left(node), node_low, mid) +
               query(low, high, right(node), mid + 1, node_high);
    }

    void update(int low, int high, T d, int node, int node_low, int node_high) {
        if (low <= node_low && node_high <= high) {
            apply(t[node].val, d);
            apply(t[node].lazy, d);
            t[node].is_lazy = true;
            return;
        }
        if (high < node_low || node_high < low) {
            return;
        }
        pushDown(node);
        int mid = (node_low + node_high) / 2;
        update(low, high, d, left(node), node_low, mid);
        update(low, high, d, right(node), mid + 1, node_high);
        t[node].val = merge(t[left(node)].val, t[right(node)].val);
    }

public:
    SegmentTree(std::vector<T>& a, Merge merge_, Apply apply_)
        : merge(merge_), apply(apply_) {
        n = 1;
        while (n < (int)a.size()) n <<= 1;
        t.resize(n << 1, Node(empty));
        build(a);
    }

    T query(int low, int high) { return query(low, high, 1, 0, n - 1); }

    void update(int low, int high, T d) {
        return update(low, high, d, 1, 0, n - 1);
    }
};

#endif  // CPL_STRUCTURES_SEGMENT_TREE_H_
