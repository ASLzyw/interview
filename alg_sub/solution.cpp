//
//  solution.cpp
//  interview
//
//  Created by Yuwei on 2021/7/24.
//  Copyright © 2021 Yuwei. All rights reserved.
//

#include "solution.hpp"

TreeNode* solution::reConstructTree(vector<int> preOrder, vector<int> inOrder) {
    if (preOrder.empty()) {return NULL;}
    auto l = inOrder.size();
    TreeNode *root = new TreeNode(preOrder[0]);
    TreeNode *cur = root;
    //通过前序遍历构建二叉树，暂时将右指针指向父节点
    for (unsigned int i=1; i<l; ++i) {
        TreeNode *node = new TreeNode(preOrder[i], NULL, cur);
        cur->left = node;
        cur = node;
    }
    unsigned int i = 0;
    cur = root;
    while (i<l) {
        //找到值为下一中序值的节点
        while (cur && cur->val!=inOrder[i]) {
            cur = cur->left;
        }
        TreeNode *t = cur;
        TreeNode *t_pre = t;
        //通过右指针回匹配中序点和前序点
        while (t && i<l && t->val==inOrder[i]) {
            t_pre = t;
            t = t->right;
            t_pre->right = NULL;
            ++i;
        }
        t_pre->right = cur->left;
        if (cur->left) {cur->left->right = t;}
        cur->left = NULL;
        cur = t_pre->right;
    }
    return root;
}

int solution::minStep(vector<int> heights) {
    //求均值
    int avg = 0;
    for (const int &height: heights) {
        avg += height;
    }
    avg /= heights.size();
    int num = 0;
    int result = 0;
    //贪心
    for (int &height: heights) {
        result += (num>0 ? num : -num);
        num += (height - avg);
    }
    return result;
}

int solution::maxSum(vector<int> path, int k) {
    //maxSum, index, 用链表维护滑动窗口中的最大值
    list<pair<int, int>> temp;
    int ret = INT_MIN;
    for (unsigned int i=0; i<path.size(); ++i) {
        if (temp.empty()) {
            ret = path[i];
            temp.push_back({ret, i});
        }else {
            int t = i - k;
            while (temp.front().second<t) {
                temp.pop_front();
            }
            ret = temp.front().first + path[i];
            if (path[i]>=0) {
                temp.clear();
            }else {
                while (temp.back().first<ret) {
                    temp.pop_back();
                }
            }
            temp.push_back({ret, i});
        }
    }
    return ret;
}
