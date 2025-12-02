#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int main() {
    printf("The Binary Tree Operations are:\n");
    printf("1.Insert\n2.Search\n3.Delete\n4.Exit\n");

    int choice, value;
    struct Node *root = NULL;

    while (1) {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
        // -----------------------------------------------------
        // INSERT
        // -----------------------------------------------------
        case 1: {
            printf("Enter the Value to insert: ");
            scanf("%d", &value);

            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->left = newNode->right = NULL;

            if (root == NULL) {
                root = newNode;
            } else {
                struct Node *curr = root, *parent = NULL;

                while (curr != NULL) {
                    parent = curr;
                    if (value < curr->data)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }

                if (value < parent->data)
                    parent->left = newNode;
                else
                    parent->right = newNode;
            }

            printf("The value %d is inserted.\n", value);
            break;
        }

        // -----------------------------------------------------
        // SEARCH
        // -----------------------------------------------------
        case 2: {
            printf("Enter the element to search: ");
            scanf("%d", &value);

            struct Node *curr = root;
            int found = 0;

            while (curr != NULL) {
                if (value == curr->data) {
                    found = 1;
                    break;
                } else if (value < curr->data)
                    curr = curr->left;
                else
                    curr = curr->right;
            }

            if (found)
                printf("The value %d is found!\n", value);
            else
                printf("The value %d is not found!\n", value);
            break;
        }

        // -----------------------------------------------------
        // DELETE
        // -----------------------------------------------------
        case 3: {
            printf("Enter the value to delete: ");
            scanf("%d", &value);

            struct Node *curr = root, *parent = NULL;

            // Step 1: Search node
            while (curr != NULL && curr->data != value) {
                parent = curr;
                if (value < curr->data)
                    curr = curr->left;
                else
                    curr = curr->right;
            }

            if (curr == NULL) {
                printf("The element %d is not found.\n", value);
                break;
            }

            // Case A: Node has 2 children
            if (curr->left != NULL && curr->right != NULL) {
                struct Node *succ = curr->right;
                struct Node *succParent = curr;

                // find inorder successor
                while (succ->left != NULL) {
                    succParent = succ;
                    succ = succ->left;
                }

                curr->data = succ->data; // copy successor value
                curr = succ;             // delete successor instead
                parent = succParent;
            }

            // Case B or C: One child or no child
            struct Node *child = NULL;
            if (curr->left != NULL)
                child = curr->left;
            else
                child = curr->right;

            if (parent == NULL) {
                root = child;
            } else if (parent->left == curr) {
                parent->left = child;
            } else {
                parent->right = child;
            }

            free(curr);
            printf("%d deleted successfully.\n", value);
            break;
        }

        // -----------------------------------------------------
        // EXIT
        // -----------------------------------------------------
        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
