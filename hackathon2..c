#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Todo {
    int id;
    char startDate[50];
    char endDate[50];
    char content[100];
    bool status;
};



struct Todo todoList[100];
int todoCount = 2; 

void printTodoList() {
    printf("Danh sach Todo:\n");
    for (int i = 0; i < todoCount; i++) {
        printf("%d. %s\n", todoList[i].id, todoList[i].content);
    }
}


void addTodo() {
    struct Todo newTodo;
    
    printf("Nhap thong tin cho Todo moi:\n");
    printf("Noi dung: ");
    scanf("%s", newTodo.content); 
    
    newTodo.id = todoCount + 1;
    newTodo.status = false; 
    
    todoList[todoCount] = newTodo;
    todoCount++;
    
    printf("Da them moi Todo thanh cong!\n");
}

void updateTodo() {
    char searchContent[100];
    int foundIndex = -1;
    
    printf("Nhap noi dung cua Todo muon chinh sua: ");
    scanf("%s", searchContent);
    
    
    for (int i = 0; i < todoCount; i++) {
        if (strcmp(todoList[i].content, searchContent) == 0) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex != -1) {
      
      
        printf("Nhap thong tin moi cho Todo:\n");
        printf("Noi dung: ");
        scanf("%s", todoList[foundIndex].content);
        
        printf("Da cap nhat Todo thanh cong!\n");
    } else {
        printf("Khong tim thay Todo can chinh sua!\n");
    }
}


void deleteTodo() {
    char deleteContent[100];
    int foundIndex = -1;
    
    printf("Nhap noi dung cua Todo muon xoa: ");
    scanf("%s", deleteContent);
    
    
    for (int i = 0; i < todoCount; i++) {
        if (strcmp(todoList[i].content, deleteContent) == 0) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex != -1) {
       
        for (int i = foundIndex; i < todoCount - 1; i++) {
            todoList[i] = todoList[i + 1];
        }
        todoCount--;
        
        printf("Da xoa Todo thanh cong!\n");
    } else {
        printf("Khong tim thay Todo can xoa!\n");
    }
}


void sortTodoList() {
    for (int i = 0; i < todoCount - 1; i++) {
        for (int j = i + 1; j < todoCount; j++) {
            if (strcmp(todoList[i].content, todoList[j].content) > 0) {
               
                struct Todo temp = todoList[i];
                todoList[i] = todoList[j];
                todoList[j] = temp;
            }
        }
    }
    
    printf("Da sap xep danh sach Todo theo content!\n");
}


void searchTodo() {
    char searchContent[100];
    int left = 0, right = todoCount - 1;
    int foundIndex = -1;
    
    printf("Nhap noi dung cua Todo can tim kiem: ");
    scanf("%s", searchContent);
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(todoList[mid].content, searchContent) == 0) {
            foundIndex = mid;
            break;
        } else if (strcmp(todoList[mid].content, searchContent) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (foundIndex != -1) {
        printf("Tim thay Todo:\n");
        printf("ID: %d\n", todoList[foundIndex].id);
        printf("Noi dung: %s\n", todoList[foundIndex].content);
        printf("Trang thai: %s\n", todoList[foundIndex].status ? "Hoan thanh" : "Chua hoan thanh");
    } else {
        printf("Khong tim thay Todo!\n");
    }
}




int main() {
    int choice;


    todoList[0].id = 1;
    strcpy(todoList[0].startDate, "2023-12-01");
    strcpy(todoList[0].endDate, "2023-12-05");
    strcpy(todoList[0].content, "hoan thanh bia tap lap trinh");
    todoList[0].status = false; 


    todoList[1].id = 2;
    strcpy(todoList[1].startDate, "2023-12-02");
    strcpy(todoList[1].endDate, "2023-12-07");
    strcpy(todoList[1].content, "doc sach");
    todoList[1].status = true;
     
	    
    do {
        printf("************************MENU**************************\n");
        printf("1. In toan bo danh sach Todo co o trong mang todoList tren cung mot hang\n");
        printf("2. Them moi Todo\n");
        printf("3. Cap nhat thong tin Todo\n");
        printf("4. Xoa Todo\n");
        printf("5. Sap xep danh sach Todo theo content\n");
        printf("6. Tim kiem Todo theo content\n");
        printf("7. Tim kiem va in ra danh sach Todo theo status\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang (1-8): ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printTodoList();
                break;
            case 2:
                addTodo();
                break;
            case 3:
                updateTodo();
                break;
            case 4:
                deleteTodo();
                break;
            case 5:
                sortTodoList();
                break;
            case 6:
                searchTodo();
                break;
            case 7:
               
                break;
            case 8:
                printf("Tam biet!\n");
                break;
            default:
                printf("Chon sai, vui long nhap lai!\n");
        }
    } while (choice != 8);

    return 0;
}


