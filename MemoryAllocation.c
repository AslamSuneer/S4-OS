#include<stdio.h>

void main() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;

    for(i = 0; i < 10; i++) {
        flags[i] = 0;
        allocation[i] = -1;
    }

    printf("Enter no. of blocks: ");
    scanf("%d", &bno);
    printf("\nEnter size of each block: ");
    for(i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("\nEnter no. of processes: ");
    scanf("%d", &pno);
    printf("\nEnter size of each process: ");
    for(i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    for(i = 0; i < pno; i++) {
        for(j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i]) {
                allocation[i] = j; // allocate block j to process i
                bsize[j] -= psize[i]; // reduce available memory in this block
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(i = 0; i < pno; i++) {
        printf(" %d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1); // add 1 to block number to make it human-readable
        else
            printf("Not Allocated\n");
    }
}
#include <stdio.h>

void main() {
    int fragment[20], b[20], p[20], barray[20], parray[20], i, j, nb, np, temp, lowest;

    printf("\n\t\t\tMemory Management Scheme - Best Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block no.%d: ", i);
        scanf("%d", &b[i]);
        barray[i] = 0; // Initialize block array
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the size of the processes:\n");
    for (i = 1; i <= np; i++) {
        printf("Process no.%d: ", i);
        scanf("%d", &p[i]);
        parray[i] = 0; // Initialize process array
    }

    for (i = 1; i <= np; i++) {
        lowest = 9999; // Initialize lowest to a large value
        for (j = 1; j <= nb; j++) {
            if (barray[j] == 0) { // Check if block is not allocated
                temp = b[j] - p[i];
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
    for (i = 1; i <= np && parray[i] != 0; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], parray[i], b[parray[i]], fragment[i]);
    }
}
