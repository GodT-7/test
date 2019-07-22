#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
	int data;//数据域 
	struct Node* pNext;//指针域 
} NODE,*PNODE;

PNODE create_list(void);//创建 
void traverse_list(PNODE);//遍历 
bool is_empty(PNODE pHead);//判断是否为空 
int length_list(PNODE pHead);//返回链表长度
bool insert_list(PNODE,int ,int);//插入//并且pos从1开始 
bool delete_list(PNODE,int,int *);//删除 
void sort_list(PNODE);//排序 

int main(){
	PNODE pHead=NULL;//等价于struct Node *pHead=NULL 
	int val;
	
	pHead=create_list();//创建一个非循环单链表，并将该链表，并将该链表的头结点返回 
	traverse_list(pHead);
	
	/*if(is_empty(pHead)){
		printf("链表为空!\n");
	}else{
		printf("链表不空\n");
	}*/
	//printf("链表长度为:%d",length_list(pHead));
	
	//sort_list(pHead);
	
	insert_list(pHead,1,33);
	if(delete_list(pHead,2,&val)){
		printf("删除成功,您删除的元素是:%d\n",val);
	} else{
		printf("删除失败\n");
	}
	
	
	traverse_list(pHead);
	
	
	
	return 0;
}

PNODE create_list(void){
	int len;
	int val;//用来临时存放用户输入的结点的值 
	
	//分配了一个不存放有效数据的头结点 
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if(NULL==pHead){
		printf("内存分配失败，程序中止!");
		exit(-1);
	}
	
	//pTail为尾节点 
	PNODE pTail=pHead;
	pTail->pNext=NULL;
	
	printf("请输入您需要生成的链表节点的个数:len=");
	scanf("%d",&len);
	
	for(int i=0;i<len;i++){
		printf("请输入第%d个节点的值:",i+1);
		scanf("%d",&val);
		
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		if(NULL==pNew){
		printf("内存分配失败，程序中止!");
		exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	}
	
	return pHead;
}

void traverse_list(PNODE pHead){
	PNODE p=pHead->pNext;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->pNext;
	}
	printf("\n");
	return;//仅为了考诉别人该函数已结束 
}

bool is_empty(PNODE pHead){
	if(pHead->pNext==NULL){
		return true;
	}else{
		return false;
	}
}

int length_list(PNODE pHead){
	PNODE p=pHead->pNext;
	int len=0;
	while(p!=NULL){
		len++;
		p=p->pNext;
	}
	return len;
}

//在pHead所指向链表的第pos个节点前面插入一个新的节点//并且pos从1开始 
bool insert_list(PNODE pHead,int pos,int val){
	int i=0;
	PNODE p=pHead;
	while(NULL!=p&&i<pos-1){//找到第pos-1位的结点 
		p=p->pNext;
		i++;
	}
	if(i>pos-1||NULL==p)
		return false;
		
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	if(NULL==pNew){
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	pNew->data=val;
	PNODE q=p->pNext;
	p->pNext=pNew;
	pNew->pNext=q;
	
	return true;
}

bool delete_list(PNODE pHead,int pos,int *pVal){
	int i=0;
	PNODE p=pHead;
	while(NULL!=p->pNext&&i<pos-1){//找到pos-1这个结点，因为不能删除头结点，所以NULL=p->pNext 
		p=p->pNext;
		i++;
	}
	if(i>pos-1||NULL==p->pNext)//如果传入的参数是正确的,i=pos-1,p=第pos-1位的结点 
		return false;		
	
	PNODE q=p->pNext;
	*pVal=q->data;
	
	//删除p节点后面的结点
	p->pNext=p->pNext->pNext;
	free(q);
	q=NULL;
	 
	return true;
}

void sort_list(PNODE pHead){
	int i,j,t;
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<length_list(pHead)-1;i++,p=p->pNext){
		for(j=i+1,q=p->pNext;j<length_list(pHead);j++,q=q->pNext){
			if(p->data>q->data){
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
		}
	}
	return;
}
