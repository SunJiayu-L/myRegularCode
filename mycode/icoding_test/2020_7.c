struct node{
	int value;
	struct node *next;
};
struct node *add_list(struct node *list, int n);

    struct node*  first;//创建一个节点指针
    first=(struct node*)malloc(sizeof(struct node));
    if(first==NULL){
        return NULL;
    }
    first->value=n;
    first->next=list;
    