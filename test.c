#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
struct node
{
	long int coef;
	long int pow;
	struct node *link;
};

typedef struct node list;

list* getnode()
{
	list* nn=(list*)malloc(sizeof(list));
	printf("Enter coefficiant\n");
	scanf("%ld",&nn->coef);
	printf("Enter Power\n");
	scanf("%ld",&nn->pow);
	nn->link = NULL;
	return nn;
}

list* createlist(list *start)
{
	list *nnode, *last;
	int ch=1;
	while(ch)
	{
		nnode = getnode();
		if(start == NULL)
		{
			start = nnode;
		}
		else
		{
			last->link = nnode;
		}
		last = nnode;
		printf("Continue..??(1-Yes/0-No) :\n");
		scanf("%d",&ch);
	}
	return start;
}

void printlist(list *start)
{
	list *temp=start;
    printf("Polynomial Linked list is.....\n");
    while(temp!=NULL)
    {
       printf("%ld x^ ",temp->coef);
       printf("%ld  -> ",temp->pow);
       temp = temp->link;
    }
    printf("NULL\n\n");
}

void polyadd(list *head1,list *head2,list *result)
{
	while(head1->link && head2->link)
	{
		if(head1->pow > head2->pow)
		{
			result->pow=head1->pow;
			result->coef=head1->coef;
			head1=head1->link;
		}
		else if(head1->pow < head2->pow)
		{
			result->pow=head2->pow;
			result->coef=head2->coef;
			head2=head2->link;
		}
		else 
		{
		 result->pow = head1->pow;
         result->coef = head1->coef+head2->coef;
         head1 = head1->link;
         head2 = head2->link;
		}
	  	result->link=(list*)malloc(sizeof(list));
      	result = result->link;
      	result->link = NULL;
	}
	while(head1->link || head2->link)
   {
      if(head1->link)
      {
         result->pow = head1->pow;
         result->coef = head1->coef;
         head1 = head1->link;
      }
      if(head2->link)
      {
         result->pow = head2->pow;
         result->coef = head2->coef;
         head2 = head2->link;
      }
      result->link=(list*)malloc(sizeof(list));
      result = result->link;
      result->link = NULL;
    }
}

void main()
{
	// main code
	list *head1,*head2,*result;
	clrscr();
	result = NULL;
	head1 = NULL;
	head2 = NULL;
	printf("poly Linked list1 creation\n");
	head1 = createlist(head1);
	printlist(head1);
	printf("poly Linked list2 creation\n");
	head2 = createlist(head2);
	printlist(head1);
	printlist(head2);
	result=(list*)malloc(sizeof(list));
	polyadd(head1,head2,result);
	printf("Addition is..");
	printlist(result);
   getch();
}
