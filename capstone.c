#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
    int validity;
    float discount_price;
};

struct Item items[MAX_ITEMS];
int itemCount = 0;

void additemforkg() {
    struct Item newItem;
    printf("Enter ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Name: ");
    scanf("%s", newItem.name);
    printf("Enter Price per KG: ");
    scanf("%f", &newItem.price);
    printf("Enter Quantity in KG: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Validity: ");
    scanf("%d", &newItem.validity);
    newItem.discount_price = 0.0;
    items[itemCount++] = newItem;
    printf("\n*****************ITEM ADD SUCCESSFUL!****************\n");
}

void additemforIndividual() {
    struct Item newItem;
    printf("Enter ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Name: ");
    scanf("%s", newItem.name);
    printf("Enter Price per Item: ");
    scanf("%f", &newItem.price);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Validity: ");
    scanf("%d", &newItem.validity);
    newItem.discount_price = 0.0;
    items[itemCount++] = newItem;
    printf("\n*****************ITEM ADD SUCCESSFUL!****************\n");
}

void additemforDozen() {
    struct Item newItem;
    printf("Enter ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Name: ");
    scanf("%s", newItem.name);
    printf("Enter Price per Dozen: ");
    scanf("%f", &newItem.price);
    printf("Enter Quantity in Dozen: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Validity: ");
    scanf("%d", &newItem.validity);
    newItem.discount_price = 0.0;
    items[itemCount++] = newItem;
    printf("\n*****************ITEM ADD SUCCESSFUL!****************\n");
}

void itemType() {
    int type, weight;
    printf("1. GROCERY\n");
    printf("2. FRUITS\n");
    printf("3. CONFECTIONARY\n");
    printf("4. MEAT ITEM\n");
    printf("5. BAKERY ITEM\n");
    printf("0. Exit\n");

    printf("\nEnter the type of item you want to add: \n");
    scanf("%d", &type);
    switch(type) {
        case 1:
            additemforkg();
            break;
        case 2:
            printf("\nSelect type of weight:\n");
            printf("1. KG\n");
            printf("2. PIECE\n");
            printf("3. DOZEN\n");
            printf("0. Exit\n");
            scanf("%d", &weight);
            switch(weight) {
                case 1:
                    additemforkg();
                    break;
                case 2:
                    additemforIndividual();
                    break;
                case 3:
                    additemforDozen();
                    break;
                case 0:
                    return;
                default:
                    printf("Invalid choice! Please enter a number between 0 to 3.\n");
            }
            break;
        case 3:
            additemforIndividual();
            break;
        case 4:
            additemforkg();
            break;
        case 5:
            additemforkg();
            break;
        case 0:
            return;
        default:
            printf("Invalid choice! Please enter a number between 0 to 5.\n");
    }
}

void additem() {
    system("cls");
    itemType();
}

void saveItemsToFile() {
    system("cls");
    FILE *fp = fopen("item.txt","a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(fp, "%d %s %.2f %d %d %.2f\n", items[i].id, items[i].name, items[i].price,
                items[i].quantity, items[i].validity, items[i].discount_price);
    }
    fclose(fp);

    printf("Items saved to file successfully.\n");
}

void loadItemsFromFile() {
    system("cls");
    FILE *fp = fopen("item.txt","a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    itemCount = 0;
    while (fscanf(fp, "%d %s %f %d %d %f", &items[itemCount].id,
                  items[itemCount].name, &items[itemCount].price, &items[itemCount].quantity,
                  &items[itemCount].validity, &items[itemCount].discount_price) == 6) {
        itemCount++;
    }
    fclose(fp);
}

void searchitem() {
    system("cls");
    printf("\nSearching Item\n");
    int search;
    printf("Enter ID of item to search: ");
    scanf("%d", &search);
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == search) {
            found = 1;
            printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", items[i].id,
                   items[i].name, items[i].price, items[i].quantity);
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", search);
    }
}

void deleteitem() {
    system("cls");
    printf("\nDeleting Item\n");
    int idToDelete;
    printf("Enter ID of item to delete: ");
    scanf("%d", &idToDelete);
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == idToDelete) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];
            }
            itemCount--;
            break;
        }
    }
    if (found) {
        printf("Item with ID %d deleted.\n", idToDelete);
        saveItemsToFile();
    } else {
        printf("Item with ID %d not found.\n", idToDelete);
    }
}

void calculatebill() {
    system("cls");
    int itemIDs[100];
    int quantity[100];
    int numItems;
    printf("\nCalculating Bill\n");
    float totalBill = 0.0;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    printf("Enter the IDs of the items to purchase: ");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &itemIDs[i]);
    }
    printf("Enter the quantity of the item: ");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &quantity[i]);
    }
    

    for (int i = 0; i < numItems; i++) {
        int found = 0;
        for (int j = 0; j < itemCount; j++) {
            if (items[j].id == itemIDs[i]) {
                found = 1;
                  if (sizeof(quantity) <= items[j].quantity)
            {
                printf("Item %s: %s x %d = %.2f\n", itemIDs, items[j].name,quantity[i],(items[j].price*quantity[i]));
                totalBill = totalBill + (items[j].price * quantity[i]);
                items[j].quantity = items[j].quantity - quantity[i];
            }
            else
            {
                printf("!!!Not available. Only %d of quantity available!!!\n", items[j].quantity);
            }
            break;
            }
        }
        if (!found) {
            printf("Item with ID %d not found.\n", itemIDs[i]);
        }
    }
    printf("Total Bill: %.2f\n", totalBill);
}


void discountitem() {
    system("cls");
    printf("\nApplying Discount\n");
    for (int i = 0; i < itemCount; i++) {
        if (items[i].validity > 30) {
            items[i].discount_price = items[i].price - (items[i].price * 0.2);
            printf("Item %d: %s, New Discount Price: %.2f\n", items[i].id,
                   items[i].name, items[i].discount_price);
        }else
        {
            printf("\n!!!!NO ITEM TO DISCOUNT!!!!\n");
        }
    }
}

void viewitem() {
    system("cls");
    printf("\nViewing Item\n");
        if (itemCount == 0)
    {
        printf("No item found\n");
    }else{
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", items[i].id,
               items[i].name, items[i].price, items[i].quantity);
        }
    }
}

int main() {
    loadItemsFromFile();
    int choice;
    do {
        printf("\n***********************Welcome***********************\n");
        printf("\n=============== Super Shop Management ===============\n");
        printf("1. Add Item\n");
        printf("2. Search Item\n");
        printf("3. Delete Item\n");
        printf("4. View Item\n");
        printf("5. Calculate Bill\n");
        printf("6. View Discount\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                additem();
                break;
            case 2:
                searchitem();
                break;
            case 3:
                deleteitem();
                break;
            case 4:
                viewitem();
                break;
            case 5:
                calculatebill();
                break;
            case 6:
                discountitem();
                break;
            case 0:
                saveItemsToFile();
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 0 to 6.\n");
        }
    } while (1);
    return 0;
}
// this is my capstone project
