/*#include<iostream>
using namespace std;
int main()
{
	int guess_num,actual_num=45,attempts,i;
	cout<<"Welcome to the number guessing game!!"<<endl;
	cout<<"Enter the number of attempts you want to execute:"<<endl;
	cin>>attempts;

	for(i=0;i<attempts;i++)
	{
		cout<<endl<<"Guess any number between 1 to 100:"<<endl;
		cin>>guess_num;
		if(guess_num>actual_num)
		{
			cout<<"The number entered is TOO HIGH";
		}
		else if(guess_num<actual_num)
		{
			cout<<"The number entered is TOO LOW";
		}
		else if(guess_num==actual_num)
		{
			cout<<"Congratulations!! You have guessed the number right!!";
			break;
		}
		else 
		{
			cout<<"Try Again!!";
		}
	}
}*/


/*#include<iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    else {
        return false;
    }
}

int winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') 
        current_marker = 'O';
    else 
        current_marker = 'X';

    current_player = (current_player == 1) ? 2 : 1;
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    int player_won;

    drawBoard();
    for (int i = 0; i < 9; i++) {
        cout << "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot occupied! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        player_won = winner();

        if (player_won == 1) {
            cout << "Player 1 wins! Congratulations!\n";
            break;
        }
        if (player_won == 2) {
            cout << "Player 2 wins! Congratulations!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (player_won == 0)
        cout << "It's a tie game!\n";
}

int main() {
    game();
    return 0;
}
*/

/*#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

struct Borrower {
    string name;
    string borrowedISBN;
    time_t borrowDate;
};

vector<Book> books;
vector<Borrower> borrowers;

void addBook() {
    Book book;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter book author: ";
    getline(cin, book.author);
    cout << "Enter book ISBN: ";
    getline(cin, book.ISBN);
    book.isAvailable = true;
    books.push_back(book);
    cout << "Book added successfully!" << endl;
}

void searchBook() {
    string query;
    cout << "Search by (title, author, ISBN): ";
    cin.ignore();
    getline(cin, query);

    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.ISBN == query) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN 
                 << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void checkoutBook() {
    string isbn, borrowerName;
    cout << "Enter ISBN of the book to checkout: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.ISBN == isbn) {
            if (book.isAvailable) {
                cout << "Enter borrower's name: ";
                getline(cin, borrowerName);

                Borrower borrower = {borrowerName, isbn, time(0)};
                borrowers.push_back(borrower);

                book.isAvailable = false;
                cout << "Book checked out successfully!" << endl;
                return;
            } else {
                cout << "Book is already checked out!" << endl;
                return;
            }
        }
    }
    cout << "Book not found!" << endl;
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN of the book to return: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& borrower : borrowers) {
        if (borrower.borrowedISBN == isbn) {
            time_t now = time(0);
            double seconds = difftime(now, borrower.borrowDate);
            int days = seconds / (60 * 60 * 24);

            if (days > 14) { // Assuming a 2-week borrow period
                int fine = (days - 14) * 1; // $1 fine per day
                cout << "Book is overdue by " << (days - 14) << " days. Fine: $" << fine << endl;
            }

            for (auto& book : books) {
                if (book.ISBN == isbn) {
                    book.isAvailable = true;
                    break;
                }
            }

            borrowers.erase(remove(borrowers.begin(), borrowers.end(), borrower), borrowers.end());
            cout << "Book returned successfully!" << endl;
            return;
        }
    }
    cout << "Borrower not found!" << endl;
}

void displayMenu() {
    cout << "\n1. Add Book\n2. Search Book\n3. Checkout Book\n4. Return Book\n5. Exit\nEnter your choice: ";
}

int main() {
    int choice;
    
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Exiting the library system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks) {
    string task;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back({task, false});
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!" << endl;
    } else {
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << endl;
        }
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

