#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int colorim;
    char dataset[20];
    struct node *link;
};

typedef struct node *NODE;

// to get the nodes
NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory not allocated \n");
        exit(0);
    }
    return temp;
}

// inserting at the front of the linked list
NODE insert_front(NODE first, int coloritems, char data[20])
{
    NODE temp = getnode();
    temp->colorim = coloritems;
    strcpy(temp->dataset, data);
    temp->link = first;
    return temp;
}

// inserting at the rear of the linked list
NODE insert_rear(NODE first, int coloritems, char data[20])
{
    NODE temp, prev, cur;
    temp = getnode();
    temp->link = NULL;
    temp->colorim = coloritems;
    strcpy(temp->dataset, data);
    if (first == NULL)
	{
        return temp;
    }
    cur = first;
    prev = NULL;
    while (cur != NULL)
	{
        prev = cur;
        cur = cur->link;
    }
    prev->link = temp;
    return first;
}

// deleting at the front of the linked list
// Function to delete a node with a specific colorim value
NODE delete_node(NODE first, int del_dataset)
{
    if (first == NULL)
	{
        printf("No Dataset Present \n");
        return first;
    }

    NODE cur = first;
    NODE prev = NULL;

    // If the node to be deleted is the first node
    if (cur->colorim == del_dataset)
	{
        NODE next = cur->link;
        free(cur);
        return next;
    }

    // Traverse the list to find the node with the specified colorim value
    while (cur != NULL && cur->colorim != del_dataset)
	{
        prev = cur;
        cur = cur->link;
    }

    // If the node with the specified colorim value is found, delete it
    if (cur != NULL)
	{
        prev->link = cur->link;
        free(cur);
    }
	else
	{
        printf("Node with colorim %d not found\n", del_dataset);
    }

    return first;
}


// displaying contents of the linked list
void display(NODE first)
{
    if (first == NULL)
	{
        printf("No datasets present\n");
        return;
    }
    NODE cur;
    cur = first;
    while (cur != NULL) 
	{
        printf("%s ", cur->dataset);
        printf("%d\n", cur->colorim);
        cur = cur->link;
    }
}

// sorting contents of the linked list based on the number of color images
void sort(NODE first)
{
    int n = 0;
    NODE count;
    int i, j;
    count = first;
    while (count != NULL)
	{
        n++;
        count = count->link;
    }
    NODE cur;
    for (i = 0; i < n - 1; i++)
	{
        cur = first;
        for (j = 0; j < n - i - 1; j++)
		{
            if (cur->colorim > cur->link->colorim)
			{
                // Swap entire nodes
                int temp_colorim = cur->colorim;
                cur->colorim = cur->link->colorim;
                cur->link->colorim = temp_colorim;

                char temp_dataset[20];
                strcpy(temp_dataset, cur->dataset);
                strcpy(cur->dataset, cur->link->dataset);
                strcpy(cur->link->dataset, temp_dataset);
            }
            cur = cur->link;
        }
    }
}

// counting the number of nodes in the linked list
void count(NODE first)
{
    int count = 0;
    if (first == NULL)
	{
        count = 0;
    }
    NODE cur;
    cur = first;
    while (cur != NULL)
	{
        count++;
        cur = cur->link;
    }
    printf("The total number of datasets are %d\n", count);
}

// main function
int main()
{
    NODE first;
    first = NULL;
    int ch, elem1;
    char elem2[20];
    while (1)
	{
        printf("1. INSERT FRONT\n2. INSERT REAR\n3. DELETE A PARTICULAR DATASET\n4. DISPLAY\n5. SORTING BASED ON NUMBER OF IMAGES\n6. COUNTING THE NUMBER OF DATASETS\n7. EXIT\n");
        printf("Enter choice:\n");
        scanf("%d", &ch);
        switch (ch)
		{
            case 1:
                printf("enter the dataset and the number of colors \n");
                scanf("%s%d", elem2, &elem1);
                first = insert_front(first, elem1, elem2);
                break;
            case 2:
                printf("enter the dataset and the number of colors \n");
                scanf("%s%d", elem2, &elem1);
                first = insert_rear(first, elem1, elem2);
                break;
            case 3:
    			printf("Enter the colorim value of the node to be deleted:\n");
    			scanf("%d", &elem1);
    			first = delete_node(first, elem1);
    			break;
            case 4:
                display(first);
                break;
            case 5:
                sort(first);
                break;
            case 6:
                count(first);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}

