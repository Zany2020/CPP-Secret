#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>


struct AVLNode
{
	int val;
	AVLNode* left;
	AVLNode* right;
	int height;

	//构造函数
	AVLNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}

};

int getHeight(AVLNode* node) 
{
	return node ? node->height : 0;
}

void updateHeight(AVLNode* node) 
{
	node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

int getBF(AVLNode* node) 
{
	return getHeight(node->left) - getHeight(node->right);
}

/////////////////////////////////////////////////


//LL型
AVLNode* rightRotate(AVLNode* A) 
{
	AVLNode* B = A->left;
	AVLNode* T3 = B->right;

	B->right = A;
	A->left = T3;

	updateHeight(A);
	updateHeight(B);

	return B;
}

//RR型
AVLNode* leftRotate(AVLNode* A) 
{
	AVLNode* B = A->right;
	AVLNode* T2 = B->left;

	B->left = A;
	A->right = T2;
	
	updateHeight(A);
	updateHeight(B);

	return B;
}

AVLNode* leftRightRotate(AVLNode* A)
{
	A->left = leftRotate(A->left);
	return rightRotate(A);
}

AVLNode* rightLeftRotate(AVLNode* A)
{
	A->right = rightRotate(A->right);
	return leftRotate(A);
}

//////////////////////////////////////



//插入节点
AVLNode* insert(AVLNode* root, int key)
{
	if(!root) return new AVLNode(key);

	if(key < root->val) 
		root->left = insert(root->left, key);
	else if(key > root->val)
		root->right = insert(root->right, key);
	else
		return root;

	updateHeight(root);

	int bf = getBF(root);
	if(bf > 1 && key < root->left->val)	//二叉搜索树永远不会替换已有节点，只会插到空叶子位置。
										//key 和它相等 → 直接 return，不插入。
		//这里bf > 1说明左子树比右子树高（左 - 右），
		//又因为key < root->left->val说明插入节点在左子树的左边，所以是LL型，右旋
		return rightRotate(root);
	if(bf < -1 && key > root->right->val)
		return leftRotate(root);
	if (bf > 1 && key > root->left->val)
		//插在左子树的右边，LR型，先左旋再右旋
		return leftRightRotate(root);
	if(bf < -1 && key < root->right->val)
		return rightLeftRotate(root);

	return root;
}


//删除节点
AVLNode* getMinNode(AVLNode* node) 
{
	while(node->left)
		node = node->left;
	return node;
}

AVLNode* remove(AVLNode* root, int val)
{
	if (!root) return nullptr;

	if(val < root->val)
		root->left = remove(root->left, val);
	else if (val > root->val)
		root->right = remove(root->right, val);
	else
	{
		if (!root->left || !root->right)
		{
			AVLNode* temp = root->left ? root->left : root->right;
			delete root;
			return temp;
		}

		AVLNode* temp = getMinNode(root->right);
				//左右都有孩子 → 找【右子树最小值】顶替，再删最小值
		root->val = temp->val;
		root->right = remove(root->right, temp->val);
		
	}

	if (!root) return nullptr;

	updateHeight(root);

	int bf = getBF(root);
	// 1. LL 型失衡
	if (bf > 1 && getBF(root->left) >= 0)
		return rightRotate(root);
	// 2. LR 型失衡
	if (bf > 1 && getBF(root->left) < 0)
		return leftRightRotate(root);
	// 3. RR 型失衡
	if (bf < -1 && getBF(root->right) <= 0)
		return leftRotate(root);
	// 4. RL 型失衡
	if (bf < -1 && getBF(root->right) > 0)
		return rightLeftRotate(root);

	return root;
}

void inorder(AVLNode* root)
{
	if (!root) return;
	inorder(root->left);
	std::cout << root->val << " ";
	inorder(root->right);
}

int main()
{
	int arr[] = { 10, 20, 30, 40, 50, 25 };
	AVLNode* root = nullptr;
	for(int x : arr)
		root = insert(root, x);

	std::cout << "Inorder traversal: ";
	inorder(root);
	std::cout << std::endl;

	root = remove(root, 40);

	std::cout << "Inorder traversal after deletion: ";
	inorder(root);
	std::cout << std::endl;

	//AVL确保增删后中序遍历仍然有序，且树的高度保持平衡，保证了O(log n)的时间复杂度。

	return 0;
}