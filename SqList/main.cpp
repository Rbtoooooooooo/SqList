//
//  main.cpp
//  SqList
//
//  Created by 罗璞 on 2017/10/31.
//  Copyright © 2017年 Rbtoooooooooo. All rights reserved.
//

#include <iostream>
using namespace std;

#define MaxSize 50
#define INITSIZE 100

typedef struct {
    int data[MaxSize];
    int length, maxSize;
}SqList;

bool initList(SqList &l) {
    l.length = 0;
    return true;
}

bool insert(SqList &l, int i, int e) {
    i--; //使元素的位序与数组的下标相等
    if (i>=0&&i<=(l.length)) {
        for (int j=l.length; j>i; j--) {
            l.data[j]=l.data[j-1];
        }
        l.data[i] = e;
        l.length++;
    } else {
        return false;
    }
    return true;
}

bool print(SqList l) {
    if (l.length==0) {
        cout<<"It's NULL !\n";
        return false;
    }
    cout<<"长度为: "<<l.length<<endl;
    for (int i=0; i<l.length; i++) {
        cout<<l.data[i]<<" ";
    }
    cout<<endl;
    return true;
}

bool length(SqList l, int &len) {
    len = l.length;
    return true;
}

bool empty(SqList l) {
    return l.length == 0;
}

bool destroy(SqList *l) {
    free(l);
    return true;
}

bool locateElem(SqList l, int e, int &index) {
    for (int i=0; i<l.length; i++) {
        if (l.data[i] == e) {
            index = i+1;
            return true;
        }
    }
    return false;
}

bool getElem(SqList l, int i, int &e) {
    if(i>0 && i<l.length+1) {
        i--;
        e=l.data[i];
        return true;
    }
    return false;
}

// 删除表中位于i位置的元素，即data数组中位于i-1的元素，并且将该元素用引用变量e返回
bool deleteElem(SqList &l, int i, int &e) {
    i--;
    e=l.data[i];
    for (int j=i; j<l.length-1; j++) {
        l.data[j] = l.data[j+1];
    }
    l.length--;
    return true;
}

// 从第m个元素起(不包括第m个元素），删除表中所有该元素,并返回有多少个该元素
bool deleteAllElem(SqList &l, int &n, int m, int e) {
    int k = m+1;
    n=0;
    for (int i=m+1; i<l.length; i++) {
        if (l.data[i]==e) {
            n++;
            continue;
        }
        l.data[k++]=l.data[i];
    }
    l.length = k;
    return true;
}

// 删除值在x和y之间（包括x和y）元素，
bool deleteXtoY(SqList &l, int x, int y) {
    int k=0;
    if(y>x) {
        return false;
    }
    for (int i=0; i<l.length; i++) {
        if (x<=l.data[i]&&l.data[i]<=y) {
            continue;
        }
        l.data[k++] = l.data[i];
    }
    l.length = k;
    return true;
}

// 删除所有重复的元素，比如：两个1，则删除后面那一个，保留前一个
bool deleteRepeatedElem(SqList &l) {
    int n;
    for (int i=0; i<l.length-1; i++) {
        deleteAllElem(l, n, i, l.data[i]);
    }
    return true;
}

bool reverse(SqList &l) {
    int temp;
    for (int i=0; i<l.length/2; i++) {
        temp = l.data[i];
        l.data[i] = l.data[l.length-i-1];
        l.data[l.length-i-1] = temp;
    }
    return true;
}

// 有序顺序表合并
bool merge_1(SqList l1, SqList l2, SqList &l3) {
    int k=0;
    for (int i=0, j=0; i<l1.length&&j<l2.length; k++) {
        if (l1.data[i]<l2.data[j]) {
            l3.data[k] = l1.data[i];
            if (i==l1.length-1) {
                for (; k<l1.length+l2.length; ) {
                    l3.data[++k] = l2.data[j++];
                }
            }
            i++;
        } else {
            l3.data[k]=l2.data[j];
            if (j==l2.length-1) {
                for (; k<l1.length+l2.length; ) {
                    l3.data[++k] = l1.data[i++];
                }
            }
            j++;
        }
    }
    l3.length=l1.length+l2.length;
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n=0, e=0;
    
    SqList l, l1, l2, l3;
    initList(l);
    insert(l, 1, 3);
    insert(l, 2, 2);
    insert(l, 3, 3);
    insert(l, 4, 3);
    insert(l, 5, 5);

    initList(l1);
    initList(l2);
    initList(l3);
    
    insert(l1, 1, 1);
    insert(l1, 2, 3);
    insert(l1, 3, 5);
    insert(l1, 4, 7);
    insert(l1, 5, 9);
    
    insert(l2, 1, 0);
    insert(l2, 2, 2);
    insert(l2, 3, 4);
    insert(l2, 4, 6);
    insert(l2, 5, 8);
    
    merge_1(l1, l2, l3);
    print(l3);
    
    return 0;
}

