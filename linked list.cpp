#include<iostream>
using namespace std;
 
class node
{
	public:
		int data; // assume for now that data linked list is stored
		node * next;
		
		node(int data_input){
			this->data=data_input;
			this->next= NULL;
		}
};

void printnode(node * &node)
{
	cout<<"value"<<node->data;
	cout<<"address"<<node->next;
	
}

void printlinkedlist(node *  head) //head  is nothing it is a fancy term to indicate the first head
{
	if(head==NULL)
	{
		cout<<"the linkedlist is still empty !!"<<endl;
		return;
	}
	
	node *temp;
	temp=head;
	
	while (temp!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->next;
	}
	cout<<endl;
}

void Insertatstart(node * &head, int data)
{
   node * temp= new  node(data);
   
   if(head==NULL)
   {
   	head=temp;
   	return;
   }
   temp->next=head; 
   head=temp;
   	
}

void Insertatend(node * &head, int data)
{
	node *temp=new node(data);
	
    if(head==NULL)
   {
   	head=temp;
   	return;
   }
	node *end;
	end=head;
	
	while(end->next!=NULL)
	{
		end=end->next;
	}
	
	//after this while loop complete we have basically reach the end element of he linked list.
	
	end->next=temp;
}

void Insertatmiddleafterwhichelement(node *& head, int location, int data)
{
	node * temp=new node(data);
	 node * var=head;
	 
	 while(var->data!=location)
	 {
	 	var=var->next;
	 	if(var==NULL)
	 	{
	 		cout<<"the location doesn't exist, check the location again"<<endl;
	 		return;
		 }
	 	
	 }
	 //var will have the node address of the element at which the new data going to be inserted
	 temp->next=var->next;
	 var->next=temp;
	 
}

void deletenodeoflinkedlist(node *&head, int data)
{
	if(head->data==data)
	{
		cout<<"the head of the linked list is going to be delete "<<endl;
		head=head->next;
		return;
	}
	
	node *temp;
	node *prev;
	temp=head;
	while(temp->data!=data)
	{
		if(temp->next==NULL)
		{
			cout<<"the element to be dleted doesnt exist"<<endl;
			return;
		}
		prev=temp;
		temp=temp->next;
		
	}
	
	if(temp->next==NULL)
	{
		prev->next=NULL;
		return;
	}
	
	prev->next=prev->next->next;
}

int main()
{
	node * head=NULL;
  	
  	printlinkedlist(head);
  	
	node * node1=new node(5);
	head=node1;
	printlinkedlist(head);
	cout<<endl;
	
	node * node2=new node(7);
	node1->next=node2;
	printlinkedlist(head);
	cout<<endl;
	
	node * node3=new node(8);
	node2->next=node3;
	printlinkedlist(head);
	cout<<endl;
	
  	//printnode(node1);
  	//printnode(node2);
  	//printnode(node3);
  	
  	printnode(node1);
  	cout<<endl<<node2;
  	printnode(node2);
  	cout<<endl<<node3;
  	printnode(node3);
  	
  	//node * head;
  	//head = node2;
  	
  //Inserting the new element at the START of the linked list 
  
  Insertatstart(head,3);
  printlinkedlist(head);
  Insertatstart(head,2);
  printlinkedlist(head);	
  
  //Inserting the new element at the END of the linked list
  
  Insertatend(head,9);
  Insertatend(head,10);
  printlinkedlist(head);
  
   //Inserting the new element at the MIDDLE of the linked list
   
   Insertatmiddleafterwhichelement(head,3,4);
   Insertatmiddleafterwhichelement(head,5,6);
   printlinkedlist(head);
   
   //Delete an element at START, MIDDLE, and END of the linked list element are 2,10,6
   
   deletenodeoflinkedlist(head,2);
   deletenodeoflinkedlist(head,10);
    deletenodeoflinkedlist(head,6);
    
     deletenodeoflinkedlist(head,100);
   
   printlinkedlist(head);
   
   
  	
	return 0;
}
