#include "BinaryTree.h"

#include <iostream>

using namespace std;

int main()
{
    BinaryTree<char> tree;

    //前序字符串
    string str = "ABC#D##E#F##GH#I##JK##L##";

    //后续字符串
    //string str = "###DC###FEB###IH##K##LJGA";

    //前序方法生成二叉树
    tree.PreOrderCreateTree(str);

    cout << "EXP STR: " << str << endl;

    //前序方法遍历打印二叉树
    tree.PreOrder();

    //中序打印二叉树
    tree.InOrder();

    //后续打印二叉树
    tree.PostOrder();

    cout << "Tree Height:" << tree.Height() << endl;
    cout << "Tree Height:" << tree.Size() << endl;

    //二叉树拷贝构造调用
    BinaryTree<char> tree2 = tree;
    tree2.PreOrder();

    cout << "PreOrder iteraotr!/n";

    //二叉树前序迭代器
    BinaryTree<char>::PreOrder_iterator preiter(tree2);
    while (!preiter.IsEnd())
    {

        cout << *preiter << ",";
        ++preiter;
    }
    cout << endl;

    //二叉树中序迭代器
    tree.InOrder();
    cout << "InOrder iteraotr!/n";
    BinaryTree<char>::InOrder_iterator initer(tree2);
    while (!initer.IsEnd())
    {

        cout << *initer << ",";
        ++initer;
    }

    //二叉树后续迭代器
    cout << endl;
    tree2.PostOrder();
    cout << "PostOrder iteraotr!/n";
    BinaryTree<char>::PostOrder_iterator postiter(tree2);

    while (!postiter.IsEnd())
    {

        cout << *postiter << ",";
        ++postiter;
    }

    return 0;
}
