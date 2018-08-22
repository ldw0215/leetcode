/*************************************************************************
	> File Name: symmetricTree.cpp
	> Author: ldw
	> Explain: Symmetric Tree
	> Created Time: Wed 22 Aug 2018 04:46:05 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<stdio.h>
using namespace std;

struct TreeNode
{
	int data;               //节点的数据
	struct TreeNode *lchild, *rchild;    //左孩子指针  右孩子指针
	TreeNode(int x):data(x),lchild(NULL),rchild(NULL){}
};
typedef struct TreeNode tree_t;

//构造一个二叉树 递归实现 ：
tree_t *CreateTree(int i, int max) 
{
	//递归结束条件
	if(i > max)
	{
		return NULL;  //  == return 0;
	}
	
	tree_t *T;

	T = (tree_t *)malloc(sizeof(tree_t));	

	T->data = i;
	T->lchild = CreateTree(2*i, max); 
	T->rchild = CreateTree(2*i+1, max);
	return T;
}

//遍历二叉树 ： 先序遍历  中序遍历 后序遍历
void FirstRoot_DLR(tree_t *p)
{
	 if(p == NULL)
		return ;
	printf("%d --", p->data);
	FirstRoot_DLR(p->lchild);
	FirstRoot_DLR(p->rchild);

}

void MiddleRoot_DLR(tree_t *p)
{
	 if(p == NULL)
		return ;
	
	MiddleRoot_DLR(p->lchild);
	printf("%d --", p->data);
	MiddleRoot_DLR(p->rchild);

}

void LastRoot_DLR(tree_t *p)
{
	 if(p == NULL)
		return ;
	
	LastRoot_DLR(p->lchild);	
	LastRoot_DLR(p->rchild);
	printf("%d --", p->data);
}

//释放所有空间 ：
void FreeTree(tree_t *p)
{
	 if(p == NULL)
		return ;
	
	FreeTree(p->lchild);	
	FreeTree(p->rchild);
	//printf("Free %d --", p->data);
	free(p);
} 

class Solution{
	public:
		bool isSymmetric(TreeNode *root)
		{
			if(NULL == root)
				return true;
			return isSymmetric(root->lchild,root->rchild);
		}
		bool isSymmetric(TreeNode *p,TreeNode *q)
		{
			//终止条件
			if(p==NULL && q==NULL)
				return true;
			if(p==NULL || q==NULL)
				return false;
			return p->data==q->data && isSymmetric(p->lchild,q->rchild) && isSymmetric(p->rchild,q->lchild);
		}
};

int main()
{
		tree_t *t = CreateTree(1,3);
		FirstRoot_DLR(t);
		cout << endl;
		Solution s;
		//vector<int> data;
		cout << boolalpha << s.isSymmetric(t) << endl;
		FreeTree(t);
		
		return 0;
}
