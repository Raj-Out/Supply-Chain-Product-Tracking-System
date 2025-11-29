#include <stdio.h>
#include "product.h"

int main() {
    struct Product products[MAX_PRODUCTS];
    int count = 0;

    int choice, id, index;

    while (1) {
        printf("\n--- Supply Chain Tracking System ---\n");
        printf("1. Add product\n");
        printf("2. Add checkpoint\n");
        printf("3. View history\n");
        printf("4. Detect anomalies\n");
        printf("5. Save logs\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 6) break;

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;

            case 2:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                index = findProduct(products, count, id);
                if (index != -1)
                    addCheckpoint(&products[index]);
                else
                    printf("Product not found.\n");
                break;

            case 3:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                index = findProduct(products, count, id);
                if (index != -1)
                    viewHistory(&products[index]);
                else
                    printf("Not found.\n");
                break;

            case 4:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                index = findProduct(products, count, id);
                if (index != -1)
                    checkAnomalies(&products[index]);
                else
                    printf("Not found.\n");
                break;

            case 5:
                saveToFile(products, count);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}