#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
}*head = NULL;

struct node *add_node (int data){
	struct node *temp;
	static struct node *last_node = NULL;

	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
	} 
	else {
		last_node->next = temp;
	}

	last_node = temp;

	return temp;
}

struct node *find_node (int data) {
	struct node *target_node = head;
	
	if (head == NULL) return NULL;
	
	while (target_node != NULL){
		if (target_node->data == data){
			return target_node;
		}
		target_node = target_node->next;
	}
	
	return NULL;
}

void delete_node (int data) {
    struct node *prev = NULL;
    for (struct node *temp = head; temp != NULL; temp=temp->next) {
        if (temp->data == data) {
            if (temp == head) {
            	temp = temp->next;
            	free(head);
            	head = temp;
			}
			else {
				prev->next = temp->next;
            	free(temp);
			}
            return;
        }
        prev = temp;
    }
    return;
}

void reverse_list () {
	struct node *prev = NULL, *next = NULL;

	for (struct node *temp = head; temp != NULL; temp = next) {
    	next = temp->next;
        temp->next = prev;
        prev = temp;
    }
    
	head = prev;
    return;
}

int print_list (){
	struct node *travel_node = head;
	
	if (head == NULL) return NULL;
	
	while (travel_node != NULL){
		printf("%d ---> ", travel_node->data);
		travel_node = travel_node->next;
	}
	printf("NULL.\n");
	
	return 0;
}

int main (){
	struct node *show_node;
	int choice, size, data;
	
	while(1){
		printf("1: ADD NODE IN LINKED LIST.\n2: FIND NODE IN LINKED LIST.\n3: PRINT THE LINKED LIST.\n4: DELETE NODE IN LINKED LIST.\n5: EXIT.\nEnter choice: ");
		scanf("%d", &choice);
		printf("--------------------------------------------------------------------------\n");
		switch (choice){
			case 1:
				ADD:
				printf("How many nodes you want to enter: ");
				scanf("%d", &size);
				while (size != 0){
					printf("Enter the value: ");
					scanf("%d", &data);
					show_node = add_node(data);
					printf("%d is added to linked list.\n", show_node->data);
					size--;
				}
			break;
				
			case 2:
				if (head == NULL){
					printf("THERE IS NO SUCH LINKED LIST YOU SHOULD CREATE LINKED LIST...\n");
					goto ADD;
				}
				else {
					printf("Enter the value of node that you want to find: ");
					scanf("%d", &data);
					show_node = find_node(data);
					if (show_node == NULL){
						printf("THERE IS NO SUCH NODE...\n");
					}
					else {
						printf("%d is found in linked list at location @%d.\n", show_node->data, &show_node);
					}
				}
			break;
			
			case 3:
				if (head == NULL){
					printf("THERE IS NO SUCH LINKED LIST YOU SHOULD CREATE LINKED LIST...\n");
					goto ADD;
				}
				else {
					print_list();
				}
			break;
			
			case 4:
				if (head == NULL){
					printf("THERE IS NO SUCH LINKED LIST YOU SHOULD CREATE LINKED LIST...\n");
					goto ADD;
				}
				else {
					printf("Enter the value of node that you want to delete: ");
					scanf("%d", &data);
					delete_node(data);
				}
			break;
			
			case 5:
				if (head == NULL){
					printf("THERE IS NO SUCH LINKED LIST YOU SHOULD CREATE LINKED LIST...\n");
					goto ADD;
				}
				else {
					reverse_list();
				}
			break;
			
			case 6:
				exit(0);
				
			default:
				printf("ENTERED CHOICE IS WRONG...\n");
			break;
		}
		printf("--------------------------------------------------------------------------\n\n");
	}
	
	return 0;
}
