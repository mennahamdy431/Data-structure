#include <bits/stdc++.h>
using namespace std;

/**
Implementation : Recursion bottom up approach
Resources : Lectures slide, data structures & algorithm analysis text book and geeksforgeeks website
**/


/// TreeNode to represent a node in AVL tree
class TreeNode{
public:
	int data = 0, height = 0;
	TreeNode* leftChild = 0;
	TreeNode* rightChild = 0;
};

///AVL Tree code
class AvlTree{

private:

    TreeNode* root;

    void innerPreOrder(TreeNode* current){
        if(current == 0){
            return;
        }
        cout<<current->data<<' ';
        innerPreOrder(current->leftChild);
        innerPreOrder(current->rightChild);
    }

    void innerInOrder(TreeNode* current){
        if(current == 0){
            return;
        }
        innerInOrder(current->leftChild);
        cout<<current->data<<' ';
        innerInOrder(current->rightChild);
    }

    void innerPostOrder(TreeNode* current){
        if(current == 0){
            return;
        }
        innerPostOrder(current->leftChild);
        innerPostOrder(current->rightChild);
        cout<<current->data<<' ';
    }

    ///method to do rotation to the right and returns the root of the rotated branch
    TreeNode* rightRotate(TreeNode* current){
        TreeNode* subRoot = current->leftChild;
        TreeNode* subRootRight = subRoot->rightChild;

        ///update the right child of subRoot to be current
        subRoot->rightChild = current;
        ///make the right child of subRoot to be leftChild of current
        current->leftChild = subRootRight;

        ///recalculate the height of the new rotated nodes(affected ones only)
        current->height = max(getHeight(current->leftChild), getHeight(current->rightChild)) + 1;
        subRoot->height = max(getHeight(subRoot->leftChild), getHeight(subRoot->rightChild)) + 1;

        ///return the new subRoot of the rotated branch
        return subRoot;
    }

    ///method to do rotation to the left and returns the root of the rotated bracnh
    TreeNode* leftRotate(TreeNode* current)
    {
        TreeNode* subRoot = current->rightChild;
        TreeNode* subRootLeft = subRoot->leftChild;

        ///update the left child of subRoot to be current
        subRoot->leftChild = current;
        ///make current right child to be subRoot left child
        current->rightChild = subRootLeft;

        ///recalculate the height of the new rotated nodes(affected ones only)
        subRoot->height = max(getHeight(subRoot->leftChild), getHeight(subRoot->rightChild)) + 1;
        current->height = max(getHeight(current->leftChild), getHeight(current->rightChild)) + 1;

        ///return the new subRoot of the rotated branch
        return subRoot;
    }

public:

    ///returns the height of a node if it's not null
    int getHeight(TreeNode* current){
        if(current == 0){
            return 0;
        }else{
            return current->height;
        }
    }

    ///default constructor to make the root point to null
    AvlTree(){
        root = 0;
    }

    ///parametrized constructor, if there is a data given
    AvlTree(int data){
        root = 0;
        root = push(root, data);
    }

    ///method to get the balance factor of not null node
    int getBalanceFactor(TreeNode* current){
        if (current == 0){
            return 0;
        }
        ///balance factor = heightOfLeftSubTree - heightOfRightSubTree
        return getHeight(current->leftChild) - getHeight(current->rightChild);
    }

    ///method to push a new node into the tree using bottom up approach for insertion
    TreeNode* push(TreeNode* current, int data)
    {
        ///if it's null then the tree is empty
        if(current == 0){
            TreeNode* current = new TreeNode;
            current->data = data;
            ///height of single node is 1
            current->height = 1;
            root = current;
            return root;
        }

        if(current->data > data){
            ///if the data of this node > new data go to left child
            current->leftChild = push(current->leftChild, data);
        }else if(current->data < data){
            ///if the data of this node < new data go to right child
            current->rightChild = push(current->rightChild, data);
        }else{
            ///this data is inserted before(duplicates are not allowed)
            return current;
        }

        ///after insertion was done let's balance the tree using the advantage of bottom up recursion

        ///update the height of the node
        current->height = 1 + max(getHeight(current->leftChild), getHeight(current->rightChild));

        ///get the balance of current node save the result to bf
        int bf = getBalanceFactor(current);

        ///the node is considered to be imbalanced if bf < -1 or bf > 1, otherwise it's balanced

        ///leftChild leftChild case
        if (bf > 1 && getBalanceFactor(current->leftChild) >= 0){
            return rightRotate(current);
        }

        ///leftChild rightChild case
        if (bf > 1 && getBalanceFactor(current->leftChild) < 0){
            current->leftChild = leftRotate(current->leftChild);
            return rightRotate(current);
        }

        ///rightChild rightChild case
        if (bf < -1 && getBalanceFactor(current->rightChild) <= 0){
            return leftRotate(current);
        }

        ///rightChild leftChild case
        if (bf < -1 && getBalanceFactor(current->rightChild) > 0){
            current->rightChild = rightRotate(current->rightChild);
            return leftRotate(current);
        }

        return current;
    }

    ///return the root of the tree
    TreeNode* getRoot(){
        return root;
    }

    ///method used to push a node to the tree by taking it's value without caring about the root
    void add(int data){
        root = push(root, data);
    }

