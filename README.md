# Super Shop Management System
This is a basic console-based application for managing items in a shop. It includes functionalities such as adding, searching, deleting, viewing, and calculating bills for items. Additionally, it supports discounts on items based on validity. Items can be of different types such as grocery, fruits, confectionary, bakery, and more. The application stores data in a file and loads it when the program starts.

## Features
### Add Item
Allows the user to add new items to the shop. Items can be categorized by weight (kg), pieces, or dozen.

### Search Item
Search for an item by its ID and display its details such as name, price, and quantity.

### Delete Item
Remove an item from the list based on its ID.

### View Item
View all the items currently available in the shop.

### Calculate Bill
Calculate the total bill by entering the IDs of items and their quantities. The system checks for availability before finalizing the bill.

### Apply Discount
Items with validity greater than 30 days will have a 20% discount applied.

### Save and Load Items from File
The system automatically loads items from a file when it starts and saves any updates before exiting.

### File Structure
__item.txt:__ This file stores the details of all items added to the system, and is read when the program starts and updated when items are added, deleted, or updated.

## Adding Items
Choose from various categories like grocery, fruits, bakery, etc.
Provide details such as ID, name, price, quantity, and validity.
## Searching Items
Input the ID of the item you wish to search for.
## Deleting Items
Input the ID of the item to be removed.
## Viewing Items
Displays the list of all current items in the shop.
## Calculating Bill
Input the IDs and quantities of items being purchased, and the total bill will be calculated.
## Applying Discount
Discounts are automatically applied to items with a validity of more than 30 days.
## File Operations
The program saves the items and their data in the file item.txt. This ensures that when the program is restarted, the data is preserved.
Every time an item is added, deleted, or updated, the file is rewritten to reflect the current state.
## _Notes_
This system currently does not support advanced features such as a graphical user interface (GUI) or database integration.
It operates as a basic console application that uses file handling to store and retrieve data.
Limitations
No concurrency support, so only one instance of the program should run at a time.
Data is saved in plain text format, which is not encrypted.
Future Improvements
Add inventory management by date to track expired items.
Introduce an admin login for security.
Improve the user interface and experience with additional features.