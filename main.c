/*
 * main.c
 *
 *  Created on: 07-Jul-2020
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct sllnode
{
	int data ;
	struct sllnode *next ;
};

int append(struct sllnode **fhead, struct sllnode **flast) ;
void display (struct sllnode **fhead) ;
int insert_head (struct sllnode **fhead) ;
int insert_between (struct sllnode **fhead, struct sllnode **flast) ;
int delete_head (struct sllnode **fhead) ;
int delete_last (struct sllnode **fhead, struct sllnode **flast) ;
int delete_between (struct sllnode **fhead, struct sllnode **flast) ;
int reverse_ll(struct sllnode **fhead,struct sllnode **flast) ;
int delete_ll(struct sllnode **fhead,struct sllnode **flast) ;
int display_reverse(struct sllnode **fhead,struct sllnode **flast) ;

int main (void)
{
	int choice = 0 ;
	int c = 0 ;
	int rval = 0 ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;

	do
	{
		do
		{
			printf("\n******************************") ;
			printf("\nLINKED LIST MENU :") ;
			printf("\n1. Append a node") ;
			printf("\n2. Display the LL") ;
			printf("\n3. Insert a node") ;
			printf("\n4. Delete a node") ;
			printf("\n5. Reverse the linked list") ;
			printf("\n6. Print the Linked List in Reverse") ;
			printf("\n0. Exit") ;
			printf("\nYour Choice = ") ;
			scanf("%d", &choice) ;
		}while (choice<0 || choice>6) ;

		switch(choice)
		{
			case 1 :
				// append
				rval = append(&head, &last) ;
				if(rval == 1)
				{
					printf("\nMemory Allocation Failed.") ;
				}
				else
				{
					printf("\nAppending successful.\n") ;
				}
				break ;

			case 2 :
				// display
				display (&head) ;
				break ;

			case 3 :
				//insert
				do
				{
					do
					{
						printf("\n\tINSERT MENU :") ;
						printf("\n\t1. Insert a head") ;
						printf("\n\t2. Insert at last") ;
						printf("\n\t3. Insert in between two nodes") ;
						printf("\n\t0. Exit") ;
						printf("\n\tYour Choice = ") ;
						scanf("%d", &c) ;
					}while (c<0 || c>3) ;

					switch(c)
					{
						case 1 :
							//Insert a head
							rval = insert_head(&head) ;
							if(rval == 1)
							{
								printf("\n\tMemory Allocation Failed.") ;
							}
							else
							{
								printf("\n\tInsertion at head successful.\n") ;
							}
							break ;

						case 2 :
							//Insert at last
							// append
							rval = append(&head, &last) ;
							if(rval == 1)
							{
								printf("\n\tMemory Allocation Failed.") ;
							}
							else
							{
								printf("\n\tInsertion at last successful.\n") ;
							}
							break ;

						case 3 :
							//Insert in between two nodes
							rval = insert_between(&head, &last) ;
							if(rval == 1)
							{
								printf("\n\tMemory Allocation Failed.") ;
							}
							if(rval == 0)
							{
								printf("\n\tInsertion successful.\n") ;
							}
							break ;

						case 0 :
							printf("\n\tYou've exited Insert.\n") ;
							break ;

					}//end of switch

				}while(c != 0) ;
				break ; //end of case 3

			case 4 :
				//delete
				do
				{
					do
					{
						printf("\n\tDELETE MENU :") ;
						printf("\n\t1. Delete head") ;
						printf("\n\t2. Delete last") ;
						printf("\n\t3. Delete a given node") ;
						printf("\n\t0. Exit") ;
						printf("\n\tYour Choice = ") ;
						scanf("%d", &c) ;
					}while (c<0 || c>3) ;

					switch(c)
					{
						case 1 :
							//Delete head
							rval = delete_head(&head) ;
							if(rval == 1)
							{
								printf("\n\tLinked List does not exist. Deletion not possible.\n") ;
							}
							else
							{
								printf("\n\tDeletion of head successful.\n") ;
							}
							break ;

						case 2 :
							//Delete last
							rval = delete_last(&head, &last) ;
							if(rval == 1)
							{
								printf("\n\tLinked List does not exist. Deletion not possible.\n") ;
							}
							else
							{
								printf("\n\tDeletion of last successful.\n") ;
							}
							break ;

						case 3 :
							//Delete a given node
							rval = delete_between(&head, &last) ;
							if(rval == 1)
							{
								printf("\n\tLinked List does not exist. Deletion not possible.\n") ;
							}
							if(rval == 0)
							{
								printf("\n\tDeletion successful.\n") ;
							}
							break ;

						case 0 :
							printf("\n\tYou've exited Delete.\n") ;
							break ;

					}//end of switch

				}while(c != 0) ;
				break ; //end of case 4

			case 5 :
				// reverse the linked list
				rval = reverse_ll(&head,&last) ;
				if(rval == 1)
				{
					printf("\nLinked List is Empty. Hence, reversal not possible.") ;
				}
				else
				{
					printf("\nReversal of Linked List Successful.") ;
				}
				break ; //end of case 5

			case 6 :
				// display reverse
				rval = display_reverse(&head,&last) ;
				if(rval == 1)
				{
					printf("\nMemory Allocation Failed.") ;
				}
				break ; //end of case 6

			case 0 :
				// exit case
				rval = delete_ll(&head, &last) ;
				if(rval == 1)
				{
					printf("\nLinked List is empty.") ;
				}
				else
				{
					printf("\nLinked List deleted successfully.") ;
					printf("\nThank You !") ;
				}
				break ;
		} //end of switch

	}while (choice != 0) ;

	return 0 ;

} //end of main

int append(struct sllnode **fhead, struct sllnode **flast)
{
	int rval = 0 ;
	struct sllnode *newnode = NULL ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *i = NULL ;
	struct sllnode *temp = NULL ;

	head = *fhead ;
	last = *flast ;

	newnode = (struct sllnode *)calloc (1, sizeof(struct sllnode)) ;

	if(newnode == NULL)
	{
		rval = 1 ; //memory allocation failed
	}
	else
	{
		rval = 0 ; //memory allocation successful

		printf("\n\tEnter Data = ") ;
		scanf("%d", &newnode->data) ;

		if(head == NULL)
		{
			head = newnode ;
			last = newnode ;
		}
		else
		{
			//last->next = newnode ;
			//last = newnode ;
			for(i=head ; i!=NULL ; i=i->next)
			{
				temp = i ;
			}
			last = temp ;
			last->next = newnode ;
			last = newnode ;
		}
	}
	*fhead = head ;
	*flast = last ;

	return rval ;

} //end of append function

void display (struct sllnode **fhead)
{
	struct sllnode *head = NULL ;
	struct sllnode *i = NULL ;

	head = *fhead ;

	if(head == NULL)
	{
		printf("Linked List is empty") ;
	}
	else
	{
		printf("\nLinked List Data = ") ;
		for(i=head ; i!=NULL ; i=i->next)
		{
			printf("%3d ", i->data) ;
		}
	}
	*fhead = head ;

} //end of display function

int insert_head (struct sllnode **fhead)
{
	int rval = 0 ;
	struct sllnode *newnode = NULL ;
	struct sllnode *head = NULL ;

	head = *fhead ;

	newnode = (struct sllnode*)calloc(1, sizeof(struct sllnode)) ;
	if(newnode == NULL)
	{
		rval = 1 ; //memory allocation failed
	}
	else
	{
		rval = 0 ; //memory allocation successful
		printf("\n\tEnter data to insert at head = ") ;
		scanf("%d", &newnode->data) ;

		if(head == NULL)
		{
			//LL is empty
			head = newnode ;
		}
		else
		{
			newnode->next = head ;
			head = newnode ;
		}
	}

	*fhead = head ;

	return rval ;

} //end of insert_head

int insert_between (struct sllnode **fhead, struct sllnode **flast)
{
	int rval = 0 ;
	int ns = 0 ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *newnode = NULL ;
	struct sllnode *a = NULL ;
	struct sllnode *b = NULL ;
	struct sllnode *i = NULL ;

	head = *fhead ;
	last = *flast ;

	newnode = (struct sllnode *)calloc(1, sizeof(struct sllnode)) ;
	if(newnode == NULL)
	{
		rval = 1 ; //memory allocation failed
	}
	else
	{
		rval = 0 ; //memory allocation successful
		printf("\n\tEnter the data to insert = ") ;
		scanf("%d", &newnode->data) ;
		printf("\n\tEnter the value of the node after which you want to insert = ") ;
		scanf("%d", &ns) ;
		if(head == NULL)
		{
			printf("\n\tLinked List is Empty.") ;
		}
		else
		{
			for(i=head ; i!=NULL ; i=i->next)
			{
				if(ns == i->data)
				{
					rval = 0 ;
					a = i ;
					i = last ;
				}
			}
			if(a != NULL)
			{
				rval = 0 ;
				b = a->next ;
				a->next = newnode ;
				newnode->next = b ;
			}
			else
			{
				rval = 2 ;
				printf("\n\tInsertion Not Possible.") ;
			}
		} //end of second else

	} //end of first else

	*fhead = head ;
	*flast = last ;

	return rval ;

} //end of insert_between

int delete_head (struct sllnode **fhead)
{
	int rval = 0 ;
	struct sllnode *head = NULL ;
	struct sllnode *temp = NULL ;

	head = *fhead ;

	if(head == NULL)
	{
		rval = 1 ; //LL does not exist
	}
	else
	{
		rval = 0 ; //LL exists
		temp = head ;
		head = head->next ;
		temp->next = NULL ;
		free(temp) ;
		temp = NULL ;
	}

	*fhead = head ;

	return rval ;

} //end of delete_head

int delete_last (struct sllnode **fhead, struct sllnode **flast)
{
	int rval = 0 ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *i = NULL ;
	struct sllnode *j = NULL ;

	head = *fhead ;
	last = *flast ;

	if(head == NULL)
	{
		rval = 1 ; //LL does not exist
	}
	else
	{
		rval = 0 ; //LL exists
		if(head->next == NULL)
		{
			head = NULL ;
			free(head) ;
		}
		else
		{
			for(i=head ; i->next!=NULL; i=i->next)
			{
				j = i ;
			}
			j->next = NULL ;
			free(i) ;
			i = NULL ;

		} //end of inner else

	} //end of outer else

	*fhead = head ;
	*flast = last ;

	return rval ;

} //end of delete_last

int delete_between (struct sllnode **fhead, struct sllnode **flast)
{
	int rval = 0 ;
	int ns = 0 ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *i = NULL ;
	struct sllnode *a = NULL ;
	struct sllnode *b = NULL ;
	struct sllnode *dnode = NULL ;

	head = *fhead ;
	last = *flast ;

	printf("\n\tEnter the value of the node to be deleted = ") ;
	scanf("%d", &ns) ;

	if(head == NULL)
	{
		rval = 1 ; //LL does not exist
	}
	else
	{
		rval = 0 ; //LL exists

		for(i=head ; i!=NULL ; i=i->next)
		{
			if(ns == i->next->data)
			{
				rval = 0 ;
				a = i ;
				i = last ;
			}
		}
		if(a != NULL)
		{
			rval = 0 ;
			dnode = a->next ;
			b = dnode->next ;
			a->next = b ;
			dnode->next = NULL ;
			free(dnode) ;
			dnode = NULL ;
		}
		else
		{
			rval = 2 ;
			printf("\n\tDeletion not possible.") ;
		}

	} //end of else

	*fhead = head ;
	*flast = last ;

	return rval ;

} //end of delete_between

int reverse_ll(struct sllnode **fhead,struct sllnode **flast)
{
	int rval = 0 ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *head1 = NULL ;
	struct sllnode *last1 = NULL ;
	struct sllnode *i = NULL ;
	struct sllnode *k = NULL ;
	struct sllnode *dnode = NULL ;

	head = *fhead ;
	last = *flast ;

	if(head == NULL)
	{
		rval = 1 ; //LL is empty
	}
	else
	{
		rval = 0 ;
		for(i=head ; i!=NULL ; i=k)
		{
			dnode = head ;
			head = head->next ;
			k = dnode->next ;
			dnode->next = NULL ;

			if(head1 == NULL)
			{
				head1 = dnode ;
				last1 = dnode ;
			}
			else
			{
				dnode->next = head1 ;
				head1 = dnode ;
			}
		}//end of for
		head = head1 ;
		last = last1 ;
		head1 = NULL ;
		last1 = NULL ;
	}//end of outer else

	*fhead = head ;
	*flast = last ;

	return rval ;

} //end of reverse_ll

int display_reverse(struct sllnode **fhead,struct sllnode **flast)
{
	int rval = 0 ;
	int *arr = NULL ;
	int k = 0 ;
	int count = 0 ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *i = NULL ;

	head = *fhead ;
	last = *flast ;

	for(i=head ; i!=NULL ; i=i->next)
	{
		++count ;
	}
	arr = (int *)calloc(count, sizeof(int)) ;
	if(arr == NULL)
	{
		rval = 1 ; //memory allocation failed
	}
	else
	{
		rval = 0 ; //memory allocation successful
		printf("\nLinked List in Reverse = ") ;
		for(i=head, k=0 ; i!=NULL ; i=i->next , ++k)
		{
			arr[k] = i->data ;
		}
		for(k=count-1 ; k>=0 ; --k)
		{
			printf("%3d", arr[k]) ;
		}
	}

	*fhead = head ;
	*flast = last ;

	return rval ;

} //end of display_reverse

int delete_ll(struct sllnode **fhead,struct sllnode **flast)
{
	int rval = 0 ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *dnode = NULL ;
	struct sllnode *i = NULL ;

	head = *fhead ;
	last = *flast ;

	if(head == NULL)
	{
		rval = 1 ; //LL is empty
	}
	else
	{
		rval = 0 ;
		for(i=head ; i!=NULL ; i=i->next)
		{
			dnode = i ;
			head = i ;
			dnode->next = NULL ;
			free(dnode) ;
			dnode = NULL ;
		}
	}

	*fhead = head ;
	*flast = last ;

	return rval ;

} //end of delete_ll