    ///BFS to travel the tree level by level
    void bfs(){
        ///if the tree is empty do nothing
        if(root == 0){
            return;
        }
        ///queue to the unvisited node fill it first with root
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        while(!toVisit.empty()){
            ///get the top node in the queue then dequeue it
            TreeNode* curr = toVisit.front();
            toVisit.pop();
            cout<<"============================\n";
            ///print its data and balance factor
            cout<<"Node = "<<curr->data<<", bf = "<<getBalanceFactor(curr)<<endl;
            ///if we have left child enqueue it
            if(curr->leftChild != 0){
                toVisit.push(curr->leftChild);
                cout<<"Left Child = "<<curr->leftChild->data<<endl;
            }else{
                cout<<"Left Child = null\n";
            }
            ///if we have right child enqueue it
            if(curr->rightChild != 0){
                toVisit.push(curr->rightChild);
                cout<<"Right Child = "<<curr->rightChild->data<<endl;
            }else{
                cout<<"Right Child = null\n";
            }
            cout<<"============================\n";
        }
    }

    ///method to return the successor of a given node
    TreeNode* getSuccessor(TreeNode* parent){
        ///minimum in right sub tree
        if(parent == 0){
            return 0;
        }
        ///first go to the right subtree
        TreeNode* minChild = parent->rightChild;
        if(minChild == 0){
            return 0;
        }
        ///get the minimum node there
        while(minChild->leftChild != 0){
            minChild = minChild->leftChild;
        }

        return minChild;
    }

    ///method to get the predecessor of a given node
    TreeNode* getPredecessor(TreeNode* parent){
        ///maximum in the left subtree
        if(parent == 0){
            return 0;
        }
        ///first go to the left subtree
        TreeNode* maxChild = parent->leftChild;
        if(maxChild == 0){
            return 0;
        }
        ///get the maximum node there
        while(maxChild->rightChild != 0){
            maxChild = maxChild->rightChild;
        }

        return maxChild;
    }

    ///method to delete a node in the tree
    TreeNode* deleteNode(TreeNode* current, int data)
    {
        ///if the tree is empty then do nothing
        if (current == 0){
            return current;
        }
        ///if the current->data < data go to right sub tree
        if (current->data < data){
            current->rightChild = deleteNode(current->rightChild, data);
        }else if(current->data > data){
            ///go to left sub tree if the current->data > data
            current->leftChild = deleteNode(current->leftChild, data);
        }else{
            ///we find the node we want to delete
            ///handle if it's a leaf node
            TreeNode* toDelete = 0;
            if(current->leftChild == 0 && current->rightChild == 0){
                ///it's a leaf node so just delete it
                toDelete = current;
                current = 0;
                delete toDelete;
            }else if(current->leftChild == 0 || current->rightChild == 0){
                ///one child case so copy the content of the child then delete that child
                toDelete = (current->leftChild == 0) ? current->rightChild : current->leftChild;
                *current = *toDelete;
                delete toDelete;
            }else{
                ///we have two children so we should get the successor or the predecessor
                ///then copy only the data then delete that successor or predecessor
                toDelete = getSuccessor(current);
                ///first : copy the data
                current->data = toDelete->data;
                ///second : delete the successor
                current->rightChild = deleteNode(current->rightChild, toDelete->data);
            }
        }

        ///if condition meet that's mean the tree has one node
        ///then it's already balanced
        if (current == 0){
            return current;
        }

        ///balance the tree with same steps that were done after insertion
        current->height = max(getHeight(current->leftChild), getHeight(current->rightChild)) + 1;

        int bf = getBalanceFactor(current);

        ///leftChild leftChild case
        if (bf > 1 && getBalanceFactor(current->leftChild) >= 0){
            return rightRotate(current);
        }

        ///leftChild rightChild case
        if (bf > 1 && getBalanceFactor(current->leftChild) < 0){
            current->leftChild = leftRotate(current->leftChild);
            return rightRotate(current);
        }

        ///rightChild rightChild case
        if (bf < -1 && getBalanceFactor(current->rightChild) <= 0){
            return leftRotate(current);
        }

        ///rightChild leftChild case
        if (bf < -1 && getBalanceFactor(current->rightChild) > 0){
            current->rightChild = rightRotate(current->rightChild);
            return leftRotate(current);
        }

        return current;
    }

    ///method to delete a node with given value
    void del(int data){
        root = deleteNode(root, data);
    }

    ///method to do inOrder traversal at a start node
    ///if start is not specified then the default if the root
    void inOrder(TreeNode* start = 0){
        if(start == 0){
            innerInOrder(root);
        }else{
            innerInOrder(start);
        }
        cout<<endl;
    }

    ///method to do preOrder traversal at a start node
    ///if start is not specified then the default if the root
    void preOrder(TreeNode* start = 0){
        if(start == 0){
            innerPreOrder(root);
        }else{
            innerPreOrder(start);
        }
        cout<<endl;
    }

    ///method to do postOrder traversal at a start node
    ///if start is not specified then the default if the root
    void postOrder(TreeNode* start = 0){
        if(start == 0){
            innerPostOrder(root);
        }else{
            innerPostOrder(start);
        }
        cout<<endl;
    }

};


int main()
{
    AvlTree tree(50);
    tree.add(90);
    tree.add(30);
    tree.add(35);
    tree.add(105);
    tree.add(205);
    tree.add(200);
    tree.add(100);
    tree.add(1023);
    tree.add(1000);
    tree.add(1012);
    tree.del(35);
    cout<<"BFS Traversal : \n";
    tree.bfs();
    cout<<"In Order : ";
    tree.inOrder();
    cout<<"Pre Order : ";
    tree.preOrder();
    cout<<"Post Order : ";
    tree.postOrder();

    return 0;
}
