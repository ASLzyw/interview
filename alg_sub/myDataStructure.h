//
//  myDataStructure.h
//  interview
//
//  Created by Yuwei on 2021/7/24.
//  Copyright © 2021 Yuwei. All rights reserved.
//

#ifndef myDataStructure_h
#define myDataStructure_h

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v, TreeNode *l=NULL, TreeNode *r=NULL): val(v), left(l), right(r) {}
    int val;
};

#endif /* myDataStructure_h */
