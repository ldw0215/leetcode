/*************************************************************************
	> File Name: LinkedListCycle.cpp
	> Author: ldw
	> Explain: Linked List Cycle
	> Created Time: Tue 21 Aug 2018 10:14:27 AM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct ListNode{
	int data;
	ListNode *next;
	//结构体构造函数
	ListNode(int x):data(x),next(NULL){}
};

typedef struct ListNode  linknode_t; 
typedef struct ListNode* linklist_t;
linknode_t *CreateLink() 		// 创建空的链表  返回值 链表的首地址
{	
	linknode_t *H;
	H = (linklist_t)malloc(sizeof(linknode_t)); 
	
	H->next = NULL;
    return H;
}   
void InitLink(linknode_t *H)    	// 初始化一个空的链表  
{
	linknode_t *r, *p;
	int i;
	r = H;             		//  r 指向 队尾位置 
	for(i = 0; i < 4; i++)
	{
		p = (linknode_t *)malloc(sizeof(linknode_t));
		p->data = i+1;
		p->next = NULL;     	// 没有下一个节点
		r->next = p;        	// 将p 放在 r 的后面
		r = p;              	//  r 指向新的队尾
	}
	
	//创建环链表，使r->next指向头
	r->next = H;
	/*for(i = 0; i < 2; i++)
	{
		p = (linknode_t *)malloc(sizeof(linknode_t));
		p->data = i+3;
		p->next = NULL;     	// 没有下一个节点
		r->next = p;        	// 将p 放在 r 的后面
		r = p;              	//  r 指向新的队尾
	} */ 
}
void ShowLink(linknode_t* H)   		// 从队首->队尾 打印所有节点
{
	struct ListNode *p;
	p = H->next;
    	while(p != NULL){
		printf("%d --> ", p->data);
		p = p->next;   
	}
	printf("\n");
}

void ClearLink(linknode_t *H)  		//  清空链表 删除 H 后面的节点
{
	linknode_t *p, *q;  		//p 是删除的节点  q 记录下一个要删除节点
	q = H->next;
	while(q != NULL)    		// q 等于 NULL 表示没有下一个 循环结束
	{
		p = q;
		q = p->next;
		//printf("free %d\n", p->data);
		free(p);    		// 释放空间   
	}
	H->next = NULL;     		// 链表 为空链表
}

class Solution{
	public:
		bool hasCycle(ListNode *head)
		{
			if(NULL == head)
				return false;
			//设置两个指针，一快一慢
			ListNode *slow=head,*fast=head;
			while(fast && fast->next)
			{
				slow = slow->next;
				fast = fast->next->next;
				if(slow == fast)
					return true;
			}
			return false;
		}
};

int main()
{
		//初始化赋值链表
		linknode_t *H = CreateLink();
		InitLink(H);
		//ShowLink(H);
		//调用hasCycle函数
		Solution s;
		//boolalpha使输出是true或false
		cout << boolalpha << s.hasCycle(H) << endl;
		//ShowLink(H1);
		//释放空间
		//ClearLink(H);    
		free(H);
}
