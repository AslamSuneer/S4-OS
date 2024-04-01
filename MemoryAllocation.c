#include <stdio.h>

void firstFit(int bsize[], int psize[], int bno, int pno) {
    int allocation[10] = {-1}; // Initialize allocation array to -1 (unallocated)

    for (int i = 0; i < pno; i++) {
        for (int j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i] && allocation[j] == -1) {
                allocation[j] = i; // Allocate block j to process i
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < pno; i++) {
        printf(" %d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1); // Add 1 to block number for human readability
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int bsize[], int psize[], int bno, int pno) {
    int fragment[20] = {0}, barray[20] = {0}, parray[20] = {0}, lowest;

    for (int i = 1; i <= pno; i++) {
        lowest = 9999; // Initialize lowest to a large value
        for (int j = 1; j <= bno; j++) {
            if (barray[j] == 0 && bsize[j] >= psize[i]) {
                int temp = bsize[j] - psize[i];
                if (temp >= 0 && temp < lowest) {
                    parray[i] = j; // Allocate block to process
                    lowest = temp; // Update lowest fragment
                }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1; // Mark block as allocated
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n");
    for (int i = 1; i <= pno && parray[i] != 0; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, psize[i], parray[i], bsize[parray[i]], fragment[i]);
    }
}

void worstFit(int bsize[], int psize[], int bno, int pno) {
    int allocation[10] = {-1}; // Initialize allocation array to -1 (unallocated)

    for (int i = 0; i < pno; i++) {
        int worstplace = -1;
        for (int j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i]) {
                if (worstplace == -1 || bsize[worstplace] < bsize[j]) {
                    worstplace = j;
                }
            }
        }
        if (worstplace != -1) {
            allocation[i] = worstplace; // Allocate block worstplace to process i
            bsize[worstplace] -= psize[i]; // Reduce available memory in this block
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < pno; i++) {
        printf(" %d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1); // Add 1 to block number for human readability
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int choice, bsize[10], psize[10], bno, pno;

    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    printf("Enter size of each block: ");
    for (int i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter size of each process: ");
    for (int i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    do {
        printf("\nMemory Management Menu\n");
        printf("1. First Fit\n");
        printf("2. Best Fit\n");
        printf("3. Worst Fit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                firstFit(bsize, psize, bno, pno);
                break;
            case 2:
                bestFit(bsize, psize, bno, pno);
                break;
            case 3:
                worstFit(bsize, psize, bno, pno);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
