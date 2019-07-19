#include <stdlib.h>
#include "tree.h"
//树初始化函数
void tree_init(tree_t *p_tree){
	p_tree->p_node = NULL;

}
//树清理函数
void tree_deinit(tree_t *p_tree){
	//后序遍历
	if(!p_tree->p_node)
		return;	
	tree_deinit(&(p_tree/*最上面的方块handle*/->p_node/*最大的圆圈tree_t*/->left/*左子树*/));
	tree_deinit(&(p_tree->p_node->right));
	free(p_tree->p_node);
	p_tree->p_node = NULL;

}
//在有序二叉树中查找某个数字所在的位置
//使用一个方块存储区的地址表示找到的位置
tree_t *tree_search(const tree_t *p_tree, int val){
	if(!p_tree->p_node){
		//没有节点的树
		return (tree_t*)p_tree;
	}
	if(p_tree->p_node->val == val){
		//根节点里的数字就是要找的数字
		return (tree_t*)p_tree;
	}
	else if(p_tree->p_node->val > val){
		//根节点数字比要找的数字大就在左子树里查找
		return tree_search(&(p_tree->p_node->left), val);
	}
	else {
		//在右子树里查找
		return tree_search(&(p_tree->p_node->right), val);
	}
}
//向二叉树中插入数字
int tree_insert(tree_t *p_tree, int val){
	node_t *p_node = NULL;
	tree_t *p_tmp =  tree_search(p_tree, val);
	if(p_tmp->p_node){
		//数字已经存在
		return 0;
	}
	p_node = (node_t*)malloc(sizeof(node_t));
	if(!p_node){
		//动态分配失败
		return 0;
	}
	p_node->val = val;
	p_node->left.p_node = NULL;
	p_node->right.p_node = NULL;
	p_tmp->p_node = p_node;//把动态分配的节点挂在找到的方块下面
	return 0;

}
//中序遍历方式处理树里的所有节点
void tree_miter(const tree_t *p_tree, p_func_t p_func){
	//中序遍历
	if(!p_tree->p_node){
		return;
	}
	tree_miter(&(p_tree->p_node->left), p_func);
	p_func(p_tree->p_node->val);
	tree_miter(&(p_tree->p_node->right), p_func);

}
//从有序二叉树中删除数字
int tree_remove(tree_t *p_tree, int val){
	node_t *p_node = NULL;
	tree_t *p_tmp1 = NULL;
	tree_t *p_tmp = tree_search(p_tree, val);//找到要删除的数字所在的位置
	if(!p_tmp->p_node){
		//没有找到数字
		return 0;
	}
	p_node = p_tmp->p_node;
	if(!p_node->left.p_node && !p_node->right.p_node){
		//要删除的节点没有子节点
		p_tmp->p_node = NULL;//把要删除的节点从树里摘出来
	}
	else if(!p_node->left.p_node){
		//没有左子节点就一定有右子节点
		p_tmp->p_node = p_node->right.p_node;//用右子节点替换要删除的节点
	}else if(!p_node->right.p_node){
		p_tmp->p_node =  p_node->left.p_node;//用左子节点替换要删除的节点
	}else{
		p_tmp1 = tree_search(&(p_node->left), p_node->right.p_node->val);//在左子树里查找右子树根节点应该插入的位置
		p_tmp1->p_node = p_node->right.p_node;//把右字数根节点插入到左字数
		p_tmp->p_node = p_node->left.p_node;//用左字数的根节点替换要删除的节点
	}
	free(p_node);
	p_node = NULL;
	return 1;
}
//计算节点的个数
void tree_account(tree_t *p_tree, int *p_count){
	//后序遍历
	if(!p_tree->p_node)
		return;	
	tree_account(&(p_tree/*最上面的方块handle*/->p_node/*最大的圆圈tree_t*/->left/*左子树*/), p_count);
	tree_account(&(p_tree->p_node->right), p_count);
	(*p_count)++;
}
