void insertnodeatend(int data)
{
struct node *newnode ,*temp;
newnode = (struct node *)malloc(sizeof(struct node));
if(newnode == NULL)
{
printf("unable to allocte memory\n ");
}
else
{
newnode->data = data;
newnode->next = NULL;
temp = head;
while(temp!= NULL&& temp->next!=NULL)
{
temp = temp->next;
}
temp->next= newnode;
printf("data is inserted successfully\n");
}
}
