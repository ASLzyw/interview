//
//  solution.hpp
//  interview
//
//  Created by Yuwei on 2021/7/24.
//  Copyright © 2021 Yuwei. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include "myDataStructure.h"
#include <vector>
#include <iostream>
#include <list>

using namespace std;

class solution {
public:
    /*
     根据前中序重建二叉树
     */
    TreeNode* reConstructTree(vector<int> preOrder, vector<int> inOrder);
    /*
     高低不同的一排柱子，柱子有一个一个方块堆成，每次移动一个方块，移动的距离为步数，请求是所有柱子等高的最小步数
     */
    int minStep(vector<int> pillars);
    /*
     一个数组，和一个数k，从数组最左端开始，每次走<=k步，一直走到最右端，求路径上的数字和最大为多少
     */
    int maxSum(vector<int> path, int k);
};

#endif /* solution_hpp */
