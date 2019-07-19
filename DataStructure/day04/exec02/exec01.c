#include <stdlib.h>
struct node;
typedef struct {
	struct node *p_node;
}tree_t;
typedef struct node{
	int val;
	tree_t left;
	tree_t right;
} node_t;
typedef void (*p_func_t)(int);//给函数指针类型起别名
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
	if(p_tree->p_node){
		return;
	}
	tree_miter(&(p_tree->p_node->left), p_func);
	p_func(p_tree->p_node->val);
	tree_miter(&(p_tree->p_node->right), p_func);

}
