#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LENGTH 5
typedef int ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;
void insertBST(BiTree *root,ElemType val);
/**插入一定是在叶子节点的左右子树上查，函数的输入参数
*一定是指针的指针，因为要对地址进行操作，叶子节点的左右子树都
为空*/
void insertBST(BiTree *root,ElemType val){
	BiTree p;
	if(*root==NULL){
	p=(BiTree)malloc(sizeof(BiTNode));
	p->data=val;
	p->lchild=p->rchild=NULL;
		*root=p;
	}else{
		if((*root)->data>val){
			insertBST(&((*root)->lchild),val);
		}else{
			insertBST(&(*root)->rchild,val);
		}
	}
}
void midOrderBiTreePrint(BiTree root){
	if(root==NULL){
		return;
	}
	midOrderBiTreePrint(root->lchild);
	printf("%d ",root->data);
	midOrderBiTreePrint(root->rchild);
}
void createBST(BiTree *root,ElemType a[]){
	int i;
	for(i=0;i<LENGTH;i++){
		insertBST(root,a[i]);
	}
}
void chaBST(BiTree root,ElemType val){
	if(root==NULL){
		printf("查找失败！");
		return;
	}else if(root->data>val){
		chaBST(root->lchild,val);
	}else if(root->data<val){
		chaBST(root->rchild,val);
	}else{
		if((root->lchild)&&(root->rchild)){
			printf("%d的左子树是%d",val,root->lchild->data);
			printf("\n");
			printf("%d的右子树是%d",val,root->rchild->data);
		}
		printf("找到了，好开心\n");
		
	}
}
ElemType searchmax(BiTree root){
	if(root->rchild==NULL){
		return root->data;
	}else{
		searchmax(root->rchild);
	}
}
ElemType searchmin(BiTree root){
	if(root->lchild==NULL){
		return root->data;
	}else{
		searchmin(root->lchild);
	}
}
void deleteBST(BiTree *root,ElemType val){
	if((*root)==NULL){
		return;
	}
	if((*root)->data>val){
		deleteBST(&((*root)->lchild),val);
	}else if((*root)->data<val){
		deleteBST(&((*root)->rchild),val);
	}else{
		if((*root)->lchild==NULL){//左子树为空(注意左子树为空和右子树同时为空也满足这个条件)；
			BiTree tempNode;
			tempNode=*root;
			*root=(*root)->rchild;
			free(tempNode);
		}else if((*root)->rchild==NULL){//右子树为空
			BiTree tempNode;
			tempNode=*root;
			*root=(*root)->lchild;
			free(tempNode);
		}else{//左右子树都不为空，寻找左子树的最大值代替该节点,
			BiTree tempNode;
			tempNode=(*root)->lchild;
			while(tempNode->rchild!=NULL){
				tempNode=tempNode->rchild;
			}
			(*root)->data=tempNode->data;
			deleteBST(&((*root)->lchild),tempNode->data);

		}
	}
}
void main(){
	BiTree T;
	ElemType a[LENGTH];
	int i;
	int charushu;
	int chazhaoshu;
	int deleteshu;
	int j;
	T=NULL;
	printf("请输入生成二叉搜索树的元素，数量为%d:\n",LENGTH);
	for (i=0;i<LENGTH;i++){
		scanf("%d",&a[i]);
	}
	createBST(&T,a);
	midOrderBiTreePrint(T);
	printf("\n请输入要插入的数据:\n");
	scanf("%d",&charushu);
	insertBST(&T,charushu);
	printf("插入数据%d后的二叉搜索树为:\n",charushu);
	midOrderBiTreePrint(T);
	printf("\n");
	j=searchmin(T);
	printf("该搜索二叉树最小值为:%d\n",j);
	printf("请输入要查找的数字：\n");
	scanf("%d",&chazhaoshu);
	chaBST(T,chazhaoshu);
	printf("\n");
	printf("请输入要删除的数据\n");
	scanf("%d",&deleteshu);
	deleteBST(&T,deleteshu);
	printf("删除数据%d后，该搜索二叉树为:",deleteshu);
	midOrderBiTreePrint(T);
	printf("\n");
	system("pause");
}


