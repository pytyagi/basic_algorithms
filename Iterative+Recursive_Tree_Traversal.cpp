#include<bits/stdc++.h>
using namespace std;

typedef long long int lln;

struct node
{
    int data;
    node *l,*r;
};

void iterative_inorder(node *t)
{
    if(t==NULL)
        return ;

    stack<node*>s;
    while(true)
    {
        if(t!=NULL)
        {
            s.push(t);
            t=t->l;
        }
        else
        {
            if(s.empty())
                break;

            t=s.top();
            cout<<(t->data)<<" ";
            s.pop();
            t=t->r;
        }
    }
    cout<<endl;
}

void iterative_preorder(node *t)
{
    if(t==NULL)
        return ;
    stack<node*>s;
    while(true)
    {
        if(t!=NULL)
        {
            cout<<(t->data)<<" ";
            s.push(t);
            t=t->l;
        }
        else
        {
            if(s.empty())
                break;

            t=s.top();
            s.pop();
            t=t->r;
        }
    }
    cout<<"\n";
}

void iterative_postorder(node *t)
{
    if(t==NULL)
        return ;

    stack<node*>s1,s2;

    s1.push(t);
    node *temp;
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->l!=NULL)
            s1.push(temp->l);

        if(temp->r!=NULL)
            s1.push(temp->r);
    }

    while(!s2.empty())
    {
        cout<<(s2.top()->data)<<" ";
        s2.pop();
    }
    cout<<"\n";
}



void inorder(node *t)
{
    if(t==NULL)
        return ;

    inorder(t->l);
    cout<<t->data<<" ";
    inorder(t->r);
}

void preorder(node *t)
{
    if(t==NULL)
        return ;

    cout<<t->data<<" ";
    preorder(t->l);
    preorder(t->r);

}

void postorder(node *t)
{
    if(t==NULL)
        return ;

    postorder(t->l);
    postorder(t->r);
    cout<<t->data<<" ";
}

node *createBT()
{
    int x;cin>>x;
    if(x==-1)
        return NULL;

    node *nn;
    nn=new node;
    nn->data=x;

    cout<<"Enter Left child of "<<x<<endl;
    nn->l=createBT();

    cout<<"Enter Right child of "<<x<<endl;

    nn->r=createBT();

    return nn;
}

int main()
{
    cout<<"Enter the root data press -1 for NULL child\n";
    node *root=createBT();
    iterative_postorder(root);
    postorder(root);//recursive
    return 0;
}
