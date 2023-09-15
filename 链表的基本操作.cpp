/*
插入的实现:
e -> prev = p;
e -> next = p -> next;
p -> next -> prev = e;
p -> nexxt = e;
*/
/*
删除的实现:
p2 -> next = p2 -> next -> next;
p3 -> next -> prev = p2;
delete p3;
*/
#include<bits/stdc++.h>

using namespace std;

//节点定义
struct Node{
    int data;
    struct Node *next;
};

//头节点
Node *head = NULL;

//在链表末尾追加
void add(int x){
    //如果有head的值
    if(head != NULL){
        Node *a = new Node;
        a -> data = x;
        a -> next = NULL;
        Node *p = head;
        //移动到最后一个节点
        while(p -> next != NULL){
            p = p -> next;
        }
        p -> next = a;
    }
    else{
        head = new Node;
        head -> data = x;
        head -> next = NULL;
    }
}

//在中间追加元素
void insert(int n, int x){
    //新节点
    Node *d = new Node;
    d -> data = x;
    d -> next = NULL;
    //如果是头节点
    if(n == 1){
        d -> next = head;
        head = d;
    }
    else{
        int i;
        Node *p = head;
        for(i = 1; i <= n - 2; i++){
            p = p -> next;
            if(p == NULL){
                break;
            }
        }

        if(p == NULL){
            cout << "n有误" << endl;
        }
        else{
            d -> next = p -> next;
            p -> next = d;
        }
    }
}

//删除链表中第一个出现的data
void deldata(int data){
    Node *p = head, *pre = NULL;
    while(p != NULL){
        if(data == p -> data){
            if(p == head){
                head = p -> next;
            }
            else{
                pre -> next = p -> next;
            }

            delete p;
        }
    }
}   