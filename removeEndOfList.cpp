/*************************************************************************
	> File Name: removeEndOfList.cpp
	> Author: ldw
	> Explain: Remove Nth Node From End of List
	> Created Time: Tue 21 Aug 2018 09:02:25 AM CST
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
	for(i = 0; i < 5; i++)
	{
		p = (linknode_t *)malloc(sizeof(linknode_t));
		p->data = i+1;
		p->next = NULL;     	// 没有下一个节点
		r->next = p;        	// 将p 放在 r 的后面
		r = p;              	//  r 指向新的队尾
	}
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
		ListNode *removeNthFromEnd(ListNode *head,int n)
		{
			if(head==NULL || n<0)
				return NULL;
				
			if(head!=NULL && n==0)
				return head;
			
			//q先走n步，p再走
			ListNode *p=head,*q=head;
			for(int i=0;i<n;i++)
				q = q->next;
			
			//一起走到达结尾
			while(q->next)
			{
				q = q->next;
				p = p->next;
			}
			ListNode *tmp = p->next;
			p->next = p->next->next;
			delete tmp;
			return head;
		}
};

int main()
{
		//初始化赋值链表
		linknode_t *H = CreateLink();
		InitLink(H);
		ShowLink(H);
		//调用deleteDup函数
		Solution s;
		linklist_t H1 = s.removeNthFromEnd(H,3);
		ShowLink(H1);
		//释放空间
		ClearLink(H);    
		free(H);
}
