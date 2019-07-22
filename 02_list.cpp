#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
	int data;//������ 
	struct Node* pNext;//ָ���� 
} NODE,*PNODE;

PNODE create_list(void);//���� 
void traverse_list(PNODE);//���� 
bool is_empty(PNODE pHead);//�ж��Ƿ�Ϊ�� 
int length_list(PNODE pHead);//����������
bool insert_list(PNODE,int ,int);//����//����pos��1��ʼ 
bool delete_list(PNODE,int,int *);//ɾ�� 
void sort_list(PNODE);//���� 

int main(){
	PNODE pHead=NULL;//�ȼ���struct Node *pHead=NULL 
	int val;
	
	pHead=create_list();//����һ����ѭ�����������������������������ͷ��㷵�� 
	traverse_list(pHead);
	
	/*if(is_empty(pHead)){
		printf("����Ϊ��!\n");
	}else{
		printf("������\n");
	}*/
	//printf("������Ϊ:%d",length_list(pHead));
	
	//sort_list(pHead);
	
	insert_list(pHead,1,33);
	if(delete_list(pHead,2,&val)){
		printf("ɾ���ɹ�,��ɾ����Ԫ����:%d\n",val);
	} else{
		printf("ɾ��ʧ��\n");
	}
	
	
	traverse_list(pHead);
	
	
	
	return 0;
}

PNODE create_list(void){
	int len;
	int val;//������ʱ����û�����Ľ���ֵ 
	
	//������һ���������Ч���ݵ�ͷ��� 
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if(NULL==pHead){
		printf("�ڴ����ʧ�ܣ�������ֹ!");
		exit(-1);
	}
	
	//pTailΪβ�ڵ� 
	PNODE pTail=pHead;
	pTail->pNext=NULL;
	
	printf("����������Ҫ���ɵ�����ڵ�ĸ���:len=");
	scanf("%d",&len);
	
	for(int i=0;i<len;i++){
		printf("�������%d���ڵ��ֵ:",i+1);
		scanf("%d",&val);
		
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		if(NULL==pNew){
		printf("�ڴ����ʧ�ܣ�������ֹ!");
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
	return;//��Ϊ�˿��߱��˸ú����ѽ��� 
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

//��pHead��ָ������ĵ�pos���ڵ�ǰ�����һ���µĽڵ�//����pos��1��ʼ 
bool insert_list(PNODE pHead,int pos,int val){
	int i=0;
	PNODE p=pHead;
	while(NULL!=p&&i<pos-1){//�ҵ���pos-1λ�Ľ�� 
		p=p->pNext;
		i++;
	}
	if(i>pos-1||NULL==p)
		return false;
		
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	if(NULL==pNew){
		printf("��̬�ڴ����ʧ��!\n");
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
	while(NULL!=p->pNext&&i<pos-1){//�ҵ�pos-1�����㣬��Ϊ����ɾ��ͷ��㣬����NULL=p->pNext 
		p=p->pNext;
		i++;
	}
	if(i>pos-1||NULL==p->pNext)//�������Ĳ�������ȷ��,i=pos-1,p=��pos-1λ�Ľ�� 
		return false;		
	
	PNODE q=p->pNext;
	*pVal=q->data;
	
	//ɾ��p�ڵ����Ľ��
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
