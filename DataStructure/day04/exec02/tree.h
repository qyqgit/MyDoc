#ifndef __TREE_H__
#define __TREE_H__
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
void tree_init(tree_t *p_tree);
//树清理函数
void tree_deinit(tree_t *p_tree);
//向二叉树中插入数字
int tree_insert(tree_t *p_tree, int val);
//中序遍历方式处理树里的所有节点
void tree_miter(const tree_t *p_tree, p_func_t p_func);
int tree_remove(tree_t *p_tree, int val);
void tree_account(tree_t *p_tree, int *p_count);
#endif
